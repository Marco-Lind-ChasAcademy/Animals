#ifndef DOG_H
#define DOG_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int tooth_length;

} Dog;

int dogInit(Dog **dog, char *name);
void dogDeinit(Dog **dog);
void dogDisplayInfo(Dog *dog);
unsigned int dogMaulAnimal(Dog *attacker, Animal *victim);


#endif