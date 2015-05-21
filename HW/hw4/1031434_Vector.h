#ifndef s1031434_Vector_H
#define s1031434_Vector_H

#include<iostream>

class Vector{
	friend std::ostream& operator<<(std::ostream&, const Vector&);
public:
	Vector(size_t = 0, const int = 0);
	Vector(int*, int*);
	Vector(const Vector&);
	~Vector();
	const Vector& operator=(const Vector&);
	bool operator==(const Vector&) const;
	bool operator!=(const Vector&) const;
	int operator[](size_t)const;
	int& operator[](size_t);
	int* begin();
	int* end();
	size_t getsize() const;
	void resize(size_t, const int = 0);
	size_t getCapacity() const;
	bool empty() const;
	void reserve(size_t);
	void shrink_to_fit();
	int& front();
	int& back();
	void push_back(int);
	void pop_back();
	void assign(int, const int = 0);
	void assign(int*, int*);
	void insert(int*, int*, int*);
	void erase(int*, int*);
	void swap(Vector&);
	void clear();
private:
	size_t size;
	size_t capacity;
	int *ptr;
};

#endif