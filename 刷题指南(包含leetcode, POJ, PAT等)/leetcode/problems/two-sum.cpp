/*********************************************************
* problem id : 1
* problem title : Two Sum
* problem link : https://leetcode.com/problems/two-sum/description/
*********************************************************/

/* A simple method, but has memory limit error */
vector<int> twoSum(vector<int>& nums, int target) {
    int i=0, j=nums.size()-1;
    vector<int> ans;

    sort(nums.begin(), nums.end());
    while(i<j) {
        int sum = nums[i] + nums[j];
        if(sum<target)  i ++;
        else if(sum>target) j --;
        else {
            ans.push_back(i);
            ans.push_back(j);
        }
    }

    return ans;
}

/* An AC method with hashmap */
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++) {
        if(m.find(target-nums[i])!=m.end()) {
            ans.push_back(i);
            ans.push_back(m[target-nums[i]]);
            return ans;
        }
        m[nums[i]] = i;
    }
}
