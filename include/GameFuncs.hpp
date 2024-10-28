#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"

class GameFuncs {
    private:
        sf::RenderWindow& m_win;
        Snake m_snake;
        Apple m_apple;
    public:
        GameFuncs(sf::RenderWindow& _win);
        void update();
        void render();
        bool check_if_pressed();
};