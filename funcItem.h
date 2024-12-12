#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Creatures.h"
#include "Items.h"
void printItem(Items item);
Items createWeapon(const char name[30], int damage);
Items createArmor(const char name[30], int defense);
Items createPotion(const char name[30], int healingAmount);