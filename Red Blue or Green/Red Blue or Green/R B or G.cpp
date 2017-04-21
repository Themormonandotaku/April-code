#include <iostream>
#include <ctime>
using namespace std;
void Wallpaper();
int main() {
	srand(time(NULL));
	while (1) {


		Wallpaper();
		system("Pause");
	}
}
void Wallpaper() {
	int num = rand() % 100 + 1;
	if (num <= 25) {
		system("Color 10");
		cout << "blue" << endl;
	}
	else if ((num >= 25)&&(num<=50)) {
		system("Color 20");
		cout << "green" << endl;
	}
	else if (num >= 50) {
		system("Color 40");
		cout << "red" << endl;
	}
}