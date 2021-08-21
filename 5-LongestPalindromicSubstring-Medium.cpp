/* 5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > opt;
        for (int i = 0; i < s.length(); i++) {
            opt.push_back(vector<bool>(s.length(), false));
        }
        for (int i = s.length()-1; i >= 0; i--) {
            for (int j = 0; j < s.length(); j++) {
                if (i > j) {
                    opt[i][j] = false;
                }
                else if (i == j) {
                    opt[i][j] = true;
                }
                else if (i+1 == j) {
                    opt[i][j] = (s[i] == s[j]);
                }
                else {
                    opt[i][j] = (opt[i+1][j-1] && s[i] == s[j]);
                }
            }
        }
        int length = 0;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (opt[i][j] && j-i+1 > length) {
                    length = j-i+1;
                    str = s.substr(i,length);
                }
            }
        }
        return str;
    }
};