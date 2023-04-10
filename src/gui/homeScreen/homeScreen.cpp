#include "homeScreen.h"
#include <iostream>
SDL_Texture *backgroundHomeScreenTex;
SDL_Texture *chessLogoTex;

Button startBtn;
Button analysisBtn;
Button statisticsBtn;
Button quitBtn;

void Button::init(int width, int height, int posX, int posY, const char *text)
{
    this->width = width;
    this->height = height;
    this->posX = posX;
    this->posY = posY;
    this->text = text;
}

void Button::render()
{
    SDL_Rect button;
    button.w = this->width;
    button.h = this->height;
    button.x = this->posX;
    button.y = this->posY;

    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &button);

    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(Game::font, this->text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    SDL_Rect textRect;
    textRect.w = 2 * this->width / 3;
    textRect.h = 2 * this->height / 3;
    textRect.x = button.x + (button.w - textRect.w) / 2;
    textRect.y = button.y + (button.h - textRect.h) / 2;
    SDL_RenderCopy(Game::renderer, texture, NULL, &textRect);
    SDL_DestroyTexture(texture);
}

bool Button::isClicked(int mouseX, int mouseY)
{
    return mouseX >= posX && mouseX <= posX + width && mouseY >= posY && mouseY <= posY + height;
}

void HomeScreen::init()
{

    backgroundHomeScreenTex = TextureManager::loadTexture("./src/assets/backgroundHomeScreen.png");
    chessLogoTex = TextureManager::loadTexture("./src/assets/chessLogo.png");

    startBtn.init(
        SCREEN_WIDTH / 5,
        SCREEN_HEIGHT / 15,
        100,
        SCREEN_HEIGHT / 5 + SCREEN_HEIGHT / 2 - 100,
        "Start");
    analysisBtn.init(
        SCREEN_WIDTH / 5,
        SCREEN_HEIGHT / 15,
        SCREEN_WIDTH - SCREEN_WIDTH / 5 - 100,
        SCREEN_HEIGHT / 5 + SCREEN_HEIGHT / 2 - 100,
        "Analysis");
    statisticsBtn.init(
        SCREEN_WIDTH / 5,
        SCREEN_HEIGHT / 15,
        100,
        SCREEN_HEIGHT / 5 + SCREEN_HEIGHT / 2,
        "Statistics");

    quitBtn.init(
        SCREEN_WIDTH / 5,
        SCREEN_HEIGHT / 15,
        SCREEN_WIDTH - SCREEN_WIDTH / 5 - 100,
        SCREEN_HEIGHT / 5 + SCREEN_HEIGHT / 2,
        "Quit");
}

void HomeScreen::handleClicks(int mouseX, int mouseY)
{
    if (startBtn.isClicked(mouseX, mouseY))
    {
        std::cout << startBtn.text << std::endl;
    }
    else if (analysisBtn.isClicked(mouseX, mouseY))
    {
        std::cout << analysisBtn.text << std::endl;
    }
    else if (statisticsBtn.isClicked(mouseX, mouseY))
    {
        std::cout << statisticsBtn.text << std::endl;
    }
    else if (quitBtn.isClicked(mouseX, mouseY))
    {
        std::cout << quitBtn.text << std::endl;
    }
}

void HomeScreen::render()
{

    SDL_Rect backGroundRect;
    backGroundRect.w = SCREEN_WIDTH;
    backGroundRect.h = SCREEN_HEIGHT;
    backGroundRect.x = backGroundRect.y = 0;
    TextureManager::drawTexture(backgroundHomeScreenTex, NULL, &backGroundRect);

    SDL_Rect chessLogoRect;
    chessLogoRect.w = SCREEN_WIDTH / 3;
    chessLogoRect.h = SCREEN_HEIGHT / 2;
    chessLogoRect.x = (SCREEN_WIDTH - chessLogoRect.w) / 2;
    chessLogoRect.y = SCREEN_HEIGHT / 5;
    TextureManager::drawTexture(chessLogoTex, NULL, &chessLogoRect);

    startBtn.render();
    analysisBtn.render();
    statisticsBtn.render();
    quitBtn.render();
    // drawButton(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 15, 100, chessLogoRect.y + chessLogoRect.h - 100, "Start");
    // drawButton(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 15, SCREEN_WIDTH - SCREEN_WIDTH / 5 - 100, chessLogoRect.y + chessLogoRect.h - 100, "Analysis");
    // drawButton(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 15, 100, chessLogoRect.y + chessLogoRect.h, "Statistics");
    // drawButton(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 15, SCREEN_WIDTH - SCREEN_WIDTH / 5 - 100, chessLogoRect.y + chessLogoRect.h, "Quit");

    SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(Game::font,
                                                "Cheese Engine", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    SDL_Rect rect;
    rect.w = 500;
    rect.h = 100;
    rect.x = SCREEN_WIDTH / 2 - rect.w / 2;
    rect.y = 100;
    SDL_RenderCopy(Game::renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}
