#include"1031434_VectorBase.hpp"

template<class T>
class Vec1 :public VectorBase<1, T, Vec1<T> >{
public:
	Vec1(const T x = 0)	{ this->arr = x; }
};

template<class T>
class Vec2 :public VectorBase<2, T, Vec2<T> >{
public:
	Vec2(const T x = 0, const T y = 0)	{ this->arr[0] = x; this->arr[1] = y; }
	T dot(const Vec2<T>& R)	{ return (this->arr[0] * R.arr[0] + this->arr[1] * R.arr[1]); }
};

template<class T>
class Vec3 :public VectorBase<3, T, Vec3<T> >{
public:
	Vec3 (const T x = 0, const T y = 0, const T z = 0)	{ this->arr[0] = x; this->arr[1] = y; this->arr[2] = z; }
	T dot(const Vec3<T>& R)	{ return (this->arr[0] * R.arr[0] + this->arr[1] * R.arr[1] + this->arr[2] * R.arr[2]); }
	Vec3<T>& cross(const Vec3<T>& R){
		return Vec3<T>((this->arr[1] * R.arr[2] - R.arr[1] * this->arr[2]), (this->arr[0] * R.arr[2] - R.arr[0] * this->arr[2]), (this->arr[0] * R.arr[1] - R.arr[0] * this->arr[1]));
	}
};

template<class T>
class Vec4 :public VectorBase<4, T, Vec4<T> >{
public:
	Vec4 (const T x = 0, const T y = 0, const T z = 0, const T w = 0){
		this->arr[0] = x;	this->arr[1] = y; this->arr[2] = z; this->arr[3] = w;
	}
	T dot(const Vec4<T>& R){
		return (this->arr[0] * R.arr[0] + this->arr[1] * R.arr[1] + this->arr[2] * R.arr[2] + this->arr[3] * R.arr[3]);
	}
};