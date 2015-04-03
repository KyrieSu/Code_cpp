#ifndef HugeNumber_h
#define HugeNumber_h

#define Max 100


class HugeNumber{
public:
	HugeNumber();
	void random(unsigned int);
	void add_function(HugeNumber);
	void sub_function(HugeNumber);
	void print();
	~HugeNumber();
private:
	int getdigit();
	short *data;		
};

#endif