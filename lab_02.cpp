/**������� 2
����������� �������� ������� ������ ��������� ������, ���������� � ��������� �����.
����������� �������� �� ����� �++ � ������� ������� � �����������.������� ��������� ������� :
1) ������� ������������ �����(����������� ������ ���� �������� ����� � ��� ���);
2) ������� ������ �����(����������� ������ ���� �������� ����� � ��� ���);
3) ������� ��������� �����(����������� ������ ���� �������� ����� � ��� ���).
� ������� ������� ������ ���� ����������� ���������� �������� ������� � ����� ������� ������ � �������.
������� ������ ������� �� ����� ����������2.doc(������ 2) �� ������ � �������.
��� ��������� ���� f.�������� � ������������ ���� ������ ����� f � ���� g.������� ����� � ����� g ������
��������� � �������� �������� ����� � ����� f.*/


#include <iostream>
#include <fstream>	//����������� ���������� ��� ������ � �������	
#include <string.h>		//����������� ���������� ��� ������ �� ��������
using namespace std;

void createfile(char fname[20], ofstream &fout)	//������� �������� �����
{
	fout.open(fname);
	if (!fout.is_open()) {
		cout << "Error";exit(1);
	}
	//�������� ����� fout
	char st[20];	//������ ��� ����� � ����

	cin.getline(st, 20);	//���� ������ ������ 20 ��������
	int i = 0;
	do
	{
		cout << "Input string \n";
		fout << st;	//�������� � ���� fout ������ st
		i++;
		if (i = 20) {
			fout << "\n";
		};	//������ � ���� �������� ����� ������
		cin.getline(st, 20);		//���� ������ ������ 20 ��������
	} while (st[0] != '*');	//����� �� �����, ����� ������� ������, ������������ *
	fout.close();		//������� ����
}

void readfile(char fname[20], ifstream &fin)	//������� ������ �����
{
	fin.open(fname);	//�������� �����
	cout << "contents of " << fname << ":\n";
	char st[20];	//������ ��� ������ �� �����
	while (fin.getline(st, 20))	//��������� �� ����� ������ st, ���� �� ����� �����
	{
		cout << st;	//����� ������ 
		int i = 0;
		i++;
		if (i = 20) {
			cout << "\n";
		}	//������� ������
	};
	fin.close();	//������� ����
}

//������� ��� ������� ����� f
void analysisfilef(char fname[20], char gname[20], ifstream &fin, ofstream &gout)
{
	fin.open(fname);	//������� ���� f ��� ������
	gout.open(gname); //������� ���� g ��� ������
	char st[20];
	while (fin.getline(st, 20))	//��������� �� ����� ������ st, ���� �� ����� �����
	{  //����� ��������� ������ s � ������ st, ���� ��������� ���, ������� strstr ������ 0 
	   //������� strstr(st,s) ������ ��������� �� ������� ��������� ������ s � ������ st
		int pos = strlen(st) - 1;
		while (pos >= 0)
		{
			gout << st[pos];
			//������ � ���� gout ������ st
			pos -= 1;	
		}
		//������ � ���� gout ����� ������
		gout << "\n";
	}
	gout.close();		//�������� ����� gout
	fin.close();		//�������� ����� fin
}

void main()		//������� �������
{
	char filenamef[20], filenameg[20];
	cout << "Enter name for new file f: \n";
	cin >> filenamef;
	ofstream fout;	//�������� ������ ����� ��� ������
	createfile(filenamef, fout);	//����� ������� �������� ����� fout
	ifstream fin;		//�������� ������ ����� ��� ������
	readfile(filenamef, fin);	//����� ������� ������ ����� fin
	cout << "Enter name for new file g:\n ";
	cin >> filenameg;
	ofstream gout;	//�������� ������ ����� ��� ������
	analysisfilef(filenamef, filenameg, fin, gout);	//������ ����� f
	ifstream gout1;
	readfile(filenameg, gout1);

}

