#include"1031434_VectorBase.h"
using namespace std;

template <int len, class DataType, class VectorType>
DataType& DataType::operator[](size_t i){
	return arr[i];
}