
// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

// // Appraoch 1: Using Brute Force
// int Solve(vector<int>&nums1,vector<int>&nums2){
//     vector<int>xr;
//     int n1=nums1.size();
//     int n2=nums2.size();
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//             xr.push_back(nums1[i]^nums2[j]);
//         }
//     }
//     int xors=0;
//     for(auto &it:xr){
//         xors^=it;
//     }
//     return xors;
//     // TC : O(n*n)
//     // SC : O(n)
// }
// Appraoch 2: Using Optimize
int Solve(vector<int>&nums1,vector<int>&nums2){
    vector<int>xr;
    int n1=nums1.size();
    int n2=nums2.size();
    int ne1=n1%2;
    int ne2=n2%2;
    int xors=0;
    for(int i=0;i<ne1*n2;i++){
        xors^=nums2[i];
    }
    for(int i=0;i<ne2*n1;i++){
        xors^=nums1[i];
    }
    return xors;
    // TC : O(n)
    // SC : O(1)
}
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        return Solve(nums1,nums2);
    }