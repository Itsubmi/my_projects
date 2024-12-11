#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Creatures.h"
#include "FuncCreatures.h"
Creatures attack(Creatures attacker, Creatures target) {
    int dx = attacker.creature_location[0] - target.creature_location[0];
    int dy = attacker.creature_location[1] - target.creature_location[1];
    int distance_squared = dx * dx + dy * dy;
    int attack_radius_squared = attacker.radius_dmg * attacker.radius_dmg;

    if (distance_squared <= attack_radius_squared) {
        if (attacker.mana >= attacker.mana_restore_by_hit) {
            target.health -= attacker.damage;
            attacker.mana -= attacker.mana_restore_by_hit;
            printf("%s attacked %s for %d damage!\n", attacker.name, target.name, attacker.damage);
        } else {
            printf("Not enough mana.\n");
        }
    } else {
        printf("%s is out of range to attack %s.\n", attacker.name, target.name);
    }
    return target;
}

Creatures regeneration_health(Creatures entity) {
    if (entity.health < entity.health_right_now) {
        entity.health += entity.regeneration_hp;
        if (entity.health > entity.health_right_now) {
            entity.health = entity.health_right_now;
        }
    }
    return entity; // Возвращаем изменённый объект
}

Creatures level_up(Creatures entity) {
    char what_make_better[30];

    printf("What do you want to improve? (luck/agility/speed): ");
    scanf("%29s", what_make_better);
    
    if (strcmp(what_make_better, "luck") == 0) {
        entity.luck += 1;
        printf("%s improved its characteristics! Luck: %d\n", entity.name, entity.luck);
    } else if (strcmp(what_make_better, "agility") == 0) {
        entity.agility += 1;
        printf("%s improved its characteristics! Agility: %d\n", entity.name, entity.agility);
    } else if (strcmp(what_make_better, "speed") == 0) {
        entity.speed += 1;
        printf("%s improved its characteristics! Speed: %d\n", entity.name, entity.speed);
    } else {
        printf("Not a valid choice.\n");
    }
    print_creature(entity);
}

bool visibility(Creatures entity, Creatures other_entities) {
    int dx = entity.creature_location[0] - other_entities.creature_location[0];
    int dy = entity.creature_location[1] - other_entities.creature_location[1];
    int distance_squared = dx * dx + dy * dy;
    int visibility_radius_squared = entity.radius_of_visibility * entity.radius_of_visibility;
    return distance_squared <= visibility_radius_squared;
}

void print_creature(Creatures entity) {
    printf("%s:\n", entity.name);
    printf("Health: %d\n", entity.health);
    printf("Mana: %d\n", entity.mana);
    printf("Damage: %.1f\n", entity.damage);
    printf("Location: (%.1f, %.1f)\n", entity.x, entity.y);
    printf("Defence: %d\n", entity.defence);
    printf("Luck: %d\n", entity.luck);
    printf("Agility: %d\n", entity.agility);
    printf("Speed: %d\n", entity.speed);
    printf("Experience: %d\n", entity.experience);
}

int choose_hero(Creatures heroes[], int size) {
    int chosen_hero_index;
    printf("Choose a hero (0-%d): ", size - 1);
    scanf("%d", &chosen_hero_index);
    
    if (chosen_hero_index < 0 || chosen_hero_index >= size) {
        printf("Not a valid choice.\n");
        return -1;
    }

    return chosen_hero_index;
}
Creatures attack_monster(Creatures hero, Creatures monster) {
    char choice;

    printf("Do you want to attack (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        int attack_count;
        printf("How many times do you want to attack? ");
        scanf("%d", &attack_count);

        for (int i = 0; i < attack_count; i++) {
            if (monster.health > 0) {
                monster = attack(hero, monster);
                printf("The monster took damage! Remaining health: %d\n", monster.health);

                if (monster.health > 0) {
                    char continue_choice;
                    printf("The monster is still alive. Do you want to continue attacking? (y/n): ");
                    scanf(" %c", &continue_choice);

                    if (continue_choice != 'y') {
                        printf("You decided not to continue the attack.\n");
                        break;
                    }
                }
            } else {
                printf("The monster is already defeated!\n");
                break;
            }
        }

        if (monster.health <= 0) {
            hero.experience += 1;
            printf("%s gains 1 experience point!\n", hero.name);
            hero = level_up(hero);
            return hero;
        }
    } else {
        printf("%s chose not to attack.\n", hero.name);
        return hero;
    }
}

void display_status(Creatures hero, Creatures monster) {
    print_creature(hero);
    printf("\n");
    print_creature(monster);
}