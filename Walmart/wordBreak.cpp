class Solution {
public:


    bool wB(string s, vector<string>& wordDict, int i){

        if(i==s.length()){
            return true;
        }

        for(string wd : wordDict){

            int size = wd.size();

            if(s.substr(i,size)==wd && wB(s,wordDict,i+size)){
                
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        return wB(s,wordDict,0);
    }
};