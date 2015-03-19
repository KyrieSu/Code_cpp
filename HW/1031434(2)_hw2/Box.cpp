#include<iostream>
#include<string>
#include<cstring>
#include"Box.h"
using namespace std;

Ball::Ball(){
	length=width=height = 0;
	myname="noname ball";
	cout << "Box constructor called" << endl;
};

Ball::Ball(double x,double y,double z, string name){
	length = x;
	width = y;
	height = z;
	myname = name;
	cout << "Box constructor called" << endl;
}

Ball::~Ball() { cout << "Box deconstructor called" << endl; }

string Ball::name(){
	return myname;
}

double Ball::volume(){
	return length*width*height;
}

int Ball::compare(Ball becmp){
	return this->volume() > becmp.volume() ? 1 : 0;
}