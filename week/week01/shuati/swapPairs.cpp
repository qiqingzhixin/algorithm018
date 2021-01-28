//
// Created by Administrator on 2020/10/22.
//


/**
 * 递归形式
 * @param head
 * @return
 */
ListNode *swapPairs3(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *p = head->next;
    head->next = swapPairs3(p->next);
    p->next = head;
    return p;
}

/**
 *
 * @param head
 * @return
 */
ListNode *swapPairs2(ListNode *head) {
    ListNode *p = head;
    ListNode *top = NULL;
    ListNode *tail = NULL;
    head = NULL;
    //头插法将两个节点倒叙
    while (p != NULL) {
        top = p;
        p = p->next;
        if (p != NULL) {
            tail = p;
            p = p->next;
            tail->next = head;
            head = top;
        } else {
            top->next = head;
            head = top;
        }
    }
    //头插法将所有的倒叙
    p = head;
    head = NULL;
    while (p != NULL) {
        top = p;
        p = p->next;
        top->next = head;
        head = top;
    }
    return head;
}