#ifndef EnignaBase_h
#define EnigmaBase_h

#include<string>

class Enigma_Files{
public:
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
	char Input_signal(char);
	void Link(Enigma_Component&);
protected:
	Enigma_Component *previos;
	Enigma_Component *next;
	virtual size_t Encoding(size_t const&) = 0;
	void Read_table(std::string);
	virtual void Spin() {}
};




#endif