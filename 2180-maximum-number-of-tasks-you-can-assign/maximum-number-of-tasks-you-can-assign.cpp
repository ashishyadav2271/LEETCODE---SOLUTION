class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0, r = min(tasks.size(), workers.size());
        while (l < r) {
            int m = (l + r + 1) / 2, i = workers.size() - 1, p = pills;
            deque<int> d;
            bool ok = true;
            for (int j = m - 1; j >= 0; --j) {
                if (!d.empty() && d.front() >= tasks[j])
                    d.pop_front();
                else if (i >= 0 && workers[i] >= tasks[j])
                    --i;
                else {
                    while (i >= 0 && workers[i] + strength >= tasks[j])
                        d.push_back(workers[i--]);
                    if (d.empty() || !p--) {
                        ok = false;
                        break;
                    }
                    d.pop_back();
                }
            }
            ok ? l = m : r = m - 1;
        }
        return l;
    }
};