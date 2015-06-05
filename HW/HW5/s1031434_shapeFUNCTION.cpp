#include"s1031434_shape.h"
#include"s1031434_main.h"
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


namespace MIME{
	/* Vectex Function */
Vertex::Vertex(){
	x = 0.0f;
	y = 0.0f;
}
Vertex::Vertex(const float inX, const float inY){
	x = inX;
	y = inY;
}
void Vertex::print(){
	cout << "(" << x << "," << y << ")" << endl;
}
	/* shape Function */
shape::shape(){
	currentType = ShapeType::Shape;
}

size_t shape::addVertex(const float inX, const float inY){
	V.push_back(Vertex(inX, inY));
	return V.size();
}

size_t shape::addVertex(Vertex& inV){
	V.push_back(inV);
	return V.size();
}

ShapeType shape::getShape(){
	return currentType;
}

void shape::print(){
	cout << "TYPE: " << ShapeName[currentType] << endl;
	for (size_t i = 0; i < V.size(); i++)
		V[i].print();
}
	/* Triangle Function */
Triangle::Triangle(){
	currentType = ShapeType::Triangle;
}

float Triangle::area(){
	/*float pointA_X = V[0].x;	float pointA_Y = V[0].y;
	float pointB_X = V[1].x;	float pointB_Y = V[1].y;
	float pointC_X = V[2].x;	float pointC_Y = V[2].y;*/
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float s = (A_B + A_C + B_C) / 2;
	return sqrt(s*(s - A_B)*(s - A_C)*(s - B_C));
}

bool Triangle::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	return ((A_B + A_C > B_C) && (A_B + B_C > A_C) && (B_C + A_C > A_B));
}

	/* Quadrilateral Function */
Quadrilateral::Quadrilateral(){
	currentType = ShapeType::Quadrilateral;
}
float Quadrilateral::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float s = (A_B + A_C + B_C) / 2;
	return sqrt(s*(s - A_B)*(s - A_C)*(s - B_C)) * 2; // 2 triangle
}

bool Quadrilateral::Valid(){
	return V.size() == 4;
}

	/* Pentagon Function */
Pentagon::Pentagon(){
	currentType = ShapeType::Pentagon;
}
float Pentagon::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float C_D = sqrt(pow((V[3].x - V[2].x), 2) + pow((V[3].y - V[2].y), 2));
	float A_D = sqrt(pow((V[3].x - V[0].x), 2) + pow((V[3].y - V[0].y), 2));
	float A_E = sqrt(pow((V[4].x - V[0].x), 2) + pow((V[4].y - V[0].y), 2));
	float D_E = sqrt(pow((V[4].x - V[3].x), 2) + pow((V[4].y - V[3].y), 2));
	float s = (A_B + A_C + B_C) / 2;
	float A = 0;
	A += sqrt(s*(s - A_B)*(s - A_C)*(s - B_C));
	s = (A_C + A_D + C_D) / 2;
	A += sqrt(s*(s - A_C)*(s - A_D)*(s - C_D));
	s = (A_D + D_E + A_E) / 2;
	A += sqrt(s*(s - A_D)*(s - D_E)*(s - A_E));
	return A;
}

bool Pentagon::Valid(){
	return V.size() == 5;
}
	/* Parallelogram Function  */
Parallelogram::Parallelogram(){
	currentType = ShapeType::Parallelogram;
}

bool Parallelogram::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float C_D = sqrt(pow((V[3].x - V[2].x), 2) + pow((V[3].y - V[2].y), 2));
	float D_A = sqrt(pow((V[3].x - V[0].x), 2) + pow((V[3].y - V[0].y), 2));
	bool status = (A_B - C_D < 0.00001) && (B_C - D_A < 0.00001); // top == bottom && left == right
	return status && (A_B != B_C); //if A_B == B_C -> Square
}

	/* Square Function */
Square::Square(){
	currentType == ShapeType::Square;
}

float Square::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	return A_B * B_C;
}

bool Square::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float C_D = sqrt(pow((V[3].x - V[2].x), 2) + pow((V[3].y - V[2].y), 2));
	float D_A = sqrt(pow((V[3].x - V[0].x), 2) + pow((V[3].y - V[0].y), 2));
	bool status = (A_B - C_D < 0.00001) && (B_C - D_A < 0.00001); // top == bottom && left == right
	return status && (A_B == B_C); //if A_B == B_C -> Square
}

	/* Trapezium Function */

Trapezium::Trapezium(){
	currentType = ShapeType::Trapezium;
}

float Trapezium::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));	
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float C_D = sqrt(pow((V[3].x - V[2].x), 2) + pow((V[3].y - V[2].y), 2));
	float A_D = sqrt(pow((V[3].x - V[0].x), 2) + pow((V[3].y - V[0].y), 2));
	float s = (A_B + A_C + B_C) / 2;
	float A = 0;
	A += sqrt(s*(s - A_B)*(s - A_C)*(s - B_C));
	s = (A_C + C_D + A_D) / 2;
	A += sqrt(s*(s - A_C)*(s - C_D)*(s - A_D));
	return A;
}

bool Trapezium::Valid(){
	float A_D = sqrt(pow((V[3].x - V[0].x), 2) + pow((V[3].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float C_D = sqrt(pow((V[3].x - V[2].x), 2) + pow((V[3].y - V[2].y), 2));
	
	return (A_B != C_D) && (A_D == B_C);
}

	/*	Isosceles_triangle Function */
Isosceles_triangle::Isosceles_triangle(){
	currentType = ShapeType::Isosceles_triangle;
}

bool Isosceles_triangle::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	
	return (A_B == A_C) || (A_C == A_B) || (A_B == B_C);
}

	/* Regular_triangle Function */
Regular_triangle::Regular_triangle(){
	currentType = ShapeType::Regular_triangle;
}

float Regular_triangle::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float hight = (A_B*1.73205) / 2;
	return (A_B*hight) / 2;
}

bool Regular_triangle::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	return (A_B == A_C == B_C);
}

	/* Right_triangle FUNCTION */

Right_triangle::Right_triangle(){
	currentType = ShapeType::Right_triangle;
}

float  Right_triangle::area(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	vector<float> ary(3);
	ary[0] = A_B; ary[1] = A_C; ary[2] = B_C;
	sort(ary.begin(), ary.end()); //mini in [0]

	return ary[0] * ary[1] * 0.5;
}

bool Right_triangle::Valid(){
	float A_B = sqrt(pow((V[1].x - V[0].x), 2) + pow((V[1].y - V[0].y), 2));
	float A_C = sqrt(pow((V[2].x - V[0].x), 2) + pow((V[2].y - V[0].y), 2));
	float B_C = sqrt(pow((V[2].x - V[1].x), 2) + pow((V[2].y - V[1].y), 2));
	vector<float> ary(3);
	ary[0] = A_B; ary[1] = A_C; ary[2] = B_C;
	sort(ary.begin(), ary.end()); //mini in [0]

	return pow(ary[0], 2) + pow(ary[1], 2) - pow(ary[2], 2) > 0.00001;
}







}