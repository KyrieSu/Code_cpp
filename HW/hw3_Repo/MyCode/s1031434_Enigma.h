#ifndef _Enigma_Wheel_H
#define _Enigma_wheel_H

#include"s1031434_EnigmaBase.h"
#include<string>

class Plugboard :public Enigma_Component{
public:
	Plugboard(std::string);
	size_t Encoding(size_t const&);
private:
	std::string data;
};

class Wheel :public Enigma_Component{ //Roter I and Roter III
public:
	Wheel();
	Wheel(std::string,char,char);
	size_t Encoding(size_t const&);
	void spin();
private:
	std::string data;
	char start; 
	char key;//to check spin()
};

class Special_Wheel : public Wheel{
public:
	Special_Wheel(std::string, char, char);
private:
	std::string data;
	char start;
	char key;
};

class Reflector : public Enigma_Component{
public:
	Reflector(std::string);
	size_t Encoding(size_t const&);
	void spin();
private:
	std::string data;
};

#endif