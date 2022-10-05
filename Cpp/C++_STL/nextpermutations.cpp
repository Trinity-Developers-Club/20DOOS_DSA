#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {10, 20, 30 , 40, 50};
    int n = sizeof(a)/sizeof(int);
    //rotating of array
    rotate(a, a+2, a+n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    vector<int> v{10, 20, 30, 40, 50};
    rotate(v.begin(), v.begin()+3, v.end());
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    //next_permutation
    next_permutation(v.begin(), v.end());
    cout<<endl;

    for(int x: v)
        cout<<x<<" ";
    return 0;
}