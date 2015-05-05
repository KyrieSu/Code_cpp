#ifndef EnignaBase_h
#define EnigmaBase_h

#include<string>
#include<map>


class Plugboard;
class wheel;
class Special_wheel;
class Reflector;


class Enigma_Files{
public:
	Enigma_Files();
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
public:
	Enigma_Component();
	char Input_signal(char);//Input a character and return a encoded one (use this function to invoke "Encoding" function)
	void Link(Enigma_Component&);
	static int changeASCII(char);
protected:
	Enigma_Component *previos;
	Enigma_Component *next;
	virtual size_t Encoding(size_t const&) = 0;
	void Read_table(std::string);//Read a mapping table from file to setup current component (It should be overrided by derived classes)
	virtual void Spin() {}//Spin current component (It should be overrided by derived classes)
};




#endif