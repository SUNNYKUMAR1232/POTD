// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

    // // Approach 1: Using Stack
    // Node* Solve(struct Node* head){
    //     struct Node* mover=head;
    //     stack<int>st;
    //     while(mover){
    //         st.push(mover->data);
    //         mover=mover->next;
    //     }
    //     mover=head;
    //     while(!st.empty()){
    //         int top=st.top();
    //         st.pop();
    //         if(mover){
    //         mover->data=top;
    //         mover=mover->next;
    //         }
    //     }
    //     return head;
    //     // TC : O(n)
    //     // SC : O(n)
    // }
    // Approach 2: Optimize Space
    Node* Solve(struct Node* head){
        struct Node* mover=head;
        struct Node* prev=NULL;
        struct Node* curr=head;
        while(mover){
            struct Node* temp=mover->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            mover=temp;
        }
        return prev;
        // TC : O(n)
        // SC : O(1)
    }