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
    int skill_points;
    int level;

} Animal;

int animalInit(Animal **animal, char *name, unsigned int weight, unsigned int height, char *sound, unsigned int speed, char *species, unsigned int strength, unsigned int hp, unsigned int skillPoints, unsigned int level);
void animalDeinit(Animal **animal);
void displayInfo(Animal *animal);
int jump(Animal *animal);
int dash(Animal *animal);
int bite(Animal *attacker, Animal *victim);
int randNum(unsigned int min, unsigned int max);
int allocStr(char **dest, size_t len);
void levelUp(Animal *animal);
void levelUpMul(Animal *animal, unsigned int levels);


#endif