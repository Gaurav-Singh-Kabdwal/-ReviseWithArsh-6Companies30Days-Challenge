class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        vector<string> ans;
        unordered_map<string,vector<int>> mpp;

        for(auto it: access_times){

            mpp[it[0]].push_back(stoi(it[1]));

        }

        for(auto x: mpp){
            
            auto arr = x.second;

            if(arr.size()>=3){

                sort(arr.begin(),arr.end());
                
                int flag = 0;

                for(int i=0;i+2<arr.size();i++){
                    if(arr[i+2]<arr[i]+100){
                        flag = 1;
                    } 
                }

                if(flag){
                    ans.push_back(x.first);
                }
            }


        }

        return ans;
    }
};