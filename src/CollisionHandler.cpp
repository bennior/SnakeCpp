#include "CollisionHandler.hpp"
#include "GameStates.hpp"
#include "Apple.hpp"
#include "Snake.hpp"
#include "Constants.hpp"

void collide(Apple& _apple, Snake& _snake) {
    if(_apple.get_pos() == _snake.m_head.get_pos()) {
            _apple.generate_new();
            _snake.add_tail();
    }
}

void collide(Snake& _snake, GameState& _state) {
    for(unsigned int i = 0; i < _snake.m_tails.size(); i++) {
        if(_snake.m_head.get_pos() == _snake.m_tails[i].get_pos()) _state = RESET;
    }

    if(_snake.m_head.get_pos().x == SCREEN_WIDTH || _snake.m_head.get_pos().x < 0 || _snake.m_head.get_pos().y == SCREEN_HEIGHT || _snake.m_head.get_pos().y < 0)
        _state = RESET;
}

