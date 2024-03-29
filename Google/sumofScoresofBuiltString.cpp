class Solution {
public:
    vector<int> lps(string &s) {
        vector<int> lps(s.size());
        for (int i = 1, j = 0; i < s.size(); ++i) {
            while (j && s[i] != s[j])
                j = max(0, lps[j - 1]);
            j += s[i] == s[j];
            lps[i] = j;
        }
        return lps;
    }    
    
    long long sumScores(string s) {
        vector<int> cnt;
        for (int j :  lps(s))
            cnt.push_back(j == 0 ? 0 : cnt[j - 1] + 1);   
        return accumulate(begin(cnt), end(cnt), 0LL) + s.size();
    }
};