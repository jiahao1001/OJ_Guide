/****************************************************
* problem id : 46
* problem title : Permutations
* problem link : https://leetcode.com/problems/permutations/description/
****************************************************/

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    if(nums.size()==0)
        return ans;

    permute_core(nums, 0, ans);

    return ans;
}

void permute_core(vector<int> &nums, int begin, vector<vector<int>> &ans) {
    if(begin>=nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int i=begin; i<nums.size(); i++) {
        swap(nums[begin], nums[i]);
        permute_core(nums, begin+1, ans);
        swap(nums[begin], nums[i]);
    }
}
