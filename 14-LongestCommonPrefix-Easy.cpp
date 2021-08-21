/* 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string retval = "";
        for (int char_i = 0; char_i < strs[0].length(); char_i++) {
            char curr = strs[0][char_i];
            for (int i = 0; i < strs.size(); i++) {
                if (char_i >= strs[i].length()) {
                    return retval;
                }
                else if (strs[i][char_i] != curr) {
                    return retval;
                }
            }
            retval += curr;
        }
        return retval;
    }
};