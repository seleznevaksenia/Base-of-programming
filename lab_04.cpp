/*Задание 4
Динамические структуры данных : линейные списки, стеки, очереди
Сформировать двусвязный кольцевой линейный список по файлу целых чисел.Решить задачу Джозефуса
: обработать список, удаляя в нем последовательно n - й элемент, пока не останется один элемент
(после удаления отсчет начинается со следующего элемента), n ввести с клавиатуры.Информацию всех
удаляемых узлов выводить на экран.Если удаляется узел – голова списка, сделать головой следующий
за ним узел.*/

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
	f.open(nameFile, ios::binary | ios::out); //Відкриваємо файл в двійковому режимі для запису
	if (!f.is_open()) {
		cout << "Error";
		exit(1);
	}
	do
	{
		cout << "Put number" << endl; //Ввод чисел
		cin >> y;
		f.write((char*)&y, sizeof y); //Записываем в файл число y
		m++;
	} while (m < number);
	f.close(); //Закрываем файл
}


void CreateList(fstream &f, char* nameFile, Node2* root) {

	f.open(nameFile, ios::binary | ios::in); //Відкриваємо файл в двійковому режимі для читання
	if (!f.is_open())
	{
		cerr << "Can't open " << nameFile << "\n";
		exit(2);
	}

	f.seekg(0);
	Node2* first;
	//додавання першого вузла в порожній список
	f.read((char*)&y, sizeof(int));
	root->data = y;//заповнення інформаційного поля даним
	root->next = nullptr;
	root->prev = nullptr;
	first = root;		// ініціалізація first 
	while (f.read((char *)&y, sizeof(int))) {
		Node2* node = new Node2;//виділення області пам’яті для вузла типу Node2
		if (root->next == nullptr) root->next = node;
		node->data = y;//заповнення інформаційного поля даним
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
				cout << "Deleted node=" << a << endl; //вивід видаленого вузла
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
			Node2* root = new Node2;//виділення області пам’яті для вузла типу Node2;
			CreateFile(f, nameFile);
			CreateList(f, nameFile, root);
			cout << "Enter n=\n" << endl; //Ввод чисел
			cin >> n;
			DeleteList(root, n);
			delete root;
			return;
		}