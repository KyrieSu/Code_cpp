#include<cstdlib>
#include<iostream>

template<int size,class Data_Type,class Vector_Type>
class VectorBase{
	template<int size, class Data_Type, class Vector_Type>
	friend std::ostream& operator<< (std::ostream&, VectorBase< size, Data_Type, Vector_Type>& R);
public:
	Data_Type arr[size];
	Data_Type& operator [](size_t i)	{ return arr[i]; }
	Data_Type& operator [](size_t i)const	{ return arr[i]; }
	Vector_Type& operator -()const{
		Vector_Type num;
		for (size_t i = 0; i < size; i++)
			num.arr[i] = this->arr[i] * (-1);
		return num;
	}
	Vector_Type& operator +(const Vector_Type& m)const{
		Vector_Type num;
		for (size_t i = 0; i < size; i++)
			num.arr[i] = this->arr[i] + m.arr[i];
		return num;
	}
	Vector_Type& operator -(const Vector_Type& m)const{
		Vector_Type num;
		for (size_t i = 0; i < size; i++)
			num.arr[i] = this->arr[i] - m.arr[i];
		return num;
	}
	Vector_Type& operator *(const Data_Type k)const{
		Vector_Type num;
		for (size_t i = 0; i < size; i++)
			num.arr[i] = (Data_Type)this->arr[i] * k;
		return num;
	}
	Vector_Type& operator /(const Data_Type k)const{
		Vector_Type num;
		for (size_t i = 0; i < size; i++)
			num.arr[i] = (Data_Type)this->arr[i] / k;
		return num;
	}
};

template<int size, class Data_Type, class Vector_Type>
friend std::ostream& operator<< (std::ostream& output, VectorBase< size, Data_Type, Vector_Type>& R){
	for (size_t i = 0; i < size; i++)
		output << R.arr[i] << "   ";
	return output;
}