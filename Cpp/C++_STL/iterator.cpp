#include<bits/stdc++.h>
//#include<list>
using namespace std;

//template<typename T>
//gives freedom from datatype in c++
//Templates + Iterators
template<class ForwardIterator, class T>

ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){

    while(start != end){
        if(*start == key)
            return start;
        start++;
    }
    return end;
}
int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);

    auto it = search(l.begin(), l.end(), 5);
    if(it == l.end())
        cout<<"Element not found!";
    else
        cout<<*it;

    //searching for element 4
    auto ite = search(l.begin(), l.end(), 4);
    if(ite == l.end())
        cout<<"\nElement not found!";
    else
        cout<<*ite;
    return 0;
}