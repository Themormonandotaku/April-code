#include <iostream>
using namespace std;
int beans, carrots, lettuce, peas, squash;
void BG(), CG(), LG(), PG(), SG(),AG();
int main() {
	cout << "Pounds of beans" << endl;
	cin >> beans;
	cout << "Pounds of carrots" << endl;
	cin >> carrots;
	cout << "Pounds of lettuce" << endl;
	cin >> lettuce;
	cout << "Pounds of peas" << endl;
	cin >> peas;
	cout << "Pounds of squash" << endl;
	cin >> squash;
	AG();
}
void AG() {
	//cout << "running function AG" << endl;
	BG();
	CG();
	LG();
	PG();
	SG();
}
void BG() {
	for (int i = 0; i < beans; i++)
		cout << "B";
cout <<endl;
				}
	
void CG() {
	for (int i = 0; i < carrots; i++)
		cout << "C";
	cout << endl;
}
		
void LG() {
	for (int i = 0; i < lettuce; i++)
		cout << "L";
	cout << endl;
}
void PG() {
	for (int i = 0; i < peas; i++)
		cout << "P";
	cout << endl;
}
void SG() {
	for (int i = 0; i < squash; i++)
		cout << "S";
	cout << endl;
}