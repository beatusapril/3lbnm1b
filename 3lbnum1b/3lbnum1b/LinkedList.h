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
//- Изменение всех элементов списка с данным значением на новое Воищева З.Ю.;
#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <list>  
#include <sstream>
#include "Node.h"
using namespace std;

template <class T>

class LinkedList
{
private:
	Node <T> *head, *tail;   // указатель на начало списка и на конец

public:
	// конструктор
	LinkedList() /*:head(NULL) ,tail(NULL) {}*/; // инициализация указателей как пустых

	~LinkedList(); //Деструктор освобождения памяти

	// инициализация
	void initalazation(T parametr);

	

	// добавление элемента в начало списка
	void addToStart(const T &t); 

	// добавление элемента в конец списка
	void addToFinish(const T &t); 

	// показ всех элементов списка
	void display();

	//- Поиск данного значения в списке возвращаем указатель на этот список
	Node<T>* searchValue(const T &t);

	//Поиск наибольшего значения в списке;
	Node<T>* searchMax();

	//Поиск наименьшего значения в списке;
	Node<T>* searchMin();

	// Удаление элемента списка с данным значением
	// булевская функция: true - удалось удалить false - нет
	bool deleteValue(const T &t);
	

	//- Удаление всех элементов списка с данным значением;
	void deleteValueAll(const T &t);

	// изменение всех элементов списка с данным значением на новое

	void сhangeAllElem(const T &t, const T &z);


};

//class LinkedList
//{
//private:
//	Node <T> *head, *tail;   // указатель на начало списка и на конец
//
//public:
    template <class T>
	LinkedList<T>::LinkedList() :head(NULL), tail(NULL) {}; // инициализация указателей как пустых

	template <class T>
	LinkedList<T>::~LinkedList() //Деструктор освобождения памяти
	{
		Node<T> *temp = head; //Временный указатель на начало списка
		while (temp != NULL) //Пока в списке что-то есть
		{
			temp = head->next; //Резерв адреса на следующий элемент списка
			delete head;  //Освобождение памяти 
			head = temp;  //Сдвиг на следующий адрес

		}
	}
	// инициализация
	template <class T>
	void LinkedList<T>::initalazation(T parametr)
	{
		head = new Node<T>;          // резервируем память для начала и конца
		tail = new Node<T>;
		head->data = parametr;		// присваиваем голове параметр
		head->next = NULL;
		tail = head;             // хвосту значение головы
	}



	// добавление элемента в начало списка
	template <class T>
	void LinkedList<T>::addToStart(const T &t){
		if (head == NULL){          // если список пустой
			initalazation(t);       // инициализируем его 
		}
		else
		{
			// Создаем новый узел для значения
			Node<T> *elem = new Node<T>;
			// Новый узел привязывается к старому головному элементу
			elem->data = t;
			elem->next = head;

			// Новый узел сам становится головным элементом
			head = elem;
		}
	}

	// добавление элемента в конец списка
	template <class T>
	void LinkedList<T>::addToFinish(const T &t){
		if (head == NULL){			   // если список пустой, инициализируем его
			initalazation(t);
		}
		else
		{
			Node<T> *elem = new Node<T>;     // резервируем память
			elem->data = t;
			elem->next = NULL;
			tail->next = elem;            // новый элемент привязывается за хвостом
			tail = elem;				  // элемент сам становится хвостом

		}
	}

	// показ всех элементов списка
	template <class T>
	void LinkedList<T>::display()
	{
		Node<T>* elem = head;       // присваиваем новому указателю голову списка
		while (elem != NULL){    // пока не конец списка
			cout << elem->data << ' ';  // выводим элемент
			elem = elem->next;            // переходим на следующий
		}
	}

	//- Поиск данного значения в списке возвращаем указатель на этот список
	template <class T>
	Node<T>* LinkedList<T>::searchValue(const T &t)
	{
		Node<T>* elem = head;
		while ((elem != NULL) && (elem->data != t)){   // пока не конец списка и элемент не равен искомому
			elem = elem->next;							// переходим на следующий
		}
		if (elem != NULL){						// если элемент нашелся 
			return elem;						// возвращаем его
		}
		else
			return NULL;					// иначе возвращаем ноль

	}

	//Поиск наибольшего значения в списке;
	template <class T>
	Node<T>* LinkedList<T>::searchMax()
	{
		Node<T>* elem = head;
		/*Node<T>* tMax;*/
		if (elem == NULL){     // если список пустой, возвращаем нулевой указатель
			return elem;
		}
		else{
			Node<T>* tMax = elem;     // запоминаем первый элемент как максимальный
			T max = elem->data;
			while (elem != NULL){        // идем по всему списку
				if (elem->data > max){    // если больше, то меняем  элемент
					max = elem->data;
					tMax = elem;
				}
				elem = elem->next;
			}
			return tMax;
		}

	}

	//Поиск наименьшего значения в списке;
	template <class T>
	Node<T>* LinkedList<T>::searchMin()
	{
		Node<T>* elem = head;    // если список пустой, возвращаем нулевой указатель
		if (elem == NULL){
			return elem;
		}
		else{
			Node<T>* tMin = elem;		// запоминаем первый элемент как максимальный
			T min = elem->data;
			tMin = elem;
			while (elem != NULL){		    // идем по всему списку
				if (elem->data < min){		// если меньше, то меняем  элемент
					min = elem->data;
					tMin = elem;
				}
				elem = elem->next;
			}
			return tMin;
		}

	}

	// Удаление элемента списка с данным значением
	// булевская функция: true - удалось удалить false - нет
	template <class T>
	bool LinkedList<T>::deleteValue(const T &t)
	{
		// если список пуст
		if (head == NULL){
			cout << "Список пустой" << endl;
			return false;
		}
		else
		{
			Node<T>* elem = head;
			// удаление из начала списка
			if (elem->data == t){
				head = elem->next;
				delete elem;
				return true;
			}
			else
			{
				Node<T> *delem = head;  // указатель на предыдущий элемент
				while ((elem != NULL) && (elem->data != t)){    // пока не конец списка и значение не равно искомому
					delem = elem;								// запоминаем предыдущий и переходим на следующий
					elem = elem->next;
				}
				// удаление элемента из середины списка или из конца
				if (elem != NULL){ // если элемент нашелся
					// удаление из конца
					if (elem->next == NULL){
						tail = delem;				// присваиваем хвосту предыдущий элемент
						delem->next = elem->next;
						delete elem;
					}
					else{
						delem->next = elem->next;  // перекидываем указатель
						delete elem;
					}
					return true;
				}
				else
					return false;

			}
		}
	}

	//- Удаление всех элементов списка с данным значением;
	template <class T>
	void LinkedList<T>::deleteValueAll(const T &t)
	{
		while (deleteValue(t))   // пока можно удалить элемент - удаляем
			;
	}

	// изменение всех элементов списка с данным значением на новое
	template <class T>
	void LinkedList<T>::сhangeAllElem(const T &t, const T &z)
	{
		Node<T> *elem = head;
		// идем по всему списку
		while (elem != NULL){
			while ((elem != NULL) && (elem->data != t)){   // пока не конец и не найден искомый
				elem = elem->next;						   // переходим на следующий
			}
			if (elem != NULL){          // если нашелся
				elem->data = z;			// меняем его
			}
		}
	}


