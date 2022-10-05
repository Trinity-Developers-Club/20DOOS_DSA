#include<bits/stdc++.h>
using namespace std;

void permute(char a[], int i, set<string> &s){
    if(a[i] == '\0'){
        //cout<<a<<endl;
        string t(a);
        s.insert(t);
        return;
    }
    else{
        for(int j = i; a[j] != '\0'; j++){
            swap(a[i],a[j]);
            permute(a, i+1, s);
            swap(a[i], a[j]);
        }
    }
}
int main(){
    char a[100];
    cin>>a;

    set<string> s;
    permute(a,0,s);

    //iterating over teh elements in the string
    for(auto str: s){
        cout<<str<<",";
    }
    return 0;
}