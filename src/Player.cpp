#include "Player.h"
Player::Player() {
}
bool Player::find_solution(const mapa& maze, pos initpos) {
	gps.setpos(initpos);
	pos cpos = gps.getpos();
	pos cord;
		cpos = gps.getpos();
		cord = gps.getcords(0);
		//mantem
		if (maze[cpos.y + cord.y][cpos.x + cord.x] == ' ' ||
			maze[cpos.y + cord.y][cpos.x + cord.x] == '@') {
			moves = "M";
			gps.updatepos( 0);
			return true;
		}
		cord = gps.getcords(3);
		//vira a esquerda
		if (maze[cpos.y + cord.y][cpos.x + cord.x] == ' ' || 
			maze[cpos.y + cord.y][cpos.x + cord.x] == '@') {
			moves = "E";
			gps.turn_left();
			gps.updatepos(0);
			return true;
		}
		cord = gps.getcords(1);
		//vira a direita
		if (maze[cpos.y + cord.y][cpos.x + cord.x] == ' '|| 
			maze[cpos.y + cord.y][cpos.x + cord.x] == '@') {
			moves = "D";
			gps.turn_right();
			gps.updatepos(0);
			return true;
		}
		else {
			moves = "O";
		}
	return true;
}
char Player::Direction_next_move() {
	return moves[0];
}
void Player::reset() {
	gps.reset();
}
