class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        struct subtree {
            int height;
            int diameter;
        };
        vector<int> res(n-1, 0);
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        function<vector<subtree>(int, int)> dfs = [&](int u, int par) {
            vector<vector<subtree>> children;
            for (int v : adj[u]) {
                if (v == par) continue;
                children.push_back(dfs(v, u));
            }
            vector<subtree> trees;
            int at = 0;
            function<void(int,int,int,int)> generateTrees = [&](int at, int max_height1, int max_height2, int diam) {
                if (at == children.size()) {
				    // generate new tree based on max_heights and biggest diameter of all used subtrees
                    int h,d;
                    if (max_height1 < 0) {
                        h = 0;
                        d = 0;
                    } else if (max_height2 < 0) {
                        h = max_height1 + 1;
                        d = max(diam, max_height1 + 1);
                    } else {
                        h = max_height1 + 1;
                        d = max(diam, max_height1 + max_height2 + 2);
                    }
                    if (d > 0) {
                        res[d-1]++;
                    }
                    trees.push_back({h,d});
                } else {
                    for (int i = 0; i <= children[at].size(); i++) {
                        if (i == children[at].size()) {
						    // decide not to use any of this child's subtrees
                            generateTrees(at+1, max_height1, max_height2, diam);
                        } else {
						    // decide to use subtree i of this child
                            int h = children[at][i].height;
                            int d = children[at][i].diameter;
                            int mh1 = max_height1;
                            int mh2 = max_height2;
                            if (h > mh1) {
                                mh2 = mh1;
                                mh1 = h;
                            } else if (h > mh2) {
                                mh2 = h;
                            } 
                            generateTrees(at+1, mh1, mh2, max(diam, d));
                        }
                    }
                }
            };
            generateTrees(0, -1, -1, -1);
            return trees;
        };
        dfs(0, -1);
        return res;
    }
};