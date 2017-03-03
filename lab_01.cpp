/*������� 1

   ����������� �������� ������� ������ ��������� ������, ���������� � �������� 
����� ����� ��� ��������. 
   ����������� �������� �� ����� �++ � ������� ������� � �����������. ������� ��������� �������: 
1) ������� ������������ ����� (����������� ������ ���� �������� ����� � ��� ���); 
2) ������� ������ ����� (����������� ������ ���� �������� ����� � ��� ���);
3) ������� ��������� ����� (����������� ������ ���� �������� ����� � ��� ���).
   � ������� ������� ������ ���� ����������� ���������� �������� ������� � ����� ������� 
������ � �������.
   ������� ������ ������� �� ����� ����������2.doc (������ 1) �� ������ � �������.
��� ���� f, ���������� �������� �������� ��������������� �������. ����� ����������
�� �������� ��������� ����� f.
*/

#include <iostream>
#include <fstream>

using namespace std;
float y;

void CreateFile(fstream &f, char* nameFile) {
	unsigned int n = 0;
	f.open(nameFile, ios::binary | ios::out); //��������� ���� � �������� ������ ��� ������
	if (!f.is_open()) {
		cout << "Error";exit;
	}
	do
	{
		cout << "Put number" << endl; //���� �����
		cin >> y;
		f.write((char*)&y, sizeof y); //���������� � ���� ����� y
		n++;
	}while (n < 5);
	f.close(); //��������� ����
}

void ReadFile(ifstream &f1, char* nameFile){
	f1.open(nameFile, ios::binary | ios::in); //��������� ���� � �������� ������ ��� ������
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

	f.open(nameFile, ios::binary | ios::in); //��������� ���� � �������� ������ ��� ������
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
	cout << "max = " << x_max << endl; //���������� X ������������
}

void main() {
	char* nameFile = "newFile";
	fstream f;
	ifstream f1;
	CreateFile(f,nameFile);
	ReadFile(f1, nameFile);
	MakeFile(f,nameFile);
	f.close(); //��������� ����
}