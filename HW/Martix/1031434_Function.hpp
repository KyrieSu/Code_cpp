#include"1031434_MartixBase.hpp"

template<class T1,class T2,class T3>
T3 Mul(const T1& left, const T2& right){
	T3 num;
	for (size_t i = 0; i < RowSize; i++)
		for (size_t j = 0; j < ColumnSize; j++){
			num[i][j] = 0;
			for (size_t k = 0; k < left.ColumnSize; k++)
				num[i][j] += left[i][k] * right[k][j];
		}
	return num;
}

template<class T1,class T2>
T2 Transpose(const T1& m){
	T2 num;
	for (size_t i = 0; i < num.ColumnSize; i++)
		for (size_t j = 0; j < m.ColumnSize; j++)
			num[j][i] = m[i][j];
	return num;
}

template <class T0, class T>
T Inverse(const T& m)
{
	T num;
	for (size_t i = 0; i < RowSize; i++)
		for (size_t j = 0; j < ColumnSize; j++){
			num[i][j] = 0;
			for (size_t k = 0; k < ColumnSize; k++)
				num[i][j] += m[i][k] * m[k][j];
		}
	return num;
}