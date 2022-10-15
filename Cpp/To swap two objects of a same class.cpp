#include <iostream>
using namespace std;
class y;
class x{
    int num;
    public: 
    x(){
        cout<<"Enter a number: ";
        cin>>num;
    }
    friend void swap(x &,y &);
};
class y{
    int data;
    public:
    y(){
        cout<<"Enter a number: ";
        cin>>data;
    }
    friend void swap(x &,y &);
};
void swap(x &o1,y &o2){
    int temp;
    temp=o1.num;
    o1.num=o2.data;
    o2.data=temp;
    cout<<"Objects after swapping are "<<o1.num<<" and "<<o2.data;
}

int main(){
    x x1;
    y y1;
    swap(x1,y1);
}
