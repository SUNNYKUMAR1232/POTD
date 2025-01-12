// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// Approach 1: Using Brute Force
//   1. When water store : if left>curr<right
//   2. ans=min(leftMax(0 to i-1),rightMax(i+1 to n))-arr[i];
    int Solve(vector<int>&arr){
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]=max(arr[i],left[i-1]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(arr[i],right[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int mn=min(left[i-1],right[i+1]);
            if(mn>arr[i])
            ans+=mn-arr[i];
        }
        return ans;
    }
    int maxWater(vector<int> &arr) {
        // code here
        return Solve(arr);
    }