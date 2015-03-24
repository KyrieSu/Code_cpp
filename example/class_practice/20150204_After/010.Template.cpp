#include<iostream>
using namespace std ;

template <class T>
class Num{
    public:
        Num(T value) ;
        T getVal() ;
    private:
        T m_value ;
};

int main(){
    Num<int> a(5) ;
    cout << a.getVal() << endl ;
}

/* Member Function */

template <class T>
Num<T>::Num(T value){
    m_value = value ;
}

template <class T>
T Num<T>::getVal(){
   return m_value ;
}
