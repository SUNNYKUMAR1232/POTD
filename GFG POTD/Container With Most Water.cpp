// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1
 // Approach 1: Using Brute Force
    int Solve(vector<int>&arr){
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mn=min(arr[i],arr[j]);
                ans=max(ans,mn*(j-i));
            }
        }
        return ans;
        // TC : O(n*n)
        // SC : O(1)
    }
      // Approach 2: Using Two Pointer
    //   How to decide to move pointer:
    //     - ans depends on minmum left so pointer is less than move 
    int Solve(vector<int>&arr){
        int n=arr.size();
        int ans=0;
        int left=0,right=n-1;
        while(left<right){
            int mn=min(arr[left],arr[right])*(right-left);
            ans=max(ans,mn);
            
            if(arr[left]<arr[right]){
                left++;
            }else right--;
        }
        return ans;
        // TC : O(n);
        // SC : O(1)
    }