/* 15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > ans;
        if(len <= 2)
            return ans;
        bool zero = true;
        for (int i = 0; i < len; i++){
            if (nums[i] != 0){
                zero = false;
                break;
            }
        }
        if (zero) {
            return {{0,0,0}};
        }
        set<vector<int> > ans_temp;
        vector<int> temp(3);
        unordered_set<int> nums_temp;
        sort(nums.begin(), nums.end());
        for(int i=0; i < len-1; i++){
            nums_temp.clear();
            int first = nums[i];
            for(int j = i+1; j < len; j++){
                int second = nums[j];
                int third = 0-first-second;
                if (nums_temp.find(third) != nums_temp.end()) {
                    temp[0] = first;
                    temp[1] = second;
                    temp[2] = third;
                    sort(temp.begin(), temp.end());
                    ans_temp.insert(temp);
                }
                else{
                    nums_temp.insert(second);
                }
            }
        }
        
        for(auto it = ans_temp.begin(); it != ans_temp.end(); ++it){
            ans.push_back(*it);
        }
        return ans;
    }
}