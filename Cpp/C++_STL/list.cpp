#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;

    //Init
    list<int> l1{1,2,3,10,8,5};
    //Different Datatype
    list<string> l2{"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");

    //sort - lexiographical sort
    l2.sort();

    //reverse
    l2.reverse();

    //pop_front
    cout<<l2.front()<<endl;
    l2.pop_front();

    //push_front
    l2.push_front("kiwi");
    cout<<l2.back()<<endl;
    l2.pop_back();

    //Iterating over the list
    for(auto it = l2.begin(); it != l2.end(); it++){
        cout<<*it<<" -> ";
    }
    cout<<endl;

    l2.push_back("orange");
    l2.push_back("guava");

    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //removing the element from the list
    string f;
    cin>>f;
    l2.remove(f);
    
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;
    //erase one or more element 
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;

    //inserting element in the list
    it = l2.begin();
    it++;
    l2.insert(it, "fruitjuice");
    
    for(string s: l2){
        cout<<s<<"-->";
    }
    cout<<endl;
    return 0;
}