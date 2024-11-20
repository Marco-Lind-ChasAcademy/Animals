#include "Dog.h"

int initDog(Dog **dog, char *name)
{
    *dog = malloc(sizeof(dog));
    if (*dog == NULL)
    {
        puts("dog ALLOCATION FAILED");
        return 0;
    }
    
    char *sound = "Woof!";
    char *species = "Dog";
    unsigned int weight = randNum(1, 10);
    unsigned int height = randNum(10, 30);
    unsigned int speed = randNum(25, 50);
    unsigned int strength = randNum(1, 10);
    unsigned int hp = randNum(5, 100);
    unsigned int claw_length = randNum(3, 10);

    if (!initAnimal(&(*dog)->base, name, weight, height, sound, speed, species, strength, hp))
    {
        free(*dog);
        *dog = NULL;
        return 0;
    }
    
    (*dog)->claw_length = claw_length;

    return 1;
}

void deinitDog(Dog **dog)
{
    deinitAnimal(&(*dog)->base);
    free(*dog);
    *dog = NULL;
}

void displayDogInfo(Dog *dog)
{
    displayAnimalInfo(dog->base);
    printf("%s claw length: %u mm\n", dog->base->species, dog->claw_length);
    puts("");
}

unsigned int DogSlashAnimal(Dog *attacker, Animal *victim)
{
    unsigned int damage = 0;
    unsigned int max = attacker->base->strength * attacker->claw_length * 10;
    damage = randNum(attacker->base->strength, max);
    victim->hp -= damage;

    printf("%s slashed like crazy, hitting %s! -%uHP\n\n", attacker->base->name, victim->name, damage);

    if (victim->hp <= 0)
    {
        printf("%s fainted...\n\n", victim->name);
        victim->hp = 0;
    }
    

    return damage;
}