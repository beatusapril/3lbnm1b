#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <list>  
#include <sstream>
using namespace std;
template <class T> struct Node
{
	// �������� ����
	T data;

	// ��������� �� ��������� ����
	Node *next;
};
