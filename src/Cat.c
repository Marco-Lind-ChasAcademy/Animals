#include "../includes/Cat.h"

int catInit(Cat **cat, char *name)
{
    *cat = malloc(sizeof(Cat));
    if (*cat == NULL)
    {
        puts("CAT ALLOCATION FAILED");
        return 0;
    }
    
    char *sound = "Meow!";
    char *species = "Cat";
    unsigned int weight = randNum(1, 10);
    unsigned int height = randNum(10, 30);
    unsigned int speed = randNum(25, 50);
    unsigned int strength = randNum(1, 10);
    unsigned int hp = randNum(5, 100);
    unsigned int skillPoints = 0;
    unsigned int level = 1;
    unsigned int claw_length = randNum(3, 10);

    if (!animalInit(&(*cat)->base, name, weight, height, sound, speed, species, strength, hp, skillPoints, level))
    {
        free(*cat);
        *cat = NULL;
        return 0;
    }
    
    (*cat)->claw_length = claw_length;

    return 1;
}

void catDeinit(Cat **cat)
{
    animalDeinit(&(*cat)->base);
    free(*cat);
    *cat = NULL;
}

void catDisplayInfo(Cat *cat)
{
    displayInfo(cat->base);
    printf("%s claw length: %u mm\n", cat->base->species, cat->claw_length);
    puts("");
}

unsigned int catSlashAnimal(Cat *attacker, Animal *victim)
{
    unsigned int damage = 0;
    unsigned int max = attacker->base->strength * attacker->claw_length * attacker->base->speed / 10;
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