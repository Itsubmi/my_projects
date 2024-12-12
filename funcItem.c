#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Creatures.h"
#include "Items.h"
void printItem(Items item) {
    printf("Name: %s\n", item.name);
    
    switch (item.type) {
        case ITEM_TYPE_WEAPON:
            printf("Type: Weapon\nDamage: %d\n", item.data.weapon.damage);
            break;
        case ITEM_TYPE_ARMOR:
            printf("Type: Armor\nDefense: %d\n", item.data.armor.defense);
            break;
        case ITEM_TYPE_POTION:
            printf("Type: Potion\nHealing Amount: %d\n", item.data.potion.healingAmount);
            break;
        default:
            printf("Unknown item type\n");
            break;
    }
}

Items createWeapon(const char name[30], int damage) {
    Items newItem;
    strcpy(newItem.name, name);
    newItem.type = ITEM_TYPE_WEAPON;
    newItem.is_selected = false;
    newItem.data.weapon.damage = damage;
    return newItem;
}

Items createArmor(const char name[30], int defense) {
    Items newItem;
    strcpy(newItem.name, name);
    newItem.type = ITEM_TYPE_ARMOR;
    newItem.is_selected = false;
    newItem.data.armor.defense = defense;
    return newItem;
}

Items createPotion(const char name[30], int healingAmount) {
    Items newItem;
    strcpy(newItem.name, name);
    newItem.type = ITEM_TYPE_POTION;
    newItem.is_selected = false;
    newItem.data.potion.healingAmount = healingAmount;
    return newItem;
}