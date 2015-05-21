#include"1031434_Vector.h"
#include<iostream>
#include<algorithm>
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
		ptr = new int(0);
	}
}

Vector::Vector(int* first, int* last){
	size = last - first;
	capacity = size >= 10 ? size : 10;
	int *data = new int[size];
	delete[]ptr;
	for (int* pointer = first, i = 0; pointer != last; pointer++, i++)
		data[i] = *pointer;
	data[size - 1] = *last;
	ptr = data;
}

Vector::Vector(const Vector& vec){
	size = vec.size;
	ptr = new int[size];
	for (int i = 0; i<size; i++)
		ptr[i] = vec.ptr[i];
}

Vector::~Vector(){  }

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
	if (ptr == NULL){
		size = 0;
		capacity = n;
		return;
	}
	int *buffer = new int[n];
	for (int i = 0; i < size; i++)
		buffer[i] = ptr[i];
	delete[]ptr;
	ptr=buffer;
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
	if (size >= capacity)
		reserve(capacity + 5);
	ptr[size++] = value;
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
	size = last-first;
	int *data = new int[size];
	delete[]ptr;
	for (int i = 0; i < size; i++)
		data[i] = *(first + i);
	ptr = data;
}

void Vector::insert(int *pos, int* first, int* last){
	if (size >= capacity)
		reserve(size + (last - first));
	int location = pos - begin();
	int length = last - first +1;
	int timer = size - length;
	size += length;
	for (int i = size - 1, j = 0; j < timer; i--, j++)
		ptr[i] = ptr[i - length];
	for (int i = 0; i < length; i++)
		ptr[i + length] = first[i];
}

void Vector::erase(int* first, int* last){
	int length = last - first;
	for (int*pointer = first, j = 0; j < length; pointer++, j++)
		*pointer = *(pointer + length);
	size -= length;
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