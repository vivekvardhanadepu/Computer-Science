ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B<2)
        return A;
    if(!A)
        return NULL;
    int tempB = B;
    ListNode *prev = NULL, *current = A, *next = NULL;
    while(tempB--){
        next= current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    A->next = reverseListB(current, B);
    return prev;
}

// https://www.interviewbit.com/problems/k-reverse-linked-list/