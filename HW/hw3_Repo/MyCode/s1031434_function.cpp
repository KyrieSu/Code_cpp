#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"s1031434_EnigmaBase.h"
#include"s1031434_Enigma.h"
using namespace std;

/* Enigma_File FUNCTION */

Enigma_Files::Enigma_Files(){}

void Enigma_Files::Read_file(string file_name){
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be open" << endl;
	getline(readfile,this->str);
}

void Enigma_Files::Write_file(string file_name){
	ofstream writefile(file_name.c_str(), ios::out | ios::trunc);
	if (!writefile) cout << file_name << " can't be open" << endl;
	writefile << this->str;
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
	this->previos = NULL;
	this->next = NULL;
}

char Enigma_Component::Input_signal(char c){
}

void Enigma_Component::Read_table(string file_name){
}

void Enigma_Component::Link(Enigma_Component& link){
	this->next = &link;
	link.previos = this;
}

/* Plugboard FUNCTION */

Plugboard::Plugboard(string file_name){
	ifstream readfile(file_name, ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
}

size_t Plugboard::Encoding(size_t const& index){

}

/* Wheel FUNCTION */

Wheel::Wheel(string file_name,char begin,char arrow){
	ifstream readfile(file_name, ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);

	start = begin;
	key = arrow;
}

/* Reflector FUNCTION */

Reflector::Reflector(string file_name){
	ifstream readfile(file_name, ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);
}

size_t Reflector::Encoding(size_t const& index){
}

/* Special_Wheel FUNCTION */

Special_Wheel::Special_Wheel(string file_name, char begin, char arrow){
	ifstream readfile(file_name, ios::in);
	if (!readfile) cout << file_name << " can't be opened!" << endl;
	getline(readfile, data);

	start = begin;
	key = arrow;
}



