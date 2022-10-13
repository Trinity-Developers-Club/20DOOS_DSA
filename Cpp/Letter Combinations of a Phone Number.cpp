/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

class Solution {
public:
    string str="";
    void find(int i, string s, vector<string>&v, map<int,vector<char>>&m){
        if(i==s.length()){
            v.push_back(str);
            return;
        }
        for(int j=0; j<m[s[i]-'0'].size(); j++){
            str.push_back(m[s[i]-'0'][j]);
            find(i+1,s,v,m);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,vector<char>>m;
        int j=1;
        for(int i=0; i<26; i++){
            if(i%3==0 && i<18){
                j++;
            }
            if(i==19) j++;
            if(i==22) j++;
            m[j].push_back('a'+i);
        }
        vector<string>v;
        if(digits=="") return v;
        find(0,digits,v,m);
        return v;
    }
};
