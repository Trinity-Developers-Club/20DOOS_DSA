#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> d{1, 2, 3, 10, 14};
    //push_back() function helps in the pushing of element into the vector
    d.push_back(20);
    for(auto i: d)
        cout<<i<<",";
    cout<<endl;

    //push_back() function helps in the poping of the last element into the vector
    d.pop_back();
    for(auto i: d)
        cout<<i<<",";
    cout<<endl;

    //insert()
    d.insert(d.begin()+3, 100);
    for(auto i: d)
        cout<<i<<",";
    cout<<endl;

    //inserting range of the values
    d.insert(d.begin()+3,4, 100);
    for(auto i: d)
        cout<<i<<",";
    cout<<endl;

    //erase function
    d.erase(d.begin()+2);
    for(int i: d)
        cout<<i<<",";
    cout<<endl;

    d.erase(d.begin()+2, d.begin()+5);
    for(int i: d)
        cout<<i<<",";
    cout<<endl;

    d.resize(8);        //if the size is increasing then more memory will be allocated
    cout<<d.capacity()<<endl;

    d.clear();      //will not delete the memory occupied by the vector
    cout<<d.size()<<endl;

    if(d.empty())
        cout<<"Vector is Empty"<<endl;

    cout<<d.size()<<endl;    

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;


    //reserve()
    int n;
    cin>>n;
    vector<int> v;
    v.reserve(1000);
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        v.push_back(no);
        cout<<"capacity: "<<v.capacity();
    }
    cout<<endl;
    for(int x: v)
        cout<<x<<",";

    return 0;
}