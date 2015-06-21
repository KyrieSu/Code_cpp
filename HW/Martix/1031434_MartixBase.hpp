#include<cstdlib>
#include<iostream>

template<int RowSize,int ColumnSize,class Data_Type,class Column_Type,class Martix_Type>
class MartixBase{
	template<int RowSize, int ColumnSize, class Data_Type, class Column_Type, class Martix_Type>
	friend std::ostream& operator<< (std::ostream&, MartixBase<RowSize, ColumnSize, Data_Type, Column_Type, Martix_Type>& R);
public:
	Column_Type arr[RowSize];
	Column_Type& operator [](size_t i)	{ return arr[i]; }
	Column_Type& operator [](size_t i)const	{ return arr[i]; }
	size_t Row_num()const	{ return ColumnSize; }
	size_t Col_num()const	{ return RowSize; }
	size_t Row_size()const	{ return RowSize; }
	size_t Col_size()const	{ return ColumnSize; }
	Martix_Type& operator +(const Martix_Type& R)const{
		Martix_Type num;
		for (size_t i = 0; i < RowSize;i++)
			for (size_t j = 0; j < ColumnSize; j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = this->arr[i][j] + R.arr[i][j];
		}
				
		return num;
	}
	Martix_Type& operator -(const Martix_Type& R)const{
		Martix_Type num;
		for (size_t i = 0; i < RowSize; i++)
			for (size_t j = 0; j < ColumnSize; j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = this->arr[i][j] - R.arr[i][j];
			}				
		return num;
	}
	Martix_Type& operator *(const Data_Type k)const{
		Martix_Type num;
		for (size_t i = 0; i < RowSize; i++)
			for (size_t j = 0; j < ColumnSize; j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = (Data_Type)this->arr[i][j] * k;
			}				
		return num;
	}
	Martix_Type& operator /(const Data_Type k)const{
		Martix_Type num;
		for (size_t i = 0; i < RowSize; i++)
			for (size_t j = 0; j < ColumnSize; j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = (Data_Type)this->arr[i][j] / k;
			}
		return num;
	}
};

template<int RowSize, int ColumnSize, class Data_Type, class Column_Type, class Martix_Type>
friend std::ostream& operator<< (std::ostream& output, MartixBase<RowSize, ColumnSize, Data_Type, Column_Type, Martix_Type>& R){
		for (size_t i = 0; i < RowSize; i++)
			output << "col[" << i << "]¡G" << R.arr[i] << std::endl;
		return output;
}