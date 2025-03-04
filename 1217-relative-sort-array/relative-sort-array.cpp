class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>result; 
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){ 
                if(arr1[j]==arr2[i]){
                    result.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }
    sort(arr1.begin(),arr1.end());
    for(int k=0;k<arr1.size();k++){
        if(arr1[k]!=-1)
        result.push_back(arr1[k]);
    }
return result;
  }
};