class Solution {
public:
    string makePalindrome(const string& firstHalf, char midChar, int n) {
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (n % 2 == 1) {
            return firstHalf + midChar + secondHalf;
        }
        return firstHalf + secondHalf;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        int oddCount = 0;
        char midChar = 0;
        vector<int> halfCount(26, 0);

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                midChar = 'a' + i;
            }
            halfCount[i] = count[i] / 2;
        }
        if (oddCount > 1) return "";
        int m = n / 2;
        vector<int> tempHalf = halfCount;
        int matchLen = 0;
        while (matchLen < m) {
            int charIdx = target[matchLen] - 'a';
            if (tempHalf[charIdx] > 0) {
                tempHalf[charIdx]--;
                matchLen++;
            } else {
                break;
            }
        }
        for (int i = matchLen; i >= 0; i--) {
            if (i < matchLen) {
                tempHalf[target[i] - 'a']++;
            }
            if (i == m) {
                string candidateHalf = target.substr(0, m);
                string cand = makePalindrome(candidateHalf, midChar, n);
                if (cand > target) {
                    return cand;
                }
                continue;
            }
            int targetCharIdx = target[i] - 'a';
            for (int c = targetCharIdx + 1; c < 26; c++) {
                if (tempHalf[c] > 0) {
                    string prefix = target.substr(0, i);
                    prefix += (char)('a' + c);
                    vector<int> remHalf = tempHalf;
                    remHalf[c]--;
                    for (int charCode = 0; charCode < 26; charCode++) {
                        while (remHalf[charCode] > 0) {
                            prefix += (char)('a' + charCode);
                            remHalf[charCode]--;
                        }
                    }
                    return makePalindrome(prefix, midChar, n);
                }
            }
        }

        return "";
        
    }
};