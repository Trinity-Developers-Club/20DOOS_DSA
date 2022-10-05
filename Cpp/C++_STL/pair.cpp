#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, char> p;
    p.first = 10;
    p.second = 'A';

    cout<<p.first<<" "<<p.second<<endl;

    pair<int, char> p2(p);
    cout<<p2.first<<" "<<p2.second<<endl;
    
    int a, b;
    cin>>a>>b;
    pair<int, int> p3 = make_pair(a,b);
    p3.first = a;
    p3.second = b;
    cout<<p3.first<<" "<<p3.second<<endl;

    pair<pair<int,int>, string> car;
    car.first.first = 10;
    car.first.second =20;
    car.second = "Audi";

    cout<<car.first.first<<" "<<car.first.second<<endl;
    return 0;
}