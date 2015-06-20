#include"1031434_VectorBase.hpp"

template<class T>
class Vec1 :public VectorBase<1, T, Vec1<T> >{
public:
	Vec1(T x = 0)	{ arr[0] = x; }
};

template<class T>
class Vec2 :public VectorBase< 2, T, Vec2<T> >{
public:
	Vec2(T x = 0, T y = 0) { arr[0] = x; arr[1] = y; }
	T dotProduct(const Vec2<T>& right){
		return (this->arr[0] * right.arr[0] + this->arr[1] * right.arr[1]);
	}
};

template<class T>
class Vec3 :public VectorBase<3, T, Vec3<T> >{
public:
	Vec3(T x = 0, T y = 0, T z = 0)	{ arr[0] = x; arr[1] = y; arr[2] = z; }
	T dotProduct(const Vec3<T>& right){
		return (this->arr[0] * right.arr[0] + this->arr[1] * right.arr[1] + this->arr[2] * right.arr[2]);
	}
	Vec3<T> crossProduct(const Vec3<T>& right){
		return Vec3<T>((this->arr[1]*right.arr[2] - right.arr[1] * this->arr[2]), (this->arr[0]*right.arr[2] - right.arr[0] * this->arr[2]), (this->arr[0]*right.arr[1] - right.arr[0] * this->arr[1]));
	}
};

template<class T>
class Vec4 :public VectorBase<4, T, Vec4<T> >{
public:
	Vec4(const T x = 0, const T y = 0, const T z = 0, const T w = 0){
		arr[0] = x;	arr[1] = y;	arr[2] = z;	arr[3] = w;
	}
	T dotProduct(const Vec3<T>& right){
		return (this->arr[0] * right.arr[0] + this->arr[1] * right.arr[1] + this->arr[2] * right.arr[2] + this->arr[3] * right.arr[3]);
	}
	//Vec4<T> crossProduct(const Vec4<T>& right)	{}
};

