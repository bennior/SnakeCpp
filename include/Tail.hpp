#pragma once
#include <SFML/Graphics.hpp>

class Tail {


    private:
        sf::RenderWindow& m_window;
        sf::RectangleShape m_rect;
    
    public:
        Tail(sf::RenderWindow& _window, sf::Vector2f pos);
        void render();
        void update(sf::Vector2f pos);
        sf::Vector2f get_pos();
};