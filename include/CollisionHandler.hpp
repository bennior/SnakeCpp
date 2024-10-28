#pragma once
#include "Apple.hpp"
#include "Snake.hpp"
#include "GameStates.hpp"

void collide(Apple& _apple, Snake& _snake);
void collide(Snake& _snake, GameState& _state);