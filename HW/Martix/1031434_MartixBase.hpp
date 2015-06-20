#include<cstdlib>

template <int RowSize,int ColumnSize,class DataType,class ColumnType,class MatrixType>
class MartixBase{
public:
	ColumnType arr[RowSize];
	ColumnType& operator[](size_t i)	{ return arr[i]; }
	const ColumnType& operator[](size_t i)const	{ return arr[i]; }
	size_t Row_num()const	{ return ColumnSize; }
	size_t Column_num()const	{ return RowSize; }
	size_t Row_size()const	{ return RowSize; }
	size_t Column_size()const	{ return ColumnSize; }
	MatrixType& operator + (const MatrixType& right) const{
		MatrixType num;
		for (size_t i = 0; i < RowSize; i++)
			num.arr[i] = this->arr[i] + right.arr[i];
		return num;
	}
	MatrixType& operator-(const MatrixType& right)const{
		MatrixType num;
		for (size_t i = 0; i < RowSize; i++)
			num.arr[i] = this->arr[i] - right.arr[i];
		return num;
	}
	MatrixType& operator*(const DataType k)const{
		MatrixType num;
		for (size_t i = 0; i < RowSize; i++)
			for (size_t j = 0; j < ColumnSize; j++)
				num.arr[i][j] = this->arr[i][j] * k;
		return num;
	}
	MatrixType& operator/(const DataType k)const{
		MatrixType num;
		for (size_t i = 0; i < RowSize; i++)
			for (size_t j = 0; j < ColumnSize; j++)
				num.arr[i][j] = this->arr[i][j] / k;
		return num;
	}
};