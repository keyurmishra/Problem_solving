class Solution {
public:
     set<string> multiply(set<string>& a, set<string>& b) {
        set<string> ans;
        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }
        return ans;
    }
    set<string> solve(string& expression, int& i) {
        set<string> result;
        set<string> current = {""};
        while (i < expression.size() && expression[i] != '}') {
            if (expression[i] == ',') {
                result.insert(current.begin(), current.end());
                current.clear();
                current.insert("");
                i++;
            }
            else if (expression[i] == '{') {
                i++; 
                set<string> inside = solve(expression, i);
                i++; 
                current = multiply(current, inside);
            }
            else {
                set<string> letter = {string(1, expression[i])};
                current = multiply(current, letter);
                i++;
            }
        }
        result.insert(current.begin(), current.end());
        return result;
    }
    vector<string> braceExpansionII(string expression) {
         int i = 0;
        set<string> ansSet = solve(expression, i);
        return vector<string>(ansSet.begin(), ansSet.end());
        
    }
};