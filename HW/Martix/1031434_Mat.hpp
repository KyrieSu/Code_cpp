#include"1031434_MartixBase.hpp"
#include"1031434_Vec.hpp"
#include"1031434_Function.inl"

template <class T> class Mat_1x1;
template <class T> class Mat_1x3;
template <class T> class Mat_1x4;
template <class T> class Mat_3x1;
template <class T> class Mat_4x1;
template <class T> class Mat_3x3;
template <class T> class Mat_3x4;
template <class T> class Mat_4x3;
template <class T> class Mat_4x4;

template <class T1, class T2, class T3> T3 Mul(const T1& left, const T2& right);
template <class T1, class T2> T2 _Transpose(const T1& m);
template <class T0, class T> T _Inverse(const T& m);

template<class T>
class Mat_1x1 :public MartixBase<1, 1, T, Vec1<T>, Mat_1x1<T> >{
public:
	Mat_1x1(const Vec1<T>& x){ this->arr[0] = x; }
	Mat_1x1 Transpose()const	{ return _Transpose<Mat_1x1, Mat_1x1>(*this); }
	Mat_1x1 Inverse()const	{ return _Inverse<T, Mat_1x1>(*this); }
	Mat_1x1 operator *(const Mat_1x1& R)const	{ return Mul<Mat_1x1, Mat_1x1, Mat_1x1>(*this, R); }
	Mat_1x3<T> operator *(const Mat_1x3<T>& R)const{
		return Mul<Mat_1x1, Mat_1x3<T>, Mat_1x3<T> >(*this, R);
	}
	Mat_1x4<T> operator *(const Mat_1x4<T>& R)const{
		return Mul<Mat_1x1, Mat_1x4<T>, Mat_1x4<T> >(*this, R);
	}
	using MartixBase<1, 1, T, Vec1<T>, Mat_1x1<T> >::operator*;
};

template<class T>
class Mat_1x3 :public MartixBase<3, 1, T, Vec1<T>, Mat_1x3<T> >{
public:
	Mat_1x3(const Vec1<T>& x = Vec1<T>(0), const Vec1<T>& y = Vec1<T>(0), const Vec1<T>& z = Vec1<T>(0)){
		this->arr[0] = x;	this->arr[1] = y; this->arr[2] = z;
	}
	Mat_3x1<T> Transpose()const{ return _Transpose<Mat_1x3, Mat_3x1<T> >(*this); }
	Mat_1x1<T> operator *(const Mat_3x1<T>& R)const {
		return Mul<Mat_1x3, Mat_3x1<T>, Mat_1x1<T> >(*this, R);
	}
	Mat_1x4<T> operator *(const Mat_3x4<T>& R)const {
		return Mul<Mat_1x3, Mat_3x4<T>, Mat_1x4<T> >(*this, R);
	}
	Mat_1x3 operator *(const Mat_3x3<T>& R)const {
		return Mul<Mat_1x3, Mat_3x3<T>, Mat_1x3<T> >(*this, R);
	}
	using MartixBase<3, 1, T, Vec1<T>, Mat_1x3<T> >::operator*;
};

template<class T>
class Mat_1x4 :public MartixBase<4, 1, T, Vec1<T>, Mat_1x4<T> >{
public:
	Mat_1x4(const Vec1<T>& x = Vec1<T>(0), const Vec1<T>& y = Vec1<T>(0), const Vec1<T>& z = Vec1<T>(0), const Vec1<T>& w = Vec1<T>(0)){
		this->arr[0] = x; this->arr[1] = y;	this->arr[2] = z;	this->arr[3] = w;
	}
	Mat_4x1<T> Transpose()const	{ return _Transpose<Mat_1x4, Mat_4x1<T> >(*this); }
	Mat_1x1<T> operator * (const Mat_4x1<T>& R)const	{ return Mul<Mat_1x4, Mat_4x1<T>, Mat_1x1<T> >(*this, R); }
	Mat_1x3<T> operator * (const Mat_4x3<T>& R)const	{ return Mul<Mat_1x4, Mat_4x3<T>, Mat_1x3<T> >(*this, R); }
	Mat_1x4 operator * (const Mat_4x4<T>& R)const	{ return Mul<Mat_1x4, Mat_4x4<T>, Mat_1x4>(*this, R); }
	using MartixBase<4, 1, T, Vec1<T>, Mat_1x4<T> >::operator*;
};

