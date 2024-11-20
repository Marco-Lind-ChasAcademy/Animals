#ifndef CAT_H
#define CAT_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int claw_length;

} Cat;

int initCat(Cat **cat, char *name);
void deinitCat(Cat **cat);
void displayCatInfo(Cat *cat);
unsigned int catSlashAnimal(Cat *attacker, Animal *victim);


#endif