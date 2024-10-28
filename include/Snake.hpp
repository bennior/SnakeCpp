#pragma once
#include "Head.hpp"
#include "Tail.hpp"
#include "Apple.hpp"

class Snake {

    private:
     sf::RenderWindow& m_window;

    public:
        Head m_head;
        int score;
        std::vector<Tail> m_tails;
        Snake(sf::RenderWindow& _window);
        void render();
        void update();
        void add_tail();
        void reset();
};