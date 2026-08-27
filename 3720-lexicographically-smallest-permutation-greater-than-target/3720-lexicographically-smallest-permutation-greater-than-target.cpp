class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int matchLen = 0;
        vector<int> tempCount = count;
        
        while (matchLen < n) {
            int charIdx = target[matchLen] - 'a';
            if (tempCount[charIdx] > 0) {
                tempCount[charIdx]--;
                matchLen++;
            } else {
                break;
            }
        }

        for (int i = matchLen; i >= 0; i--) {
            if (i < matchLen) {
                tempCount[target[i] - 'a']++;
            }
            if (i == n) continue; 
            int targetCharIdx = target[i] - 'a';
            for (int c = targetCharIdx + 1; c < 26; c++) {
                if (tempCount[c] > 0) {
                    string result = target.substr(0, i);
                    result += (char)('a' + c);
                    tempCount[c]--;
                    for (int charCode = 0; charCode < 26; charCode++) {
                        while (tempCount[charCode] > 0) {
                            result += (char)('a' + charCode);
                            tempCount[charCode]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
        
    }
};