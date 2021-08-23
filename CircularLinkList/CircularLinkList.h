#ifndef DATASTRUCTURE_CIRCULARLINKLIST_H
#define DATASTRUCTURE_CIRCULARLINKLIST_H

/* 
循环链表最大特点：尾节点的next指向第一个节点
优点：能够通过任意节点遍历整个链表结构
 */
#include <stdio.h>
#include <stdlib.h>
#include "..//SequenceList//DataElement.h"

typedef struct CircularNode
{
    ElementType data;
    struct CircularNode *next;
}CircularNode;

typedef struct CircularLinkList
{
    CircularNode *next;     //指向第一个节点的指针
    int length;
}CircularLinkList;


/* 在循环链表的指定位置插入元素 */
void InsertCircularLinkList(CircularLinkList *circularLinkList, int pos, ElementType element);

void InitCircularLinkList(CircularLinkList *circularLinkList, ElementType *dataArray, int length);

ElementType DeleteCircularLinkList(CircularLinkList *clList, int pos);

void PrintCircularLinkList(CircularLinkList *circularLinkList);

/* 根据元素内容返回对应的结点指针 */
CircularNode *GetCircularLinkListNode(CircularLinkList *clList, ElementType element);

/* 根据给出的某个节点，遍历链表的每个元素 */
void PrintCircularLinkListByNode(CircularLinkList *clList, CircularNode *node);

#endif