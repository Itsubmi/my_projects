#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Creatures.h"
Creatures attack(Creatures attacker, Creatures target);
Creatures regeneration_health(Creatures entity);
Creatures level_up(Creatures entity);
bool visibility(Creatures entity, Creatures other_entities);
void print_creature(Creatures entity);
int choose_hero(Creatures heroes[], int size);
Creatures attack_monster(Creatures hero, Creatures monster);
void display_status(Creatures hero, Creatures monster);