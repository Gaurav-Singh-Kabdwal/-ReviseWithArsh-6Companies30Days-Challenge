class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        int ans = 0;
        unordered_set<int> hs;
        
        for(auto word: startWords){
            int mask = 0;
            for(char c: word){
                mask |= 1<<(c-'a');
            }
            hs.insert(mask);
        }
        
        for(auto target: targetWords){
            int mask = 0;
            for(char c: target){
                mask |= 1<<(c-'a');
            }
            for(char c: target){
                if(hs.count(mask^(1<<(c-'a')))){
                    ans++;
                    break;
                }
            }
        }


        return ans;
    }
};