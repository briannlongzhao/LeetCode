/* 12. Integer to Roman
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
Given an integer, convert it to a roman numeral.
*/

class Solution {
public:
    string intToRoman(int num) {
        int temp = num;
        string retval = "";
        unsigned int bit = 0;
        while (temp > 0) {
            unsigned int digit = temp % 10;
            temp /= 10;
            if (bit == 0) {
                if (digit < 4) {
                    for (unsigned short i = 0; i < digit; i++) {
                        retval = 'I' + retval;
                    }
                }
                else if (digit == 4) {
                    retval = "IV" + retval;
                }
                else if (digit < 9) {
                    string tmp = "V";
                    for (unsigned short i = 0; i < digit-5; i++) {
                        tmp += 'I';
                    }
                    retval = tmp + retval;
                }
                else {
                    retval = "IX" + retval;
                }
            }
            else if (bit == 1) {
                if (digit < 4) {
                    for (unsigned short i = 0; i < digit; i++) {
                        retval = 'X' + retval;
                    }
                }
                else if (digit == 4) {
                    retval = "XL" + retval;
                }
                else if (digit < 9) {
                    string tmp = "L";
                    for (unsigned short i = 0; i < digit-5; i++) {
                        tmp += 'X';
                    }
                    retval = tmp + retval;
                }
                else {
                    retval = "XC" + retval;
                }
            }
            else if (bit == 2) {
                if (digit < 4) {
                    for (unsigned short i = 0; i < digit; i++) {
                        retval = 'C' + retval;
                    }
                }
                else if (digit == 4) {
                    retval = "CD" + retval;
                }
                else if (digit < 9) {
                    string tmp = "D";
                    for (unsigned short i = 0; i < digit-5; i++) {
                        tmp += 'C';
                    }
                    retval = tmp + retval;
                }
                else {
                    retval = "CM" + retval;
                }
            }
            else if (bit == 3) {
                if (digit < 4) {
                    for (unsigned short i = 0; i < digit; i++) {
                        retval = 'M' + retval;
                    }
                }
                else if (digit == 4) {
                    retval = "M?" + retval;
                }
                else if (digit < 9) {
                    string tmp = "?";
                    for (unsigned short i = 0; i < digit-5; i++) {
                        tmp += 'M';
                    }
                    retval = tmp + retval;
                }
                else {
                    retval = "M?" + retval;
                }
            }
            bit++;
        }
        return retval;
    }
};