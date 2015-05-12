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
	start = 'A';
}

size_t Plugboard::Encoding(const size_t index){
	next->spin();
	return this->next->Encoding(next->start);
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
	key = arrow;
}

size_t Wheel::Encoding(const size_t index){
	if (!timer){
		timer = 1;
		char add_code = this->data[index - 65];

	}
	if (timer){
		timer = 0;
	}
}

void Wheel::spin(){
	start++;
	start = start > 90 ? start - 26 /* 90 - 65 - 1 */: start;
	if (start == key)
		this->next->spin();
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
	}
	if (timer){
		timer = 0;
	}
}

void Special_Wheel::spin(){
	start++;
	start = start > 90 ? start - 26 /* 90 - 65 - 1 */ : start;
	if (start == key)
		this->next->spin();
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
	
}



