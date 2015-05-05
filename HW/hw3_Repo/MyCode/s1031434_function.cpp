#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<map>
#include"s1031434_EnigmaBase.h"
using namespace std;

/* Enigma_File FUNCTION */

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

void Enigma_Component::Read_table(string str){

}

void Enigma_Component::Link(Enigma_Component& link){
	this->next = &link;
	link.previos = this;
}