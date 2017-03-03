#ifndef CLASSES_H	//����� �������������� CLASSES_H � ������
#define CLASSES_H	//���� �� ��������� CLASSES_H, �����������

#include <iostream>
#include <fstream>

using namespace std;
class Cpoint
{
protected://������� ��� protected � ����������� �������, ������� ����������, ��� ����������� ���������� ��������� ������������. � ����������� ������� �� ���������� ������������ ����� ��������, ������� ������ ����������� ��� �������� private, �� � ������� �� private ��� ����������� �� ���� ����������� � ������ ����� ������� ����� ��������������� ������ ������ ������
	int x;//���������� x
	int y; //���������� y
public: //������ ������

	Cpoint(int Value1, int Value2);  // ����������� � �����������
	Cpoint();  // ����������� ��� ���������
	virtual ~Cpoint();
	int PublicMethodX(void);
	int PublicMethodY(void);
	virtual double area() const ;
	void Show();
};

class Cline : public Cpoint
{
protected://������� ���
	int x2;//���������� x
	int y2; //���������� y
public: //������ ������

		Cline(int Value1, int Value2, int Value3, int Value4);
		Cline();
		~Cline();
		virtual double area() const;
		void Show();

};


class Cube : public Cline
{
protected://������� ���
public: //������ ������

		Cube(int Value1, int Value2, int Value3, int Value4);
		Cube();
		~Cube();
		void Show();//��������� �ᒺ���
		Cube operator>(Cube &t);
		double area() const;//	������� ���������� ����� �������
		friend ostream& operator<<(ostream& outs, const  Cube& xCube);// ������ �������
};
#endif