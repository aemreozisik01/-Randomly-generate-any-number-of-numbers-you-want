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
	cout << "Kaç adet sayı üretmek istersiniz= ";
	cin >> adet;
	cout << "Peki bu sayılar hangi aralıkta üretilsinler 'üst sınır' =  ";
	cin >> adet1;
	cout << "Peki bu sayılar hangi aralıkta üretilsinler 'alt sınır' =  ";
	cin >> adet2;
	ofstream file("Rastgele sayılar.txt");
	if (!file.is_open()) {
		cout << "Dosya Oluşturulamadı" << endl;
	}

	for (int i = 0; i < adet; i++) {
		int rastSayı = rand() % adet1 + adet2;
		file << rastSayı << endl;

	}
	file.close();

	cout << adet << " adet sayı Rastgele sayılar.txt text dosyasına yazıldı" << endl;
	
	cout << "#####################################" << endl;

	ifstream openFile("Rastgele sayılar.txt");
	if (!openFile.is_open()) {
		cout << "Dosya Okunamadı!" << endl;
	}

	vector<int>sayılar;
	int sayı;

	while (openFile >> sayı) {
		sayılar.push_back(sayı);
	}
	sort(sayılar.begin(), sayılar.end());

	openFile.close();

	ofstream sıralıDosya("Sıralı sayılar.txt");
	if (!sıralıDosya.is_open()) {
		cout << "Dosya Açılamadı!" << endl;
	}
	for (int a : sayılar) {
		sıralıDosya << a << endl;
	}
	
	sıralıDosya.close();
	cout << "Sayılar oluşturuldu ve sıralandı.Sıralanan sayılarda 'Sıralı sayılar.txt' text dosyasına yazıldı " << endl;


}