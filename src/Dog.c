#include "../includes/Dog.h"

int dogInit(Dog **dog, char *name)
{
    *dog = malloc(sizeof(Dog));
    if (*dog == NULL)
    {
        puts("DOG ALLOCATION FAILED");
        return 0;
    }
    
    char *sound = "Meow!";
    char *species = "Dog";
    unsigned int weight = randNum(1, 10);
    unsigned int height = randNum(10, 30);
    unsigned int speed = randNum(25, 50);
    unsigned int strength = randNum(1, 10);
    unsigned int hp = randNum(5, 100);
    unsigned int skillPoints = 0;
    unsigned int level = 1;
    unsigned int tooth_length = randNum(3, 10);

    if (!animalInit(&(*dog)->base, name, weight, height, sound, speed, species, strength, hp, skillPoints, level))
    {
        free(*dog);
        *dog = NULL;
        return 0;
    }
    
    (*dog)->tooth_length = tooth_length;

    return 1;
}

void dogDeinit(Dog **dog)
{
    animalDeinit(&(*dog)->base);
    free(*dog);
    *dog = NULL;
}

void dogDisplayInfo(Dog *dog)
{
    displayInfo(dog->base);
    printf("%s claw length: %u mm\n", dog->base->species, dog->tooth_length);
    puts("");
}

unsigned int dogMaulAnimal(Dog *attacker, Animal *victim)
{
    unsigned int damage = 0;
    unsigned int max = attacker->base->strength * attacker->tooth_length * 10;
    damage = randNum(attacker->base->strength, max);
    victim->hp -= damage;

    printf("%s bit and shaked %s like crazy! -%uHP\n\n", attacker->base->name, victim->name, damage);

    if (victim->hp <= 0)
    {
        printf("%s fainted...\n\n", victim->name);
        victim->hp = 0;
    }
    

    return damage;
}