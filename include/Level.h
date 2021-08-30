#pragma once
#include <ctime>
#include <iostream>

#include "Player.h"

class Level{

	mapa map; //<! mapa do level
	pos initpos; //<! posição inicial do level
	int l, c; //<! quantidade de linhas e colunas do mapa
	int initfood; //<!quantidade de comida para vencer o level
	int foodn; //<! quantidade de comida restante a ser gerada
	pos foodpos; //<! posição da comida no mapa
	int scorecount; //<! contador para o cálculo do score

public:
	/**
	 * @brief construtor, recebe um labirinto e a quantidade de comida inicial
	 * @param mazein labirinto para gerar os atributos do level
	 * @param food comida inicial
	*/
	Level(const mapa& mazein, int food);

	/**
	 * @brief retorna a posição inicial do level
	 * @return a posição inicial do level
	*/
	pos getinitpos();

	/**
	 * @brief desenha o jogo no terminal
	 * @param snek cobra a ser desenhada
	 * @param score pontuação a ser exibido
	 * @param totallevels quantidade total de levels carregados
	 * @param levelcount contador para saber o level atual
	*/
	void draw( Snake& snek, int score, int totallevels, int levelcount);

	/**
	 * @brief recebe um Player para achar os passos da cobra
	 * @param AI Player a ser recebido
	*/
	void solve(Player& AI);

	/**
	 * @brief gera uma comida sabendo apenas a posição inicial do level
	*/
	void generatefood();

	/**
	 * @brief gera uma comida sabendo a posição da cobra
	 * @param snek cobra a ser recebida
	*/
	void generatefood(Snake& snek);

	/**
	 * @brief atualiza o level a cobra e o score
	 * @param snek cobra a ser recebida
	 * @param score score a ser recebida
	 * @return o estado do level
	*/
	int update(Snake& snek, int& score);

	/**
	 * @brief reseta o level
	*/
	void reset();

	/**
	 * @brief computa o score
	 * @param cscore score atual
	*/
	void computescore(int& cscore);

	/**
	 * @brief desenha a interface de usuário
	 * @param lives quantidade de vidas da cobra
	 * @param score pontuação atual
	 * @param totallevels quantidade total de levels carregados
	 * @param levelcount contador para saber o level atual
	*/
	void drawUI(int lives,int score, int totallevels, int levelcount);
};

