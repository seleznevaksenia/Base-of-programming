/*������� 4
������������ ��������� ������ : �������� ������, �����, �������
������������ ���������� ��������� �������� ������ �� ����� ����� �����.������ ������ ���������
: ���������� ������, ������ � ��� ��������������� n - � �������, ���� �� ��������� ���� �������
(����� �������� ������ ���������� �� ���������� ��������), n ������ � ����������.���������� ����
��������� ����� �������� �� �����.���� ��������� ���� � ������ ������, ������� ������� ���������
�� ��� ����.*/

#include <iostream>
#include <fstream>

using namespace std;

struct Node2 {
	int data;
	Node2* prev;
	Node2* next;
};

int y;
int n;
const int number = 5;
void CreateFile(fstream &f, char* nameFile) {
	unsigned m = 0;
	f.open(nameFile, ios::binary | ios::out); //³�������� ���� � ��������� ����� ��� ������
	if (!f.is_open()) {
		cout << "Error";
		exit(1);
	}
	do
	{
		cout << "Put number" << endl; //���� �����
		cin >> y;
		f.write((char*)&y, sizeof y); //���������� � ���� ����� y
		m++;
	} while (m < number);
	f.close(); //��������� ����
}


void CreateList(fstream &f, char* nameFile, Node2* root) {

	f.open(nameFile, ios::binary | ios::in); //³�������� ���� � ��������� ����� ��� �������
	if (!f.is_open())
	{
		cerr << "Can't open " << nameFile << "\n";
		exit(2);
	}

	f.seekg(0);
	Node2* first;
	//��������� ������� ����� � ������� ������
	f.read((char*)&y, sizeof(int));
	root->data = y;//���������� �������������� ���� �����
	root->next = nullptr;
	root->prev = nullptr;
	first = root;		// ����������� first 
	while (f.read((char *)&y, sizeof(int))) {
		Node2* node = new Node2;//�������� ������ ����� ��� ����� ���� Node2
		if (root->next == nullptr) root->next = node;
		node->data = y;//���������� �������������� ���� �����
		node->next = nullptr;
		first->next = node;
		node->prev = first;
		first = node;
	}
	f.close();

	root->prev = first;
	first->next = root;
}

void DeleteList(Node2* root,int n) {
			int j = 0;
			int a;
			int i = 0;
			
			while (j < number){
				Node2* q = root;
				while (i < n) {
					q = q->next;
					i++;
			}
			i = 0;
				Node2* p = q->prev;
				a = q->data;
				cout << "Deleted node=" << a << endl; //���� ���������� �����
				p->next = q->next;
				q->next->prev = p;
				j++;
				if (n%number == 0) root = p;
			}
}



void main() {
			char* nameFile = "newFile";
			fstream f;
			ifstream f1;
			Node2* root = new Node2;//�������� ������ ����� ��� ����� ���� Node2;
			CreateFile(f, nameFile);
			CreateList(f, nameFile, root);
			cout << "Enter n=\n" << endl; //���� �����
			cin >> n;
			DeleteList(root, n);
			delete root;
			return;
		}