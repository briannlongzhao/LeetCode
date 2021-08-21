/* 11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.
*/

class Solution {
public:
    int area(vector<int>& height, int i, int j) {
        return (min(height[i], height[j]) * (j-i));
    }
    
    int maxArea(vector<int>& height) {
        int retval = 0;
        int i = 0;
        int j = height.size()-1;
        while (i < j) {
            int a = area(height, i, j);
            if (a > retval) {
                retval = a;
            }
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return retval;
    }
};