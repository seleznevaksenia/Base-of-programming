#ifndef CLASSES_H	//пошук ідентифікатора CLASSES_H в списку
#define CLASSES_H	//якщо не визначено CLASSES_H, визначається

#include <iostream>
#include <fstream>

using namespace std;
class Cpoint
{
protected://захищені дані protected — Модификатор доступа, который определяет, что программист собирается применить наследование. В наследуемых классах он собирается унаследовать такие элементы, которые должны срабатывать как элементы private, но в отличии от private они расплодятся по всем наследникам и каждый такой элемент будет соответствовать только своему классу
	int x;//координата x
	int y; //координата y
public: //відкриті методи

	Cpoint(int Value1, int Value2);  // конструктор з параметрами
	Cpoint();  // конструктор без параметрів
	virtual ~Cpoint();
	int PublicMethodX(void);
	int PublicMethodY(void);
	virtual double area() const ;
	void Show();
};

class Cline : public Cpoint
{
protected://захищені дані
	int x2;//координата x
	int y2; //координата y
public: //відкриті методи

		Cline(int Value1, int Value2, int Value3, int Value4);
		Cline();
		~Cline();
		virtual double area() const;
		void Show();

};


class Cube : public Cline
{
protected://захищені дані
public: //відкриті методи

		Cube(int Value1, int Value2, int Value3, int Value4);
		Cube();
		~Cube();
		void Show();//виведення об’єкта
		Cube operator>(Cube &t);
		double area() const;//	Функція обчислення площі поверхні
		friend ostream& operator<<(ostream& outs, const  Cube& xCube);// Дружня функція
};
#endif