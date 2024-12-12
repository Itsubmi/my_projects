#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Items.h"
#include "Creatures.h"
#include "Chest.h"
int random_number(int max) {
    return rand() % max;
}

Chest create_chest(Creatures entity, Items allItems[], int numAllItems) {
    Chest chest;
    chest.isOpen = false;
    chest.ItemsNow = 0;

    // Выбираем 5 случайных предметов из общего списка
    for (int i = 0; i < 5; i++) {
        int randomIndex = random_number(numAllItems);
        chest.items[chest.ItemsNow++] = allItems[randomIndex];
    }

    return chest;
}

Chest chest_location(Chest chest_loc) {
    chest_loc.x = 10.0; // Значение X для сундука
    chest_loc.y = 10.0; // Значение Y для сундука
    return chest_loc;
}

void printItem(Items item) {
    switch (item.type) {
        case ITEM_TYPE_WEAPON:
            printf("Weapon: %s, Damage: %d\n", item.data.weapon.name, item.data.weapon.damage);
            break;
        case ITEM_TYPE_ARMOR:
            printf("Armor: %s, Defense: %d\n", item.data.armor.name, item.data.armor.defense);
            break;
        case ITEM_TYPE_POTION:
            printf("Potion: %s, Healing Amount: %d\n", item.data.potion.name, item.data.potion.healingAmount);
            break;
        default:
            printf("Unknown item type.\n");
            break;
    }
}

void display_chest(Chest chest) { 
    printf("Chest contents:\n");
    for (int i = 0; i < chest.ItemsNow; i++) { 
        printItem(chest.items[i]);
        printf("---------\n");
    }
}