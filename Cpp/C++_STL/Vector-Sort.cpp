#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
void print_vector(vector<int> &arr)
{
    for (vector<int> :: iterator i = arr.begin(); i!= arr.end(); i++) {
    cout<<*i<<" ";
    }
}

int main() {
    int n,temp;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        arr.push_back(temp);
    }   
    vector<int> :: iterator str = arr.begin();
    sort(arr.begin(),arr.end());
    print_vector(arr);
    return 0;
}