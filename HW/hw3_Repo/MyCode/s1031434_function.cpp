#include<iostream>
#include<fstream>
#include<string>
#include"s1031434_EnigmaBase.h"
using namespace std;

/* Enigma_File FUNCTION */

void Enigma_File::Read_File(string file){
	ifstream readfile(file, ios::in);
	if (!readfile) cout << file << "can't be open" << endl;
	while (getline(readfile, this->str));
}

void Enigma_File::Write_file(string file){
	ofstream writefile(file, ios::out || ios::trunc);
	if (!writefile) cout << file << "can't be open" << endl;
	while (writefile << this->str);
}

const char& Enigma_File::operator [](size_t const&i){
	return this->str[i];
}

string Enigma_File::Data(){
	return str;
}

size_t Enigma_File::length(){
	return this->str.size();
}