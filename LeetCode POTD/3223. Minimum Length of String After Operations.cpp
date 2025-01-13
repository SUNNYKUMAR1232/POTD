// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/


// Approach 1: Using Brute Force
    int Solve(string& s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int left = -1, right = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == s[i]) {
                    left = j;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[i]) {
                    right = j;
                    break;
                }
            }
            if (left != -1 && right != -1) {
                s.erase(s.begin() + right);
                s.erase(s.begin() + left);
                n -= 2;
                i--;
            }
        }
        return s.size();
        // TC : O(n*n)
        // SC : O(1)
    }
// Approach 2: Using Hashing
/* 
 1. odd frequency only one element left after operation
 2. even frequency two element left after operation
 */
    int Solve(string& s) {
        int n = s.length();
        unordered_map<int ,int>mp;
        int ans=0;
        for (auto &ch:s) {
           mp[ch-'a']++;
        }
        for (auto &it:mp) {
            if(it.second>0)
               ans+=(it.second%2==0)?2:1;
        }
        return ans;
        // TC : O(n)
        // SC : O(n) 
    }