/*����������� �������� ������� ������ ��������� ������, ���������� � �������� ����� ��������. �������� ��� ��������� (struct) ��� �������� ������.
   ����������� �������� �� ����� �++ � ������� ������� � �����������. ������� ��������� �������: 
1) ������� ������������ ����� (����������� ������ ���� �������� ����� � ��� ���); � ������ �������� ����� ����������� ��� ���� � � ����
���������� ��������� �������;
2) ������� ������ ����� (����������� ������ ���� �������� ����� � ��� ���); � ������ �������� ����� �� ����� ������ ��������� ������� � 
������������ �� �����;
3) ������� ��������� ����� (����������� ������ ���� �������� ����� � ��� ���).
   � ������� ������� ������ ���� ����������� ���������� �������� ������� � ����� ������� ������ � �������.
   ������� ������ ������� �� ����� BinaryFileStruct.doc �� ������ � �������.
����� ��������� ��������������� ����������� ����� � ����� ����� �����. ��� ���� f, ���������� ���������� � ������ ���������� ����������,
���������� � ������ ������� ���������� ��������� ������������ ����� ��������������� ���� �����.
����������, ������� �� ��� ���������, ������ ������� ��������� �� ����� ����� � ����������� �� ���� �� ����� ��� �� 0,5 ��. ���������
���������� ������� � ���� g.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;
struct MyStruct
{
	unsigned short countOfStuff;
	float weightOfStuff;
};
MyStruct ms;
unsigned int p = 0;

void CreateFile(fstream &f, char nameFile[]) {
	f.open(nameFile, ios::binary | ios::in | ios::out);
	if (!f.is_open())
	{
		cerr << "Can't open " << nameFile << "\n";
		exit(1);
	}
	char y;
	while(true) {
		cout << "Enter a quontity of laggage (enter +):\n";
		cin >> ms.countOfStuff;
		cout << "Enter weight:\n";
		cin >> ms.weightOfStuff;
		f.write((char *)&ms, sizeof ms);
		p++;
		cout << "Next?(y/n)\n";
		cin >> y;
		if (y == 'y')
			break;
	}
		

}


void readfile(fstream &f, char nameFile[]) {	//������� ������ �����
		f.seekg(0);
		cout << "The current content of file " << nameFile << "\n";

		while (f.read((char *)&ms, sizeof ms))

		{
			cout.precision(1);
			cout << ms.countOfStuff << ", " << ms.weightOfStuff << "\n";
			p++;
		}

		/*while (!f.getline(str, sizeof(ms)).eof())
			cout << str << endl;     // ����� ����������� ������ �� �����**/
}
void analysisfilef(fstream &f, char nameFile[], char gname[], fstream &g) {
	f.seekg(0);
	g.open(gname, ios::binary | ios::in | ios::out);
	unsigned int n = 0;
	unsigned int j = 0;
	for (n = 0; n < p-1; n++) {
		streampos plase = j * sizeof(ms);
		f.seekg(plase);

		f.read((char *)&ms, sizeof ms);
		MyStruct mss = ms;
		for (unsigned int i = 2; i < p; i++) {
			f.read((char *)&ms, sizeof ms);
			if (mss.countOfStuff == ms.countOfStuff && abs(mss.weightOfStuff - ms.weightOfStuff) <= 0.5) {//����������, ������� �� ��� ���������, ������ ������� ��������� �� ����� ����� � ����������� �� ���� �� ����� ��� �� 0,5 ��. 
				g.write((char *)&mss, sizeof ms);
				g.write((char *)&ms, sizeof ms);
			}
		}
		j ++;
	}
		
	g.seekg(0);
	cout << "The  content of file " << gname << "\n";

	while (g.read((char *)&ms, sizeof ms))
	{
		cout << ms.countOfStuff << ", " << ms.weightOfStuff << "\n";
	}

	/*while (!f.getline(str, sizeof(ms)).eof())
	cout << str << endl;     // ����� ����������� ������ �� �����**/
	getch();
	f.close();
	g.close();
}


void main() {
	fstream f;
	fstream g;
	char nameFile[100] = "fileName.dat";
	char gname[100] = "fileNameg.dat";
	CreateFile(f, nameFile);
	readfile(f, nameFile);
	analysisfilef(f, nameFile, gname, g);
	return;
}

