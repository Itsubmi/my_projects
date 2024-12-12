#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Creatures.h"
#ifndef ITEMS_H
#define ITEMS_H
typedef enum {
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_ARMOR,
    ITEM_TYPE_POTION
} ItemType;

typedef struct {
    char name[30];
    int damage;
} Weapon;

typedef struct {
    char name[30];
    int defense;
} Armor;

typedef struct {
    char name[30];
    int healingAmount;
} Potion;

typedef union {
    Weapon weapon;
    Armor armor;
    Potion potion;
} ItemData;

typedef struct {
    char name[30];
    ItemType type;
    bool is_selected;
    ItemData data;
    char description[100];
    Creatures luck;
} Items;
#endif