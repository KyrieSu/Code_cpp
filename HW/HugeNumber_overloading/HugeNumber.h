#include<iostream>
#ifndef HugeNumber_h
#define HugeNumber_h

#define Max 100


class HugeNumber{	
	public:		
		friend std::ostream &operator<<(std::ostream&,const HugeNumber&);
		HugeNumber();
		static HugeNumber zero(HugeNumber&); 
		static HugeNumber random(unsigned int,HugeNumber&);
		HugeNumber operator=(const HugeNumber&);
		bool operator==(const HugeNumber&);
		bool operator!=(const HugeNumber&);
		bool operator>(const HugeNumber&);
		bool operator<(const HugeNumber&);
		HugeNumber operator+(const HugeNumber&);
		HugeNumber operator-(const HugeNumber&);
		HugeNumber operator*(const HugeNumber&);
		HugeNumber operator/(const HugeNumber&);
		HugeNumber operator%(const HugeNumber&);		
	private:
		HugeNumber helpdivison(int,int);
		bool check;
		int my_digit;
		short data[Max];
};


#endif
