# Progama Snaze
-Pedro Victor

-Jonas Mateus

## Como compilar

Execute os comandos:
```
mkdir build
cd build
cmake ..
cmake --build .
```

## Executar programa
Para executar o programa, esteja na pasta principal e use o comando:

```
build/snaze data/"arquivo" "modo" "outras flags"
```
Onde o modo é "com" para jogar com cauda, e "sem" para jogar sem cauda.
E outras flags são :"-loop" para fazerem os níveis looparem, e "-random" para ativar o random start que faz a cobra inície numa posição aleatoria,
adicione elas ou não dependo de como você queira o jogo. 

## Arquivos de teste
### Os arquivos de teste são:

```
maze1:level clássico para ver a cobra andando normalmente
```

```
transicao:testa a passagem para próximos níveis
```

```
morte:testa a morte da cobra
```

```
falharandom:testa erro de arquivo invalido para começo aleatório, não se esqueça de utilizar a flag "-random"
```

```
julio:mapa grande para ver a cobra crescendo
```

```
aberto:mapa aberto para ver a cobra achando solução num mapa aberto
```

# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

ok

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

ok

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

ok

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

ok

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

ok