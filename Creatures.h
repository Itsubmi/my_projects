#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Location.h"
#include "Location.h"
#ifndef CREATURES_H
#define CREATURES_H
typedef struct {
    char name[50];
    int health; /* Здоровье */
    int mana; /* Мана */
    int mana_restore_by_hit; /* Сколько тратится маны за удар */
    int regeneration_hp; /* Сколько регенерируется здоровья в секунду */
    int restore_mana; /* Сколько регенерируется мана в секунду */
    float damage; /* Сколько хп может отнять */
    int radius_of_visibility;
    int radius_dmg;
    float x;
    float y;
    int creature_location[2]; /* Координаты */
    int defence;
    bool see_other_creature;
    int health_right_now;
    int luck;
    int agility;
    int speed;
    int experience;
} Creatures;
#endif