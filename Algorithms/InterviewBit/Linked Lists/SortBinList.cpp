ListNode* Solution::solve(ListNode* A) {
    ListNode *nextPos = A, *node=A;
    while(node!=NULL){
        if(!node->val){
            if(nextPos!=node){
                node->val=1;
                nextPos->val=0;
            }
            nextPos = nextPos->next;
        }
        node = node->next;
    }
    return A;
}

// https://www.interviewbit.com/problems/sort-binary-linked-list/