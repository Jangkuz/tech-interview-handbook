#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
int insertAtTheEnd(struct ListNode **head, int val)
{
    if (*head == NULL)
    {
        *head = createNode(val);
        return 0;
    }

    struct ListNode *newNode = createNode(val);
    struct ListNode *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    // printf("Current->next->val: %d\n", current->next->val);
    return 0;
}

int printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
    return 0;
}
int freeList(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *next;
    while (current->next != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
int combineTwoList(struct ListNode *head1, struct ListNode *head2, struct ListNode **result)
{
    struct ListNode *current1 = head1;
    struct ListNode *current2 = head2;

    while (current1 != NULL || current2 != NULL)
    {
        if (current1 == NULL && current2 != NULL)
        {
            insertAtTheEnd(result, current2->val);
            current2 = current2->next;
        }
        if (current2 == NULL && current1 != NULL)
        {
            insertAtTheEnd(result, current1->val);
            current1 = current1->next;
        }
        if (current1 != NULL && current2 != NULL)
        {
            if (current1->val <= current2->val)
            {
                insertAtTheEnd(result, current1->val);
                current1 = current1->next;
            }
            if (current2->val < current1->val)
            {
                insertAtTheEnd(result, current2->val);
                current2 = current2->next;
            }
        }
    }

    return 0;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    //THIS IS THE CORRECT ANSWER
    if(!list1) return list2;
    if(!list2) return list1;
    struct ListNode* itteratorl1,* backOfNewList;
    if(list1->val > list2->val){
        backOfNewList = list2;
        list2 = list1;
        list1 = backOfNewList;
    }else{
        backOfNewList = list1;
    }
    itteratorl1 = list1->next;
    while(itteratorl1 && list2){
        if(itteratorl1->val < list2->val){
            backOfNewList->next = itteratorl1;
            itteratorl1 = itteratorl1->next;
        }else{
            backOfNewList->next = list2;
            list2 = list2->next;
        }
        backOfNewList = backOfNewList->next;
    }
    while(itteratorl1){
        backOfNewList->next = itteratorl1;
        itteratorl1 = itteratorl1->next;
        backOfNewList = backOfNewList->next;
    }
    while(list2){
        backOfNewList->next = list2;
        list2 = list2->next;
        backOfNewList = backOfNewList->next;
    }
    return list1;
}


int main()
{
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *resultList = NULL;
    // head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    // head2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    int array1[10] = {1, 3, 5, 6, 7, 9, 23};
    int array2[10] = {1, 2, 4, 5, 6, 8, 9, 10};
    int i;
    for (i = 0; i < 10; i++)
    {
        insertAtTheEnd(&head1, array1[i]);

        insertAtTheEnd(&head2, array2[i]);
    }
    combineTwoList(head1, head2, &resultList);
    printLinkedList(head1);
    printLinkedList(head2);
    printLinkedList(resultList);
    freeList(head1);
    freeList(head2);
    freeList(resultList);
    free(head1);
    free(head2);
    free(resultList);
    return 0;
}
