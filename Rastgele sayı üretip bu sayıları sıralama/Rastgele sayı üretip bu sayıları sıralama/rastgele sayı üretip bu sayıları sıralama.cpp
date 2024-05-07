#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(0));
	int adet;
	int adet1;
	int adet2;
	cout << "Ka� adet say� �retmek istersiniz= ";
	cin >> adet;
	cout << "Peki bu say�lar hangi aral�kta �retilsinler '�st s�n�r' =  ";
	cin >> adet1;
	cout << "Peki bu say�lar hangi aral�kta �retilsinler 'alt s�n�r' =  ";
	cin >> adet2;
	ofstream file("Rastgele say�lar.txt");
	if (!file.is_open()) {
		cout << "Dosya Olu�turulamad�" << endl;
	}

	for (int i = 0; i < adet; i++) {
		int rastSay� = rand() % adet1 + adet2;
		file << rastSay� << endl;

	}
	file.close();

	cout << adet << " adet say� Rastgele say�lar.txt text dosyas�na yaz�ld�" << endl;
	
	cout << "#####################################" << endl;

	ifstream openFile("Rastgele say�lar.txt");
	if (!openFile.is_open()) {
		cout << "Dosya Okunamad�!" << endl;
	}

	vector<int>say�lar;
	int say�;

	while (openFile >> say�) {
		say�lar.push_back(say�);
	}
	sort(say�lar.begin(), say�lar.end());

	openFile.close();

	ofstream s�ral�Dosya("S�ral� say�lar.txt");
	if (!s�ral�Dosya.is_open()) {
		cout << "Dosya A��lamad�!" << endl;
	}
	for (int a : say�lar) {
		s�ral�Dosya << a << endl;
	}
	
	s�ral�Dosya.close();
	cout << "Say�lar olu�turuldu ve s�raland�.S�ralanan say�larda 'S�ral� say�lar.txt' text dosyas�na yaz�ld� " << endl;


}