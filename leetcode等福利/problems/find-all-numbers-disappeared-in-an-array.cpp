/********************************************************
* problem id : 448
* problem title : Find All Numbers Disappeared in an Array
* problem link : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*********************************************************/

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();
    int record[size+1];
    vector<int> ans;

    if(size==0)
        return ans;
    for(int i=0; i<=size; i++)
        record[i] = 0;
    for(int i=0; i<size; i++)
        record[nums[i]] ++;
    for(int i=1; i<=size; i++)
        if(record[i]==0)
            ans.push_back(i);

    return ans;
}
