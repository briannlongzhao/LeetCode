/* 20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
	1. Open brackets must be closed by the same type of brackets.
	2. Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if ((curr == '(') || (curr == '{') || (curr == '[')) {
                st.push(curr);
            }
            else if (curr == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
            else if (curr == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
            else if (curr == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            }
            else {
                return false;
            }
        }
        if (st.size() != 0) {
            return false;
        }
        return true;
    }
};