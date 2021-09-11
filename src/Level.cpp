#include "Level.h"

using namespace std;
Level::Level(const mapa& mazein, int food, bool randomflag) {
	this->map = mazein;
	l = map.size();
	c = map[0].size();
	for (int ii = 0; ii < l; ii++) {
		for (int jj = 0; jj < c; jj++) {
			if (map[ii][jj] == '*') {
				map[ii][jj] = ' ';
				initpos.y = ii;
				initpos.x = jj;
			}
		}
	}
	random = randomflag;
	if (random) {
		findpos();
	}
	initfood = food;
	foodn = initfood;
	foodpos = { -1,-1 };
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
	mapa solvemap = map;
	solvemap[foodpos.y][foodpos.x] = '@';
	AI.find_solution(solvemap);
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
			return 3;
		}
		snek.grow();
		generatefood(snek);
		return 2;
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
}
void Level::computescore(int& cscore) {
	cscore += 5000 / scorecount;
}
void Level::drawUI(int lives, int score, int totallevels, int levelcount) {
	cout << "_________________________________________________________________________________\n" << endl;
	cout << "Level: " <<levelcount+1<< " of " <<totallevels << " | " << " Lives: " << lives << " | " << "Score: " << score << " | " << "Food eaten: " << initfood - foodn-1 << " of " << initfood << endl;
	cout << "_________________________________________________________________________________" << endl;
}
void Level::shufflepos() {
	if (random) {
		initpos = valid_pos_vec[rand() % valid_pos_vec.size()];
	}
}
void Level::findpos() {
	for (int ii = 0; ii < l; ii++) {
		for (int jj = 0; jj < c; jj++) {
			if (map[ii][jj] == ' ') {
				if (map[ii - 1][jj] == ' ') {
					valid_pos_vec.push_back({ ii,jj });
				}
			}
		}
	}
	if (valid_pos_vec.empty()) {
		cout << "arquivo invalido para começo aleatório"<<endl;
		exit(1);
	}
}
	