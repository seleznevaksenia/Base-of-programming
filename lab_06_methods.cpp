#include "Header.h"
#include <fstream>
#include <iostream>
using namespace std;




Cpoint::Cpoint(int Value1, int Value2)	
{
	x = Value1;
	y = Value2;
	cout << "Работа конструктора Cpoint, c параметрами при создании нового объекта: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

}
Cpoint::Cpoint()
{
	x = 0;
	y = 0;
	cout << "Работа конструктора Cpoint,без параметров при создании нового объекта: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

Cpoint::~Cpoint() { cout << "Тут сработал деструктор Cpoint" << endl; } // деструктор

int  Cpoint::PublicMethodX(void)	//загальний (відкритий) метод
{
	cout << "\n Открытый метод Cpoint возвращает private поле x=" << x << endl;
	cout << "\n x=" << x << endl;
	return x;	//повертає приватне поле
}
int Cpoint::PublicMethodY(void)	//загальний (відкритий) метод
{
	cout << "\n Открытый метод Cpoint возвращает private поле y=" << y << endl;
	cout << "\n y=" << y << endl;
	return y;	//повертає приватне поле
}


double Cpoint::area() const
{
	cout << "Тут сработала функция area() для Cpoint" << endl;return 0; }//	Функція обчислення площі (Виртуальная функция — это функция, которая определяется в базовом классе, а любой порожденный класс может ее переопределить. Виртуальная функция вызывается только через указатель или ссылку на базовый класс.)

void Cpoint :: Show()//виведення об’єкта
{
	cout << "\n Тут сработала функция Show() для Cpoint" << endl;
	cout << "x1 =" << x << endl;
	cout << "y1 =" << y << endl;
}



Cline :: Cline(int Value1, int Value2, int Value3, int Value4)
{
	x = Value1;//присвоєння приватному полю значення
	y = Value2;
	x2 = Value3;//присвоєння приватному полю значення
	y2 = Value4;
	cout << "Работа конструктора Cline, c параметрами при создании нового объекта: " << endl;//и здесь же их отобразим на экран
	cout << "x1 = " << x << endl;
	cout << "y1 = " << y << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;

};
Cline::Cline()
{
	x = 0;//присвоим начальные значения переменным
	y = 0;
	x2 = 1;//присвоєння приватному полю значення
	y2 = 1;
	cout << "Работа конструктора Cline,без параметров при создании нового объекта: " << endl;//и здесь же их отобразим на экран
	cout << "x1 = " << x << endl;
	cout << "y1 = " << y << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;

};

Cline :: ~Cline() { cout << "Тут сработал деструктор Cline" << endl; }

//int getx2() { return x2; }
//int gety2() { return y2; }

double Cline ::  area() const { cout << "Тут сработала функция area() для Cline" << endl;return sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)); }//	Функція обчислення площі
																					//виведення об’єкта
void Cline :: Show()//виведення об’єкта
{
	cout << "Работа конструктора ,без параметров при создании нового объекта Cline или Сube: " << endl;
	cout << "x1 =" << x << endl;
	cout << "y1 =" << y << endl;
	cout << "x2 =" << x2 << endl;
	cout << "y2 =" << y2 << endl;

}

Cube :: Cube(int Value1, int Value2, int Value3, int Value4) : Cline(Value1,Value2,Value3,Value4) {}// конструктор класса Cube вызывает конструктор класса Cline
Cube:: Cube() : Cline() {}   // конструктор класса Cube вызывает конструктор класса Cline
Cube ::~Cube() { cout << "Тут сработал деструктор Cube" << endl; }

Cube Cube:: operator>(Cube &t)
	{
	cout << "Тут сработала перезагрузка операции >\n";
	if (area() > t.area())
			return *this;
		else
			return t;
	}
double Cube::area() const { return 6 * Cline::area() * Cline::area(); }//	Функція обчислення площі поверхні
void Cube::Show()//виведення об’єкта
	{
		cout << "\n Тут сработала функция Show() для Cube" << endl;
		cout << "x1 =" << x << endl;
		cout << "y1 =" << y << endl;
		cout << "x2 =" << x2 << endl;
		cout << "y2 =" << y2 << endl;

	}
	ostream& operator<<(ostream& outs,const  Cube& xCube)// Дружня функція
	{
		outs << "Работа функции перегрузка операции вывода << (включения в выходной поток)" << "\n";
		outs <<"x1=" <<xCube.x << "\n";
		outs << "y1=" << xCube.y << "\n";
		outs << "x2=" << xCube.x2 << "\n";
		outs << "y2=" << xCube.y2 << "\n";
		if (xCube.x == xCube.x2 && xCube.y == xCube.y2)outs <<"S = 0\n";
		outs << "S="<< xCube.area();
		return outs;
	}

