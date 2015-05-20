#include"1031434_Vector.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& output, const Vector& vec){
	for (int i = 0; i<vec.size; i++)
		output << vec[i] << " ";
	output << endl;
	return output;
}

Vector::Vector(size_t n,const int value){
	if (n > 10){
		ptr = new int[n];
		for (int i = 0; i < n; i++)
			ptr[i] = value;
		size = n;
		capacity = n;
	}
	else if (n > 0){
		ptr = new int[n];
		for (int i = 0; i < n; i++)
			ptr[i] = value;
		size = n;
		capacity = 10;
	}
	else{
		size = 0;
		capacity = 10;
		ptr = new int;
	}
}

Vector::Vector(int first, int last){
	cout << "constructor" << endl;
}

Vector::Vector(const Vector& vec){
	for (int i = 0; i < vec.size; i++)
		this->ptr[i] = vec.ptr[i];
	size = vec.size;
	capacity = vec.capacity;
}

Vector::~Vector(){
	delete [] ptr;
}

const Vector& Vector::operator=(const Vector& vec){
	size = vec.size;
	capacity = vec.capacity;
	int *data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = vec.ptr[i];
	ptr = data;
	return *this;
}

bool Vector::operator==(const Vector& vec)const{
	if (this->size != vec.size)
		return false;
	for (int i = 0; i < vec.size; i++)
		if (this->ptr[i] != vec.ptr[i])
			return false;
	return true;
}

bool Vector::operator!=(const Vector& vec)const{
	return !(*this == vec);
}

int Vector::operator[](size_t index)const{
	return this->ptr[index];
}

int& Vector::operator[](size_t index){
	return this->ptr[index];
}

int* Vector::begin(){
	return ptr;
}

int* Vector::end(){
	return ptr + size;
}

size_t Vector::getsize()const{
	return size;
}

void Vector::resize(size_t n, const int value){
	if (n > size){
		for (int i = 0; i < n - size; i++)
			this->push_back(value);
		size = n;
		capacity = n;
	}
	else{
		for (int i = 0; i < size - n; i++)
			this->pop_back();
		size = n;
		capacity = n;
	}
}

size_t Vector::getCapacity()const{
	return capacity;
}

bool Vector::empty()const{
	return size == 0;
}

void Vector::reserve(size_t n){
	
}

void Vector::shrink_to_fit(){
	capacity = size;
}

int& Vector::front(){
	return ptr[0];
}

int& Vector::back(){
	return ptr[size - 1];
}

void Vector::push_back(int value){
	int *data = new int[size + 1];
	for (int i = 0; i < size; i++)
		data[i] = ptr[i];
	data[size] = value;
	size++;
	ptr = data;
}

void Vector::pop_back(){
	size--;
}

void Vector::assign(int n, const int value){
	size = n;
	capacity = n;
	for (int i = 0; i < n; i++)
		ptr[i] = value;
}

void Vector::assign(int* first, int* last){
	int count = 0;
	for (int *pointer = first, count = 0; pointer != last; pointer++, count++)
		ptr[count] = *pointer;
	size = count;
	capacity = count;
}

void Vector::insert(int *pos, int* first, int* last){
	cout << "insert" << endl;
}

void Vector::erase(int* first, int* last){
	
}



void Vector::swap(Vector& vec){
	int *data = vec.ptr;
	int _size = vec.size;
	int _capacity = vec.capacity;
	/* ====================== */
	vec.ptr = this->ptr;
	this->ptr = data;
	vec.size = this->size;
	this->size = _size;
	vec.capacity = this->capacity;
	this->capacity = _capacity;
}

void Vector::clear(){
	size = 0;
	capacity = 0;
}