#ifndef ANIMAL_H
#define ANIMAL_H

#define NAME_LENGTH 20
#define NAME_LENGTH_STRUCT NAME_LENGTH + 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char *name;
    unsigned int weight;
    unsigned int height;
    char *sound;
    unsigned int speed;
    char *species;
    unsigned int strength;
    int hp;

} Animal;

Animal *initAnimal(char *name, unsigned int weight, unsigned int height, char *sound, unsigned int speed, char *species, unsigned int strength, int hp);
void deinitAnimal(Animal **animal);
void displayAnimalInfo(Animal *animal);
unsigned int animalJump(Animal *animal);
unsigned int dashAnimal(Animal *animal);
unsigned int animalBiteAnimal(Animal *attacker, Animal *victim);
unsigned int randNum(unsigned int min, unsigned int max);
char **allocStr(char **dest, char *src);


#endif