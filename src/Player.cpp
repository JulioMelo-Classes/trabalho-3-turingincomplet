#include "Player.h"

Player::Player() {
	solvecount = 0;
}

bool Player::find_solution(mapa& maze) {
	solvecount++;
	if (maze[gps.getpos().y][gps.getpos().x] == '@') {
		if (mode == "com") {
			trace.push_back(gps.getpos());
		}
		solvecount = 0;
		return true;
	}
	pos prevpos;
	pos look = gps.getcords(3);
	//esquerda
	if (!looking_at_trace(look)) {
		if (maze[look.y][look.x] == ' ' ||
			maze[look.y][look.x] == '@' ||
			maze[look.y][look.x] == 's') {
			if (maze[gps.getpos().y][gps.getpos().x] == 's')
				maze[gps.getpos().y][gps.getpos().x] = 'd';
			else
				maze[gps.getpos().y][gps.getpos().x] = 's';
			if (solvecount > 1) {
				trace.push_back(gps.getpos());
				prevpos = trace.front();
				trace.pop_front();
			}
			gps.turn_left();
			gps.updatepos(0);
			moves.push_back('E');
			if (find_solution(maze))
				return true;
			moves.pop_back();
			gps.updatepos(2);
			gps.turn_right();
			if (solvecount > 1) {
				trace.push_front(prevpos);
				trace.pop_back();
			}
			if (maze[gps.getpos().y][gps.getpos().x] == 'd')
				maze[gps.getpos().y][gps.getpos().x] = 's';
			else
				maze[gps.getpos().y][gps.getpos().x] = ' ';
		}
	}
	//frente
	look = gps.getcords(0);
	if (!looking_at_trace(look)) {
		if (maze[look.y][look.x] == ' ' ||
			maze[look.y][look.x] == '@' ||
			maze[look.y][look.x] == 's') {
			if (maze[gps.getpos().y][gps.getpos().x] == 's')
				maze[gps.getpos().y][gps.getpos().x] = 'd';
			else
				maze[gps.getpos().y][gps.getpos().x] = 's';
			if (solvecount > 1) {
				trace.push_back(gps.getpos());
				prevpos = trace.front();
				trace.pop_front();
			}
			gps.updatepos(0);
			moves.push_back('M');
			if (find_solution(maze))
				return true;
			moves.pop_back();
			gps.updatepos(2);
			if (solvecount > 1) {
				trace.push_front(prevpos);
				trace.pop_back();
			}
			if (maze[gps.getpos().y][gps.getpos().x] == 'd')
				maze[gps.getpos().y][gps.getpos().x] = 's';
			else
				maze[gps.getpos().y][gps.getpos().x] = ' ';
		}
	}
	//direita
	look = gps.getcords(1);
	if (!looking_at_trace(look)) {
		if (maze[look.y][look.x] == ' ' ||
			maze[look.y][look.x] == '@' ||
			maze[look.y][look.x] == 's') {
			if (maze[gps.getpos().y][gps.getpos().x] == 's')
				maze[gps.getpos().y][gps.getpos().x] = 'd';
			else
				maze[gps.getpos().y][gps.getpos().x] = 's';
			if (solvecount > 1) {
				trace.push_back(gps.getpos());
				prevpos = trace.front();
				trace.pop_front();
			}
			gps.turn_right();
			gps.updatepos(0);
			moves.push_back('D');
			if (find_solution(maze))
				return true;
			moves.pop_back();
			gps.updatepos(2);
			gps.turn_left();
			if (solvecount > 1) {
				trace.push_front(prevpos);
				trace.pop_back();
			}
			if (maze[gps.getpos().y][gps.getpos().x] == 'd')
				maze[gps.getpos().y][gps.getpos().x] = 's';
			else
				maze[gps.getpos().y][gps.getpos().x] = ' ';
		}
	}
	solvecount--;
	return false;
}

char Player::Direction_next_move() {
	if (moves.empty())
		return 'O';
	char temp = moves.front();
	moves.pop_front();
	return temp;
}

void Player::reset() {
	gps.reset();
	trace.clear();
}

void Player::setpos(pos inpos) {
	gps.setpos(inpos);
}

void Player::setmode(std::string inmode) {
	mode = inmode;
}

bool Player::looking_at_trace(pos look) {
	if(trace.empty()){
		return false;
	}
	int l=0;
	if (solvecount > 1) {
		l = 1;
	}
	for (auto it = trace.begin()+l; it != trace.end(); it++) {
		if (it->x == look.x && it->y == look.y)
			return true;
	}
	return false;
}
