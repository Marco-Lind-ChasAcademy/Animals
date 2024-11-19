#ifndef CAT_H
#define CAT_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int claw_length;

} Cat;

Cat *initCat(char *name);
void deInitCat(Cat **cat);
void displayCatInfo(Cat *cat);
unsigned int catCrazyClawSlash(Cat *attacker, Animal *victim);


#endif