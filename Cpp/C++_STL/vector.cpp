#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    vector<int> b(5, 10);
    vector<int> c(b.begin(), b.end());
    vector<int> d{1, 10, 50, 20, 70};

    for(int i = 0 ; i < b.size(); i++)
        cout<<b[i]<<",";
    cout<<endl;
    for(auto it = c.begin(); it != c.end(); it++)
        cout<<*it<<",";
    cout<<endl;
    for(int x: b)       //you can use auto in place of int
        cout<<x<<",";
    cout<<endl;
    //adding element to the end of the vector
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        v.push_back(no);
    }

    for(int i = 0; i < n ; i++)
        cout<<v[i]<<",";
    return 0;
}