class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int sizs = s.size(), siza = a.size(), sizb = b.size();
        
        vector<int> aind, bind;
        for(int i=0; i<=sizs - siza; i++) {
            if(s.substr(i, siza) == a) aind.push_back(i);
        }
        for(int i=0; i<=sizs - sizb; i++) {
            if(s.substr(i, sizb) == b) bind.push_back(i);
        }
        
        set<int> st;
        for(auto i: aind) {
            for(auto j: bind) {
                if(abs(i - j) <= k) {
                    st.insert(i);
                    break;
                }
            }
        }
        
        vector<int> ans;
        for(auto i: st) ans.push_back(i);
        return ans;
    }
};