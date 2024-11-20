#ifndef DOG_H
#define DOG_H

#include "Animal.h"

typedef struct
{
    Animal *base;
    unsigned int claw_length;

} Dog;

int initDog(Dog **dog, char *name);
void deinitDog(Dog **dog);
void displayDogInfo(Dog *dog);
unsigned int DogSlashAnimal(Dog *attacker, Animal *victim);


#endif