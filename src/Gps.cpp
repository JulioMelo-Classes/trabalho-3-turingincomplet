#include "Gps.h"

using namespace std;
Gps::Gps() {
	d = 0;
	cpos = { -1,-1 };
	compass.push_back({ -1,0 });
	compass.push_back({ 0,1 });
	compass.push_back({ 1, 0 });
	compass.push_back({ 0, -1 });
}

pos Gps::getcords(int p) {
	return { cpos.y + compass[(d + p) % 4].y, cpos.x + compass[(d + p) % 4].x };
}
int Gps::getdirec() {
	return d;
}
pos Gps::getpos() {
	return cpos;
}
void Gps::setpos(pos inpos) {
	if (cpos.x == -1) {
		cpos = inpos;
	}
}
void Gps::updatepos( int p) {
	int tdirec = (this->d + p)%4;
	if (tdirec == 0) {
		cpos.y--;
	}
	else if (tdirec == 1) {
		cpos.x++;
	}
	else if (tdirec == 2) {
		cpos.y++;
	}
	else if (tdirec == 3) {
		cpos.x--;
	}
}
void Gps::turn_left() {
	d = (d + 3) % 4;
}
void Gps::turn_right() {
	d = (d + 1) % 4;
}
void Gps::reset() {
	d = 0;
	cpos = { -1,-1 };
}