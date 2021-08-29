#pragma once
#include <utility>
#include <string>
#include <deque>
#include "Gps.h"

using mapa = std::vector<std::string>;
class Snake{
	
	Gps gps; //<! Gps da Snake
	std::string head; //<! sprites da cabeça da cobra
	std::deque<pos> body; //<! posições do corpo da cobra
	int lives; //<! quantidade de vidas da cobra
	std::string mode; //<! modo de jogo
	bool eaten; //<! indica se a cobra comeu ou não
	
public:
	/**
	 * @brief  construtor
	*/
	Snake();

	/**
	 * @brief seta a posição da cabeça da cobra
	 * @param inpos posição a ser setada
	*/
	void setpos(pos inpos);

	/**
	 * @brief retorna a posição da cabeça da cobra
	 * @return 
	*/
	pos getpos();

	/**
	 * @brief avança a cobra para a posição a sua frente
	*/
	void advance();

	/**
	 * @brief processa o proximo movimento a ser feito
	 * @param m movimento a ser feito
	*/
	void process_move(char m);

	/**
	 * @brief retorna o sprite da cabeça da cobra correspondente a sua direção
	 * @return sprite da cabeça da cobra
	*/
	char gethead();

	/**
	 * @brief retona o corpo da cobra
	 * @return corpo da cobra
	*/
	const std::deque<pos>& getbody();

	/**
	 * @brief testa se a cobra colidiu com com si mesma
	 * @return true se a cobra colidiu com com si mesma ou false caso contrário
	*/
	bool selfcollide();

	/**
	 * @brief resata o gps, reseta o corpo, e reduz uma vida
	 * @return true se a cobra perdeu todas as vidas ou false caso contrario
	*/
	bool die();

	/**
	 * @brief seta o modo de jogo
	 * @param inmode modo a ser setado
	*/
	void setmode(std::string inmode);

	/**
	 * @brief reseta a cobra
	*/
	void reset();

	/**
	 * @brief retorna a quantidade de vidas
	 * @return quantidade de vidas
	*/
	int getlives();

	/**
	 * @brief cresce o corpo da cobra
	*/
	void grow();
};


