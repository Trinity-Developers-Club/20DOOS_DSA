#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr)/sizeof(int);
    
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    //iterating over the elements
    for(auto it: s){
        cout<<it<<",";
    }
    cout<<endl;

    s.erase(20);
    auto it = s.find(11);
    s.erase(it);
    //iterating over the limits 
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<",";
    }
    return 0;
}