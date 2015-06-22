#include<cstdlib>
#include<iostream>


template<int RowSize,int ColumnSize,class Data_Type,class Column_Type,class Martix_Type>
class MartixBase{
	friend std::ostream& operator<< (std::ostream&, MartixBase<RowSize, ColumnSize, Data_Type, Column_Type, Martix_Type>&);
public:
	Column_Type arr[RowSize];
	Column_Type& operator [](size_t i)	{ return this->arr[i]; }
	Column_Type operator [](size_t i)const	{ return this->arr[i]; }
	size_t Row_num()const	{ return ColumnSize; }
	size_t Col_num()const	{ return RowSize; }
	size_t Row_size()const	{ return RowSize; }
	size_t Col_size()const	{ return ColumnSize; }
	Martix_Type& operator +(const Martix_Type& R)const{
		Martix_Type num;
		for (size_t i = 0; i < this->Row_size();i++)
			for (size_t j = 0; j < this->Col_size(); j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = this->arr[i][j] + R.arr[i][j];
		}
				
		return num;
	}
	Martix_Type& operator -(const Martix_Type& R)const{
		Martix_Type num;
		for (size_t i = 0; i < this->Row_size(); i++)
			for (size_t j = 0; j < this->Col_size(); j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = this->arr[i][j] - R.arr[i][j];
			}				
		return num;
	}
	Martix_Type& operator *(const Data_Type k)const{
		Martix_Type num;
		for (size_t i = 0; i < this->Row_size(); i++)
			for (size_t j = 0; j < this->Col_size(); j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = (Data_Type)this->arr[i][j] * k;
			}				
		return num;
	}
	Martix_Type& operator /(const Data_Type k)const{
		Martix_Type num;
		for (size_t i = 0; i < this->Row_size(); i++)
			for (size_t j = 0; j < this->Col_size(); j++){
				num.arr[i][j] = 0;
				num.arr[i][j] = (Data_Type)this->arr[i][j] / k;
			}
		return num;
	}
};

template<int RowSize, int ColumnSize, class Data_Type, class Column_Type, class Martix_Type>
std::ostream& operator << (std::ostream& output, MartixBase<RowSize, ColumnSize, Data_Type, Column_Type, Martix_Type>& R){
	for (size_t i = 0; i < R.Row_size(); i++)
		output << "col[ " << i << " ]: " << R.arr[i] << std::endl;
	return output;
}