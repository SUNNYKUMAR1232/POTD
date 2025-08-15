# Day 1 15-08-25 GFG POTD

## 🗝️ Key Points

1. **Visualize interval problems using a number line.**
2. **Sort intervals by start time.**
3. **Intervals overlap if** `end >= start`.

---

## 💡 Brute Force Approach

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
```

---

## ⚡ In-Place Approach

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < (int)intervals.size() - 1;) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + (i + 1));
            } else {
                i++;
            }
        }
        return intervals;
    }
};
```
