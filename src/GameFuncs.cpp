#include "GameFuncs.hpp"
#include "CollisionHandler.hpp"
#include "GameStates.hpp"
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"
#include "Constants.hpp"

sf::RectangleShape screen(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
GameState STATE;
sf::Font font;
sf::Text menu, over, score;

void cycle_trough_font();

GameFuncs::GameFuncs(sf::RenderWindow& _win) : m_win(_win), m_snake(_win), m_apple(_win, m_snake.m_tails, m_snake.m_head) {
    STATE = MENU;
    screen.setFillColor(sf::Color::Magenta);
    font.loadFromFile("src/res/prstartk.ttf");

    //Initialise Menu Font
    menu.setFont(font);
    menu.setString("PRESS ANY KEY TO START!");
    menu.setCharacterSize(24);
    menu.setPosition((SCREEN_WIDTH - menu.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - menu.getGlobalBounds().height) / 2);

    //Initialise Death screen Font
    over.setFont(font);
    over.setString("GAME OVER!");
    over.setCharacterSize(40);
    over.setPosition((SCREEN_WIDTH - over.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - over.getGlobalBounds().height) / 2);

    //Initialise score font
    score.setFont(font);
    score.setCharacterSize(15);
    score.setPosition(5, 5);
}


void GameFuncs::render() {
    switch(STATE) {
        case MENU:
            m_win.draw(screen);
            m_win.draw(menu);
            break;
        case PLAY:
            m_snake.render();
            m_apple.render();
            score.setPosition(5, 5);
            score.setString(std::string("SCORE: ").append(std::to_string(m_snake.score)));
            m_win.draw(score);
            break;
        case RESET: break;
        case OVER:
            m_win.draw(screen);
            m_win.draw(over);
            score.setPosition((SCREEN_WIDTH - score.getGlobalBounds().width) / 2, (SCREEN_HEIGHT + 80) / 2);
            m_win.draw(score);
            break;
    }

    cycle_trough_font();
}

void GameFuncs::update() {
    switch(STATE) {
        case MENU:
            if(check_if_pressed()) STATE = PLAY;
            break;
        case PLAY:
            m_snake.update();
            collide(m_apple, m_snake);
            collide(m_snake, STATE);        
            break;
        case RESET:
            m_snake.reset();
            m_apple.generate_new();
            STATE = OVER;
            break;
        case OVER:
            if(check_if_pressed()) { STATE = PLAY; }
            break;
    }
}

bool GameFuncs::check_if_pressed() {
    bool status;
    for(int i = 0; i < sf::Keyboard::KeyCount; i++)
        status = status != true ? sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)) : status;
    
    return status;
}

void cycle_trough_font() {
    static int i = 0, c = 2;
    i++;
    if(i >= FPS) {
        i = 0;
        c *= -1;
        menu.setCharacterSize(menu.getCharacterSize() + c); over.setCharacterSize(over.getCharacterSize() + c);
        menu.setPosition((SCREEN_WIDTH - menu.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - menu.getGlobalBounds().height) / 2);
        over.setPosition((SCREEN_WIDTH - over.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - over.getGlobalBounds().height) / 2);
    }
}