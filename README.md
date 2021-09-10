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
build/snaze data/"arquivo" "modo"
```
onde o modo é "com" para jogar com cauda, e "sem" para jogar sem cauda.
e os arquivos são:

```
"bigmap.txt" "colisao.txt" "julio.txt" "maze1.txt" "morte.txt" "smallmap.txt" "testecauda.txt"
```

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Acho que a divisão de código ficou muito boa, com isso você com certeza consegue uma boa folga para tentar resolver os problemas do CP2
- Jonas não me apresentou o trabalho, se ele apresentar o CP2 vou considerar que ele ficou com 50% neste!