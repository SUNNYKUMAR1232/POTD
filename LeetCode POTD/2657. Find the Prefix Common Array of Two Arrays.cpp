    //https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
    
    // Approach 1: Using Brute Force
    // vector<int> Solve(vector<int>& A, vector<int>& B) {
    //     vector<int> ans;
    //     int n = A.size();
    //     int cnt = 0;
    //     unordered_set<int> st;
    //     for (int i = 0; i < n; i++) {
    //         if (st.find(A[i]) != st.end())
    //             cnt++;
    //         if (st.find(B[i]) != st.end())
    //             cnt++;
    //         if (A[i] == B[i])
    //             cnt++;
    //         st.insert(A[i]);
    //         st.insert(B[i]);
    //         ans.push_back(cnt);
    //     }
    //     return ans;
    //     // TC : O(n)
    //     // SC : O(n)
    // }
    // Approach 2: improve insert time and find time 
    vector<int> Solve(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans,fre(n+1,0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            fre[A[i]]++;
            if(fre[A[i]]==2) cnt++;
            fre[B[i]]++;
            if(fre[B[i]]==2) cnt++;
            ans.push_back(cnt);
        }
        return ans;
        // TC : O(n)
        // SC : O(n)
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        return Solve(A, B);
    }