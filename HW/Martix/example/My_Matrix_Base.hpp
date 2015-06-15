#pragma once

template <int Row_Size, int Column_Size, class Data_Type, class Column_Type, class Matrix_Type> 
class Matrix_Base  // Matrix: Column_Size x Row_Size, a 4x3 Matrix has 3 column with 4 elements in each column
{
	public:
		Column_Type _[Row_Size] ;

		inline Column_Type & operator [] ( size_t const& i )			{ return _[i]; }
		inline Column_Type const& operator [] ( size_t const& i ) const	{ return _[i]; }

		inline size_t Row_num () const									{ return Column_Size; }
		inline size_t Column_num () const								{ return Row_Size; }
		inline size_t Row_size () const									{ return Row_Size; }
		inline size_t Column_size () const								{ return Column_Size; }

		//inline Matrix_Type operator + (Matrix_Type const& m) const	{ ... }
		//inline Matrix_Type operator - (Matrix_Type const& m) const	{ ... }

		//inline Matrix_Type operator * (Data_Type const& f) const	{ ... }
		//inline Matrix_Type operator / (Data_Type const& f) const	{ ... }

		//add some friendship?
};

//template < ... > 
//std::ostream& operator << ( ... )	