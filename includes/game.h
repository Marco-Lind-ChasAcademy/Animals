#ifndef GAME_H
#define GAME_H

#define CONSOLE_WIDTH 90

#include <stdio.h>
#include <string.h>
#include "../includes/Animal.h"
#include <math.h>

void displayMainMenu();
void displayCharacterCreationMenu();
void startFight(Animal *player, Animal *enemy, int window_width);
void printCentered(const char* text, unsigned int window_width);
void printCenteredNoNewline(const char* text, unsigned int window_width);
void printSpaces(unsigned int num);

#endif