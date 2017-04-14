#include <iostream>
using namespace std;

void II(int x), YI(int x), Help();

int main() {

	char input = 'a';
	int number;

	while (input != 'q') {
		cout << "h for help" << endl;
		cout << "..." << endl;
		cin >> input;

		if (input == 'i') {
			cout << "Enter index." << endl;
			cin >> number;
			II(number);
		}
		if (input == 'y') {
			cout << "Enter year." << endl;
			cin >> number;
			YI(number);
		}
		if (input == 'h') {

			Help();
		}



	}


}

void II(int x) {

	if (x == 1)
		cout << 1900 << endl;
	if (x == 2)
		cout << 1904 << endl;
	if (x == 3)
		cout << 1907 << endl;
	if (x == 4)
		cout << 1908 << endl;
	if (x == 5)
		cout << 1909 << endl;
	if (x == 6)
		cout << 1910 << endl;
	if (x == 7)
		cout << 1913 << endl;
	if (x == 8)
		cout << 1914 << endl;
	if (x == 9)
		cout << 1915 << endl;
	if (x == 10)
		cout << 1916 << endl;
	if (x == 11)
		cout << 1917 << endl;
	if (x == 12)
		cout << 1918 << endl;
	if (x == 13)
		cout << 1919 << endl;
	if (x == 14)
		cout << 1920 << endl;

}

void YI(int x) {
	if (x == 1900)
		cout << "The Wonderful Wizard of oz" << endl;
	if (x == 1904)
		cout << " The Marvelous Land of oz" << endl;
	if (x == 1907)																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		cout << "ozma of oz" << endl;
	if (x == 1908)
		cout << "Dorothy and the Wizard in oz" << endl;
	if (x == 1909)
		cout << "The Road to oz" << endl;
	if (x == 1910)
		cout << "The Emerald City of oz" << endl;
	if (x == 1913)
		cout << "The Patchwork Girl of oz" << endl;
	if (x == 1914)
		cout << "Tik-Tok of oz" << endl;
	if (x == 1915)
		cout << "The Scarecrow of oz" << endl;
	if (x == 1916)
		cout << "Rinkitink in oz" << endl;
	if (x == 1917)
		cout << "The Lost Princess of oz" << endl;
	if (x == 1918)
		cout << "The Tin Woodman of oz" << endl;
	if (x == 1919)
		cout << "The Magic of oz" << endl;
	if (x == 1920)
		cout << "Glinda of oz" << endl;



}

void Help() {
	cout << "type i,y" << endl;
}