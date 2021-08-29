#pragma once
#include <vector>

struct pos {
	int y, x;
};
class Gps{
	int d; //<! direção do Gps
	pos cpos; //<! posição do Gps
	std::vector<pos> compass; //<! cordenadas para norte,leste,sul e oeste

public:
	/**
	 * @brief construtor
	*/
	Gps();

	/**
	 * @brief retorna cordenadas para a posição desejada
	 * @param p posição, como esquerda, direita,frente ou trás
	 * @return cordenadas para a posição desejada
	*/
	pos getcords(int p);

	/**
	 * @brief retorna a direção do Gps
	 * @return a direção do Gps
	*/
	int getdirec();

	/**
	 * @brief seta a posição do Gps
	 * @param inpos posição a ser setada
	*/
	void setpos(pos inpos);

	/**
	 * @brief retorna a posição do Gps
	 * @return posição do Gps
	*/
	pos getpos();

	/**
	 * @brief atualiza para a posição para a posição desejada
	 * @param p posição, como esquerda, direita,frente ou trás
	*/
	void updatepos( int p);

	/**
	 * @brief vira a direção do Gps a sua esquerda
	*/
	void turn_left();

	/**
	 * @brief vira a direção do Gps a sua direita
	*/
	void turn_right();

	/**
	 * @brief reseta o Gps
	*/
	void reset();
};

