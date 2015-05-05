#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"s1031434_EnigmaBase.h"
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

int Enigma_Component::changeASCII(char c){ //reset ASCII A=1 ~ Z=26
	/* 65~90 -> A~Z
	   97~122-> a~z  */
	return int(c) - 64;
}


char Enigma_Component::Input_signal(char c){
	return c;
}

void Enigma_Component::Read_table(string file_name){
	string file_data;
	ifstream readfile(file_name.c_str(), ios::in);
	if (!readfile) cout << file_name << " can't be open" << endl;
	getline(readfile,file_data);
}

void Enigma_Component::Link(Enigma_Component& link){
	this->next = &link;
	link.previos = this;
}