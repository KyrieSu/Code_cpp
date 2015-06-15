#pragma once

#include "My_Vector_Base.hpp"

template <class T> 
class Vec1 : public Vector_Base <1, T, Vec1<T>>
{
	public:
		inline Vec1 ( T const& x = 0 )									{ _[0] = x; }
} ;

template <class T> 
class Vec2 : public Vector_Base <1, T, Vec2<T>>
{
	public:
		inline Vec2 ( T const& x = 0, T const& y = 0 )					{ _[0] = x; _[1] = y; }

		inline T dotProduct ( Vec2<T> const& v )						{ return ( _[0]*v._[0] + _[1]*v._[1] ); }
} ;


template <class T> //10pts
class Vec3 : public Vector_Base <3, T, Vec3<T>>
{
	public:
		inline Vec3 ( T const& x = 0, T const& y = 0, T const& z = 0 )	{ _[0] = x; _[1] = y; _[2] = z; }

		//inline Vec3<T> crossProduct(Vec3<T> const& v)					{ ... }
		//inline T dotProduct(Vec3<T> const& v)							{ ... }
} ;
 
//template <class T> //10pts
//class Vec4 : public Vector_Base <4, T, Vec4<T>>
//{
//	...
//} ;

