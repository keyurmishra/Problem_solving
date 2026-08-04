class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>change(1001,0);
        for(auto&trip:trips){
            int passenger=trip[0];
            int from=trip[1];
            int to=trip[2];
            // now u have two task like .. made a change vector and like (from) --> (to).. and and during the change calculate the curr passenger 
            change[from]+=passenger;
            change[to]-=passenger;
        }
        int currpassenger=0;
        for(int i=0;i<1001;i++){
            currpassenger+=change[i];
            if(currpassenger>capacity){
                return false;
            }
        }
        return true;
        
    }
};