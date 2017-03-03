/*Задание 1

   Разработать алгоритм решения задачи обработки данных, хранящихся в бинарном 
файле чисел или символов. 
   Реализовать алгоритм на языке С++ с помощью функций с параметрами. Описать следующие функции: 
1) функцию формирования файла (параметрами должны быть файловый поток и его имя); 
2) функцию чтения файла (параметрами должны быть файловый поток и его имя);
3) функцию обработки файла (параметрами должны быть файловый поток и его имя).
   В главной функции должны быть реализованы объявления файловых потоков и вызов функций 
работы с файлами.
   Условие задачи выбрать из файла Приложение2.doc (Задача 1) по номеру в журнале.
Дан файл f, компоненты которого являются действительными числами. Найти наибольшее
из значений компонент файла f.
*/

#include <iostream>
#include <fstream>

using namespace std;
float y;

void CreateFile(fstream &f, char* nameFile) {
	unsigned int n = 0;
	f.open(nameFile, ios::binary | ios::out); //Открываем файл в двоичном режиме для записи
	if (!f.is_open()) {
		cout << "Error";exit;
	}
	do
	{
		cout << "Put number" << endl; //Ввод чисел
		cin >> y;
		f.write((char*)&y, sizeof y); //Записываем в файл число y
		n++;
	}while (n < 5);
	f.close(); //Закрываем файл
}

void ReadFile(ifstream &f1, char* nameFile){
	f1.open(nameFile, ios::binary | ios::in); //Открываем файл в двоичном режиме для записи
if (!f1.is_open())
{
	cerr << "Can't open " << nameFile << "\n";
	exit(1);
}
f1.seekg(0);
cout << "The current content of file " << nameFile << "\n";

while (f1.read((char *)&y, sizeof(float)))
{
	cout << y << "\n";
}

f1.close();
}

void MakeFile(fstream &f, char* nameFile) {

	f.open(nameFile, ios::binary | ios::in); //Открываем файл в двоичном режиме для записи
	if (!f.is_open())
	{
		cerr << "Can't open " << nameFile << "\n";
		exit(1);
	}
	f.seekg(0);
	float x_max = 0.0;
	while (f.read((char*)&y, sizeof(float))) {
		if (x_max < y) {
			x_max = y;
        }
	}
	cout << "max = " << x_max << endl; //Показываем X максимальный
}

void main() {
	char* nameFile = "newFile";
	fstream f;
	ifstream f1;
	CreateFile(f,nameFile);
	ReadFile(f1, nameFile);
	MakeFile(f,nameFile);
	f.close(); //Закрываем файл
}