#include <stdio.h>
#include "Cat.h"
#include "Dog.h"

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
    displayCatInfo(halvan); */
    
    /* Cat _sid;
    Cat *sid = &_sid;
    sid->base = &sid->_base;
    initCat(sid, "Sid");
    displayCatInfo(sid);

    animalJump(sid->base); */

    /* Cat *alfons = initCat("Alfons");
    displayCatInfo(alfons); */

    Cat *kalle;
    initCat(&kalle, "Kalle");
    displayCatInfo(kalle);

    Cat *oscar;
    initCat(&oscar, "Oscar");
    displayCatInfo(oscar);

    animalBiteAnimal(oscar->base, kalle->base);

    displayCatInfo(kalle);

    catSlashAnimal(oscar, kalle->base);

    displayCatInfo(kalle);

    deinitCat(&oscar);
    deinitCat(&kalle);
    /* deinitCat(&alfons);

    printf("%u", alfons); */

    getchar();
    

    return 0;
}