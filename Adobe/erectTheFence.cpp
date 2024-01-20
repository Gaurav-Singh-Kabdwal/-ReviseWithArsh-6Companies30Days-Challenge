class Solution {

    int slope(array<int,2> x, array<int,2> y, array<int,2> z){

        return (z[1]-y[1])*(y[0]-x[0]) -(y[1]-x[1])*(z[0]-y[0]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        vector<vector<int>> ans;
        deque<array<int,2>> upper, lower;

        sort(trees.begin(),trees.end());    

        for(auto it: trees){

            int l = lower.size(), u= upper.size();

            while(l>=2&& slope(lower[l-2],lower[l-1],{it[0],it[1]})>0){
                lower.pop_back();
                l--;
            }

            while(u>=2&& slope(upper[u-2],upper[u-1],{it[0],it[1]})<0){
                upper.pop_back();
                u--;
            }

            lower.push_back({it[0],it[1]});
            upper.push_back({it[0],it[1]});
        }

         set<array<int,2>> hs;   

         for(auto x: lower) hs.insert(x);
         for(auto x: upper) hs.insert(x);

         for(auto x: hs) ans.push_back({x[0],x[1]});

         return ans;  

    }
};