#ifndef VectorBase_H
#define VectorBase_H

#include<cstdlib>

template<int len, class DataType, class VectorType>
class VectorBase{
public:
	DataType arr[len];
	DataType& operator[](size_t i);
	const DataType& operator[](size_t i)const;
	VectorType operator-()const;
	VectorType operator+(const VectorType&)const;
	VectorType operator-(const VectorType&)const;
	//VectorType operator*(const DataType&)const;
	//VectorType operator+(const DataType&)const;
};

#endif