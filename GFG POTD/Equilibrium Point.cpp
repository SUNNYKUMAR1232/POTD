 // https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
    int Solve(vector<int>&arr){
        int n=arr.size();
        if (n < 3) return -1; // Not possible to find such an index if size < 3
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        leftSum[0]=arr[0];
        for(int i=1;i<n;i++){
            leftSum[i]=arr[i]+leftSum[i-1];
        }
        rightSum[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightSum[i]=arr[i]+rightSum[i+1];
        }
        int ans=-1;
        for(int i=1;i<n-1;i++){
            if(leftSum[i-1]==rightSum[i+1]) {
                ans=i;
                break;
            }
        }
        return ans;
        // TC : O(n)
        // SC : O(2n)
    }