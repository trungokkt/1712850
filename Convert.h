/*
* Lớp chuyển đổi đi kèm với các phương thức chuyển đổi
* Đây là lớp thuần tĩnh được xây dựng theo mẫu thiết kế Singleton.
* Dễ dàng trong việc bảo trì và nâng cấp chương trình.
*/

#ifndef _CONVERT_H_
#define _CONVERT_H_

#define _MAX_BIT_	128

#include "QInt.h"
#include<stdint.h>

#pragma pack(1)
class Convert
{
protected:
	static Convert *m_Instance;

	//--------------------------NHÓM HÀM TẠO, HỦY--------------------------
	//Hàm tạo.
	Convert();
	//Hàm hủy.
	~Convert();
public:
	//--------------------------NHÓM HÀM GET, SET--------------------------
	//Hàm lấy đối tượng.
	static Convert* getInstance();

	//--------------------------NHÓM HÀM CONVERT--------------------------
	//Hàm chuyển chuỗi số nguyên sang chuỗi nhị phân.
	static std::string StrDectoBin(std::string);
	//Hàm chuyển chuỗi thập lục phân hoặc bát phân sang nhị phân.
	static std::string StrHexorOcttoBin(std::string);
	//Hàm cuyển chuỗi thập lục phân hoặc bát phân sang nhị phân.
	static std::string StrBintoHex(std::string);
	//Hàm chuyển số QInt sang số bù 2.
	static QInt QInttoTwosComplement(QInt);
	//Hàm chuyển QInt sang chuỗi nhị phân.
	static std::string QInttoBinaryString(QInt&);
	//Hàm chuyển QInt sang chuỗi số thập phân.
	static std::string QInttoDecimalString(QInt&);

	//--------------------------NHÓM HÀM HỖ TRỢ--------------------------
	//Hàm chia một chuỗi số thập phân cho 2.
	static std::string StrDivTwo(const std::string&);
	//Hàm cộng hai chuỗi số.
	static std::string AddNumberString(std::string, std::string);
	//Hàm trừ hai chuỗi số dương.
	static std::string SubNumberString(std::string, std::string);
	//Hàm nhân hai chuỗi số.
	static std::string MultiplyNumberString(std::string, std::string);
	//Hàm tính a lũy thừa n (a, n là số nguyên không âm).
	static std::string Power(int, int);
};
#endif