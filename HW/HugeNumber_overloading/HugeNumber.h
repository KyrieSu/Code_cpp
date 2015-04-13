#ifndef HugeNumber_h
#define HugeNumber_h

#define Max 100


class HugeNumber{
	friend ostream &operator<<(ostream&, const HugeNumber&);
	public:		
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
		bool check;
		int my_digit;
		short data[Max];
		bool helpdivide(HugeNumber,int);
};



#endif