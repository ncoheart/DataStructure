//
// Created by ncoheart on 2021/8/28.
//

#include "DoublyLinkList.h"


void InsertDoublyLinkList(DoublyLinkList *dlList, int pos, ElementType element)
{
    DoublyNode *node = (DoublyNode*) malloc(sizeof(DoublyNode));
    node->data = element;
    node->prev = NULL;
    node->next = NULL;
    if(pos == 1)
    {
        node->next = dlList->next;
        if(node->next)
        {
            node->next->prev = node;
        }
        dlList->next = node;
        dlList->length++;
        return;
    }
    DoublyNode  *currNode = dlList->next;
    for(int i = 1; currNode && i < pos - 1; i++)
    {
        currNode = currNode->next;
    }
    if(currNode)
    {
        node->prev = currNode;
        if(currNode->next) //如果前置节点非空
        {
            currNode->next->prev = node;
        }
        node->next = currNode->next;
        currNode->next = node;
        dlList->length++;
    }
}

void PrintDoublyLinkList(DoublyLinkList *dlList)
{
    DoublyNode *node = dlList->next;
    if(!node || dlList->length == 0)
    {
        printf("链表为空，没有内容可以打印！\n");
        dlList->length = 0;
        return;
    }
    for(int i = 0; i < dlList->length; i++)
    {
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}