template <class T> 
class Mat_3x1 :public MartixBase<1, 3, T, Vec3<T>, Mat_3x1<T> >{
public:
	Mat_3x1(const Vec3<T>& x = Vec3<T>(0, 0, 0))		{ this->arr[0] = x; }
	Mat_1x3<T> Transpose() const						{ return _Transpose<Mat_3x1, Mat_1x3<T> >(*this); }
	Mat_3x3<T> operator * (const Mat_1x3<T>& R) const	{ return Mul<Mat_3x1, Mat_1x3<T>, Mat_3x3<T> >(*this, R); }
	Mat_3x1 operator * (const Mat_1x1<T>& R) const		{ return Mul<Mat_3x1, Mat_1x1<T>, Mat_3x1>(*this, R); }
	Mat_3x4<T> operator *(const Mat_1x4<T>& R) const    { return Mul<Mat_3x1, Mat_1x4<T>, Mat_3x4<T> >(*this, R); }
	using MartixBase<1, 3, T, Vec3<T>, Mat_3x1<T> >::operator *;
};

template <class T> 
class Mat_4x1 : public MartixBase<1, 4, T, Vec4<T>, Mat_4x1<T> >{
public:
	Mat_4x1(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0))        { this->arr[0] = x; }
	Mat_1x4<T> Transpose() const                           { return _Transpose<Mat_4x1, Mat_1x4<T> >(*this); }
	Mat_4x4<T> operator * (const Mat_1x4<T>& R)const       { return Mul<Mat_4x1, Mat_1x4<T>, Mat_4x4<T> >(*this, R); }
	Mat_4x1 operator * (const Mat_1x1<T>& R)const          { return Mul<Mat_4x1, Mat_1x1<T>, Mat_4x1>(*this, R); }
	Mat_4x3<T> operator * (const Mat_1x3<T>& R)const       { return Mul<Mat_4x1, Mat_1x3<T>, Mat_4x3<T> >(*this, R); }
	using MartixBase<1, 4, T, Vec4<T>, Mat_4x1<T> >::operator *;
};

template <class T> 
class Mat_3x3 : public MartixBase<3, 3, T, Vec3<T>, Mat_3x3<T> >{
public:
	Mat_3x3(const Vec3<T>& x = Vec3<T>(0, 0, 0),const Vec3<T>& y = Vec3<T>(0, 0, 0), const Vec3<T>& z = Vec3<T>(0, 0, 0)){
		this->arr[0] = x;	this->arr[1] = y;	this->arr[2] = z;
	}
	Mat_3x3 Transpose() const								{ return _Transpose<Mat_3x3, Mat_3x3>(*this); }
	Mat_3x3 Inverse() const									{ return _Inverse<T, Mat_3x3>(*this); }
	Mat_3x3 operator * (const Mat_3x3& R) const				{ return Mul<Mat_3x3, Mat_3x3, Mat_3x3>(*this, R); }
	Mat_3x4<T> operator * (const Mat_3x4<T>& R) const		{ return Mul<Mat_3x3, Mat_3x4<T>, Mat_3x4<T> >(*this, R); }
	Mat_3x1<T> operator * (const Mat_3x1<T>& R) const		{ return Mul<Mat_3x3, Mat_3x1<T>, Mat_3x1<T> >(*this, R); }
	using MartixBase<3, 3, T, Vec3<T>, Mat_3x3<T> >::operator *;
};

