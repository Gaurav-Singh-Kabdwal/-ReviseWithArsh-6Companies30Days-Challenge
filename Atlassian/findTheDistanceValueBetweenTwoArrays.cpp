class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        
        for(int x: arr1){

            if(upper_bound(arr2.begin(),arr2.end(),x+d)==lower_bound(arr2.begin(), arr2.end(), x-d))
                cnt++;
        }

        return cnt;
    }
};