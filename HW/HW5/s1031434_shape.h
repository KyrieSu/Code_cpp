#ifndef PG2_1434HW5_Shape
#define PG2_1434HW5_Shape

class shape{
public:
	void print();
	virtual double area() = 0;
	bool valid();
};

#endif