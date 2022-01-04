int Solution::solve(ListNode* A, int B) {
    ListNode *fast = A, *slow = A;
    if(A==NULL){
        return -1;
    }

    int count =1;
    while(fast && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }

    //slow is the  middle element
    if(count<=B)
        return -1;
    
    fast = A;
    int k = count-B-1;
    while(k){
        fast = fast->next;
        k--;
    }

    return fast->val;
}

// https://www.interviewbit.com/problems/kth-node-from-middle/