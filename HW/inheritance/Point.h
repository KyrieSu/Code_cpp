#ifndef s1031434_Point_h
#define s1031434_Point_h

class Point{
	friend class Figure;
	friend class Line;
	friend class Rectangle;
	friend class Triangle;
	friend class Circle;
public:
	Point();
private:
	int x, y;
};

class Figure{
public:
	int area();
	Point A, B, C;
};

class Line :public Figure{
public:
	Line(int=0, int=0,int=0,int=0);
};

class Rectangle :public Figure{
public:
	Rectangle(int = 0, int = 0, int = 0, int = 0);
	int area();
};

class Triangle :public Figure{
public:
	Triangle(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	double area();
};

class Circle :public Figure{
public:
	Circle(int = 0, int = 0, int = 0, int = 0);
	double area();
};



#endif