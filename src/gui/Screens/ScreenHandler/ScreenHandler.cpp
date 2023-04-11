#include "ScreenHandler.h"
#include "../HomeScreen/HomeScreen.h"
screen currentScreen = HOME_SCREEN;

void initScreen()
{
    switch (currentScreen)
    {
    case HOME_SCREEN:
        HomeScreen::init();
        break;
    case PLAY_SCREEN:
        HomeScreen::init();
        break;
    case ANALYSIS_SCREEN:
        HomeScreen::init();
        break;
    case STATISTICS_SCREEN:
        HomeScreen::init();
        break;

    default:
        break;
    }
}

void renderScreen()
{

    switch (currentScreen)
    {
    case HOME_SCREEN:
        HomeScreen::render();
        break;
    case PLAY_SCREEN:
        HomeScreen::render();
        break;
    case ANALYSIS_SCREEN:
        HomeScreen::render();
        break;
    case STATISTICS_SCREEN:
        HomeScreen::render();
        break;

    default:
        break;
    }
}

void updateScreen()
{

    switch (currentScreen)
    {
    case HOME_SCREEN:
        HomeScreen::update();
        break;
    case PLAY_SCREEN:
        HomeScreen::update();
        break;
    case ANALYSIS_SCREEN:
        HomeScreen::update();
        break;
    case STATISTICS_SCREEN:
        HomeScreen::update();
        break;

    default:
        break;
    }
}

void handleEventsScreen(SDL_Event *event)
{
    switch (currentScreen)
    {
    case HOME_SCREEN:
        HomeScreen::handleEvents(event);
        break;
    case PLAY_SCREEN:
        HomeScreen::handleEvents(event);
        break;
    case ANALYSIS_SCREEN:
        HomeScreen::handleEvents(event);
        break;
    case STATISTICS_SCREEN:
        HomeScreen::handleEvents(event);
        break;

    default:
        break;
    }
}

void cleanUpScreen()
{

    switch (currentScreen)
    {
    case HOME_SCREEN:
        HomeScreen::cleanUp();
        break;
    case PLAY_SCREEN:
        HomeScreen::cleanUp();
        break;
    case ANALYSIS_SCREEN:
        HomeScreen::cleanUp();
        break;
    case STATISTICS_SCREEN:
        HomeScreen::cleanUp();
        break;

    default:
        break;
    }
}

void switchScreen(screen targetScreen)
{
    cleanUpScreen();

    switch (targetScreen)
    {
    case HOME_SCREEN:
        currentScreen = HOME_SCREEN;
        break;
    case PLAY_SCREEN:
        currentScreen = HOME_SCREEN;
        break;
    case ANALYSIS_SCREEN:
        currentScreen = HOME_SCREEN;
        break;
    case STATISTICS_SCREEN:
        currentScreen = HOME_SCREEN;
        break;
    default:
        break;
    }

    initScreen();
}