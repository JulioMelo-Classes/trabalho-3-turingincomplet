#pragma once
#include "Snake.h"

#include <string>

class Player{
	std::string moves; //<! movimentos para a cobra realizar
	Gps gps; //<! Gps do player

public:
	/**
	 * @brief construtor
	*/
	Player();

	/**
	 * @brief acha o proximo movimento a ser feiro pela cobra
	 * @param maze labirinto atual
	 * @param initpos posição inicial do labirinto
	 * @return true
	*/
	bool find_solution(const mapa& maze, pos initpos);

	/**
	 * @brief retorna o proximo movimento a ser realizado pela cobra
	 * @return o proximo movimento a ser realizado pela cobra
	*/
	char Direction_next_move();

	/**
	 * @brief reseta o Player
	*/
	void reset();
};

