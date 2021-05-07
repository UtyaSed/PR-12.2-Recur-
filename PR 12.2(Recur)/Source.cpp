#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

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
	srand((unsigned)time(NULL)); // настройка рандому 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);  // настройка відображення кирилиці

	Elem* first = NULL,
		* last = NULL; // створення списку 

	Info value = 1 + rand() % 10; // рандомно вичисляється число від 1 до 10
	enqueue(first, last, 1, 10, value); // ввід в чергу елементів 
	cout << "Оригінальний список: " << endl << endl;
	print(first); // Вивід черги
	cout << endl << endl;

	Info info;
	cout << "Введіть значення інформаційного поля, яке буде продубльовано в списку: "; cin >> info;
	cout << endl;
	process(first, info); // Опрацювання черги
	cout << "Змінений список: " << endl << endl;
	dequeue(first, last); // Вивід та видалення черги
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info k, Info end, Info value) // функція введення в список
{
	// нічого не помінялось з ітеріції
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
	// рекурсія
	if (k < end) { // перевірка чи вже є 10 цифр
		k++; // збільшення лічильника чисел
		value = 1 + rand() % 10; // рандомно вичисляється число від 1 до 10
		enqueue(first, last, k, end, value); // рекурсивний виклик
	}

}

void dequeue(Elem*& first, Elem*& last) // функція виведення з списку
{
	// без змін з ітерації
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	cout << value << " ";
	// ітераційний виклик
	if (last != NULL) { // поки не закінчився список
		dequeue(first, last);
	}
}

void print(Elem* L)
{
	// рекурсивно виводить значення інформаційних полей елементів списку
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
			Elem* tmp = new Elem;  // створюється тимчасовий елемент
			tmp->info = value;  // тимчасовий елемент отримує значення, введене користувачем 
			tmp->link = L->link; // посилання тимчасового елементу настроюється на посиланя елемента 
			L->link = tmp; // вставляється тимчасовий елемент
			process(L->link->link, value); // рекурсивний виклик і перехід далі на 2 елементи, оскільки один вставлено
		}
		else
			process(L->link, value); // рекурсивний виклик і перехід
}