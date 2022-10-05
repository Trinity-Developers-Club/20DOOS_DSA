#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;
    auto it = find(arr, arr+n, key);
    if(it != arr+n){
        cout<<it;
        cout<<"\n"<<*it;
        cout<<"\nIndex of "<<key<<" is: "<<it-arr;
    }
    else{
        cout<<"Element not found!";
    }
}