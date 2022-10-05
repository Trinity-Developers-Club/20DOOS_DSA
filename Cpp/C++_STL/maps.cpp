#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> m;

    //1.insert
    m.insert(make_pair("Mango", 100));

    //2.insert
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    //3.insert
    m["banana"] = 20;


    //serching the element
    string fruit;
    cin>>fruit;

    auto it = m.find(fruit);
    m[fruit] += 22;

    if(it != m.end()){
        cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else{
        cout<<"fruit is not present";
    }

    //another way for finding the fruit present or not.
    if(m.count(fruit))
        cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    else 
        cout<<"could not find "<<fruit;

    //eraseing the fruit
    m.erase(fruit);

    //another way for finding the fruit present or not.
    if(m.count(fruit))
        cout<<"price of "<<fruit<<" is "<<m[fruit]<<endl;
    else 
        cout<<"could not find "<<fruit<<endl;

    m["lichi"] = 60;
    m["pineapple"] = 80;

    //Iterate over key value pair - keys are sorted in lexicographical order
    for(auto it = m.begin(); it!= m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
        cout<<(*it).first<<" "<<(*it).second<<endl; 
    }

    //for each loop
    for(auto p: m){
        cout<<p.first<<":"<<p.second<<endl;
    }
    return 0;
}