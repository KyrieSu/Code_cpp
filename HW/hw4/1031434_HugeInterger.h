#ifndef s1031434_HugeIntergerH
#define s1031434_HugeIntergerH

#include"1031434_Vector.h"
#include<iostream>

class HugeInterger{
	friend std::ostream& operator<<(std::ostream&, HugeInterger&);
public:
	HugeInterger(){}
	HugeInterger(HugeInterger&);
	HugeInterger(size_t);
	~HugeInterger(){}
	static HugeInterger random(size_t);
	static HugeInterger zero();
	HugeInterger operator=(const HugeInterger&);
	bool operator==(const HugeInterger&);
	bool operator!= (const HugeInterger&);
	bool operator>(const HugeInterger&);
	bool operator<(const HugeInterger&);
	HugeInterger operator+(const HugeInterger&);
	HugeInterger operator-(const HugeInterger&);
	HugeInterger operator*(const HugeInterger&);
	HugeInterger operator/(const HugeInterger&);
	HugeInterger operator%(const HugeInterger&);
private:
	Vector data;
};


#endif