#pragma once

#include "Enigma_Base.h"

//a derived class for plugboard
class Plugboard : public Enigma_Component
{
	//...
} ;

//a derived class for the ordinary wheel (Rotor I and III)
class Wheel : public Enigma_Component
{
	//...
} ;

//a derived class for the special version of wheel (Rotor II)
class Special_Wheel : public Wheel
{
	//...
} ;

//a derived class for reflector
class Reflector : public Enigma_Component
{
	//...
} ;