//1. ����������� ������ ������ �����������(����������������) ������(LinkedList<X>),
//�������� �������� ������������� ����.����� ������ ��������� :
//- ������������� ������;
//- ���������� �������� � ������ ������;
//- ���������� �������� � ����� ������;
//- ����� ���� ��������� ������.
//b)
//- ����� ������� �������� � ������;
//- ����� ����������� � ����������� �������� � ������;
//- �������� �������� ������ � ������ ���������;
//- �������� ���� ��������� ������ � ������ ���������;
//- ��������� ���� ��������� ������ � ������ ��������� �� �����;
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
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������������" << endl;
	cout << "2 - ���������� �������� � ������ ������ " << endl;
	cout << "3 - ���������� �������� � ����� ������" << endl;
	cout << "4 - ����� ���� ��������� ������" << endl;
	cout << "5 - ����� ������� �������� � ������ " << endl;
	cout << "6 - ����� ����������� �������� � ������" << endl;
	cout << "7 - ����� ����������� �������� � ������" << endl;
	cout << "8 - �������� �������� ������ � ������ ��������� " << endl;
	cout << "9 - �������� ���� ��������� ������ � ������ ��������� " << endl;
	cout << "10 - ��������� ���� ��������� ������ � ������ ��������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	cout << "������� ��� ������� " << endl;
	int n;
	do {
		cout << ">> ";
		cin >> n;
		if ((n < 0) || (n > 10))
			cout << "�������� �������� �������. ��������� ����.\n";
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
			cout << "������� �������" << endl;
			cin >> elem;
			link.initalazation(elem);
			break;
		case 2:
			cout << "������� �������" << endl;
			cin >> elem;
			link.addToStart(elem);
			break;
		case 3:
			cout << "������� �������" << endl;
			cin >> elem;
			link.addToFinish(elem);
			break;
		case 4:
			cout << "������ :" << endl;
			link.display();
			cout << endl;
			break;
		case 5:
			cout << "������� �������, ������� ������ �����" << endl;
			cin >> elem;
			if (link.searchValue(elem) != NULL)
				cout << "������� ������" << endl;
			else
				cout << "������� �� ������" << endl;
			break;
		case 6:
			cout << "������������ ������� � ������:" << endl;
			tmp = link.searchMax();
			if (tmp == NULL)
				cout << "������ ������" << endl;
			else
				cout << tmp->data << endl;
			break;
		case 7:
			cout << "����������� ������� � ������:" << endl;
			tmp = link.searchMin();
			if (tmp == NULL)
				cout << "������ ������" << endl;
			else
				cout << tmp->data << endl;
			break;
		case 8:
			cout << "������� �������, ������� ������ �������" << endl;
			cin >> elem;
			if (link.deleteValue(elem))
				cout << "������� ������" << endl;
			else
				cout << "������� �� ������" << endl;
			break;
		case 9:
			cout << "������� �������, ������� ������ �������(����� ������� ��� ���������)" << endl;
			cin >> elem;
			link.deleteValueAll(elem);
			break;
		case 10:
			cout << "������� �������, ������� ������ ��������(����� �������� ��� ��������)" << endl;
			cin >> elem;
			cout << "������� �������, �� ������� ������ ��������(����� �������� ��� ��������)" << endl;
			cin >> elem2;
			link.�hangeAllElem(elem, elem2);
			break;
		case 0:
			cout << "������ �� ������� ���������� ���� ���������" << endl;
			/*exit(1);*/
			break;
		default: cout << "����������� ���� " << endl;
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
		cout << "�������� ��� ������" << endl;
		cout << "1 - ����� �����" << endl;
		cout << "2 - ������" << endl;
		cout << "3 - ���������" << endl;
		cout << "0 - �����" << endl;

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
				cout << "�� �������� " << endl; 
				exit(1); 
				break;
			default: 
				cout << "����������� ���� " << endl;
				break;
		}
		system("pause");
	}

}




	
