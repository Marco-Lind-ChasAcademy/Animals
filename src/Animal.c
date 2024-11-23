#include "../includes/Animal.h"

// name[20], sound[10], species[20]
int animalInit(Animal **animal, char *name, int weight, int height, char *sound, int speed, char *species, int strength, int hp)
{
    size_t len1 = strlen(name);
    size_t len2 = strlen(sound);
    size_t len3 = strlen(species);

    // Validate string lengths
    if (len1 > 20 || 
        len2 > 10 || 
        len3 > 20)
    {
        puts("STRINGS TOO LONG");
        return 0;
    }

    // Allocate memory for animal
    *animal = malloc(sizeof(Animal));
    if (*animal == NULL)
    {
        puts("ANIMAL ALLOCATION FAILED");
        return 0;
    }

    // Allocate memory for strings
    allocStr(&(*animal)->name, len1);
    allocStr(&(*animal)->sound, len2);
    allocStr(&(*animal)->species, len3);

    // Clean up on failure
    if ((*animal)->name == NULL ||
        (*animal)->sound == NULL ||
        (*animal)->species == NULL)
    {
        animalDeinit(&(*animal)); 
        return 0;
    }

    // Initialize fields
    strcpy((*animal)->name, name);
    strcpy((*animal)->sound, sound);
    strcpy((*animal)->species, species);
    (*animal)->weight = weight;
    (*animal)->height = height;
    (*animal)->speed = speed;
    (*animal)->strength = strength;
    (*animal)->hp = hp;

    return 1;
}

void animalDeinit(Animal **animal)
{
        free((*animal)->name);
        free((*animal)->sound);
        free((*animal)->species);
        free((*animal));
        *animal = NULL;
}

void displayInfo(Animal *animal)
{
    printf("%s name: %s\n", animal->species, animal->name);
    printf("%s height: %u cm\n", animal->species, animal->height);
    printf("%s weight: %u kg\n", animal->species, animal->weight);
    printf("%s sound: %s\n", animal->species, animal->sound);
    printf("%s speed: %u km/h\n", animal->species, animal->speed);
    printf("%s strength: %u\n", animal->species, animal->strength);
    printf("%s HP: %d\n", animal->species, animal->hp);
}

int jump(Animal *animal)
{
    int height = randNum(0, animal->speed * 3);
    printf("%s jumps %u cm high!\n\n", animal->name, height);

    return height;
}

int dash(Animal *animal)
{
    int distance = randNum(0, animal->speed);
    printf("%s dashed %u m!\n", animal->name, distance);
    puts("");

    return distance;
}

int bite(Animal *attacker, Animal *victim)
{
    int damage = randNum(0, attacker->strength);
    victim->hp = (victim->hp > damage) ? (victim->hp - damage) : 0;

    printf("%s bit %s! -%u HP\n\n", attacker->name, victim->name, damage);

    if (victim->hp <= 0)
    {
        printf("%s fainted...\n\n", victim->name);
        victim->hp = 0;
    }

    return damage;
}

int randNum(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int allocStr(char **dest, size_t len)
{
    *dest = malloc(len + 1);
    if (*dest == NULL)
    {
        puts("ALLOCATION FAILED");
        return 0;
    }
    return 1;
}