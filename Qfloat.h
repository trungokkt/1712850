#ifndef _QFLOAT_H_
#define _QFLOAT_H_
#include"Convert.h"
#include"QInt.h"
#include<iostream>
#include<string>
using namespace std;


class Qfloat
{
protected:
	unsigned int data[4];
public:
	Qfloat();
	Qfloat(string);

	unsigned int* getData()const;
	void setData(int viTrim, unsigned int Data);
	bool isNegative();

};
bool* DecToBin(Qfloat x);
string StrQfloat(Qfloat x);
#endif