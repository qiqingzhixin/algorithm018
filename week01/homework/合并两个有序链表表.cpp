//
// Created by Administrator on 2020/10/25.
//

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode();
    ListNode *p = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        } else {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    if (l1 == NULL) {
        p->next = l2;
    } else {
        p->next = l1;
    }
    return head->next;
}