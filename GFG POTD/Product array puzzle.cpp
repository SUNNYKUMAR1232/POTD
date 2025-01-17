// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

//   // Approach 1: Using Brute Force
//   vector<int>Solve(vector<int>&arr){
//       vector<int>ans;
//       int n=arr.size();
//       for(int i=0;i<n;i++){
//           int mult=1;
//           for(int j=0;j<n;j++){
//               if(i!=j) mult*=arr[j];
//           }
//           ans.push_back(mult);
//       }
//       return ans;
//       // TC : O(n*n)
//       // SC : O(n)
//   }
   // Approach 1: Using Otimize
   vector<int>Solve(vector<int>&arr){
       vector<int>ans;
       int n=arr.size();
        int total_multi=1;
        int flag=1;
        int cnt=0;
       for(int i=0;i<n;i++){
              if(arr[i]!=0){
               total_multi*=arr[i];
              }else {cnt++; flag=0;};
       }
       for(int i=0;i<n;i++){
           if(cnt>=2)
               ans.push_back(0);
             else if(cnt==1) ans.push_back(arr[i]==0?total_multi:0);
             else ans.push_back(total_multi/arr[i]);
       }
       return ans;
       // TC : O(n)
       // SC : O(n)
   }
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        return Solve(arr);
    }