#include<iostream>
using namespace std;

//generic programming in c++ for all data type
//Templates
template<typename T>
int search(T arr[], int n, T k){
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}

int main(){
    int a[] = {1,2,5,10,8,9,7};
    int k = 10;
    cout<<search(a, 7, k)<<endl;

    float b[] = {1.1, 1.2, 1.3};
    float key = 1.3;
    cout<<search(b, 3, key)<<endl;
    return 0;
}
/*
#include <iostream>
using namespace std;

template<class T>
int search(T arr[], int n, T k){
    for(int i = 0; i < n; i++ ){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}
int main() {
    //cout<<"Hello World!";
    int a[] = {1 , 2 , 5, 8, 10, 9};
    int n = sizeof(a)/sizeof(int);
    int key = 10;
    cout<<search(a, n, key)<<endl;

    float b[] = {1.1, 1.2, 1.3};
    float k = 1.2;
    cout<<search(b,3,k)<<endl;
}
*/