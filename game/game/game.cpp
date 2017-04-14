#include <iostream>
#include <ctime>
using namespace std;
void rw(), ui();
bool gg = 0;
int rn, lives = 7;
char guess;
char word[5], gword[5] = { ' ',' ',' ',' ',' ' };
int main() {
	srand(time(NULL));
	while (lives > 0) {
		rw();
		ui();
	}

}

void rw() {
	rn = rand() % 5 + 1;

	if (rn == 1)
		word[0] = 'a', word[1] = 'r', word[2] = 'a', word[3] = 'm', word[4] = 'a';
	else if (rn == 2)
		word[0] = 's', word[1] = 'h', word[2] = 'e', word[3] = 'l', word[4] = 'l';
	else if (rn == 3)
		word[0] = 'r', word[1] = 'e', word[2] = 'a', word[3] = 'd', word[4] = 'y';
	else if (rn == 4)
		word[0] = 'g', word[1] = 'h', word[2] = 'o', word[3] = 's', word[4] = 't';
	else if (rn == 5)
		word[0] = 's', word[1] = 'n', word[2] = 'a', word[3] = 'k', word[4] = 'e';




}

void ui() {
	while (lives > 0) {
		gg = 0;
		cout << "Whats your guess" << endl;
		cin >> guess;

		if (guess == word[0])
			gword[0] = word[0], gg = 1;

		if (guess == word[1])
			gword[1] = word[1], gg = 1;

		if (guess == word[2])
			gword[2] = word[2], gg = 1;

		if (guess == word[3])
			gword[3] = word[3], gg = 1;

		if (guess == word[4])
			gword[4] = word[4], gg = 1;

		else if (gg == 0) {
			cout << "Wrong guess" << endl;
			lives--;
		}
		cout << gword << "     " << lives << endl;
		if (word[0] == gword[0] && word[1] == gword[1] && word[2] == gword[2] && word[3] == gword[3] && word[4] == gword[4]) {
			cout << "You win" << endl;
			//rewrite gword with spaces!
			for (int i = 0; i < 5; i++)
				gword[i] = ' ';
			break;
		}
	}//end of whle

}