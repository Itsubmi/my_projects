#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Items.h"
#include "Creatures.h"
#include "Chest.h"
int random_number(int max);
Chest create_chest(Creatures entity, Items allItems[], int numAllItems);
void printItem(Items item);
void display_chest(Chest chest);