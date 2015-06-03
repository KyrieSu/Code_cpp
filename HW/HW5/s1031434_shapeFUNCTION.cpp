#include"s1031434_shape.h"
#include"s1031434_main.h"
#include<iostream>
#include<vector>
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
	cout << "(" << x << "," << y << ")";
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
	for (size_t i = 0; i < V.size(); i++)
		V[i].print();
}
	/* Triangle Function */
Triangle::Triangle(){
	
}



}