#pragma once
#include "Snake.h"

#include <string>

class Player{
	Gps gps; //<! Gps do player
	std::deque<char> moves; //<! movimentos para a cobra realizar
	std::deque<pos> trace; //<! trilha do player 
	std::string mode; //<! modo de jogo
	int solvecount; //<! contador de resolução

	/**
	 * @brief checa se o Player está olhando para sua trilha
	 * @param look posição que o Player está olhando
	 * @return true se o Player está olhando para sua trilha, false caso contrario
	*/
	bool looking_at_trace(pos look);

public:
	/**
	 * @brief construtor
	*/
	Player();

	/**
	 * @brief acha a solução até a comida
	 * @param maze labirinto atual
	 * @return true se achou a solução, false caso não achou ainda
	*/
	bool find_solution(mapa& maze);
	/**
	 * @brief retorna o proximo movimento a ser realizado pela cobra
	 * @return o proximo movimento a ser realizado pela cobra
	*/
	char Direction_next_move();

	/**
	 * @brief reseta o Player
	*/
	void reset();

	/**
	 * @brief  seta a posição do Player
	 * @param inpos posição a ser setada
	*/
	void setpos(pos inpos);

	/**
	 * @brief seta o modo de jogo
	 * @param inmode modo a ser setado
	*/
	void setmode(std::string inmode);
};

