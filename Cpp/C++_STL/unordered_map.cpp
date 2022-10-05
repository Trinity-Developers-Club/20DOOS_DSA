#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, vector<string>> phonebook;

    phonebook["Rahul"].push_back("9110");
    phonebook["Rahul"].push_back("9112");
    phonebook["Rahul"].push_back("9113");
    phonebook["Rahul"].push_back("9114");
    phonebook["Kajal"].push_back("8112");
    phonebook["Kajal"].push_back("8113");
    phonebook["Kajal"].push_back("8114");
    
    for(auto p: phonebook){
        cout<<"Name: "<<p.first<<" ->";
        for(string s: p.second){
            cout<<s<<",";
        }
        cout<<endl;
    }

    //finding whether that name is present in that map or not
    string name;
    cin>>name;
    if(phonebook.count(name)==0){
        cout<<"Absent";
    }
    else{
        for(string s: phonebook[name]){
            cout<<s<<endl;
        }
    }
    cout<<endl;

    return 0;
}