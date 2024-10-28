#include "Apple.hpp"
#include "Tail.hpp"
#include "Head.hpp"
#include "Constants.hpp"

Apple::Apple(sf::RenderWindow& _window, std::vector<Tail>& _tails, Head& _head) : m_window(_window), m_tails(_tails), m_head(_head), m_rect(sf::Vector2f(30, 30)) {

    m_rect.setFillColor(sf::Color::Yellow);
    generate_new();
}

void Apple::render() {
    m_window.draw(m_rect);
}

void Apple::generate_new() {
    sf::Vector2f new_pos = random_vec(0, SCREEN_WIDTH / SIZE);
    unsigned int i = 0;

    while(i < m_tails.size())
        if(new_pos != m_head.get_pos() && new_pos != m_tails[i].get_pos()) {
            i++;
        }else {
            i = 0;
            new_pos = random_vec(0, SCREEN_WIDTH / SIZE);
    }
    m_rect.setPosition(new_pos);
    }


sf::Vector2f Apple::random_vec(int min, int max) { 
    srand(clock());
    int x = min + rand() % (max - min);
    int y = min + rand() % (max - min);
    return sf::Vector2f(x * SIZE, y * SIZE);
}

sf::Vector2f Apple::get_pos() {
    return m_rect.getPosition();
}



