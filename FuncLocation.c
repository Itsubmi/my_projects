#include <stdio.h>
#include <stdlib.h>
#include "Location.h"
#include "Creatures.h"
Location tecushee_location(float width, float height) {
    Location loc;
    Creatures creature;
    loc.x = width / 2; // Значение X для героя, стоящего в середине комнаты
    loc.y = height / 2; // Значение Y для героя, стоящего в середине комнаты
    loc.room[0] = width; // ДЛИНА
    loc.room[1] = height; // ВЫСОТА
    creature.x = loc.x;
    creature.y = loc.y;
    return loc;
}

Location move(Location loc, char direction, Creatures creature) {
    switch (direction) {
        case 'w':
            if (loc.y < loc.room[1] - 1) {
                loc.y += 1;
                creature.y = loc.y;
            } else {
                printf("Hit the wall up!\n");
            }
            break;
        case 's':
            if (loc.y > 0) {
                loc.y -= 1;
                creature.y = loc.y;
            } else {
                printf("Hit the wall down!\n");
            }
            break;
        case 'a':
            if (loc.x > 0) {
                loc.x -= 1;
                creature.x = loc.x;
            } else {
                printf("Hit the wall left!\n");
            }
            break;
        case 'd':
            if (loc.x < loc.room[0] - 1) {
                loc.x += 1;
                creature.x = loc.x;
            } else {
                printf("Hit the wall right!\n");
            }
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
    return loc;
}

void print_location(const Location loc) {
    printf("Current position: (%.1f, %.1f)\n", loc.x, loc.y);
}

Location your_choice(Location loc, Creatures creature) {
    char choice;
    char continue_choice;

    do {
        printf("In which direction do you want to go (w/a/s/d): ");
        scanf(" %c", &choice);

        loc = move(loc, choice, creature);
        print_location(loc);

        printf("Continue moving? (y/n): ");
        scanf(" %c", &continue_choice);

    } while (continue_choice == 'y');

    return loc;
}