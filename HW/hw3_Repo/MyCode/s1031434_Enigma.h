#ifndef _Enigma_Wheel_H
#define _Enigma_wheel_H

#include"s1031434_EnigmaBase.h"
#include<string>

class Plugboard :public Enigma_Component{
public:
	Plugboard(std::string);
	size_t Encoding(const size_t);
	static bool direction;
};

class Wheel :public Enigma_Component{ //Roter I and Roter III
public:
	Wheel();
	Wheel(std::string,char,char);
	size_t Encoding(const size_t);
	void spin();
private:
	char start; 
	char key;//to check spin()
};

class Special_Wheel : public Wheel{
public:
	Special_Wheel(std::string, char, char);
	size_t Encoding(const size_t);
	void spin();
private:
	char start;
	char key;
};

class Reflector : public Enigma_Component{
public:
	Reflector(std::string);
	size_t Encoding(const size_t);
};

#endif