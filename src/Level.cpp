#include "Level.h"

using namespace std;
Level::Level(const mapa& mazein, int food) {
	this->map = mazein;
	for (size_t ii = 0; ii < map.size(); ii++) {
		for (size_t jj = 0; jj < map[ii].size(); jj++) {
			if (map[ii][jj] == '*') {
				map[ii][jj] = ' ';
				initpos.y = ii;
				initpos.x = jj;
			}
		}
	}
	l = map.size();
	c = map[0].size();
	initfood = food;
	foodn = initfood;
	foodpos = { -1,-1 };
	generatefood();
	scorecount = 1;
}

pos Level::getinitpos() {
	return initpos;
}
void Level::draw(Snake& snek, int score, int totallevels, int levelcount){
	drawUI(snek.getlives(), score, totallevels, levelcount);
	mapa drawmap = map;
	for (size_t ii = 0; ii < drawmap.size(); ii++) {
		for (size_t jj = 0; jj < drawmap[ii].size(); jj++) {
			if (drawmap[ii][jj] == '.') {
				drawmap[ii][jj] = ' ';
				
			}
		}
	}
	drawmap[foodpos.y][foodpos.x] = '@';
	for (auto it = snek.getbody().begin(); it != snek.getbody().end(); it++) {
		drawmap[it->y][it->x] = 'o';
	}
	pos cpos = snek.getpos();
	drawmap[cpos.y][cpos.x] = snek.gethead();
	for (auto line : drawmap) {
		cout << line << endl;
	}
}
void Level::solve(Player& AI) {
	AI.find_solution(map, initpos);
}
void Level::generatefood() {
	foodn--;
	pos newfood;
	while (true) {
		newfood.y = rand() % l;
		newfood.x = rand() % c;
		if (newfood.y == initpos.y && newfood.x == initpos.x)
			continue;
		if (map[newfood.y][newfood.x] == ' ')
			break;
	}
	foodpos = newfood;
}
void Level::generatefood(Snake& snek) {
	foodn--;
	mapa testmap=map;
	for (auto it = snek.getbody().begin(); it != snek.getbody().end(); it++) {
		testmap[it->y][it->x] = '#';
	}
	testmap[snek.getpos().y][snek.getpos().x]= '#';
	pos newfood;
	while (true) {
		newfood.y = rand() % l;
		newfood.x = rand() % c;
		if (testmap[newfood.y][newfood.x] == ' ')
			break;
	}
	foodpos = newfood;
}
int Level::update(Snake& snek, int& score) {
	snek.advance();
	pos cpos = snek.getpos();
	if (foodpos.y == cpos.y && foodpos.x == cpos.x) {
		computescore(score);
		scorecount = 1;
		if (foodn == 0) {
			return 2;
		}
		snek.grow();
		generatefood(snek);
	}
	if (map[cpos.y][cpos.x] != ' ' && map[cpos.y][cpos.x] != '@') {
		scorecount = 1;
		return 1;
	}
	if (snek.selfcollide()) {
		scorecount = 1;
		return 1;
	}
	scorecount++;
	return 0;
}
void Level::reset() {
	foodn = initfood;
	generatefood();
}
void Level::computescore(int& cscore) {
	cscore += 5000 / scorecount;
}
void Level::drawUI(int lives, int score, int totallevels, int levelcount) {
	cout << "_________________________________________________________________________________\n" << endl;
	cout << "Level: " <<levelcount+1<< " of " <<totallevels << " | " << " Lives: " << lives << " | " << "Score: " << score << " | " << "Food eaten: " << initfood - foodn-1 << " of " << initfood << endl;
	cout << "_________________________________________________________________________________" << endl;
}