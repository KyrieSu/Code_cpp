/*  This program is just executed correctly under linux  */
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std ;

int main(){
	string s ;
	cin >> s ;

	fstream fout;
	fout.open("temp.cpp", ios::out) ;
	fout << "#include<iostream>\n" ;
	fout << "using namespace std;\n" ;
	fout << "int main(){\n" ;
	fout << "cout << (" << s << ") << endl ;\n" ;
	fout << "return 0 ;\n" ;
	fout << "}\n" ;
	fout.close() ;

	system("g++ temp.cpp -o temp.out") ;
	system("./temp.out") ;
	system("rm temp.cpp") ;
	system("rm temp.out") ;
}
