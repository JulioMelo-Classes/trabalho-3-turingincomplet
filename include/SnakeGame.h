#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Level.h"

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER, //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
            START_LEVEL,//<! quando o jogo inicia um level estado é START_LEVEL
            COLLIDE, //<!quando a cobra colidir com uma parede mas não morrer o estado será COLLIDE
            END_LEVEL, //!quando um nivel acabar o estado será END_LEVEL
            NEXT_LEVEL, //<!quando a cobra finaliza um level o estado será NEXT_LEVEL
            WIN, //<!quando a cobra vence todos os levels o estado será WIN
            LOSE //<!quando a cobra perde todas as vidas o estado será LOSE
        };

    private:
        //<! atributos adicione outros se quiser
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        std::vector<Level> levels; //<! todos os levels carregados no jogo
        Snake snek; //<! a cobra
        Player AI; //<! a inteligencia artificial que controla a cobra
        int levelstate; //<! 1 se o a cobra colidiu, 2 se a cobra venceu o level ou 0 caso contrário
        int levelcount; //<! contador para o level atual
        int score; //<! pontuação do jogo
        std::string next_level_message; //<! parte da mensagem a ser exibida quando a cobra passa para o próximo level

    public:
        /**
         * @brief contrutor, recebe os comandos dados no terminal
         * @param argv comandos do terminal
        */
        SnakeGame(char* argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
         * @brief realiza a inicialização geral do jogo
         * @param argv comandos do terminal
        */
        void initialize_game(char* argv[]);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h