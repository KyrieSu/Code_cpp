#include<iostream>
#include"s1031434_EnigmaBase.h"
using namespace std;

int main(){
	Enigma_Files wheel_start_file;
	Enigma_Files wheel_arrow_file;
	Enigma_Files original_message_file;
	Enigma_Files encoded_message_file;

	cout << "Read original message:¡@\"original_data.txt\"" << endl;
	original_message_file.Read_file("original_data.txt");


	cout << "Read arrows position of [Rotor]: \"wheel_web_arrow.txt\"" << endl;
	wheel_arrow_file.Read_file("wheel_web_arrow.txt");
	char wheel_0_arrows = wheel_arrow_file[0];
	char wheel_1_arrows = wheel_arrow_file[1];
	char wheel_2_arrows = wheel_arrow_file[2];

	cout << "Read start position of [Rotor]: \"wheel_web_start.txt\"" << endl;
	wheel_start_file.Read_file("wheel_web_start.txt");

	cout << "Read [Plugboard]: \"plugboard_web.txt\"" << endl;
	cout << "Read [Rotor III]: \"wheel_web_0.txt\"" << endl;
	cout << "Read [Rotor II]: \"wheel_web_1.txt\"" << endl;
	cout << "Read [Rotor I]: \"wheel_web_2.txt\"" << endl;
	cout << "Read [Reflector]: \"reflector_web.txt\"" << endl;


	system("PAUSE");
	return 0;
}