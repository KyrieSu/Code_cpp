#include"1031434_MartixBase.hpp"

template<class T1, class T2, class T3>
T3 Mul(const T1& left, const T2& right){
	T3 num;
	for (size_t i = 0; i < left.Row_size(); i++)
	for (size_t j = 0; j < right.Column_size(); j++){
		num.arr[i][j] = 0;
		for (size_t k = 0; k < left.Column_size(); k++)
			num.arr[i][j] += left.arr[i][k] * right.arr[k][j];
	}
	return num;
}

template<class T1, class T2>
T2 _Transpose(const T1& m){
	T2 num;
	for (size_t i = 0; i < num.Column_size(); i++)
	for (size_t j = 0; j < m.Column_size(); j++)
		num.arr[j][i] = m[i][j];
	return num;
}

template <class T0, class T>
T _Inverse(const T& m)
{
	T num;
	for (size_t i = 0; i < this->Row_size(); i++)
	for (size_t j = 0; j < this->Column_size(); j++){
		num[i][j] = 0;
		for (size_t k = 0; k < this->Column_size(); k++)
			num.arr[i][j] += m.arr[i][k] * m.arr[k][j];
	}
	return num;
}