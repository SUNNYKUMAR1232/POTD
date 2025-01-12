// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

    // Approach 1: Using Brute Force
    /* 
    why used index: 'open' ko balance kerne ke liye right side me 'close' chahiye jo index ke comparision se ho jayega
    1.  size is odd return false
    2.  locked='0' store in openClose(use as  '('||')')
    3.  locked='1' and s[i]=='(' store in open (use as open only);
    4.  s[i]=')' :
                - first check in open and pop
                - check in openClose and pop
                - return false
    5.  if still have element in open and openClose
               - while(!open.empty()&&!openClose.empty()&&open.top()<openClose.top) and pop
     */
    bool Solve(string& s, string& l) {
        int n = s.length();
        if (n % 2 != 0)
            return false;
        stack<int> open;
        stack<int> openClose;
        // WTC : O(n)
        for (int i = 0; i < n; i++) {
            if (l[i] == '0') {
                openClose.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else if (!openClose.empty())
                    openClose.pop();
                else
                    return false;
            }
        }
        // WTC : O(m)
        while (!open.empty() && !openClose.empty() &&
               open.top() < openClose.top()) {
            open.pop();
            openClose.pop();
        }
        return open.empty();
        // TC : O(2n)
        // SC : O(2n)
    }
    // Approach 2: Optimize Space
    /* 
      used logic to balance :
             - open need close in right side
             - close need open in left side
     */
    bool Solve(string& s, string& l) {
        int n = s.length();
        if (n % 2 != 0)
            return false;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('||l[i]=='0') open++;
            else if(s[i]==')'&&l[i]=='1') open--;
            if(open<0) return false;
        }
        int close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'||l[i]=='0') close++;
            else if(s[i]=='('&&l[i]=='1') close--;
            if(close<0) return false;
        }
        return true;
        // TC : O(2n)
        // SC : O(1)
    }