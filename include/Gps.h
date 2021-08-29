#pragma once
#include <vector>

struct pos {
	int y, x;
};
class Gps{
	int d; //<! dire��o do Gps
	pos cpos; //<! posi��o do Gps
	std::vector<pos> compass; //<! cordenadas para norte,leste,sul e oeste

public:
	/**
	 * @brief construtor
	*/
	Gps();

	/**
	 * @brief retorna cordenadas para a posi��o desejada
	 * @param p posi��o, como esquerda, direita,frente ou tr�s
	 * @return cordenadas para a posi��o desejada
	*/
	pos getcords(int p);

	/**
	 * @brief retorna a dire��o do Gps
	 * @return a dire��o do Gps
	*/
	int getdirec();

	/**
	 * @brief seta a posi��o do Gps
	 * @param inpos posi��o a ser setada
	*/
	void setpos(pos inpos);

	/**
	 * @brief retorna a posi��o do Gps
	 * @return posi��o do Gps
	*/
	pos getpos();

	/**
	 * @brief atualiza para a posi��o para a posi��o desejada
	 * @param p posi��o, como esquerda, direita,frente ou tr�s
	*/
	void updatepos( int p);

	/**
	 * @brief vira a dire��o do Gps a sua esquerda
	*/
	void turn_left();

	/**
	 * @brief vira a dire��o do Gps a sua direita
	*/
	void turn_right();

	/**
	 * @brief reseta o Gps
	*/
	void reset();
};

