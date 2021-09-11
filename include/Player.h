#pragma once
#include "Snake.h"

#include <string>

class Player{
	Gps gps; //<! Gps do player
	std::deque<char> moves; //<! movimentos para a cobra realizar
	std::deque<pos> trace; //<! trilha do player 
	std::string mode; //<! modo de jogo
	int solvecount; //<! contador de resolu��o

	/**
	 * @brief checa se o Player est� olhando para sua trilha
	 * @param look posi��o que o Player est� olhando
	 * @return true se o Player est� olhando para sua trilha, false caso contrario
	*/
	bool looking_at_trace(pos look);

public:
	/**
	 * @brief construtor
	*/
	Player();

	/**
	 * @brief acha a solu��o at� a comida
	 * @param maze labirinto atual
	 * @return true se achou a solu��o, false caso n�o achou ainda
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
	 * @brief  seta a posi��o do Player
	 * @param inpos posi��o a ser setada
	*/
	void setpos(pos inpos);

	/**
	 * @brief seta o modo de jogo
	 * @param inmode modo a ser setado
	*/
	void setmode(std::string inmode);
};

