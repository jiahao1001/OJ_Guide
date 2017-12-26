/****************************************************
* problem id : 136
* problem title : Single Number
* problem link : https://leetcode.com/problems/single-number/description/
*****************************************************/

/* Use XOR */
int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int i=0; i<nums.size(); i++)
        ans ^= nums[i];

    return ans;
}
