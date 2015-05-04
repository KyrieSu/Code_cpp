#include"_s1031434_Box.h"
#include<cmath>
#include<string>
using namespace std;


Can::Can(double x, double y, string str){
	diameter = x;
	height = y;
	name = str;
}

double Can::volume(){
	return pow(diameter / 2, 2)*PI*height;
}

string Can::getName(){
	return name;
}

Box::Box(){}

Box::Box(double x, double y, double z, string str){
	height = x;
	length = y;
	breadth = z;
	name = str;
}

double Box::volume(){
	return height*length*breadth;
}

string Box::getName(){
	return name;
}


Carton::Carton(double x, double y, double z, string str){
	height = x;
	length = y;
	breadth = z;
	name = str;
}

double Carton::volume(){
	return (length - 0.5)*(breadth - 0.5)*(height - 0.5);
}


ToughPack::ToughPack(double x, double y, double z, string str){
	height = x;
	length = y;
	breadth = z;
	name = str;
}

double ToughPack::volume(){
	return 0.85*length*breadth*height;
}