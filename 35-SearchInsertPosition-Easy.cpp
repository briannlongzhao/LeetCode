/* 35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int searchInsertHelper(vector<int>& nums, int target, int begin, int end) {
        if (begin == end) {
            return begin;
        }
        int len = end-begin;
        int mid = begin+len/2;
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {
            return searchInsertHelper(nums, target, begin, mid);
        }
        else {
            return searchInsertHelper(nums, target, mid+1, end);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return searchInsertHelper(nums, target, 0, nums.size());
    }
};