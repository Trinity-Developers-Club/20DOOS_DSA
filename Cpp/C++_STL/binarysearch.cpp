#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {20, 30, 40, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;
    bool present= binary_search(arr, arr+n, key);
    if(present)
        cout<<"Present";
    else
        cout<<"Absent";

    //two methods of the binary search
    //lower_bound() - returns iterator of first occurance of element.
    //upper_bound() - returns iterator of last occurance of element.

    //lower_bound()
    auto lb = lower_bound(arr, arr+n, 40);
    cout<<"\nLower bound of 40 is : "<<lb-arr;

    //upper_bound()
    auto ub = upper_bound(arr, arr+n, 40);
    cout<<"\nUpper bound of 40 is : "<<ub-arr;

    cout<<"\nFrequency of 40 is: "<<ub-lb;

    return 0;
}