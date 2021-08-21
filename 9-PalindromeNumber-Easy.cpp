/* 9. Palindrome Number
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. 
For example, 121 is palindrome while 123 is not.
*/

class Solution {
public:
    bool isPalindromeHelper(string s) {
        if (s.length() <= 1) {
            return true;
        }
        if (s[0] == s[s.length()-1]) {
            return isPalindromeHelper(s.substr(1,s.length()-2));
        }
        return false;
    }
    
    bool isPalindrome(int x) {
        string s = to_string(x);
        return isPalindromeHelper(s);
    }
};