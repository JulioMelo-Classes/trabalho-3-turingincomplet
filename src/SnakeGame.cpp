#include "SnakeGame.h"


#include <iostream>
#include <fstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(char* argv[]){
    choice = "";
    frameCount = 0;
    levelstate = 0;
    score = 0;
    srand((unsigned int)time(0));
    initialize_game(argv);
}

void SnakeGame::initialize_game(char* argv[]){
    //carrega o nivel ou os níveis
    ifstream levelFile(argv[1]);
    snek.setmode(argv[2]);
    levelcount = 0;
    int linecount;
    int levelfood;
    string line;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            stringstream ss;
            ss << line;
            ss>>linecount;
            ss >> levelfood;
            ss >> levelfood;
            for (int ii = 0; ii < linecount; ii++) {
                getline(levelFile, line);
                maze.push_back(line);
            }
            Level templ(maze, levelfood);
            levels.push_back(templ);
            maze.clear();
        }
        
    }
    state = START_LEVEL;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando e processa o movimento
            cin>>std::ws >> choice;
            break;
       case RUNNING: //processa o proximo movimento da cobra
            snek.process_move(AI.Direction_next_move());
            break;
        case COLLIDE: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin >> std::ws >> choice;
            break;
        case NEXT_LEVEL: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin >> std::ws >> choice;
            break;
        case WIN: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin >> std::ws >> choice;
            break;
        case LOSE: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin >> std::ws >> choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case START_LEVEL: //o jogo inicia o level
            snek.setpos(levels[levelcount].getinitpos());
            levels[levelcount].solve(AI);
            state = RUNNING;
            break;
        case RUNNING:
            if (frameCount > 0 && frameCount % 10 == 0) { //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            }
            levelstate=levels[levelcount].update(snek,score);
            levels[levelcount].solve(AI);
            if (levelstate == 1) {
                state = COLLIDE;
                if (snek.die()) {
                    state = LOSE;
                    snek.reset();
                }
                levels[levelcount].reset();
                AI.reset();
            }
            if (levelstate == 2) {
                state = END_LEVEL;
            }
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        case COLLIDE: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if (choice == "n") {
                state = GAME_OVER;
                game_over();
            }
            else {
                state = START_LEVEL;
            }
            break;
        case END_LEVEL: 
            levels[levelcount].reset();
            AI.reset();
            snek.reset();
            state = NEXT_LEVEL;
            if (levelcount == levels.size() - 1) {
                next_level_message = "Passou do último nível!";
                if(levelcount==0)
                    next_level_message = "Passou do primeiro e último nível!";
            }
            else  next_level_message = "Passou de nível!";
            break;
        case NEXT_LEVEL: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if (choice == "c") {
                levelcount++;
                if (levelcount == levels.size()) {
                    state = WIN;
                }
                else state = START_LEVEL;
            }
            else if (choice == "v") {
                levelcount = 0;
                score = 0;
                state = START_LEVEL;
            }
            else {
                score = 0;
                state= START_LEVEL;
            }
            break;
        case WIN: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if (choice == "n") {
                state = GAME_OVER;
                game_over();
            }
            else {
                levelcount = 0;
                score = 0;
                state = START_LEVEL;
            }
            break;
        case LOSE: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if (choice == "n") {
                state = GAME_OVER;
                game_over();
            }
            else {
                levelcount = 0;
                score = 0;
                state = START_LEVEL;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenha todas as linhas do labirinto
            levels[levelcount].draw(snek, score,levels.size(),levelcount);
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
        case COLLIDE:
            cout << "A cobra morreu! Deseja continuar? (s/n)" << endl;
            break;
        case END_LEVEL:
            levels[levelcount].draw(snek, score, levels.size(), levelcount);
            break;
        case NEXT_LEVEL:
            cout << next_level_message<<" Deseja continuar (c), reiniciar o level(r), ou voltar ao começo(v)? " << endl;
            break;
        case WIN:
            cout << "A cobra venceu! Pontuação final: " << score << " Deseja reiniciar? (s/n)" << endl;
            break;
        case LOSE:
            cout << "A cobra perdeu! Pontuação final: "<<score<< " Deseja reiniciar? (s/n)" << endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}
