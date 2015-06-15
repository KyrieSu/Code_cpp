#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

template <int Size, class Data_Type, class Vector_Type> 
class Vector_Base	// all vector is column vector
{
	public:
		Data_Type _[Size] ;

		inline Data_Type & operator [] ( size_t const& i )				{ return _[i]; }
		inline Data_Type const& operator [] ( size_t const& i ) const	{ return _[i]; }

		inline Vector_Type operator - () const 	{
			Vector_Type rv;
			for (size_t i = 0; i < Size; i++)	rv._[i] = -_[i];
			return rv;
		}
		
		//10pts
		//inline Vector_Type operator + ( Vector_Type const& v ) const			{ ... }
		//inline Vector_Type operator - ( Vector_Type const& v ) const			{ ... }

		//inline Vector_Type operator * ( Data_Type const& f ) const			{ ... }
		//inline Vector_Type operator / ( Data_Type const& f ) const			{ ... }

		//add some friendship?
} ;

//template < ... > //5pts
//std::ostream& operator << ( ... )	