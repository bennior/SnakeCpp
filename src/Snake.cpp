#include "Snake.hpp"
#include "Head.hpp"
#include "Tail.hpp"
#include "Apple.hpp"
#include "Constants.hpp"

Snake::Snake(sf::RenderWindow& _window) : m_window(_window), m_head(_window), score(0) {
    m_tails.reserve((SCREEN_WIDTH * SCREEN_HEIGHT) / (SIZE * SIZE));
    m_tails.emplace_back(Tail(_window, m_head.get_pos() - sf::Vector2f(0, SIZE)));
    m_tails.emplace_back(Tail(_window, m_head.get_pos() - sf::Vector2f(0, 2 * SIZE)));
    m_tails.emplace_back(Tail(_window, m_head.get_pos() - sf::Vector2f(0, 3 * SIZE)));
}

void Snake::update() {
    for(int i = m_tails.size() - 1; i >= 1; i--) {
        m_tails[i].update(m_tails[i - 1].get_pos());
    }
    m_tails[0].update(m_head.get_pos());
    m_head.update();

}

void Snake::render() {
    m_head.render();
    for(unsigned i = 0; i < m_tails.size(); i++) {
        m_tails[i].render();
    }
}

void Snake::add_tail() {
    m_tails.emplace_back(Tail(m_window, m_tails[0].get_pos()));
    score++;
}

void Snake::reset() {
    //reset head
    m_head.reset();
    //reset tails
    m_tails.clear(); m_tails.reserve((SCREEN_WIDTH * SCREEN_HEIGHT) / (SIZE * SIZE));
    m_tails.emplace_back(Tail(m_window, m_head.get_pos() - sf::Vector2f(0, SIZE)));
    m_tails.emplace_back(Tail(m_window, m_head.get_pos() - sf::Vector2f(0, 2 * SIZE)));
    m_tails.emplace_back(Tail(m_window, m_head.get_pos() - sf::Vector2f(0, 3 * SIZE)));
    score = 0;
}
