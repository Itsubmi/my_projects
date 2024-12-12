#include <stdio.h>
#include <math.h>   
#include <stdbool.h>
#include <string.h>
#include "Creatures.h"
#include "FuncCreatures.h"
#include <stdlib.h>
#include "Location.h"
#include "FuncLocation.h"
#include "FuncChest.h"
#include "Chest.h"
#include "Items.h"
#include "funcItem.h"
#include <time.h>
int main() {

    srand(time(NULL));

    // Хорошие и плохие предметы, объединенный списочек
    Items allItems[24] = {
    // Хорошие предметы
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Brandon's Sword", .damage = 15}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Mark's Axe", .damage = 15}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Elis's Klinok", .damage = 15}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Jessel's Posoh", .damage = 15}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Shield", .defense = 10}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Shlem", .defense = 15}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Nagrudnik", .defense = 20}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Shtani", .defense = 18}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Botinki", .defense = 12}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Healing Potion", .healingAmount = 30}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Healing Potion", .healingAmount = 15}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Healing Potion", .healingAmount = 60}},

        // Плохие предметы
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Bad Brandon's Sword", .damage = -1}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Bad Mark's Axe", .damage = -5}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Bad Elis's Klinok", .damage = -3}},
        {.type = ITEM_TYPE_WEAPON, .data.weapon = {.name = "Bad Jessel's Posoh", .damage = -2}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Bad Shield", .defense = -10}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Bad Shlem", .defense = -15}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Bad Nagrudnik", .defense = -20}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Bad Shtani", .defense = -18}},
        {.type = ITEM_TYPE_ARMOR, .data.armor = {.name = "Bad Botinki", .defense = -12}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Bad Healing Potion", .healingAmount = -30}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Bad Healing Potion", .healingAmount = -15}},
        {.type = ITEM_TYPE_POTION, .data.potion = {.name = "Bad Healing Potion", .healingAmount = -60}}
    };

    Creatures heroes[4] = 
    {
        {"Brandon", 100, 50, 10, 20, 0, 0, 2, 2, 5.5, 5.5, {11.0, 11.0}, 0, true, 100, 0, 0, 0},
        {"Mark", 150, 100, 5, 1, 0, 10, 2, 1, 5.5, 5.5, {11.0, 11.0}, 0, true, 150, 0, 0, 0},
        {"Elis", 80, 120, 30, 4, 0, 30, 5, 4, 5.5, 5.5, {11.0, 11.0}, 0, true, 80, 0, 0, 0},
        {"Jissel", 110, 70, 9, 1, 0, 5, 2, 1, 5.5, 5.5, {11.0, 11.0}, 0, true, 110, 0, 0, 0}
    };

    Location loc = tecushee_location(11.0, 11.0);
    Chest treasure_chest;
    
    Creatures monster = {"Monster", 110, 70, 9, 1, 0, 5, 2, 1, 10.5, 10.5, {11.0, 11.0}, 0, true, 110, 0, 0, 0};
    
    int chosen_hero_index = choose_hero(heroes, sizeof(heroes) / sizeof(heroes[0]));
    
    if (chosen_hero_index == -1) {
        return -1;
    }

    Creatures chosen_hero = heroes[chosen_hero_index];

    display_status(chosen_hero, monster);

    print_location(loc);
    your_choice(loc);
    chosen_hero.x = loc.x; 
    chosen_hero.y = loc.y;
    treasure_chest.x = 10.0; // Значение X для сундука
    treasure_chest.y = 10.0; // Значение Y для сундука
    
    char choice;

    if (visibility(chosen_hero, monster)) {
        printf("You see a monster!\n");
        chosen_hero = attack_monster(chosen_hero, monster);
    } else {
        printf("The monster is not in the radius of visibility.\n");
    }

    if (visibility_with_chest(chosen_hero, treasure_chest)) {
        char choice;
        printf("You see a chest! Want to open? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            treasure_chest = create_chest(chosen_hero, allItems, sizeof(allItems) / sizeof(allItems[0]));
            display_chest(treasure_chest);
        } else if (choice == 'n' || choice == 'N') {
            printf("You chose not to open the chest.\n");
        } else {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    } else {
        printf("You do not see any chests nearby.\n");
    }  

    system("pause");
    return 0;
}