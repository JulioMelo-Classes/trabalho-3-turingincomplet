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