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
    int weight;
    int height;
    char *sound;
    int speed;
    char *species;
    int strength;
    int hp;

} Animal;

int initAnimal(Animal **animal, char *name, int weight, int height, char *sound, int speed, char *species, int strength, int hp);
void deinitAnimal(Animal **animal);
void displayAnimalInfo(Animal *animal);
int animalJump(Animal *animal);
int dashAnimal(Animal *animal);
int animalBiteAnimal(Animal *attacker, Animal *victim);
int randNum(int min, int max);
int allocStr(char **dest, size_t len);
void copyString(char *dest, const char *src);


#endif