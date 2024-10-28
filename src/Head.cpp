#include "Head.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

enum Direction
{
    Up,
    Down,
    Left,
    Right
};

Direction current_direction = Down;

Head::Head(sf::RenderWindow& _window) : m_window(_window), m_rect(sf::Vector2f(SIZE, SIZE)) {
    m_rect.setFillColor(sf::Color::Cyan);
    m_rect.setPosition(SCREEN_WIDTH / 2, SIZE * 2);
}

void Head::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { current_direction = current_direction != Down ? Up : current_direction; goto set_pos; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { current_direction = current_direction != Up ? Down : current_direction; goto set_pos; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { current_direction = current_direction != Right ? Left : current_direction; goto set_pos; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { current_direction = current_direction != Left ? Right : current_direction; goto set_pos; }

set_pos:
    switch(current_direction) {
        case Up: m_rect.setPosition(m_rect.getPosition() + sf::Vector2f(0, -SIZE)); break;
        case Down: m_rect.setPosition(m_rect.getPosition() + sf::Vector2f(0, SIZE)); break;
        case Left: m_rect.setPosition(m_rect.getPosition() + sf::Vector2f(-SIZE, 0)); break;
        case Right: m_rect.setPosition(m_rect.getPosition() + sf::Vector2f(SIZE, 0)); break;
    }
}

void Head::render() {
    m_window.draw(m_rect);
}

sf::Vector2f Head::get_pos() {
    return m_rect.getPosition();
}

void Head::reset() {
    m_rect.setPosition(SCREEN_WIDTH / 2, SIZE * 2);
    current_direction = Down;
}