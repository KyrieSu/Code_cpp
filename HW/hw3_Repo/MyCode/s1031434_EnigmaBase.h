#ifndef EnignaBase_h
#define EnigmaBase_h

#include<string>
#include<map>


class Plugboard;
class Wheel;
class Special_Wheel;
class Reflector;


class Enigma_Files{
public:
	Enigma_Files(){}
	void Read_file(std::string);
	void Write_file(std::string);
	void Push(const char&); //push a character on the tail(end) of string
	char const& operator [] (const size_t);//get specific character
	std::string Data(); //get data
	size_t Length();
private:
	std::string str;
};

class Enigma_Component{
	friend class Plugboard;
	friend class Wheel;
	friend class Special_Wheel;
	friend class Reflector;
public:
	Enigma_Component();
	char Input_signal(char);//Input a character and return a encoded one (use this function to invoke "Encoding" function)
	void Link(Enigma_Component&);
protected:
	std::string data;
	Enigma_Component *previous;
	Enigma_Component *next;
	virtual size_t Encoding(size_t const&) = 0;
	void Read_table(std::string);//Read a mapping table from file to setup current component (It should be overrided by derived classes)
	virtual void spin() {}//Spin current component (It should be overrided by derived classes)
};




#endif