#ifndef Point_h
#define Point_h

class Point{
public:
	Point();
	Point(int, int, int);
	Point operator++();
	Point operator+(Point);
	Point operator-(Point);
	void print();
private:
	int my_x;
	int my_y;
	int my_z;
};

#endif