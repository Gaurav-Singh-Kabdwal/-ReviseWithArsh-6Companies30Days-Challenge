class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        int i=0,n = buildings.size(), x,y;

        while(i<n|| pq.size()){

            x = pq.empty()?buildings[i][0]: pq.top().second;

            if(i>=n || x < buildings[i][0]){

                while(pq.size() && pq.top().second <= x) pq.pop();

            }
            else{
                x = buildings[i][0];

                while(i<n && buildings[i][0]==x){ 
                    pq.push({buildings[i][2], buildings[i][1]});
                    i++;
                }
            }

            y = pq.size()?pq.top().first: 0;
            if(!ans.size() || ans.back()[1]!=y) ans.push_back({x,y});
        }

        return ans;
    }
};