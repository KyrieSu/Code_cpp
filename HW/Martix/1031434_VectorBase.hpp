#include<cstdlib>
#include<iostream>

template <int Size, class DataType, class VectorType>
class VectorBase{
public:
	DataType arr[Size];
	DataType& operator[](size_t i)	{ return arr[i]; }
	const DataType& operator[](size_t i)const	{ return arr[i]; }
	VectorType& operator-()const{
		VectorType num;
		for (size_t i = 0; i < Size; i++)
			num.arr[i] = -this->arr[i];
		return num;
	}
	VectorType& operator+(const VectorType& right)const{
		VectorType num;
		for (size_t i = 0; i < Size; i++)
			num.arr[i] = this->arr[i] + right.arr[i];
		return num;
	}
	VectorType& operator-(const VectorType& right)const{
		VectorType num;
		for (size_t i = 0; i < Size; i++)
			num.arr[i] = this->arr[i] - right.arr[i];
		return num;
	}
	VectorType& operator*(const DataType& k)const{
		VectorType num;
		for (size_t i = 0; i < Size; i++)
			num.arr[i] = (DataType)this->arr[i] * k;
		return num;
	}
	VectorType& operator/(const DataType k)const{
		VectorType num;
		for (size_t i = 0; i < Size; i++)
			num.arr[i] = (DataType)this->arr[i] / k;
		return num;
	}
};
