class Solution {
    unordered_map<int,int> mpp;
    int x,y,total;
public:

    Solution(int m, int n) {
        
        x = m;
        y = n;
        total = x*y;
        
    }
    
    vector<int> flip() {
        
        int r = rand()%total;
        total--;

        int t;
        if(mpp.count(r)){
             t = mpp[r];
        }
        else 
            t = r;

        if(mpp.count(total))
            mpp[r] = mpp[total];
        else
            mpp[r] = total;    

        return {t/y,t%y};     
        
    }
    
    void reset() {
    
        mpp.clear();
        total = x*y;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */