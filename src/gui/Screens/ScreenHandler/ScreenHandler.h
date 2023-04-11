#pragma once
#include <SDL.h>

enum screen {
    HOME_SCREEN,
    PLAY_SCREEN,
    ANALYSIS_SCREEN,
    STATISTICS_SCREEN
};

extern screen currentScreen;

void initScreen();
void renderScreen();
void updateScreen();
void handleEventsScreen(SDL_Event*);
void cleanUpScreen();

void switchScreen(screen);