#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"s1031434_EnigmaBase.h"
using namespace std;

/* Enigma_File FUNCTION */

void Enigma_Files::Read_file(string file){
	ifstream readfile(file, ios::in);
	if (!readfile) cout << file << " can't be open" << endl;
	while (getline(readfile, this->str));
}

void Enigma_Files::Write_file(string file){
	ofstream writefile(file.c_str(), ios::out | ios::trunc);
	if (!writefile) cout << file << " can't be open" << endl;
	while (writefile << this->str);
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

void Enigma_Component::Link(Enigma_Component& next){
	this->next = &next;
	next.previos = this;
}