#include<bits/stdc++.h>
using namespace std;

int main(){
    string s0;
    string s1("Hello");
    string s2 = "Hello World!";
    string s3(s2);
    string s4 = s3;

    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;

    //empty()
    if(s0.empty())
        cout<<"s0 is empty."<<endl;
    //Appending
    s0.append("I love C++");
    cout<<s0<<endl;

    s0 += " and Real Estate";
    cout<<s0<<endl;

    //clear()
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;
    
    //compare()
    s0 = "Apple";
    s1 = "Mango";
    cout<< s0.compare(s1)<<endl;
    cout<< s0.compare(s0)<<endl;
    cout<< s1.compare(s0)<<endl;

    //s1 > s0
    if(s1 > s0){
        cout<<"Mango is lexographically greater than Apple"<<endl;
    }
    else
        cout<<"Apple is lexographically greater than Mango"<<endl;

    //finding word index in the apple
    string s = "I want to have apple juice";
    int index = s.find("apple");
    cout<<index<<endl;

    //using erase function in c++
    string word = "apple";
    int len = word.length();
    cout<<s<<endl;
    s.erase(index, len);
    cout<<s<<endl;

    //Iterator in string
    for(int i = 0; i < s1.length(); i++){
        cout<<s1[i]<<":";
    }
    cout<<endl;

    //using iterator
    for(auto it = s1.begin(); it != s1.end(); it++){
        cout<<*(it)<<":";
    }
    return 0;
}