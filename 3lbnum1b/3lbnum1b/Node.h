#pragma once
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <list>  
#include <sstream>
using namespace std;
template <class T> struct Node
{
	// «начение узла
	T data;

	// ”казатель на следующий узел
	Node *next;
};
