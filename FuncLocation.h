#include <stdio.h>
#include <stdlib.h>
#include "Location.h"
#ifndef FUNC_CREATURES_H
#define FUNC_CREATURES_H
Location tecushee_location(float width, float height);
Location move(Location loc, char direction, Creatures creature);
Location your_choice(Location loc);
void print_location(const Location loc);
#endif