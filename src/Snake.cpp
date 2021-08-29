#include "Snake.h"

using namespace std;
Snake::Snake() {
	head = "V<^>";
	lives = 5;
	eaten = false;
}
void Snake::setpos(pos inpos) {
	gps.setpos(inpos);
}
pos Snake::getpos() {
	return gps.getpos();
}
void Snake::advance() {
	if (!eaten) {
		body.push_back(getpos());
		body.pop_front();
	}
	gps.updatepos(0);
	eaten = false;
}
void Snake::process_move(char m) {
	if (m == 'E') {
		gps.turn_left();
	}
	else if (m == 'D') {
		gps.turn_right();
	}
}
char Snake::gethead() {
	return head[gps.getdirec()];
}
const std::deque<pos>& Snake::getbody() {
	return body;
}
bool Snake::selfcollide() {
	if (eaten) {
		return false;
	}
	for (auto it = body.begin(); it != body.end(); it++) {
		if (it->x == getpos().x && it->y == getpos().y)
			return true;
	}
	return false;
}
bool Snake::die() {
	gps.reset();
	body.clear();
	lives--;
	if (lives == 0)
		return true;
	else return false;
}
void Snake::setmode(string inmode) {
	mode = inmode;
}
void Snake::reset() {
	gps.reset();
	lives = 5;
	body.clear();
}
int Snake::getlives() {
	return lives;
}
void Snake::grow() {
	if (mode == "com") {
		body.push_back(getpos());
		eaten = true;
	}
}