#include "QInt.h"
#include "Convert.h"

#pragma pack(1)
using namespace std;

void main()
{
	QInt a("10");
	QInt B("10");
	if (a >= B)
		cout << "true";
	else
		cout << "false";
}