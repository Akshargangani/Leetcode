class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]={0};
        for(int i=0;i<s.size();i++) last[s[i]-'a']=i;
        vector<int> res;
        int j=0,sz=0;
        for(int i=0;i<s.size();i++){
            j=max(j,last[s[i]-'a']);
            sz++;
            if(i==j) res.push_back(sz),sz=0;
        }
        return res;
    }
};
