#ifndef DOG_H
#define DOG_H

#define DOG_SPEED 100

#include "Animal.h"

typedef struct
{
    Animal _base;
    Animal *base;
    unsigned int tooth_length;

} Dog;

void initDog(Dog *destination, char *name);
void displayDogInfo(Dog *dog);


#endif