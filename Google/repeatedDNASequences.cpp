class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<string> ansSet;
        unordered_set<string> hs;

        for(int i=0; i<s.size();i++){

            if(hs.count(s.substr(i,10))) ansSet.insert(s.substr(i,10)); 

            hs.insert(s.substr(i,10));
        }

        
        vector<string> ans(ansSet.begin(),ansSet.end());

        return ans;
    }
};