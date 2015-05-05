#ifndef _Enigma_Wheel_H
#define _Enigma_wheel_H

#include"s1031434_EnigmaBase.h"
#include<string>

class Plugboard :public Enigma_Component{
public:
	Plugboard(std::string);
	size_t Encoding(size_t const&);
};



#endif