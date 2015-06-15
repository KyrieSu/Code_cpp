#ifndef VectorBase_H
#define VectorBase_H

template<int len,class DataType,class VectorType>
class VectorBase{
public:
	DataType [len];
	DataType& operator[](size_t i);
	DataType const& operator[](size_t i)const;
	VectorType operator-()const;
	VectorType operator+(const VectorType&)const;
	VectorType operator-(const VectorType&)const;
	//VectorType operator*(const DataType&)const;
	//VectorType operator+(const DataType&)const;
};

#endif