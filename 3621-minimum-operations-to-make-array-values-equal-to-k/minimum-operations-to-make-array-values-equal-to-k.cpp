class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int n=nums.size();
        unordered_map<int,int> mp;
        for(auto num:nums){
            if(num<k)
                return -1;
            if(num!=k)
                mp[num]++;
        }
        return mp.size();
    }
};