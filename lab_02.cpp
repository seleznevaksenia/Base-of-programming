/**Задание 2
Разработать алгоритм решения задачи обработки данных, хранящихся в текстовом файле.
Реализовать алгоритм на языке С++ с помощью функций с параметрами.Описать следующие функции :
1) функцию формирования файла(параметрами должны быть файловый поток и его имя);
2) функцию чтения файла(параметрами должны быть файловый поток и его имя);
3) функцию обработки файла(параметрами должны быть файловый поток и его имя).
В главной функции должны быть реализованы объявления файловых потоков и вызов функций работы с файлами.
Условие задачи выбрать из файла Приложение2.doc(Задача 2) по номеру в журнале.
Дан текстовый файл f.Записать в перевернутом виде строки файла f в файл g.Порядок строк в файле g должен
совпадать с порядком исходных строк в файле f.*/


#include <iostream>
#include <fstream>	//подключение библиотеки для работы с файлами	
#include <string.h>		//подключение библиотеки для работы со строками
using namespace std;

void createfile(char fname[20], ofstream &fout)	//функция создания файла
{
	fout.open(fname);
	if (!fout.is_open()) {
		cout << "Error";exit(1);
	}
	//открытие файла fout
	char st[20];	//строка для ввода в файл

	cin.getline(st, 20);	//ввод строки длиной 20 символов
	int i = 0;
	do
	{
		cout << "Input string \n";
		fout << st;	//записать в файл fout строку st
		i++;
		if (i = 20) {
			fout << "\n";
		};	//запись в файл признака конца строки
		cin.getline(st, 20);		//ввод строки длиной 20 символов
	} while (st[0] != '*');	//выход из цикла, когда введена строка, начинающаяся *
	fout.close();		//закрыть файл
}

void readfile(char fname[20], ifstream &fin)	//функция чтения файла
{
	fin.open(fname);	//открытие файла
	cout << "contents of " << fname << ":\n";
	char st[20];	//строка для чтения из файла
	while (fin.getline(st, 20))	//прочитать из файла строку st, пока не конец файла
	{
		cout << st;	//вывод строки 
		int i = 0;
		i++;
		if (i = 20) {
			cout << "\n";
		}	//перевод строки
	};
	fin.close();	//закрыть файл
}

//функция для анализа файла f
void analysisfilef(char fname[20], char gname[20], ifstream &fin, ofstream &gout)
{
	fin.open(fname);	//открыть файл f для чтения
	gout.open(gname); //открыть файл g для записи
	char st[20];
	while (fin.getline(st, 20))	//прочитать из файла строку st, пока не конец файла
	{  //поиск вхождения строки s в строку st, если вхождения нет, функция strstr вернет 0 
	   //функция strstr(st,s) вернет указатель на позицию вхождения строки s в строку st
		int pos = strlen(st) - 1;
		while (pos >= 0)
		{
			gout << st[pos];
			//запись в файл gout строки st
			pos -= 1;	
		}
		//запись в файл gout конца строки
		gout << "\n";
	}
	gout.close();		//закрытие файла gout
	fin.close();		//закрытие файла fin
}

void main()		//главная функция
{
	char filenamef[20], filenameg[20];
	cout << "Enter name for new file f: \n";
	cin >> filenamef;
	ofstream fout;	//создание класса файла для записи
	createfile(filenamef, fout);	//вызов функции создания файла fout
	ifstream fin;		//создание класса файла для чтения
	readfile(filenamef, fin);	//вызов функции чтения файла fin
	cout << "Enter name for new file g:\n ";
	cin >> filenameg;
	ofstream gout;	//создание класса файла для записи
	analysisfilef(filenamef, filenameg, fin, gout);	//анализ файла f
	ifstream gout1;
	readfile(filenameg, gout1);

}

