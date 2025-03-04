class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size();
        unordered_map<int,int> a2i;
        for(int i=0; i<n2; i++)
            a2i[arr2[i]]=i;
        for(int i = 0 ; i < arr1.size() ;i++)
        {
            if(a2i.count(arr1[i]) == 0)
            {
                a2i[arr1[i]] = arr1.size();
            }
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if (a2i[x]==a2i[y]) return x<y;
            return a2i[x]<a2i[y];
        });
        return arr1;  
    }
};