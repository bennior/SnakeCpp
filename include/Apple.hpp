#pragma once
#include "Tail.hpp"
#include "Head.hpp"

class Apple {

    private:
        sf::RenderWindow& m_window;
        std::vector<Tail>& m_tails;
        Head& m_head;
        sf::RectangleShape m_rect;
        sf::Vector2f random_vec(int min, int max);

    public:
        Apple(sf::RenderWindow& _window, std::vector<Tail>& _tails, Head& _head);
        void render();
        void generate_new();
        sf::Vector2f get_pos();
};