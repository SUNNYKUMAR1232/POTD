// https://leetcode.com/problems/neighboring-bitwise-xor/

    // // Approach 1: Using Bit Manipulation
    // bool Solve(vector<int>& d) {
    //     int xr = 0;
    //     for (auto& it : d)
    //         xr ^= it;
    //     return xr == 0;
    //     // TC : O(n)
    //     // SC : O(1)
    // }
    // Approach 2: Using accumutate fuction
    bool Solve(vector<int>& d) {
        return accumulate(d.begin(),d.end(),0,bit_xor<>())==0;
        // TC : O(n)
        // SC : O(1)
    }
    bool doesValidArrayExist(vector<int>& derived) { return Solve(derived); }