#ifndef _QINT_H_
#define _QINT_H_

#define _SIZE_INT_		4
#define _BIT_INT_		32
#define _DEFAULT_SIZE	16
#define _POSITION		((Binary.size() - 1 - i) / (sizeof(int) * CHAR_BIT)) 
#define _SHIFT_OFFSET	(((Binary.size() - 1) % (CHAR_BIT * sizeof(int))) - (i % (CHAR_BIT * sizeof(int))))



#include <iostream>
#include <vector>
#include <string>

#pragma pack(1)

using namespace std;

class QInt 
{
protected:
	int m_Data[_DEFAULT_SIZE / _SIZE_INT_];
public:
	QInt();
	QInt(const string&);
	~QInt();

	int* getData();
	//Hàm lấy size
	int size();


	//Toán tử gán =.
	QInt operator = (QInt);
	//Toán tử +.
	QInt operator + (QInt) const;
	//Toán tử -.
	QInt operator - (QInt) const;
	//Toán tử *.
	QInt operator * (QInt) const;
	//Toán tử /.
	QInt operator / (QInt);
	
	//Toán tử ==.
	bool operator == (QInt);
	//Toán tử /.
	bool operator < (QInt);
	//Toán tử /.
	bool operator > (QInt);
	//Toán tử /.
	bool operator >= (QInt);
	//Toán tử /.
	bool operator <= (QInt);


	//Hàm kiếm tra bằng không.
	bool isEqualZero();
	//Hàm kiểm tra số âm.
	bool isNegative();
};
#endif
