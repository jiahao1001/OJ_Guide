/***************************************************
* problem id : 26
* problem title : Remove Duplicates from Sorted Array
* problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
****************************************************/

int removeDuplicates(vector<int>& nums) {
    int sum = 0, dup = 0, flag;

    if(nums.size()==0)
        return 0;

    flag = nums[0];
    for(int i=1; i<nums.size(); i++) {
        if(nums[i]==flag)
            dup ++;
        else
            flag = nums[i];
        nums[i-dup] = nums[i];
    }

    return nums.size()-dup;
}
