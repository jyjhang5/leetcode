#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

void showListNode(ListNode list)
{

    while (1) {
        printf("%d ", list.val);
        if (list.next == NULL) break;
        list = *list.next;
    }
    printf("\n");
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) 
{
    int x, y, sum, carry = 0;
    struct ListNode *resultHead = NULL, *resultTail = NULL;

    while (1) {
        x = 0;
        y = 0;

        if (l1 == NULL && l2 == NULL) break;
        if (l1 != NULL) x = l1->val;
        if (l2 != NULL) y = l2->val;
        sum = x + y + carry;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        carry = sum / 10;

        if (resultHead == NULL) {
            resultHead = newNode;
            resultTail = resultHead;
        }
        else {
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        resultTail->next = newNode;
        resultTail = resultTail->next;
    }

    return resultHead;
}

int main()
{
    struct ListNode l1_1 = {9, NULL};
    struct ListNode l1_2 = {4, NULL};
    struct ListNode l1_3 = { 3, NULL};
    l1_1.next = &l1_2;
    l1_2.next = &l1_3;
    // showListNode(l1_1);

    struct ListNode l2_1 = {1, NULL};
    struct ListNode l2_2 = {6, NULL};
    struct ListNode l2_3 = {4, NULL};
    l2_1.next = &l2_2;
    l2_2.next = &l2_3;
    // showListNode(l2_1);

    struct ListNode *result = addTwoNumbers(&l1_1, &l2_1);
    showListNode(*result);
    // TODO: free ListNode;
}