#ifndef EnignaBase_h
#define EnigmaBase_h

#include<string>

class Enigma_File{
public:
	void Read_File(std::string);
	void Write_file(std::string);
	void Push(const char&); //push a character on the tail(end) of string
	char const& operator [] (size_t const&);//get specific character
	std::string Data(); //get data
	size_t length();
private:
	std::string str;
};

class Enigma_Component{
public:
	void Link(Enigma_Component&);
protected:
	Enigma_Component *previos;
	Enigma_Component *next;
	virtual size_t Encoding(size_t const&) = 0;
	void Read_table(std::string file);
	virtual void Spin() {}
};




#endif