// https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

//   // Approach 1: Using Brute Force
//   bool isValid(vector<int>&arr,int start,int end){
//       int ones=0,zeros=0;
//       for(int i=start;i<=end;i++){
//           if(arr[i]==1) ones++;
//           else zeros++;
//       }
//       return zeros==ones;
//   }
//   int Solve(vector<int>&arr){
//       int n=arr.size();
//       int maxLen=0;
//       for(int i=0;i<n;i++){
//           if(maxLen>(n-i)) break;
//           for(int j=i;j<n;j++){
//               if(isValid(arr,i,j)){
//                   maxLen=max(maxLen,j-i+1);
//               }
//           }
//       }
//       return maxLen;
//       // TC : O(n*n*n)
//       // SC : O(1)
//   }
//   // Approach 2: Using Hashing
//   bool isValid(vector<int>&arr,unordered_map<int,int>&mp){
//       return mp[0]==mp[1];
//   }
//   int Solve(vector<int>&arr){
//       int n=arr.size();
//       int maxLen=0;
//       for(int i=0;i<n;i++){
//           if(maxLen>(n-i)) break;
//           unordered_map<int,int>mp;
//           for(int j=i;j<n;j++){
//               mp[arr[j]]++;
//               if(isValid(arr,mp)){
//                   maxLen=max(maxLen,j-i+1);
//               }
//           }
//       }
//       return maxLen;
//       // TC : O(n*n)
//       // SC : O(n)
//   }
  // Approach 3: Using Two Pointer
  // Convert this problem to logest subarray of sum =0 bu converting 0 to -1
   int Solve(vector<int>&arr){
       int n=arr.size();
       unordered_map<int,int>mp;
       int maxLen=0;
       int sum=0;
       for(int i=0;i<n;i++){
           sum+=(arr[i]==0)?-1:1;
           
           if(sum==0) maxLen=i+1;
           
           if(mp.find(sum)!=mp.end()){
               maxLen=max(maxLen,i-mp[sum]);
           }else mp[sum]=i;
       }
       return maxLen;
       // TC : O(n)
       // SC : O(n)
   }
    int maxLen(vector<int> &arr) {
        // Your code here
        return Solve(arr);
    }