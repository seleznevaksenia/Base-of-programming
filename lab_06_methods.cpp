#include "Header.h"
#include <fstream>
#include <iostream>
using namespace std;




Cpoint::Cpoint(int Value1, int Value2)	
{
	x = Value1;
	y = Value2;
	cout << "������ ������������ Cpoint, c ����������� ��� �������� ������ �������: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

}
Cpoint::Cpoint()
{
	x = 0;
	y = 0;
	cout << "������ ������������ Cpoint,��� ���������� ��� �������� ������ �������: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

Cpoint::~Cpoint() { cout << "��� �������� ���������� Cpoint" << endl; } // ����������

int  Cpoint::PublicMethodX(void)	//��������� (��������) �����
{
	cout << "\n �������� ����� Cpoint ���������� private ���� x=" << x << endl;
	cout << "\n x=" << x << endl;
	return x;	//������� �������� ����
}
int Cpoint::PublicMethodY(void)	//��������� (��������) �����
{
	cout << "\n �������� ����� Cpoint ���������� private ���� y=" << y << endl;
	cout << "\n y=" << y << endl;
	return y;	//������� �������� ����
}


double Cpoint::area() const
{
	cout << "��� ��������� ������� area() ��� Cpoint" << endl;return 0; }//	������� ���������� ����� (����������� ������� � ��� �������, ������� ������������ � ������� ������, � ����� ����������� ����� ����� �� ��������������. ����������� ������� ���������� ������ ����� ��������� ��� ������ �� ������� �����.)

void Cpoint :: Show()//��������� �ᒺ���
{
	cout << "\n ��� ��������� ������� Show() ��� Cpoint" << endl;
	cout << "x1 =" << x << endl;
	cout << "y1 =" << y << endl;
}



Cline :: Cline(int Value1, int Value2, int Value3, int Value4)
{
	x = Value1;//��������� ���������� ���� ��������
	y = Value2;
	x2 = Value3;//��������� ���������� ���� ��������
	y2 = Value4;
	cout << "������ ������������ Cline, c ����������� ��� �������� ������ �������: " << endl;//� ����� �� �� ��������� �� �����
	cout << "x1 = " << x << endl;
	cout << "y1 = " << y << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;

};
Cline::Cline()
{
	x = 0;//�������� ��������� �������� ����������
	y = 0;
	x2 = 1;//��������� ���������� ���� ��������
	y2 = 1;
	cout << "������ ������������ Cline,��� ���������� ��� �������� ������ �������: " << endl;//� ����� �� �� ��������� �� �����
	cout << "x1 = " << x << endl;
	cout << "y1 = " << y << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl;

};

Cline :: ~Cline() { cout << "��� �������� ���������� Cline" << endl; }

//int getx2() { return x2; }
//int gety2() { return y2; }

double Cline ::  area() const { cout << "��� ��������� ������� area() ��� Cline" << endl;return sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)); }//	������� ���������� �����
																					//��������� �ᒺ���
void Cline :: Show()//��������� �ᒺ���
{
	cout << "������ ������������ ,��� ���������� ��� �������� ������ ������� Cline ��� �ube: " << endl;
	cout << "x1 =" << x << endl;
	cout << "y1 =" << y << endl;
	cout << "x2 =" << x2 << endl;
	cout << "y2 =" << y2 << endl;

}

Cube :: Cube(int Value1, int Value2, int Value3, int Value4) : Cline(Value1,Value2,Value3,Value4) {}// ����������� ������ Cube �������� ����������� ������ Cline
Cube:: Cube() : Cline() {}   // ����������� ������ Cube �������� ����������� ������ Cline
Cube ::~Cube() { cout << "��� �������� ���������� Cube" << endl; }

Cube Cube:: operator>(Cube &t)
	{
	cout << "��� ��������� ������������ �������� >\n";
	if (area() > t.area())
			return *this;
		else
			return t;
	}
double Cube::area() const { return 6 * Cline::area() * Cline::area(); }//	������� ���������� ����� �������
void Cube::Show()//��������� �ᒺ���
	{
		cout << "\n ��� ��������� ������� Show() ��� Cube" << endl;
		cout << "x1 =" << x << endl;
		cout << "y1 =" << y << endl;
		cout << "x2 =" << x2 << endl;
		cout << "y2 =" << y2 << endl;

	}
	ostream& operator<<(ostream& outs,const  Cube& xCube)// ������ �������
	{
		outs << "������ ������� ���������� �������� ������ << (��������� � �������� �����)" << "\n";
		outs <<"x1=" <<xCube.x << "\n";
		outs << "y1=" << xCube.y << "\n";
		outs << "x2=" << xCube.x2 << "\n";
		outs << "y2=" << xCube.y2 << "\n";
		if (xCube.x == xCube.x2 && xCube.y == xCube.y2)outs <<"S = 0\n";
		outs << "S="<< xCube.area();
		return outs;
	}

