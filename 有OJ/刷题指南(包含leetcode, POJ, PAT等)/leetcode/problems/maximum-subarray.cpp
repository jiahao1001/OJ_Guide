/************************************************************
* problem id : 53
* problem title : Maximum Subarray
* problem link : https://leetcode.com/problems/maximum-subarray/description/
************************************************************/

/* enumerate algorithm, time complexity O(n^2) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return 0;
        int distance[size][size];
        int ans = INT_MIN;

        for(int i=0; i<size; i++) {
            int sum = 0;
            for(int j=i; j<size; j++) {
                sum += nums[j];
                distance[i][j] = sum;
            }
        }

        for(int i=0; i<size; i++)
            for(int j=i; j<size; j++)
                if(distance[i][j]>ans)
                    ans = distance[i][j];

        return ans;
    }
};

/* Greedy algorithm, O(n) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], sum=0;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }

        return ans;
    }
};
