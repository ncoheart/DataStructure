//
// Created by ncoheart on 2021/8/28.
// 双向链表
//

#ifndef DATASTRUCTURE_DOUBLYLINKLIST_H
#define DATASTRUCTURE_DOUBLYLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "..//SequenceList//DataElement.h"

/*双向链表的节点*/
typedef struct DoublyNode{
    ElementType data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
}DoublyNode;

/*双向链表*/
typedef struct DoublyLinkList{
    int length;
    DoublyNode *next;
}DoublyLinkList;

void InsertDoublyLinkList(DoublyLinkList *dlList, int pos, ElementType element);

void PrintDoublyLinkList(DoublyLinkList *dlList);

#endif //DATASTRUCTURE_DOUBLYLINKLIST_H
