#include <stdio.h>
#include "../includes/Cat.h"
#include "../includes/Dog.h"

int main()
{
    srand(time(NULL));
    
    /* Animal _cat;
    Animal *cat = &_cat;
    initAnimal(cat, "Halvan", 3, 13);
    displayAnimalInfo(cat); */
    
    /* Dog _buster;
    Dog *buster = &_buster;
    buster->base = &buster->_base;
    initDog(buster, "Buster");
    displayDogInfo(buster); */
    
    /* Cat _halvan;
    Cat *halvan = &_halvan;
    halvan->base = &halvan->_base;
    initCat(halvan, "Halvan");
    catDisplayInfo(halvan); */
    
    /* Cat _sid;
    Cat *sid = &_sid;
    sid->base = &sid->_base;
    initCat(sid, "Sid");
    catDisplayInfo(sid);

    animalJump(sid->base); */

    /* Cat *alfons = initCat("Alfons");
    catDisplayInfo(alfons); */

    Cat *kalle;
    catInit(&kalle, "Kalle");
    catDisplayInfo(kalle);

    Cat *oscar;
    catInit(&oscar, "Oscar");
    catDisplayInfo(oscar);

    bite(oscar->base, kalle->base);

    catDisplayInfo(kalle);    
    catDisplayInfo(oscar);

    catSlashAnimal(oscar, kalle->base);

    catDisplayInfo(kalle);

    catDeinit(&oscar);
    catDeinit(&kalle);
    /* deinitCat(&alfons);

    printf("%u", alfons); */

    getchar();
    

    return 0;
}