#include "HomeScreen.h"

#include <gui/Game.h>

#include <iostream>

#include "../ScreenHandler/ScreenHandler.h"

SDL_Texture *backgroundHomeScreenTex;
SDL_Texture *chessLogoTex;

TTF_Font *HomeScreen::font;

Button startBtn;
Button analysisBtn;
Button statisticsBtn;
Button quitBtn;

void Button::init(int width, int height, int posX, int posY, const char *text) {
    this->width = width;
    this->height = height;
    this->posX = posX;
    this->posY = posY;
    this->text = text;
}

void Button::render() {
    SDL_Rect button;
    button.w = this->width;
    button.h = this->height;
    button.x = this->posX;
    button.y = this->posY;

    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &button);

    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface =
        TTF_RenderText_Solid(HomeScreen::font, this->text, color);
    SDL_Texture *texture =
        SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    SDL_Rect textRect;
    textRect.w = 2 * this->width / 3;
    textRect.h = 2 * this->height / 3;
    textRect.x = button.x + (button.w - textRect.w) / 2;
    textRect.y = button.y + (button.h - textRect.h) / 2;
    SDL_RenderCopy(Game::renderer, texture, NULL, &textRect);
    SDL_DestroyTexture(texture);
}

bool Button::isClicked(int mouseX, int mouseY) {
    return mouseX >= posX && mouseX <= posX + width && mouseY >= posY &&
           mouseY <= posY + height;
}

void HomeScreen::init() {
    backgroundHomeScreenTex =
        TextureManager::LoadTexture("src/gui/assets/backgroundHomeScreen.png");
    chessLogoTex = TextureManager::LoadTexture("src/gui/assets/chessLogo.png");
    font = TTF_OpenFont(GET("src/gui/assets/fonts/OpenSans.ttf"), 100);

    startBtn.init(Game::getPos(1, false) / 5, Game::getPos(1, true) / 15, 100,
                  Game::getPos(1, true) / 5 + Game::getPos(1, true) / 2 - 100,
                  "Start");
    analysisBtn.init(Game::getPos(1, false) / 5, Game::getPos(1, true) / 15,
                     Game::getPos(1, false) - Game::getPos(1, false) / 5 - 100,
                     Game::getPos(1, true) / 5 + Game::getPos(1, true) / 2 -
                         100,
                     "Analysis");
    statisticsBtn.init(
        Game::getPos(1, false) / 5, Game::getPos(1, true) / 15, 100,
        Game::getPos(1, true) / 5 + Game::getPos(1, true) / 2, "Statistics");

    quitBtn.init(Game::getPos(1, false) / 5, Game::getPos(1, true) / 15,
                 Game::getPos(1, false) - Game::getPos(1, false) / 5 - 100,
                 Game::getPos(1, true) / 5 + Game::getPos(1, true) / 2, "Quit");
}

void HomeScreen::update() {}

void HomeScreen::handleEvents(SDL_Event *event) {
    switch (event->type) {
    case SDL_MOUSEBUTTONUP: {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        handleClicks(mouseX, mouseY);
        break;
    }
    }
}

void HomeScreen::render() {
    SDL_Rect backGroundRect;
    backGroundRect.w = Game::getPos(1, false);
    backGroundRect.h = Game::getPos(1, true);
    backGroundRect.x = backGroundRect.y = 0;
    TextureManager::Draw(backgroundHomeScreenTex, SDL_Rect{0, 0, 329, 277},
                         backGroundRect);

    SDL_Rect chessLogoRect;
    chessLogoRect.w = Game::getPos(1, false) / 3;
    chessLogoRect.h = Game::getPos(1, true) / 2;
    chessLogoRect.x = (Game::getPos(1, false) - chessLogoRect.w) / 2;
    chessLogoRect.y = Game::getPos(1, true) / 5;
    TextureManager::Draw(chessLogoTex, SDL_Rect{0, 0, 136, 141}, chessLogoRect);

    startBtn.render();
    analysisBtn.render();
    statisticsBtn.render();
    quitBtn.render();

    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "Cheese Engine", color);
    SDL_Texture *texture =
        SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.w = 500;
    rect.h = 100;
    rect.x = Game::getPos(1, false) / 2 - rect.w / 2;
    rect.y = Game::getPos(0.1, true);
    SDL_RenderCopy(Game::renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

void HomeScreen::cleanUp() { TTF_CloseFont(font); }

void HomeScreen::handleClicks(int mouseX, int mouseY) {
    if (startBtn.isClicked(mouseX, mouseY)) {
        switchScreen(PLAY_SCREEN);
    } else if (analysisBtn.isClicked(mouseX, mouseY)) {
        std::cout << analysisBtn.text << std::endl;
    } else if (statisticsBtn.isClicked(mouseX, mouseY)) {
        std::cout << statisticsBtn.text << std::endl;
    } else if (quitBtn.isClicked(mouseX, mouseY)) {
        std::cout << quitBtn.text << std::endl;
    }
}