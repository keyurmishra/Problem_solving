class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        
        // Step 1: Precompute matching parentheses positions
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        // Step 2: Traverse s and collect characters without nested reversals
        std::string result = "";
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i]; // Teleport to matching bracket
                dir = -dir;  // Reverse reading direction
            } else {
                result += s[i];
            }
        }
        
        return result;
        
    }
};