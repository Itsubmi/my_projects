#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Items.h"
#include "Creatures.h"
#ifndef CHEST_H
#define CHEST_H
typedef struct {
    Items items[12];
    bool isOpen;
    int ItemsNow;
    int creature_location[2];
    float x;
    float y;
} Chest;
#endif