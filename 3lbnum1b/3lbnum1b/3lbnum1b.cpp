//1. Реализовать шаблон класса односвязный(однонаправленный) список(LinkedList<X>),
//хранящий элементы произвольного типа.Класс должен содержать :
//- Инициализация списка;
//- Добавление элемента в начало списка;
//- Добавление элемента в конец списка;
//- Показ всех элементов списка.
//b)
//- Поиск данного значения в списке;
//- Поиск наибольшего и наименьшего значений в списке;
//- Удаление элемента списка с данным значением;
//- Удаление всех элементов списка с данным значением;
//- Изменение всех элементов списка с данным значением на новое;
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Complex.h"
#include "Node.h"
using namespace std;




int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Инициализация" << endl;
	cout << "2 - Добавление элемента в начало списка " << endl;
	cout << "3 - Добавление элемента в конец списка" << endl;
	cout << "4 - Показ всех элементов списка" << endl;
	cout << "5 - Поиск данного значения в списке " << endl;
	cout << "6 - Поиск наибольшего значения в списке" << endl;
	cout << "7 - Поиск наименьшего значения в списке" << endl;
	cout << "8 - Удаление элемента списка с данным значением " << endl;
	cout << "9 - Удаление всех элементов списка с данным значением " << endl;
	cout << "10 - Изменение всех элементов списка с данным значением на новое " << endl;
	cout << "0 - Выход" << endl;
	cout << "Введите ваш вариант " << endl;
	int n;
	do {
		cout << ">> ";
		cin >> n;
		if ((n < 0) || (n > 10))
			cout << "Введеное значение неверно. Повторите ввод.\n";
	} while ((n < 0) || (n > 10));
	getchar();
	cout << "\n";
	return n;
}

template < typename T >
void ChangeMenu(LinkedList<T> link)
{
	int n;
	T elem,elem2;
	Node<T>* tmp;
	do
	{
		n = Menu();
		switch (n)
		{
		case 1:
			cout << "введите элемент" << endl;
			cin >> elem;
			link.initalazation(elem);
			break;
		case 2:
			cout << "введите элемент" << endl;
			cin >> elem;
			link.addToStart(elem);
			break;
		case 3:
			cout << "введите элемент" << endl;
			cin >> elem;
			link.addToFinish(elem);
			break;
		case 4:
			cout << "Список :" << endl;
			link.display();
			cout << endl;
			break;
		case 5:
			cout << "Введите элемент, который хотите найти" << endl;
			cin >> elem;
			if (link.searchValue(elem) != NULL)
				cout << "Элемент найден" << endl;
			else
				cout << "Элемент не найден" << endl;
			break;
		case 6:
			cout << "Максимальный элемент в списке:" << endl;
			tmp = link.searchMax();
			if (tmp == NULL)
				cout << "Список пустой" << endl;
			else
				cout << tmp->data << endl;
			break;
		case 7:
			cout << "Минимальный элемент в списке:" << endl;
			tmp = link.searchMin();
			if (tmp == NULL)
				cout << "Список пустой" << endl;
			else
				cout << tmp->data << endl;
			break;
		case 8:
			cout << "Введите элемент, который хотите удалить" << endl;
			cin >> elem;
			if (link.deleteValue(elem))
				cout << "Элемент удален" << endl;
			else
				cout << "Элемент не найден" << endl;
			break;
		case 9:
			cout << "Введите элемент, который хотите удалить(будут удалены все вхождения)" << endl;
			cin >> elem;
			link.deleteValueAll(elem);
			break;
		case 10:
			cout << "Введите элемент, который хотите изменить(будут изменены все элементы)" << endl;
			cin >> elem;
			cout << "Введите элемент, на который хотите изменить(будут изменены все элементы)" << endl;
			cin >> elem2;
			link.сhangeAllElem(elem, elem2);
			break;
		case 0:
			cout << "Работа со списком выбранного типа закончена" << endl;
			/*exit(1);*/
			break;
		default: cout << "Некорретный ввод " << endl;
			break;
		}

	} while (n != 0);

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LinkedList<int> LinkInt;
	LinkedList<string> LinkStr;
	LinkedList<Complex> LinkPr;

	int it = -1;

	while (it != 0)
	{
		it = -1;
		cout << "Выберите тип списка" << endl;
		cout << "1 - Целое число" << endl;
		cout << "2 - Строка" << endl;
		cout << "3 - Структура" << endl;
		cout << "0 - Выход" << endl;

		while ((it < 0) || (it > 4))
			cin >> it;

		switch (it)
		{
			case 1:
				ChangeMenu(LinkInt);
				break;
			case 2:
				ChangeMenu(LinkStr);
				break;
			case 3:
				ChangeMenu(LinkPr);
				break;
			case 0:
				cout << "До свидания " << endl; 
				exit(1); 
				break;
			default: 
				cout << "Некорретный ввод " << endl;
				break;
		}
		system("pause");
	}

}
