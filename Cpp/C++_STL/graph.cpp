#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    list<pair<int,int>> *l;
    l = new list<pair<int,int>>[n];

    //creating graph with the e no of the edges
    int e;
    cin>>e;

    for(int i = 0; i < e; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    //printing the graph
    for(int i = 0; i < n; i++){
        cout<<"Linked list "<<i<<" -> ";
        for(auto xp: l[i]){
            cout<<"("<<xp.first<<","<<xp.second<<"),";
        } 
        cout<<endl;
    }
    return 0;
}