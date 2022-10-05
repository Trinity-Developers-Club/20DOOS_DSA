#include<bits/stdc++.h>
using namespace std;

int main(){
    multimap<char, string> m;

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        char ch;
        string s;
        cin>>ch>>s;
        m.insert(make_pair(ch,s));
    }
    
    //erasing the first iterator
    auto it = m.begin();
    m.erase(it);

    //printing entire multimap
    for(auto p: m){
        cout<<p.first<<"->"<<p.second<<endl;
    }

    //iterating from specific element
    auto it2 = m.lower_bound('b');
    auto it3 = m.upper_bound('d');
    for(auto it4 = it2; it4!=it3; it4++){
        cout<<it4->second<<endl;
    }

    auto f = m.find('c');
    if(f->second == "cat"){
        m.erase(f);
    }
    for(auto it5 = m.begin(); it5 != m.end(); it5++){
        cout<<it5->first<<"->"<<it5->second<<endl;
    }


    return 0;
}