#include<iostream>
#include<cstdio>
using namespace std ;


namespace twoD{
    class Point{
        public:
            Point(int x, int y){
                this -> x = x ;
                this -> y = y ;
            }
            void print(){
                printf("(%d,%d)\n", x, y) ;
            }
        private:
            int x ;
            int y ;
    } ;
}


namespace threeD{
    class Point{
        public:
            Point(int x, int y){
                this -> x = x ;
                this -> y = y ;
            }
            void print(){
                printf("(%d,%d)\n", x, y) ;
            }
        private:
            int x ;
            int y ;
    } ;
}

using namespace twoD ;
using namespace threeD ;

int main(){

	threeD::Point point1(3, 2) ;
	point1.print() ;
}