template <class T> 
class Mat_3x4 : public MartixBase<4, 3, T, Vec3<T>, Mat_3x4<T> >{
public:
	Mat_3x4(const Vec3<T>& x = Vec3<T>(0, 0, 0), const Vec3<T>& y = Vec3<T>(0, 0, 0), const Vec3<T>& z = Vec3<T>(0, 0, 0), const Vec3<T>& w = Vec3<T>(0, 0, 0)){
		this->arr[0] = x; this->arr[1] = y; this->arr[2] = z; this->arr[3] = w;
	}
	Mat_4x3<T> Transpose() const                                { return _Transpose<Mat_3x4, Mat_4x3<T> >(*this); }
	Mat_3x4 operator * (const Mat_4x4<T>& R) const              { return Mul<Mat_3x4, Mat_4x4<T>, Mat_3x4>(*this, R); }
	Mat_3x1<T> operator * (const Mat_4x1<T>& R) const           { return Mul<Mat_3x4, Mat_4x1<T>, Mat_3x1<T> >(*this, R); }
	Mat_3x3<T> operator * (const Mat_4x3<T>& R) const           { return Mul<Mat_3x4, Mat_4x3<T>, Mat_3x3<T> >(*this, R); }
	using MartixBase<4, 3, T, Vec3<T>, Mat_3x4<T> >::operator *;
};

template <class T> 
class Mat_4x3 : public MartixBase<3, 4, T, Vec4<T>, Mat_4x3<T> >{
public:
	Mat_4x3(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0), const Vec4<T>& y = Vec4<T>(0, 0, 0, 0), const Vec4<T>& z = Vec4<T>(0, 0, 0, 0)){
		this->arr[0] = x; this->arr[1] = y; this->arr[2] = z;
	}
	Mat_3x4<T> Transpose() const                                 { return _Transpose<Mat_4x3, Mat_3x4<T> >(*this); }
	Mat_4x3 operator * (const Mat_3x3<T>& R) const               { return Mul<Mat_4x3, Mat_3x3<T>, Mat_4x3>(*this, R); }
	Mat_4x1<T> operator * (const Mat_3x1<T>& R) const            { return Mul<Mat_4x3, Mat_3x1<T>, Mat_4x1<T> >(*this, R); }
	Mat_4x4<T> operator * (const Mat_3x4<T>& R) const            { return Mul<Mat_4x3, Mat_3x4<T>, Mat_4x4<T> >(*this, R); }
	using MartixBase<3, 4, T, Vec4<T>, Mat_4x3<T> >::operator *;
};

template <class T> 
class Mat_4x4 : public MartixBase<4, 4, T, Vec4<T>, Mat_4x4<T> >{
public:
	Mat_4x4(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0), const Vec4<T>& y = Vec4<T>(0, 0, 0, 0), const Vec4<T>& z = Vec4<T>(0, 0, 0, 0), const Vec4<T>& w = Vec4<T>(0, 0, 0, 0)){
		this->arr[0] = x; this->arr[1] = y; this->arr[2] = z; this->arr[3] = w;
	}
	Mat_4x4 Transpose() const                                  { return _Transpose<Mat_4x4, Mat_4x4>(*this); }
	Mat_4x4 Inverse() const                                    { return _Inverse<T, Mat_4x4>(*this); }
	Mat_4x4 operator * (const Mat_4x4& R) const                { return Mul<Mat_4x4, Mat_4x4, Mat_4x4>(*this, R); }
	Mat_4x3<T> operator * (const Mat_4x3<T>& R) const          { return Mul<Mat_4x4, Mat_4x3<T>, Mat_4x3<T> >(*this, R); }
	Mat_4x1<T> operator * (const Mat_4x1<T>& R) const          { return Mul<Mat_4x4, Mat_4x1<T>, Mat_4x1<T> >(*this, R); }
	using MartixBase<4, 4, T, Vec4<T>, Mat_4x4<T> >::operator *;
};

