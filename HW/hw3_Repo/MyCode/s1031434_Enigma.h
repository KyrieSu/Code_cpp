#ifndef _Enigma_Wheel_H
#define _Enigma_wheel_H

#include<string>

class Plugboard :public Enigma_Component{
public:
	Plugboard(std::string);
	size_t Encoding(const size_t);
};

class Wheel :public Enigma_Component{ //Roter I and Roter III
public:
	Wheel();
	Wheel(std::string,char,char);
	size_t Encoding(const size_t);
	void spin();
protected:
	char now;
	int timer;
};

class Special_Wheel : public Wheel{
public:
	Special_Wheel(std::string, char, char);
	size_t Encoding(const size_t);
	void spin();
};

class Reflector : public Enigma_Component{
public:
	Reflector(std::string);
	size_t Encoding(const size_t);
};


#endif