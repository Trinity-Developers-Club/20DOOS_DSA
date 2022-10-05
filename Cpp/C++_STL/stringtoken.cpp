#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[100] = "Today is a rainy day";
    
    //strtok(*char,delimiter);
    char *ptr = strtok(s," ");
    cout<<ptr<<endl;
    
    while(ptr != NULL){
        ptr = strtok(NULL, " ");        //for getting next token
        cout<<ptr<<endl;
    }
    return 0;
}