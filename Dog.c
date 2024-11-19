#include "Dog.h"

void initDog(Dog *destination, char *name)
{
    
    char *sound = "Woof!";
    char *species = "Dog";
    unsigned int weight = randNum(2, 90);
    unsigned int height = randNum(15, 90);
    unsigned int speed = randNum(8, 72);
    unsigned int strength = randNum(5, 100);
    unsigned int tooth_length = randNum(5, 40);
    unsigned int hp = randNum(50, 500);

    initAnimal(name, weight, height, sound, speed, species, strength, hp);
    destination->tooth_length = tooth_length;
}

void displayDogInfo(Dog *dog)
{
    displayAnimalInfo(dog->base);
    printf("%s tooth length: %u mm\n", dog->base->species, dog->tooth_length);
    puts("");
}