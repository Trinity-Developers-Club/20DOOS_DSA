#include<bits/stdc++.h>
using namespace std;

int main(){
    int a =10;
    int b = 20;

    swap(a,b);
    cout<<"a = "<< a <<",b = "<<b<<endl;

    cout<<min(a, b)<<endl;
    cout<<max(a, b)<<endl;  

    int arr[] = {1 , 2 , 3, 4, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    next_permutation(arr, arr+n);
    next_permutation(arr, arr+n);
    for(int i =0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}