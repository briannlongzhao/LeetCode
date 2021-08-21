/* 3. Longest Substring Without Repeating Characters 
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    string isDup(string str, char ch) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ch) {
                if (i+1 == str.length()) {
                    return "";
                }
                else {
                    return str.substr(i+1);
                }
            }
        }
        return "\r";
    }
    
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        int length = 1;
        string substr = string(1, s[0]);
        unordered_set<char> temp;
        vector<string> opt(s.length(), "");
        opt[0] = substr;
        
        for (int i = 1; i < s.length(); i++) {
            if (isDup(opt[i-1], s[i]) != "\r") {
                opt[i] = isDup(opt[i-1], s[i]) + s[i];
            }
            else {
                opt[i] = opt[i-1] + s[i];
                if (opt[i].length() > length) {
                    length = opt[i].length();
                }
            }
        }
        return length;
    }
};