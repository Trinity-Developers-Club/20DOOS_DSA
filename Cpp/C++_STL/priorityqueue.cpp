#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        pq.push(no);        //O(logN)
        pq_min.push(no);    //O(logN);
    }

    //removing the elements from heap
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;
    return 0;
}