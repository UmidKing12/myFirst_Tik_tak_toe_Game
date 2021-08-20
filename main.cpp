#include <iostream>
#include <random>
#include <ctime>
using namespace std;

char c1, c2, c3, c4, c5, c6, c7, c8, c9, player;
void draw();
void charecters();
void input();
char winner();
int random_player();
void counter(int);
bool full(char);
void select();
void exit_game(char);

int main() {
	charecters();
	int c = random_player();
	int breaker = 0;

	while (true) {
		breaker++;
		draw();
		if (winner() == player) {
			cout << endl << "\t\t" << player << " is winner" << endl << endl;
			break;
		}

		c++;
		counter(c);
		input();

		if (breaker == 9) {
			cout << "\t+++ Ta3adul +++" << endl << endl;
			break;
		}
	}

	select();
	return 0;
}

void draw() {
	cout << "Enter 0 to exit" << endl << endl;
	cout << "\t" << c1 << "\t" << "|" << "\t" << c2 << "\t" << "|" << "\t" << c3 << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t" << c4 << "\t" << "|" << "\t" << c5 << "\t" << "|" << "\t" << c6 << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t" << c7 << "\t" << "|" << "\t" << c8 << "\t" << "|" << "\t" << c9 << endl;
}

void charecters() {
	c1 = '1';
	c2 = '2';
	c3 = '3';
	c4 = '4';
	c5 = '5';
	c6 = '6';
	c7 = '7';
	c8 = '8';
	c9 = '9';
}

void input() {
	char p;
	cout << player << " select number: ";
	cin >> p;
	exit_game(p);

	if (full(p)) {
		switch (p) {
		case '1': c1 = player;
			break;
		case '2': c2 = player;
			break;
		case '3': c3 = player;
			break;
		case '4': c4 = player;
			break;
		case '5': c5 = player;
			break;
		case '6': c6 = player;
			break;
		case '7': c7 = player;
			break;
		case '8': c8 = player;
			break;
		case '9': c9 = player;
			break;
		default:
			cout << "there is error";
			break;
		}
	}

	else {
		system("cls");
		draw();
		cout << p << " Full select another number" << endl;
		input();
	}
	system("cls");
}

char winner() {
	if (c1 == player && c2 == player && c3 == player)
		return player;
	else if (c4 == player && c5 == player && c6 == player)
		return player;
	else if (c7 == player && c8 == player && c9 == player)
		return player;
	else if (c1 == player && c4 == player && c7 == player)
		return player;
	else if (c2 == player && c5 == player && c8 == player)
		return player;
	else if (c3 == player && c6 == player && c9 == player)
		return player;
	else if (c1 == player && c5 == player && c9 == player)
		return player;
	else if (c3 == player && c5 == player && c7 == player)
		return player;
	else
		return '0';
}

int random_player() {
	srand(time(0));
	int a = rand() % 2;
	if (a == 0)
		return 0;
	else
		return 1;
}
void counter(int b) {
	if (b % 2 == 0)
		player = 'X';
	else
		player = 'O';
}

bool full(char k) {
	switch (k) {
	case '1':
		if (c1 == 'O' || c1 == 'X')
			return false;
		break;
	case '2':
		if (c2 == 'O' || c2 == 'X')
			return false;
		break;
	case '3':
		if (c3 == 'O' || c3 == 'X')
			return false;
		break;
	case '4':
		if (c4 == 'O' || c4 == 'X')
			return false;
		break;
	case '5':
		if (c5 == 'O' || c5 == 'X')
			return false;
		break;
	case '6':
		if (c6 == 'O' || c6 == 'X')
			return false;
		break;
	case '7':
		if (c7 == 'O' || c7 == 'X')
			return false;
		break;
	case '8':
		if (c8 == 'O' || c8 == 'X')
			return false;
		break;
	case '9':
		if (c9 == 'O' || c9 == 'X')
			return false;
		break;
	default:
		return true;
		break;
	}
}

void select() {
	int s;
	cout << "Enter 1 for restart" << endl;
	cout << "Enter 2 for exit" << endl;
	cout << ">> ";
	cin >> s;
	if (s == 1) {
		system("cls");
		main();
	}
	else
		exit(0);
}

void exit_game(char e) {
	if (e == '0')
		exit(1);
}