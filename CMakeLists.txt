cmake_minimum_required(VERSION 3.5)
project(snaze VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "snaze", adiciona neste executável os arquivos src/Gps.cpp src/Level.cpp src/Player.cpp src/Snake.cpp src/SnakeGame.cpp src/Snaze.cpp
add_executable( snaze
                src/Gps.cpp
                src/Level.cpp
		src/Player.cpp
		src/Snake.cpp
		src/SnakeGame.cpp
								src/Snaze.cpp )

# The end