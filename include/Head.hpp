#pragma once
#include <SFML/Graphics.hpp>

class Head {

    private:
        sf::RenderWindow& m_window;
        sf::RectangleShape m_rect;
    public:
        Head(sf::RenderWindow& _window);
        void update();
        void render();
        sf::Vector2f get_pos();
        void reset();
};