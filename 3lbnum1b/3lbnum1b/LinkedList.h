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
//- ��������� ���� ��������� ������ � ������ ��������� �� ����� ������� �.�.;
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
	Node <T> *head, *tail;   // ��������� �� ������ ������ � �� �����

public:
	// �����������
	LinkedList() /*:head(NULL) ,tail(NULL) {}*/; // ������������� ���������� ��� ������

	~LinkedList(); //���������� ������������ ������

	// �������������
	void initalazation(T parametr);

	

	// ���������� �������� � ������ ������
	void addToStart(const T &t); 

	// ���������� �������� � ����� ������
	void addToFinish(const T &t); 

	// ����� ���� ��������� ������
	void display();

	//- ����� ������� �������� � ������ ���������� ��������� �� ���� ������
	Node<T>* searchValue(const T &t);

	//����� ����������� �������� � ������;
	Node<T>* searchMax();

	//����� ����������� �������� � ������;
	Node<T>* searchMin();

	// �������� �������� ������ � ������ ���������
	// ��������� �������: true - ������� ������� false - ���
	bool deleteValue(const T &t);
	

	//- �������� ���� ��������� ������ � ������ ���������;
	void deleteValueAll(const T &t);

	// ��������� ���� ��������� ������ � ������ ��������� �� �����

	void �hangeAllElem(const T &t, const T &z);


};

//class LinkedList
//{
//private:
//	Node <T> *head, *tail;   // ��������� �� ������ ������ � �� �����
//
//public:
    template <class T>
	LinkedList<T>::LinkedList() :head(NULL), tail(NULL) {}; // ������������� ���������� ��� ������

	template <class T>
	LinkedList<T>::~LinkedList() //���������� ������������ ������
	{
		Node<T> *temp = head; //��������� ��������� �� ������ ������
		while (temp != NULL) //���� � ������ ���-�� ����
		{
			temp = head->next; //������ ������ �� ��������� ������� ������
			delete head;  //������������ ������ 
			head = temp;  //����� �� ��������� �����

		}
	}
	// �������������
	template <class T>
	void LinkedList<T>::initalazation(T parametr)
	{
		head = new Node<T>;          // ����������� ������ ��� ������ � �����
		tail = new Node<T>;
		head->data = parametr;		// ����������� ������ ��������
		head->next = NULL;
		tail = head;             // ������ �������� ������
	}



	// ���������� �������� � ������ ������
	template <class T>
	void LinkedList<T>::addToStart(const T &t){
		if (head == NULL){          // ���� ������ ������
			initalazation(t);       // �������������� ��� 
		}
		else
		{
			// ������� ����� ���� ��� ��������
			Node<T> *elem = new Node<T>;
			// ����� ���� ������������� � ������� ��������� ��������
			elem->data = t;
			elem->next = head;

			// ����� ���� ��� ���������� �������� ���������
			head = elem;
		}
	}

	// ���������� �������� � ����� ������
	template <class T>
	void LinkedList<T>::addToFinish(const T &t){
		if (head == NULL){			   // ���� ������ ������, �������������� ���
			initalazation(t);
		}
		else
		{
			Node<T> *elem = new Node<T>;     // ����������� ������
			elem->data = t;
			elem->next = NULL;
			tail->next = elem;            // ����� ������� ������������� �� �������
			tail = elem;				  // ������� ��� ���������� �������

		}
	}

	// ����� ���� ��������� ������
	template <class T>
	void LinkedList<T>::display()
	{
		Node<T>* elem = head;       // ����������� ������ ��������� ������ ������
		while (elem != NULL){    // ���� �� ����� ������
			cout << elem->data << ' ';  // ������� �������
			elem = elem->next;            // ��������� �� ���������
		}
	}

	//- ����� ������� �������� � ������ ���������� ��������� �� ���� ������
	template <class T>
	Node<T>* LinkedList<T>::searchValue(const T &t)
	{
		Node<T>* elem = head;
		while ((elem != NULL) && (elem->data != t)){   // ���� �� ����� ������ � ������� �� ����� ��������
			elem = elem->next;							// ��������� �� ���������
		}
		if (elem != NULL){						// ���� ������� ������� 
			return elem;						// ���������� ���
		}
		else
			return NULL;					// ����� ���������� ����

	}

	//����� ����������� �������� � ������;
	template <class T>
	Node<T>* LinkedList<T>::searchMax()
	{
		Node<T>* elem = head;
		/*Node<T>* tMax;*/
		if (elem == NULL){     // ���� ������ ������, ���������� ������� ���������
			return elem;
		}
		else{
			Node<T>* tMax = elem;     // ���������� ������ ������� ��� ������������
			T max = elem->data;
			while (elem != NULL){        // ���� �� ����� ������
				if (elem->data > max){    // ���� ������, �� ������  �������
					max = elem->data;
					tMax = elem;
				}
				elem = elem->next;
			}
			return tMax;
		}

	}

	//����� ����������� �������� � ������;
	template <class T>
	Node<T>* LinkedList<T>::searchMin()
	{
		Node<T>* elem = head;    // ���� ������ ������, ���������� ������� ���������
		if (elem == NULL){
			return elem;
		}
		else{
			Node<T>* tMin = elem;		// ���������� ������ ������� ��� ������������
			T min = elem->data;
			tMin = elem;
			while (elem != NULL){		    // ���� �� ����� ������
				if (elem->data < min){		// ���� ������, �� ������  �������
					min = elem->data;
					tMin = elem;
				}
				elem = elem->next;
			}
			return tMin;
		}

	}

	// �������� �������� ������ � ������ ���������
	// ��������� �������: true - ������� ������� false - ���
	template <class T>
	bool LinkedList<T>::deleteValue(const T &t)
	{
		// ���� ������ ����
		if (head == NULL){
			cout << "������ ������" << endl;
			return false;
		}
		else
		{
			Node<T>* elem = head;
			// �������� �� ������ ������
			if (elem->data == t){
				head = elem->next;
				delete elem;
				return true;
			}
			else
			{
				Node<T> *delem = head;  // ��������� �� ���������� �������
				while ((elem != NULL) && (elem->data != t)){    // ���� �� ����� ������ � �������� �� ����� ��������
					delem = elem;								// ���������� ���������� � ��������� �� ���������
					elem = elem->next;
				}
				// �������� �������� �� �������� ������ ��� �� �����
				if (elem != NULL){ // ���� ������� �������
					// �������� �� �����
					if (elem->next == NULL){
						tail = delem;				// ����������� ������ ���������� �������
						delem->next = elem->next;
						delete elem;
					}
					else{
						delem->next = elem->next;  // ������������ ���������
						delete elem;
					}
					return true;
				}
				else
					return false;

			}
		}
	}

	//- �������� ���� ��������� ������ � ������ ���������;
	template <class T>
	void LinkedList<T>::deleteValueAll(const T &t)
	{
		while (deleteValue(t))   // ���� ����� ������� ������� - �������
			;
	}

	// ��������� ���� ��������� ������ � ������ ��������� �� �����
	template <class T>
	void LinkedList<T>::�hangeAllElem(const T &t, const T &z)
	{
		Node<T> *elem = head;
		// ���� �� ����� ������
		while (elem != NULL){
			while ((elem != NULL) && (elem->data != t)){   // ���� �� ����� � �� ������ �������
				elem = elem->next;						   // ��������� �� ���������
			}
			if (elem != NULL){          // ���� �������
				elem->data = z;			// ������ ���
			}
		}
	}


