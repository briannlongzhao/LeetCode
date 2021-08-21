/* 13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. 
Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:
 - I can be placed before V (5) and X (10) to make 4 and 9. 
 - X can be placed before L (50) and C (100) to make 40 and 90. 
 - C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

class Solution {
public:
    int romanToInt(string s) {
        unsigned short i = 0;
        int retval = 0;
        while (s[i] == 'M') {
            retval += 1000;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'C' && i+1 < s.length()) {
            if (s[i+1] == 'M') {
                retval += 900;
                i += 2;
            }
            else if (s[i+1] == 'D') {
                retval += 400;
                i += 2;
            }
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'D') {
            retval += 500;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        
        while (s[i] == 'C') {
            retval += 100;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'X' && i+1 < s.length()) {
            if (s[i+1] == 'C') {
                retval += 90;
                i += 2;
            }
            else if (s[i+1] == 'L') {
                retval += 40;
                i += 2;
            }
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'L') {
            retval += 50;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        
        while (s[i] == 'X') {
            retval += 10;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'I' && i+1 < s.length()) {
            if (s[i+1] == 'X') {
                retval += 9;
                i += 2;
            }
            else if (s[i+1] == 'V') {
                retval += 4;
                i += 2;
            }
            if (i >= s.length()) {
                return retval;
            }
        }
        if (s[i] == 'V') {
            retval += 5;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        
        while (s[i] == 'I') {
            retval += 1;
            i++;
            if (i >= s.length()) {
                return retval;
            }
        }
        return retval;
    }
};