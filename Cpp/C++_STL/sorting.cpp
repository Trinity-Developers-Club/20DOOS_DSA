#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    cout<<"Comparing inputs "<<a<<" and "<<b<<endl;
    return a < b;   //for increasing order of the array
    //return a > b;   //for decreasing order of the array
}

int main(){
    int n;
    cin>>n;

    int arr[1000];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    //sorting
    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<",";
    }
    return 0;
}