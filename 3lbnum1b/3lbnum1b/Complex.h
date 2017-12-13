#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{

public:
	// целая и вещественная часть 
	double re, im;
	// конструкторы 
	Complex()
	{
	};

	Complex(double r)
	{
		re = r;
		im = 0;
	}

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(const Complex &c)   // конструктор копирования
	{
		re = c.re;
		im = c.im;
	}

	/* деструктор*/
	~Complex()
	{
	}

	// остальные функции

	// Модуль комплексного числа
	double abs()
	{
		return sqrt(re * re + im * im);
	}


	// оператор присваивания
	Complex& operator = (Complex c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}


	// оператор +=
	Complex& operator += (Complex &c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	// оператор сложения
	Complex operator + (const Complex &c)
	{
		return Complex(re + c.re, im + c.im);
	}

	// оператор вычитания
	Complex operator - (const Complex &c)
	{
		return Complex(re - c.re, im - c.im);
	}

	// оператор умножения
	Complex operator * (const Complex &c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	// оператор деления
	Complex operator / (const Complex &c)
	{
		Complex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}

	// оператор неравенства
	bool operator != (const Complex &c)
	{
		return ((re!=c.re)||(im!=c.im));
	}

	// оператор больше
	bool operator > (const Complex &c)
	{
		return ((re > c.re) || (re==c.re)&&(im >c.im));
	}

	// оператор меньше
	bool operator < (const Complex &c)
	{
		return ((re < c.re) || (re == c.re) && (im <c.im));
	}

	// оператор равенства
	bool operator == (const Complex &c)
	{
		return ((re == c.re) && (im ==c.im));
	}

	// укажем дружественные операторы, которым мы разрешаем доступ
	// к личным (private) данным
	friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator>> (istream &, Complex &);
private:

};

// перегрузка оператора <<
ostream& operator<< (ostream &out, const Complex &c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

// перегрузка оператора >>
istream& operator>> (istream &in, Complex &c)
{
	in >> c.re >> c.im;
	return in;
}
