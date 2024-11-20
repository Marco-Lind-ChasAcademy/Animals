#ifndef DOG_H
#define DOG_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int tooth_length;

} Dog;

Dog *initDog(char *name);
void deinitDog(Dog **dog);
void displayDogInfo(Dog *dog);
unsigned int dogCrazyClawSlash(Dog *attacker, Animal *victim);


#endif