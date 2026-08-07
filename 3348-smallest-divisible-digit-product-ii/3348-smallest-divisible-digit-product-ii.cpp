class Solution {
public:
     vector<array<int,4>>factor={
        {0,0,0,0},
        {0,0,0,0}, 
        {1,0,0,0}, 
        {0,1,0,0}, 
        {2,0,0,0}, 
        {0,0,1,0}, 
        {1,1,0,0},
        {0,0,0,1}, 
        {3,0,0,0}, 
        {0,2,0,0}  
    };
    int dp[50][35];
    void buildDP() {
        const int INF=1e9;
        for (int a=0;a<50;a++)
            for (int b=0;b<35;b++)
                dp[a][b]=INF;
        dp[0][0]=0;
        vector<pair<int,int>> useful = {
            {1,0}, 
            {0,1}, 
            {2,0}, 
            {1,1}, 
            {3,0}, 
            {0,2}  
        };

        for (int a =0; a< 50;a++) {
            for (int b = 0; b <35;b++) {

                if (a ==0 && b== 0)
                    continue;
                for (auto [x,y]:useful) {
                    int na =max(0,a - x);
                    int nb =max(0,b - y);

                    dp[a][b] =
                        min(dp[a][b],1 +dp[na][nb]);
                }
            }
        }
    }
    bool possible(array<int,4> need, int slots) {
        for (int i = 0; i < 4; i++)
            need[i] = max(0, need[i]);
        int requiredDigits = dp[need[0]][need[1]]+ need[2]+ need[3];
        return requiredDigits <= slots;
    }
    string buildSuffix(array<int,4> need, int len) {
        string ans;
        for (int pos = 0; pos < len; pos++) {
            int remaining = len - pos - 1;
            for (int d = 1; d <= 9; d++) {
                array<int,4> next = need;
                for (int j = 0; j < 4; j++)
                    next[j] -= factor[d][j];
                if (possible(next, remaining)) {
                    ans += char('0' + d);
                    need = next;
                    break;
                }
            }
        }
        return ans;
    }
    string smallestNumber(string num, long long t) {
        buildDP();
        array<int,4> target = {0,0,0,0};
        int primes[4] = {2,3,5,7};
        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                target[i]++;
                t /= primes[i];
            }
        }
        if (t!=1)
            return"-1";
        int n = num.size();
        vector<array<int,4>> prefix(n + 1);
        prefix[0] = {0,0,0,0};
        int firstZero = n;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            int d = num[i] - '0';
            if (d == 0 && firstZero == n)
                firstZero = i;
            if (d != 0) {
                for (int j = 0; j < 4; j++)
                    prefix[i + 1][j] += factor[d][j];
            }
        }
        if (firstZero == n) {
            bool valid = true;
            for (int j = 0; j < 4; j++) {
                if (prefix[n][j] < target[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return num;
        }
        int startPosition = min(n - 1, firstZero);
        for (int i = startPosition; i >= 0; i--) {
            int original = num[i] - '0';
            for (int d = max(1, original + 1); d <= 9; d++) {
                array<int,4> need = target;
               
                for (int j = 0; j < 4; j++)
                    need[j] -= prefix[i][j];
            
                for (int j = 0; j < 4; j++)
                    need[j] -= factor[d][j];
                int remaining = n - i - 1;
                if (possible(need, remaining)) {
                    string answer =
                        num.substr(0, i);
                    answer += char('0' + d);
                    answer += buildSuffix(need, remaining);
                    return answer;
                }
            }
        }
        int len = n + 1;
        while (!possible(target, len))
            len++;
        return buildSuffix(target, len);
    }   
    
};