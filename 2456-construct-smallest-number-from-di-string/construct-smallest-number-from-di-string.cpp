class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result = "";
        vector<int> stack; 
        int index = 0;  
        for (int i = 0; i <= n; i++) {
            stack.push_back(i + 1);
            if (i == n || pattern[i] == 'I') {  
                while (!stack.empty()) {
                    result += to_string(stack.back());
                    stack.pop_back();
                }
            }
        }
        return result;
    }
};
