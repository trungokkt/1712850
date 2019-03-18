QInt::QInt()
{
}

//Hàm khỏi tạo bằng cách truyền vào chuỗi bit nhị phân.
QInt::QInt(const string &Binary)
{
	memset(this->m_Data, 0, _DEFAULT_SIZE);
	for (size_t i = 0; i < Binary.size(); i++)
	{
		if (Binary[i] == '1')
		{
			this->m_Data[_POSITION] = this->m_Data[_POSITION] | (1 << _SHIFT_OFFSET);
		}
	}
}

//Hàm hủy dữ liệu của kiểu QInt (Không có xử lý gì đặc biệt).
QInt::~QInt()
{
}

//---------------------------------NHÓM HÀM GET, SET---------------------------------
//Hàm lấy data .
int* QInt::getData()
{
	return this->m_Data;
}
////Hàm lấy size
int QInt::size()
{
	return _DEFAULT_SIZE / _SIZE_INT_;
}

//Toán tử gán =.
QInt QInt::operator = (QInt x)
{
	if (this != &x)
	{
		for (int i = 0; i < x.size(); i++)
		{
			this->m_Data[i] = x.m_Data[i];
		}
	}
	return *this;
}
// toan tu *
QInt QInt::operator * (QInt x) const
{
	QInt Result;

	QInt Temp = *this;

	QInt One("1"); // 1
	bool Negative = false; //kiem tra so am

	if ((Temp.isNegative() && !x.isNegative()) || (!Temp.isNegative() && x.isNegative()))//kiem tra trai dau
	{
		Negative = true;
	}
	if (x.isNegative())
	{
		x = ~(x - One); //neu am thi chuyen sang dang so duong
	}
	if (Temp.isNegative())
	{
		Temp = ~(Temp - One); //neu am thi chuyen sang dang so duong
	}
	//nhan 2 so
	while (!(x.isNegative() || x.isEqualZero()))
	{
		if (((x & One) - One).isEqualZero()) //x le thi cong ket qua voi Temp
		{

			Result = Result + Temp;
		}

		Temp = Temp << 1; //nhan temp cho 2;
		x = x >> 1; //chia x cho 2.
	}

	// neu 2 so trai dau
	if (Negative == true)
	{
		Result = ~Result + One; //chuyet ket qua ve dang bu 2.
	}

	return Result;
}
// toan tu /
QInt QInt::operator / (QInt x)
{
	QInt Result;

	if (this->isEqualZero() || x.isEqualZero()) // kiem tra kq va x co bang 0 khong
	{
		return Result;
	}
	else
	{
		QInt One("1");

		if ((x - One).isEqualZero())
		{
			Result = *this;
		}
		else
		{
			QInt Temp = *this;
			int k = _DEFAULT_SIZE;
			bool Negative = false;

			if ((Temp.isNegative() && !x.isNegative()) || (!Temp.isNegative() && x.isNegative()))//neu 2 so trai dau
			{
				Negative = true;
			}

			if (x.isNegative())
			{
				x = ~(x - One); //am thi chuyen ve so duong
			}
			if (Temp.isNegative())
			{
				Temp = ~(Temp - One); //am thi chuyen ve so duong
			}

			while (k > 0)
			{
				Result = Result << 1;
				Result.m_Data[0] = Result.m_Data[0] | ((Temp.m_Data[Result.size() - 1] & (1 << (_SIZE_INT_ - 1))) >> (_SIZE_INT_ - 1));
				Temp = Temp << 1;

				Result = Result - x;
				if (Result.isNegative())
				{
					Result = Result + x;
				}
				else
				{
					Temp.m_Data[0] = Temp.m_Data[0] | 1;
				}

				--k;
			}

			Result = Temp;
			if (Negative == true)
			{
				Result = ~Result + One;
			}
		}
	}

	return Result;
}

//toan tu +.
QInt QInt::operator + (QInt x) const
{
	QInt Result = *this;
	QInt test1; //kiem tra bit cung 1 cua 2 so

	while (!(x.isEqualZero()))
	{
		//test1 là những bit cùng là 1 giữa 2 số.
		test1 = Result & x;

		//Tổng các bit khác nhau của hai số (0 + 1 = 1).
		Result = Result ^ x;

		//Đưa các bit cùng là 1 bên 1 bit để tiếp tục phép cộng cần thực hiện.
		x = test1 << 1;
	}

	return Result;
}
//toan tu -.
QInt QInt::operator - (QInt x) const
{
	return (*this + Convert::QInttoTwosComplement(x));
}
//Toán tử ==.
bool QInt::operator == (QInt x) {
	if (this != &x)
	{
		for (int i = 0; i < x.size(); i++)
		{
			if(this->m_Data[i] != x.m_Data[i])
				return false;
		}
	}
	return true;
}
//Toán tử <.
bool  QInt::operator < (QInt x) {
	if (this->isNegative() && !x.isNegative())
		return true;
	if (!this->isNegative() && x.isNegative())
		return false;
	if (this->isNegative() && x.isNegative()){
		QInt One("1");
		x = ~(x - One); //doi ve so duong
		*this = ~(*this - One);
		if (this != &x)
		{
			for (int i = 0; i < x.size(); i++)
			{
				if (this->m_Data[i] < x.m_Data[i])
					return false;
			}
		}
		return true;
	}

	if (!this->isNegative() && !x.isNegative()) {
		if (this != &x)
		{
			for (int i = 0; i < x.size(); i++)
			{
				if (this->m_Data[i] > x.m_Data[i])
					return false;
			}
		}
		return true;
	}
}
//Toán tử >.
bool  QInt::operator > (QInt x) {
	return !(*this < x);
}
//Toán tử >=.
bool  QInt::operator >= (QInt x) {
	return (*this > x || *this == x);
}
/*Toán tử <=*/
bool  QInt::operator <= (QInt x ) {
	return (*this < x || *this == x);
}

//Hàm kiếm tra bằng không.
bool QInt::isEqualZero()
{
	for (int i = 0; i < this->size(); i++)
	{
		if (this->m_Data[i] != 0)
		{
			return false;
		}
	}

	return true;
}

//Hàm kiểm tra số âm.
bool QInt::isNegative()
{
	if ((this->m_Data[this->size() - 1] & (1 << (_SIZE_INT_ - 1))) >> (_SIZE_INT_ - 1) == 1)
	{
		return true;
	}

	return false;
}
