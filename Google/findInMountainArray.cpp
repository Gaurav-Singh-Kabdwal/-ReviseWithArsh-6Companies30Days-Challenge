/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        int start = 0;
        int end = len - 1;
        int minindex1 = INT_MAX;
        int minindex2 = INT_MAX;
        while(start<end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        int peak1=start;
        int peak2=start;
        start=0;
        while (start <= peak1)
        {
            int mid = start+(peak1-start)/2;
        
            if (mountainArr.get(mid) == target)
            {
                if (mid < minindex1)
                {
                    minindex1 = mid;
                }
            }
            if (mountainArr.get(mid) < target)
            {
                start = mid + 1;
            }
            else
            {
                peak1 = mid - 1;
            }
        }
        start = 0;
        end = len - 1;
        while (peak2 <= end)
        {
            int mid = peak2+(end-peak2)/2;
            if (mountainArr.get(mid) == target)
            {
                if (mid < minindex2)
                {
                    minindex2 = mid;
                }
            }
            if (mountainArr.get(mid) <= target)
            {
                end = mid -1;
            }
            else
            {
                peak2 = mid + 1;
            }
        }

        if ((minindex1  != INT_MAX) || (minindex2 !=INT_MAX))
        {
            if(minindex1<minindex2){
                return minindex1;
            }
            else{
                return minindex2;
            }
        }
        else
        {
            return -1;
        }
    }
};