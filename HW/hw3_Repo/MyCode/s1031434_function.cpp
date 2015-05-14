#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include"s1031434_EnigmaBase.h"
#include"s1031434_Enigma.h"
using namespace std;

/* Enigma_File FUNCTION */

void Enigma_Files::Read_file(string file_name){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be open" << endl;
	getline(readfile,this->str);
	readfile.close();
}

void Enigma_Files::Write_file(string file_name){
	ofstream writefile(file_name.c_str(), ios::out | ios::trunc);
	if (!writefile) cout << file_name << " can't be open" << endl;
	writefile << this->str;
	writefile.close();
}

void Enigma_Files::Push(const char& c){
	str += c;
}

const char& Enigma_Files::operator [](const size_t i){
	return this->str[i];
}

string Enigma_Files::Data(){
	return str;
}

size_t Enigma_Files::Length(){
	return this->str.size();
}

/* Enigma_Component FUNCTION */


Enigma_Component::Enigma_Component(){
	this->previous = NULL;
	this->next = NULL;
}

char Enigma_Component::Input_signal(char c){
	return this->Encoding(c);
}

void Enigma_Component::Link(Enigma_Component& link){
	this->next = &link;
	link.previous = this;
}

/* Plugboard FUNCTION */

Plugboard::Plugboard(string file_name){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
	readfile.close();

	timer = 0;
	start = 'A';
}

size_t Plugboard::Encoding(const size_t index){//89
	if (!timer){
		timer = 1;
		next->spin();
		char en_code = data[index - 65];
		//cout << en_code <<"Plugboard#1"<< endl;
		size_t pos = en_code - start;
		//cout << pos << "plugboard#pos" << endl;
		return this->next->Encoding(pos);
	}
	if (timer){
		timer = 0;
		char back_code = start + index;
		if (back_code > 90) back_code -= 26;
		size_t location = data.find(back_code) + 65;
		size_t pos = 0;
		if (location > this->start)
			pos = location - this->start;
		else
			pos = this->start - location;
		if (this->start > location) pos = 26 - pos;
		return pos + 65;
	}	
}

/* Wheel FUNCTION */

Wheel::Wheel(){}

Wheel::Wheel(string file_name,char begin,char arrow){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
	readfile.close();

	timer = 0;
	start = begin;
	now = begin;
	key = arrow;
}

size_t Wheel::Encoding(const size_t index){
	if (!timer){
		timer = 1;
		size_t pos = this->start + index;
		if (pos > 90) pos -= 26;
		//cout << pos << "Wheel#pos" << endl;
		char add_code = data[pos - 65];
		//cout << add_code << "Wheel#1" << endl;
		size_t D = 0;
		if (add_code > this->start)
			D = add_code - this->start;
		else
			D = this->start - add_code;
		if (this->start > add_code)	D = 26 - D;
		return 	next->Encoding(D);
	}
	if (timer){
		timer = 0;
		char back_code = start + index;
		if (back_code > 90) back_code -= 26;
		size_t location = data.find(back_code) + 65;
		//cout << (char)location << "Wheel#2" << endl;
		size_t pos = 0;
		if (location > this->start)
			pos = location - this->start;
		else
			pos = this->start - location;
		if (this->start > location) pos = 26 - pos;
		return previous->Encoding(pos);		
	}
}

void Wheel::spin(){
	start++;
	if (start > 90) start -= 26;
	if (start == key)
		next->spin();	
}

/* Special_Wheel FUNCTION */

Special_Wheel::Special_Wheel(string file_name, char begin, char arrow){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
	readfile.close();

	timer = 0;
	start = begin;
	key = arrow;
}

size_t Special_Wheel::Encoding(const size_t index){
		if (!timer){
			timer = 1;
			size_t pos = this->start + index;
			if (pos > 90) pos -= 26;
			char add_code = data[pos - 65];
			//cout << add_code << "Special#1" << endl;
			size_t D = 0;
			if (add_code > this->start)
				D = add_code - this->start;
			else
				D = this->start - add_code;
			if (this->start > add_code)	D = 26 - D;
			return 	next->Encoding(D);
		}
	if (timer){
		timer = 0;
		char back_code = start + index;
		if (back_code > 90) back_code -= 26;
		size_t location = data.find(back_code) + 65;
		//cout << (char)location << "Special#2" << endl;
		size_t pos = 0;
		if (location > this->start)
			pos = location - this->start;
		else
			pos = this->start - location;
		if (this->start > location) pos = 26 - pos;
		return previous->Encoding(pos);
	}
}

void Special_Wheel::spin(){
	start++;
	if (start > 90) start -= 26;
	if (start == key)
		next->spin();
}

/* Reflector FUNCTION */

Reflector::Reflector(string file_name){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
	readfile.close();

	start = 'A';
}

size_t Reflector::Encoding(const size_t index){
	size_t pos = this->start + index;
	if (pos > 90) pos -= 26;
	char add_code = data[pos - 65];
	//cout << add_code << "Reflector" << endl;
	pos = add_code - start;
	return previous->Encoding(pos);
}