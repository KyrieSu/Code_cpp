#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include"s1031434_shape.h"
#include"s1031434_main.h"
using namespace std;

vector<MIME::shape*> data;

int loadshape(string file){
	ifstream readfile(file, ios::in);
	if (!readfile){
		readfile.close();
		cout << "*Note: File can't be open !" << endl;
		exit(1);
	}
	int num = 0;//to count the number of shape
	for (int n = 0; !readfile.eof();){
		readfile >> n;
		float myX, myY;
		switch ((ShapeType)n){
		case Shape:
			cout << "[LOADER] invalde abstract type: Shape" << endl;
			return num;
		case Triangle:
			cout << "[LOADER] add : Triangle" << endl;
			data.push_back(new MIME::Triangle());
			for (int i = 0; i < 3; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}			
			num++;
			break;
		case Quadrilateral:
			cout << "[LOADER] add : Quadrilateral" << endl;
			data.push_back(new MIME::Quadrilateral());
			for (int i = 0; i < 4; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Pentagon:break;
			cout << "[LOADER] add : Pentagon" << endl;
			data.push_back(new MIME::Pentagon());
			for (int i = 0; i < 5; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Parallelogram:
			cout << "[LOADER] add : Parallelogram" << endl;
			data.push_back(new MIME::Parallelogram());
			for (int i = 0; i < 4; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Square:
			cout << "[LOADER] add : Square" << endl;
			data.push_back(new MIME::Square());
			for (int i = 0; i < 4; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Trapezium:
			cout << "[LOADER] add : Trapezium" << endl;
			data.push_back(new MIME::Trapezium());
			for (int i = 0; i < 4; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Isosceles_triangle:
			cout << "[LOADER] add : Isosceles_triangle" << endl;
			data.push_back(new MIME::Isosceles_triangle());
			for (int i = 0; i < 3; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Regular_triangle:
			cout << "[LOADER] add : Regular_triangle" << endl;
			data.push_back(new MIME::Regular_triangle());
			for (int i = 0; i < 3; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		case Right_triangle:
			cout << "[LOADER] add : Right_triangle" << endl;
			data.push_back(new MIME::Right_triangle());
			for (int i = 0; i < 3; i++){
				readfile >> myX >> myY;
				(data.back())->addVertex(myX, myY);
			}
			num++;
			break;
		/*case Polygon:
			cout << "[LOADER] add : Right_triangle" << endl; 
			data.push_back(new MIME::Polygon());
			/* input information into Polygon */
			//break;
		}//end switch

	}//end for-loop

	return num;
}


int main()
{
	int NUMofSHAPE = loadshape("test_shape.txt");
	cout << "# of shapes = " << NUMofSHAPE << endl;

	for each (MIME::shape* ptr in data){
		ptr->print();
		cout << "AREA: " << ptr->area() << endl;
		cout << "Valid ? : " << (ptr->Valid() ? "YES" : "NO") << endl;
		//cout << "Convex ? : " << (ptr->Convex() ? "YES" : "NO") << endl << endl; -> §PÂ_¥W¥Y
	}
	for each (MIME::shape* ptr in data)
		delete ptr;

	system("PAUSE");
	return 0;
}