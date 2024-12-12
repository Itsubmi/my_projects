#include <stdio.h>
#include <stdlib.h>
#include "Location.h"
Location tecushee_location(float width, float height);
Location move(Location loc, char direction, Creatures creature);
Location your_choice(Location loc);
void print_location(const Location loc);