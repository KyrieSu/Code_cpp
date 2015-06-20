#include"1031434_MartixBase.hpp"
#include"1031434_Vector.hpp"
#include"1031434_Function.hpp"

template <class T> class Mat_1x1;
template <class T> class Mat_1x3;
template <class T> class Mat_1x4;
template <class T> class Mat_3x1;
template <class T> class Mat_4x1;
template <class T> class Mat_3x3;
template <class T> class Mat_3x4;
template <class T> class Mat_4x3;
template <class T> class Mat_4x4;

template <class T1, class T2, class T3> T3 Mul(const T1&, const T2&);
template <class T1, class T2> T2 Transpose(const T1&);
template <class T0, class T> T Inverse(const T&);

template<class T>
class Mat_1x1 :public MartixBase<1, 1, T, Vec1<T>, Mat_1x1<T> >{
public:
	Mat_1x1(const Vec1<T>& vec)	{ arr[0] = vec; }
	Mat_1x1 Transpose()const	{ return Transpose<Mat_1x1, Mat_1x1>(*this); }
	Mat_1x1 operator*(const Mat_1x1& m)const{
		return Mul<Mat_1x1, Mat_1x1, Mat_1x1>(*this, m);
	}
	Mat_1x3<T> operator*(const Mat_1x3& m)const{ 
		return Mul<Mat_1x1, Mat_1x3<T>, Mat_1x3<T> >(*this, m); 
	}
	Mat_1x4<T> operator*(const Mat_1x4& m)const{
		return Mul<Mat_1x1, Mat_1x4<T>, Mat_1x4<T> >(*this, m);
	}

	using MartixBase<1, 1, T, Vec1<T>, Mat_1x1<T>>::operator*;
};

template<class T>
class Mat_1x3 :public MartixBase<3, 1, T, Vec1<T>, Mat_1x3<T> >{
public:
	Mat_1x3(const Vec1<T>& x = Vec1<T>(0), const Vec1<T>& y = Vec1<T>(0), const Vec1<T>& z = Vec1<T>(0)){
		arr[0] = x; arr[1] = y; arr[2] = z;
	}
	Mat_1x3<T> Transpose()const	{ return Transpose<Mat_1x3, Mat_3x1<T> >(*this); }
	Mat_1x1<T> operator*(const Mat_3x1& m)const{
		return Mul<Mat_1x3, Mat_3x1<T>, Mat_1x1<T> >(*this, m);
	}
	Mat_1x3 operator*(const Mat_3x3& m)const{
		return Mul<Mat_1x3, Mat_3x3<T>, Mat_1x3>(*this, m);
	}
	using MartixBase<3, 1, T, Vec1<T>, Mat_1x3<T> >::operator*;
};

template<class T>
class Mat_1x4 :public MartixBase<4, 1, T, Vec1<T>, Mat_1x4<T> >{
public:
	Mat_1x4(const Vec1<T>& x = Vec1<T>(0), const Vec1<T>& y = Vec1<T>(0), const Vec1<T>& z = Vec1<T>(0), const Vec1<T>& w = Vec1<T>(0)){
		arr[0] = x;	arr[1] = y; arr[2] = z;	arr[3] = w;
	}
	Mat_4x1<T> Transpose()const	{ return Transpose<Mat_1x4, Mat_4x1<T> >(*this); }
	Mat_1x1<T> operator*(const Mat_4x1<T>& m) const	{ return Mul<Mat_1x4, Mat_4x1<T>, Mat_1x1<T> >(*this, m); }
	Mat_1x4 operator*(Mat4x4<T> const& m) const     { return Mul<Mat_1x4, Mat_4x4<T>, Mat_1x4>(*this, m); }
	using MatrixBase<4, 1, T, Vec1<T>, Mat_1x4<T>>::operator*;
};

template<class T>
class Mat_3x1 :public MartixBase<1, 3, T, Vec3<T>, Mat_3x1<T> >{
public:
	Mat_3x1(const Vec3<T>& x = Vec3<T>(0, 0, 0))	{ arr[0] = x; }
	Mat_1x3 Transpose()const	{ return Transpose<Mat_3x1, Mat_1x3<T>, Mat_3x3<T> >(*this, m); }
	Mat_3x1 operator* (const Mat_1x1<T>& m) const	{ return Mul<Mat_3x1, Mat_1x1<T>, Mat_3x1>(*this, m); }
	using MatrixBase<1, 3, T, Vec3<T>, Mat_3x1<T>>::operator*;
};

template<class T>
class Mat_3x3 :public MartixBase<3, 3, T, Vec3<T>, Mat_3x3<T> >{
public:
	Mat_3x3(const Vec3<T>& x = (0, 0, 0), const Vec3<T>& y = (0, 0, 0), const Vec3<T>& z = (0, 0, 0)){
		arr[0] = x;	arr[1] = y;	arr[2] = z;
	}
	Mat_3x3 Transpose()const	{ return Transpose<Mat_3x3, Mat_3x3>(*this); }
	Mat_3x3 Inverse()const	{ return Inverse<T, Mat_3x3>(*this); }
	Mat_3x3 operator*(const Mat_3x3& m)const	{ return Mul<Mat_3x3, Mat_3x3, Mat_3x3>(*this, m); }
	Mat_3x4<T> operator*(const Mat_3x4<T>& m)const	{ 
		return Mul<Mat_3x3, Mat_3x4<T>, Mat_3x4<T> >(*this, m); 
	}
	Mat_3x1<T> operator*(const Mat_3x1<T>& m)const	{
		return Mul<Mat_3x3, Mat_3x1<T>, Mat_3x1<T> >(*this, m);
	}
	using MartixBase<3, 3, T, Vec3<T>, Mat_3x3<T> >::operator*;
};


