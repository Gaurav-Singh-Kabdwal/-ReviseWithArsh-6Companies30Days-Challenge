class Solution {

public:

    vector<vector<int>> highestPeak(vector<vector<int>>& wM) {

        int dirs[5] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        int h = 1, n = wM.size(), m = wM[0].size();

        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++) {
                wM[i][j] = wM[i][j] == 1 ? 0 : -1;
                if (wM[i][j] == 0)
                    q.push({i, j});
            }

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k<size; k++) {

                auto it = q.front();
                q.pop();    
                int i = it.first, j = it.second;  

                for (int d = 0; d < 4; d++) {
                
                    int x = i + dirs[d], y = j + dirs[d + 1];

                    if (x >= 0 && y >= 0 && x < n && y < m && wM[x][y] == -1) {
                        wM[x][y] = h;
                        q.push({x,y});
                        
                    }
                }
            }
            h++;
        }
        return wM;
    }
};