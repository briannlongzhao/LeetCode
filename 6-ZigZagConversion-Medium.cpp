/* 6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string ret = "";
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows-1) {
                int j;
                if (i == 0) {
                    j = 0;
                }
                else {
                    j = numRows-1;
                }
                while (j < s.length()) {
                    ret += s[j];
                    j += 2*(numRows-2)+2;
                }
            }
            else {
                int j = i;
                int seq = 0;
                while (j < s.length()) {
                    ret += s[j];
                    if (seq == 0) {
                        j += 2*(numRows-i-1);
                        seq = 1;
                    }
                    else {
                        j += 2*i; 
                        seq = 0;
                    }
                }
            }
        }
        return ret;
    }
};