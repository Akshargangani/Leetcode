#include<iostream>
#include<string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> freq;
    if(s.size() !=t.size()) return false;
        for(int i=0; i< s.size();i++){
            freq[s[i]]++;
        }
        map<char,int> freq1;
        for(int i=0; i<t.size();i++){
            freq1[t[i]]++;
        }
        return freq == freq1;
    }
};