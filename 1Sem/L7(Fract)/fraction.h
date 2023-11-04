#pragma once
#include <fstream>
#include <iostream>
#ifndef Fraction
#endif Fraction
#include <string>
using std::ostream;
using std::istream;
using std::string;
class Fraction
{
private:
	int numerator;
	int denominator;
	void SetNumerator(int);
	void SetDenomerator(int);
	void FractReduction(int, int);
public:
	Fraction(int num = 1, int denom = 1);
	Fraction(const Fraction& other);
	~Fraction();
	void SetFract(int, int);
	int GetNumerator();
	int GetDenominator();
	void PrintFract(); 
	Fraction operator +(const Fraction&);
	Fraction operator -(const Fraction&);
	Fraction operator *(const Fraction&);
	Fraction operator /(const Fraction&);
	bool operator <(Fraction&) const;
	bool operator >(Fraction&) const;
	bool operator <=(Fraction&) const;
	bool operator >=(Fraction&) const;
	bool operator ==(Fraction&) const;
	bool operator !=(Fraction&) const;
	Fraction& operator ++();
	Fraction operator ++(int a);
	Fraction& operator --();
	Fraction operator --(int a);
	Fraction& operator -();
	Fraction& operator =(const Fraction&);
	Fraction& operator +=(const Fraction&);
	Fraction& operator -=(const Fraction&);
	Fraction& operator *=(const Fraction&);
	Fraction& operator /=(const Fraction&);
	friend ostream& operator <<(ostream& os, const Fraction&);
	friend istream& operator >>(istream& is, Fraction&);
	operator double();


	Fraction& operator+(const int& num);
	Fraction& operator-(const int& num);
	Fraction& operator*(const int& num);
	Fraction& operator/(const int& num);

	friend Fraction operator+(const int& num, const Fraction&);
	friend Fraction operator-(const int& num, const Fraction&);
	friend Fraction operator*(const int& num, const Fraction&);
	friend Fraction operator/(const int& num, const Fraction&);
	Fraction& operator+=(const int& num);

};
