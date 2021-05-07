#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // ��������� ��������� ����

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info k, Info end, Info value);
void print(Elem* L);
void process(Elem* L, Info value);
void dequeue(Elem*& first, Elem*& last);

int main()
{
	srand((unsigned)time(NULL)); // ��������� ������� 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);  // ��������� ����������� ��������

	Elem* first = NULL,
		* last = NULL; // ��������� ������ 

	Info value = 1 + rand() % 10; // �������� ������������ ����� �� 1 �� 10
	enqueue(first, last, 1, 10, value); // ��� � ����� �������� 
	cout << "����������� ������: " << endl << endl;
	print(first); // ���� �����
	cout << endl << endl;

	Info info;
	cout << "������ �������� �������������� ����, ��� ���� ������������� � ������: "; cin >> info;
	cout << endl;
	process(first, info); // ����������� �����
	cout << "������� ������: " << endl << endl;
	dequeue(first, last); // ���� �� ��������� �����
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info k, Info end, Info value) // ������� �������� � ������
{
	// ����� �� ��������� � �������
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
	// �������
	if (k < end) { // �������� �� ��� � 10 ����
		k++; // ��������� ��������� �����
		value = 1 + rand() % 10; // �������� ������������ ����� �� 1 �� 10
		enqueue(first, last, k, end, value); // ����������� ������
	}

}

void dequeue(Elem*& first, Elem*& last) // ������� ��������� � ������
{
	// ��� ��� � ��������
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	cout << value << " ";
	// ����������� ������
	if (last != NULL) { // ���� �� ��������� ������
		dequeue(first, last);
	}
}

void print(Elem* L)
{
	// ���������� �������� �������� ������������� ����� �������� ������
	if (L != NULL) {
		cout << L->info << " ";
		L = L->link;
		print(L);
	}
}

void process(Elem* L, Info value)
{
	if (L != NULL)
		if (L->info == value)
		{
			Elem* tmp = new Elem;  // ����������� ���������� �������
			tmp->info = value;  // ���������� ������� ������ ��������, ������� ������������ 
			tmp->link = L->link; // ��������� ����������� �������� ������������ �� �������� �������� 
			L->link = tmp; // ������������ ���������� �������
			process(L->link->link, value); // ����������� ������ � ������� ��� �� 2 ��������, ������� ���� ���������
		}
		else
			process(L->link, value); // ����������� ������ � �������
}