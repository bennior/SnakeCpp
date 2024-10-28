#pragma once
#include "GameFuncs.hpp"

class Game {
    private:
        sf::RenderWindow m_window;
        sf::Event m_event;
        GameFuncs m_funcs;

    public:
        Game();
        void run();
};