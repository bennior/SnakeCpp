#include "Tail.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

Tail::Tail(sf::RenderWindow& _window, sf::Vector2f pos) : m_window(_window), m_rect(sf::Vector2f(SIZE, SIZE)) {
    m_rect.setFillColor(sf::Color::Cyan);
    m_rect.setPosition(pos);
}

void Tail::update(sf::Vector2f pos) {
    m_rect.setPosition(pos); 
}
    
void Tail::render() {
    m_window.draw(m_rect);
}

sf::Vector2f Tail::get_pos() {
    return m_rect.getPosition();
}