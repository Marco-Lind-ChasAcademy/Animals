#include "Animal.h"

// name[20], sound[10], species[20]
Animal *initAnimal(char *name, unsigned int weight, unsigned int height, char *sound, unsigned int speed, char *species, unsigned int strength, int hp)
{
    // Validate string lengths
    if (strlen(name) > 20 || strlen(sound) > 10 || strlen(species) > 20)
    {
        puts("STRINGS TOO LONG");
        return NULL;
    }

    Animal *animal = malloc(sizeof(Animal));
    if (animal == NULL)
    {
        puts("ALLOCATION FAILED");
        return NULL;
    }
    

    // Allocate memory for strings
    if (allocStr(&animal->name, name) == NULL ||
        allocStr(&animal->sound, sound) == NULL ||
        allocStr(&animal->species, species) == NULL)
    {
        deinitAnimal(&animal); // Clean up on failure
        return NULL;
    }

    // Initialize other fields
    animal->weight = weight;
    animal->height = height;
    animal->speed = speed;
    animal->strength = strength;
    animal->hp = hp;

    return animal;
}

void deinitAnimal(Animal **animal)
{
        free((*animal)->name);
        free((*animal)->sound);
        free((*animal)->species);
        free((*animal));
        *animal = NULL;
}

void displayAnimalInfo(Animal *animal)
{
    printf("%s name: %s\n", animal->species, animal->name);
    printf("%s height: %u cm\n", animal->species, animal->height);
    printf("%s weight: %u kg\n", animal->species, animal->weight);
    printf("%s sound: %s\n", animal->species, animal->sound);
    printf("%s speed: %u km/h\n", animal->species, animal->speed);
    printf("%s strength: %u\n", animal->species, animal->strength);
    printf("%s HP: %d\n", animal->species, animal->hp);
}

unsigned int animalJump(Animal *animal)
{
    unsigned int height = randNum(0, animal->speed * 3);
    printf("%s jumps %u cm high!\n\n", animal->name, height);

    return height;
}

unsigned int dashAnimal(Animal *animal)
{
    unsigned int distance = randNum(0, animal->speed);
    printf("%s dashed %u m!\n", animal->name, distance);
    puts("");

    return distance;
}

unsigned int animalBiteAnimal(Animal *attacker, Animal *victim)
{
    unsigned int damage = randNum(0, attacker->strength);
    victim->hp = (victim->hp > damage) ? (victim->hp - damage) : 0;

    printf("%s bit %s! -%u HP\n\n", attacker->name, victim->name, damage);

    if (victim->hp <= 0)
    {
        printf("%s fainted...\n\n", victim->name);
        victim->hp = 0;
    }

    return damage;
}

unsigned int randNum(unsigned int min, unsigned int max)
{
    return (rand() % (max - min + 1)) + min;
}

char **allocStr(char **dest, char *src)
{
    *dest = malloc(strlen(src) + 1);
    if (*dest == NULL)
    {
        puts("ALLOCATION FAILED");
        return 0;
    }

    strcpy(*dest, src);

    return dest;
}
