class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto num: nums){
            mp[num]++;
            if(mp[num]>=2){
                return num;
            }
        }
        return 0;

        
    }
};