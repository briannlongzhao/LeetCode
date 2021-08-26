/* 28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        if (haystack == "") {
            return -1;
        }
        
        const int len_n = needle.size();
        vector<int> prefix(len_n);
        prefix[0] = 0;
        for (int i = 1, j = 0; i < len_n;) {
    		if (needle[i] != needle[j]){
    			if (j > 0){
    				j = prefix[j-1];
    			}
    			else{
    				i++;
    			}
    		}
    		else {
    			prefix[i] = j+1;
    			i++;
    			j++;
    		}
    	}
        
        int len_h = haystack.size();
        int j = 0;
        for (int i = 0; i < len_h; i++) {
            if (haystack[i] == needle[j]) {
                if (j == len_n-1) {
                    return i-j;
                }
                j++;
            }
            else {
                if (j > 0) {
                    j = prefix[j-1];
                    i--;
                }
                else {
                    j = 0;
                }
            }
        }
        return -1;
    }
};