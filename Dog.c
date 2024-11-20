#include "Dog.h"

Dog *initDog(char *name)
{
    char *sound = "Meow!";
    char *species = "Dog";
    unsigned int weight = randNum(1, 10);
    unsigned int height = randNum(10, 30);
    unsigned int speed = randNum(25, 50);
    unsigned int strength = randNum(1, 10);
    unsigned int hp = randNum(5, 100);
    unsigned int tooth_length = randNum(3, 10);

    Dog *dog = malloc(sizeof(Dog));
    if (dog == NULL)
    {
        puts("ALLOCATION FAILED");
        return 0;
    }
    
    dog->tooth_length = tooth_length;

    dog->base = initAnimal(name, weight, height, sound, speed, species, strength, hp);
    if (dog->base == NULL)
    {
        free(dog);
        return 0;
    }

    return dog;
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
    printf("%s claw length: %u mm\n", dog->base->species, dog->tooth_length);
    puts("");
}

unsigned int dogCrazyClawSlash(Dog *attacker, Animal *victim)
{
    unsigned int damage = 0;
    unsigned int max = attacker->base->strength * attacker->tooth_length;
    damage = randNum(attacker->base->strength * 10, max);
    victim->hp -= damage;

    printf("%s slashes like crazy, hitting %s\n\n", attacker->base->name, victim->name);

    if (victim->hp == 0)
    {
        printf("%s fainted...\n\n", victim->name);
        victim->hp = 0;
    }
    

    return damage;
}