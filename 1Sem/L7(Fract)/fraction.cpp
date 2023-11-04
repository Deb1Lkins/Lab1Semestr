#include "fraction.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <numeric>
using std::ostream;
using std::fstream;
using std::istream;
using std::gcd;
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom)
{
	if (denominator == 0)
	{
		throw"нельзя делить на ноль";
	}
	FractReduction(numerator, denominator);
}
Fraction::Fraction(const Fraction& other) :numerator{ other.numerator }, denominator{ other.denominator }
{
	/*numerator = other.numerator;
	denominator = other.denominator;*/
}
Fraction::~Fraction()
{
	std::cout << "\nдеструктор был вызван\n";
}
void Fraction::SetNumerator(int)
{
	if (numerator == 0)
	{
		throw"0/x = 0";
	}
	this->numerator = numerator;
}
void Fraction::SetDenomerator(int)
{
	this->denominator = denominator;
}
void Fraction::FractReduction(int, int)
{
	int nod = gcd(numerator, denominator);
	if (nod != 1)
	{
		this->numerator /= nod;
		this->denominator /= nod;
	}
	/*if (denominator == 0)
	{
		throw"знаменатель не может быть равен нулю";
	}*/
	if (denominator < 0)
	{
		this->numerator *= -1;
		this->denominator *= (-1);
	}

}
void Fraction::SetFract(int, int)
{
	SetNumerator(numerator);
	SetDenomerator(denominator);
	FractReduction(numerator, denominator);
}
int Fraction::GetNumerator()
{
	return numerator;
}
int Fraction::GetDenominator()
{
	return denominator;
}
void Fraction::PrintFract()
{
	SetFract(numerator,denominator);
	if (denominator < 0)
	{
		this->numerator *= -1;
		this->denominator *= (-1);
	}
	std::cout << this->numerator << "/" << this->denominator;
}
Fraction Fraction::operator +(const Fraction& other)
{
	this->numerator = numerator * other.denominator + other.numerator * denominator;
	this->denominator = denominator * other.denominator;
	SetFract(this->numerator, this->denominator);
	return *this;
}
Fraction Fraction::operator -(const Fraction& other)
{
	this->numerator = numerator * other.denominator - other.numerator * denominator;
	this->denominator = denominator * other.denominator;
	SetFract(this->numerator, this->denominator);

	return *this;
}
Fraction Fraction::operator *(const Fraction& other)
{
	this->numerator = numerator * other.numerator;
	this->denominator = denominator * other.denominator;
	SetFract(this->numerator, this->denominator);
	return *this;
}
Fraction Fraction::operator /(const Fraction& other)
{
	if (other.numerator == 0)
	{
		throw"получиться деление на ноль";
	}
	this->numerator = numerator * other.denominator;
	this->denominator = denominator * other.numerator;
	SetFract(this->numerator, this->denominator);
	return *this;
}
bool Fraction::operator <(Fraction& other) const
{
	return (numerator * other.denominator - other.numerator * denominator < 0);
}
bool Fraction::operator >(Fraction& other) const
{
	return (numerator * other.denominator - other.numerator * denominator > 0);
}
bool Fraction::operator <=(Fraction& other) const
{
	return (numerator * other.denominator - other.numerator * denominator <= 0);
}
bool Fraction::operator >=(Fraction& other) const
{
	return (numerator * other.denominator - other.numerator * denominator >= 0);
}
bool Fraction::operator ==(Fraction& other) const
{
	return (numerator * other.denominator - other.numerator * denominator == 0);
}
bool Fraction::operator !=(Fraction& other) const
{
	
	return (numerator * other.denominator - other.numerator * denominator != 0);
}
Fraction& Fraction::operator ++()
{
	this->numerator = numerator + denominator;
	return *this;
}
Fraction Fraction::operator ++(int a)
{
	Fraction temp(*this);
	this->numerator = numerator + denominator;
	return temp;
}
Fraction& Fraction::operator --()
{
	this->numerator = numerator - denominator;
	return *this;
}
Fraction Fraction::operator --(int a)
{
	Fraction temp(*this);
	this->numerator = numerator - denominator;
	return temp;
}
Fraction& Fraction::operator -()
{
	this->numerator = numerator * (-1);
	return *this;
}
Fraction& Fraction::operator =(const Fraction& other)
{
	if (this != &other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	return *this;
}
Fraction& Fraction::operator +=(const Fraction& other)
{
	this->numerator = numerator * other.denominator + other.numerator * denominator;
	this->denominator = denominator * other.denominator;
	return *this;
}
Fraction& Fraction::operator -=(const Fraction& other)
{
	this->numerator = numerator * other.denominator - other.numerator * denominator;
	this->denominator = denominator * other.denominator;
	return *this;
}
Fraction& Fraction::operator *=(const Fraction& other)
{
	this->numerator = numerator * other.numerator;
	this->denominator = denominator * other.denominator;
	return *this;
}
Fraction& Fraction::operator /=(const Fraction& other)
{
	if (other.numerator == 0)
	{
		throw"получиться деление на ноль";
	}
	this->numerator = numerator * other.denominator;
	this->denominator = denominator * other.numerator;
	return *this;
}
Fraction::operator double()
{
	double temp;
	temp = (1.0 * numerator) / (1.0 * denominator);
	return temp;

}
ostream& operator <<(ostream& os, const Fraction& other)
{
	
	if (other.denominator == 0)
	{
		std::cout << 0;
	}
	else
	{
		os << other.numerator << "/" << other.denominator;
		return os;
	}
}
istream& operator >>(istream& is,Fraction& other)
{
	char temp = '/';
	is >> other.numerator;
	std::cout << "/";
	is >> other.denominator;
	if (other.denominator < 0)
	{
		other.numerator = other.numerator * - 1;
		other.denominator = other.denominator *(-1);
	}
	int nod = gcd(other.numerator, other.denominator);
	if (nod != 1)
	{
		other.numerator /= nod;
		other.denominator /= nod;
	}
	return is;
}


Fraction& Fraction::operator +(const int& num)
{
	this->numerator = numerator + denominator * num;
	return *this;
}
Fraction& Fraction::operator -(const int& num)
{
	this->numerator = numerator - denominator * num;
	return *this;
}
Fraction& Fraction::operator *(const int& num)
{
	this->numerator = numerator * num;
	return *this;
}
Fraction& Fraction::operator /(const int& num)
{
	if (num == 0)
	{
		this->numerator = 0;
		this->denominator = 0;
	}
	else
	{
		if (num < 0)
		{
			this->numerator = -numerator;
			this->denominator = denominator * ( - num);
			return *this;
		}
		else
		{
			this->denominator = denominator * num;
			return *this;
		}
	}
}


Fraction operator +(const int& num, const Fraction& other)
{

	return Fraction(num * other.denominator + other.numerator, other.denominator);
}
Fraction operator -(const int& num, const Fraction& other)
{
	return Fraction(num * other.denominator - other.numerator, other.denominator);
}
Fraction operator *(const int& num, const Fraction& other)
{
	return Fraction(num * other.numerator, abs(num) * other.denominator);
}
Fraction operator /(const int& num, const Fraction& other)
{
	if (other.numerator == 0)
	{
		throw"получиться деление на ноль";
	}
	return Fraction(num * other.denominator, abs(num) * other.numerator);
}

//Fraction& Fraction::operator +=(const int& num)
//{
//	this->numerator = numerator + denominator * num;
//	return *this;
//}
//Fraction& Fraction::operator -=(const int& num)
//{
//	this->numerator = numerator - denominator * num;
//	return *this;
//}
//Fraction& Fraction::operator *=(const int& num)
//{
//	this->numerator *= num;
//	this->denominator *= abs(num);
//	return *this;
//}
//Fraction& Fraction::operator /=(const int& num)
//{
//	this->numerator = numerator + denominator * num;
//	return *this;
//}

