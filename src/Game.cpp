#include "GameFuncs.hpp"
#include "Game.hpp"
#include "Constants.hpp"

Game::Game() : m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake"), m_event(), m_funcs(m_window) {}

void Game::run() {

    clock_t last_time = clock();

    const double time_per_frame = 1.0 / UPS, time_per_update = 1.0 / FPS;
    double dt_update = 0, dt_frame = 0;


    while (m_window.isOpen()) {
        //*******************UPDATE*******************
        while (m_window.pollEvent(m_event)) {
            if(m_event.type == sf::Event::Closed) m_window.close();
        }
        //*******************UPDATE*******************

        dt_update += (double) (clock() - last_time) / CLOCKS_PER_SEC;
        dt_frame += (double) (clock() - last_time) / CLOCKS_PER_SEC;
        last_time = clock();

        //===================UPDATE====================
        if(dt_update >= time_per_update) {
            m_funcs.update();

            dt_update -= time_per_update;
        }
        //===================UPDATE====================

        //===================DRAW====================
        if(dt_frame >= time_per_frame) {
            m_funcs.render();
            m_window.display();
            m_window.clear();

            dt_frame -= time_per_frame;
        }
        //===================DRAW====================

    }
} 