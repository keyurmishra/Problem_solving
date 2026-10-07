class Solution {
public:
    vector<string> ans;

    void dfs(string s, int start, int leftRemove, int rightRemove) {

        // If removals are finished, check validity
        if (leftRemove == 0 && rightRemove == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(')
                    balance++;
                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Avoid duplicate removals
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove ')'
            if (rightRemove > 0 && s[i] == ')') {

                string next = s.substr(0, i) + s.substr(i + 1);

                dfs(next, i, leftRemove, rightRemove - 1);
            }

            // Remove '('
            if (leftRemove > 0 && s[i] == '(') {

                string next = s.substr(0, i) + s.substr(i + 1);

                dfs(next, i, leftRemove - 1, rightRemove);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove);

        return ans;
    }
};