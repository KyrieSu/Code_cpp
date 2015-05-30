#ifndef PG2_1434HW5
#define PG2_1434HW5

class Point{
	friend class Vector;
public:
	Point(int = 0, int = 0);
private:
	double my_X;
	double my_Y;
};

class Vector:public Point{
public:
	Vector();
	Vector(Point&, Point&);
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	static double cross(Vector&, Vector&);
	static double dot(Vector&, Vector&);
private:
	Point Q;
};

#endif