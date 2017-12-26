/**********************************************************
* problem id : 198
* problem title : House Robber
* problem link : https://leetcode.com/problems/house-robber/description/
***********************************************************/

class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0, b=0;

        for(int i=0; i<nums.size(); i++) {
            if(i%2==0)
                a = max(a+nums[i], b);
            else
                b = max(a, b+nums[i]);
        }

        return max(a,b);
    }
};
