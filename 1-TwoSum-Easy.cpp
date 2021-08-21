/* 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retval;
        retval.push_back(0);
        retval.push_back(0);
        unordered_set<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.insert(nums[i]);
        }
        int curr = 0, comp = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = nums[i];
            comp = target - curr;
            if (temp.find(comp) != temp.end()) {
                retval[0] = i;
                for (int j = 0; j < nums.size(); j++) {
                    if (j != i && nums[j] == comp) {
                        retval[1] = j;
                        return retval;
                    }
                }
            }
        }
        return retval;
    }
};