template<class T>
class Mat_4x1 :public MartixBase<1, 4, T, Vec4<T>, Mat_4x1<T>>
{
public:
	Mat4x1(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0))          { arr[0] = x; }

	Mat_1x4<T> Transpose() const                           { return Transpose<Mat_4x1, Mat_1x4<T>>(*this); }
	Mat_4x4<T> operator* (const Mat_1x4<T> const& m) const { return Mul<Mat_4x1, Mat_1x4<T>, Mat_4x4<T>>(*this, m); }
	Mat_4x1 operator* (const Mat_1x1<T>& m) const          { return Mul<Mat_4x1, Mat_1x1<T>, Mat_4x1>(*this, m); }

	using MartixBase<1, 4, T, Vec4<T>, Mat4x1<T>>::operator*;
};

template <class T> 
class Mat_3x4 : public MartixBase<4, 3, T, Vec3<T>, Mat_3x4<T>>
{
public:
	Mat_3x4(const Vec3<T>& x = Vec3<T>(0, 0, 0), const Vec3<T>& y = Vec3<T>(0, 0, 0), const Vec3<T>& z = Vec3<T>(0, 0, 0), const Vec3<T>& w = Vec3<T>(0, 0, 0)) {
		arr[0] = x;	arr[1] = y; arr[2] = z; arr[3] = w;
	}
	Mat_4x3<T> Transpose() const                                { return Transpose<Mat_3x4, Mat_4x3<T>>(*this); }
	Mat_3x4 operator* (const Mat_4x4<T>& m) const                  { return Mul<Mat_3x4, Mat_4x4<T>, Mat_3x4>(*this, m); }
	Mat_3x1<T> operator* (const Mat_4x1<T>& m) const               { return Mul<Mat_3x4, Mat_4x1<T>, Mat_3x1<T>>(*this, m); }
	Mat_3x3<T> operator * (const Mat_4x3<T>& m) const              { return Mul<Mat_3x4, Mat_4x3<T>, Mat_3x3<T>>(*this, m); }

	using Matrix_Base<4, 3, T, Vec3<T>, Mat3x4<T>>::operator *;
};

template<class T>
class Mat_4x3 : public MartixBase<3, 4, T, Vec4<T>, Mat_4x3<T> >
{
public:
	Mat_4x3(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0), const Vec4<T>& y = Vec4<T>(0, 0, 0, 0), const Vec4<T>& z = Vec4<T>(0, 0, 0, 0)){
		arr[0] = x;	arr[1] = y; arr[2] = z;
	}
	Mat_3x4<T> Transpose() const                      { return Transpose<Mat_4x3, Mat_3x4<T>>(*this); }
	Mat_4x3 operator* (const Mat3x3<T>& m) const      { return Mul<Mat_4x3, Mat_3x3<T>, Mat_4x3>(*this, m); }
	Mat_4x1<T> operator* (const Mat3x1<T>& m) const   { return Mul<Mat_4x3,Mat_3x1<T>, Mat_4x1<T>>(*this, m); }

	using Matrix_Base<3, 4, T, Vec4<T>, Mat4x3<T>>::operator *;
};

template <class T> 
class Mat_4x4 : public MartixBase<4, 4, T, Vec4<T>, Mat_4x4<T>>
{
public:
	Mat_4x4(const Vec4<T>& x = Vec4<T>(0, 0, 0, 0),const Vec4<T>& y = Vec4<T>(0, 0, 0, 0), const Vec4<T>& z = Vec4<T>(0, 0, 0, 0),const Vec4<T>& w = Vec4<T>(0, 0, 0, 0)){
		arr[0] = x; arr[1] = y; arr[2] = z; arr[3] = w;
	}
	Mat_4x4 Transpose() const                                  { return Transpose<Mat_4x4, Mat_4x4>(*this); }
	Mat_4x4 Inverse() const                                    { return Inverse<T, Mat_4x4>(*this); }
	Mat_4x4 operator * (const Mat4x4& m) const                 { return Mul<Mat_4x4, Mat_4x4, Mat_4x4>(*this, m); }
	Mat_4x3<T> operator * (const Mat4x3<T>& m) const           { return Mul<Mat_4x4, Mat_4x3<T>, Mat_4x3<T>>(*this, m); }
	Mat_4x1<T> operator * (const Mat4x1<T>& m) const           { return Mul<Mat_4x4, Mat_4x1<T>, Mat_4x1<T>>(*this, m); }

	using MartixBase<4, 4, T, Vec4<T>, Mat_4x4<T>>::operator*;
};


