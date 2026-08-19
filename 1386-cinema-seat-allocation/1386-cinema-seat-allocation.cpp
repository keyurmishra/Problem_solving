class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reservedMap;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedMap[row] |= (1 << (col - 2));
            }
        }
        int totalGroups = 2 * n;
        int leftBlock   = 0b00001111;
        int middleBlock = 0b00111100; 
        int rightBlock  = 0b11110000; 

        for (const auto& [row, mask] : reservedMap) {
            bool left   = (mask & leftBlock) == 0;
            bool right  = (mask & rightBlock) == 0;
            bool middle = (mask & middleBlock) == 0;
            if (left && right) {
                continue;
            } else if (left || right || middle) {
                totalGroups -= 1;
            } else {
                totalGroups -= 2;
            }
        }

        return totalGroups;
        
    }
};