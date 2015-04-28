#ifndef s1031434_Point_h
#define s1031434_Point_h

class Point{
public:
	Point();
	friend class Figure ;
	friend class Line ;
	friend class Rectangle ;
private:
	int x, y;
};

class Figure{
public:
	int area();
};

class Line :public Figure{
public:
	Line(int=0, int=0,int=0,int=0);
private:
	Point A;
	Point B;
};

class Rectangle :public Figure{
public:
	Rectangle(int = 0, int = 0, int = 0, int = 0);
private:
	Point A;
	Point B;
};




#endif
