class Solution {
public:
    vector<int> nums;
    int n;
    int maxi;
private:
    int rec(int ind){
        if(ind==n) return 0;
        int pick = nums[ind]|rec(ind+1), notPick = rec(ind+1);
        return max(pick,notPick);
    }
    int f(int ind, int gor){
        if(ind==n){
            if(gor == maxi) return 1;
            return 0;
        }
        int pick = f(ind+1, gor|nums[ind] ),notPick = f(ind+1, gor);
        return pick+notPick;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        int n = int(nums.size());
        this->n = n;
        int maxi = rec(0);
        this->maxi = maxi;
        int ans = f(0,0);
        return ans;
    }
};