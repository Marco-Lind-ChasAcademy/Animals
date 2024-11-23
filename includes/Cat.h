#ifndef CAT_H
#define CAT_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int claw_length;

} Cat;

int catInit(Cat **cat, char *name);
void catDeinit(Cat **cat);
void catDisplayInfo(Cat *cat);
unsigned int catSlashAnimal(Cat *attacker, Animal *victim);


#endif