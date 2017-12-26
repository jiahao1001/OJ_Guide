/***********************************************************
* problem id : 169
* problem title : Majority Element
* problem link : https://leetcode.com/problems/majority-element/description/
***********************************************************/

/* Use extra space with unordered map */
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mm;
    int size = nums.size();

    for(int i=0; i<size; i++) {
        mm[nums[i]] ++;
        if(mm[nums[i]]>size/2)
            return nums[i];
    }
}

/* Use no extra space */
int majorityElement(vector<int>& nums) {
    int size = nums.size(), flag, freq;

    sort(nums.begin(), nums.end());
    flag = nums[0];
    freq = 1;
    for(int i=1; i<size; i++) {
        if(nums[i]==flag) {
            freq ++;
            if(freq>size/2)
                return flag;
        }
        else {
            flag = nums[i];
            freq = 1;
        }
    }

    return flag;
}
