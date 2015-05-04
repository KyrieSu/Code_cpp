#ifndef _1031434_Box_h
#define _1031434_Box_h

#define PI 3.14159265
#include<string>

class Vessel{
public:
	virtual std::string getName()=0;
	virtual double volume()=0;
};

class Can :public Vessel{
public:
	Can(double, double, std::string);
	double volume();
	std::string getName();
private:
	std::string name;
	double diameter;
	double height;
};

class Box :public Vessel{
	friend class Carton;
	friend class ToughPack;
public:
	Box();
	Box(double, double, double, std::string);
	double volume();
	std::string getName();
private:
	std::string name;
	double height;
	double length;
	double breadth;
};

class Carton :public Box{ //inheritance Box and Vessel
public:
	Carton(double,double,double,std::string);
	double volume();
};

class ToughPack:public Box{
public:
	ToughPack(double, double, double, std::string);
	double volume();
};


#endif