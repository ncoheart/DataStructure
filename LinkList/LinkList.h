//
// Created by njupt on 2021/8/22.
// 链表抽象数据类型的实现
//
#include <stdio.h>
#include <stdlib.h>
#include "..//SequenceList//DataElement.h"

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

/*定义链表的节点，包含数据域和指针域*/
typedef struct Node {
	ElementType data;
	struct Node *next;
}Node;

/* 头节点
 * 注意：定义链表时，习惯性的会定义头节点，
 * 以便对链表头节点进行插入和删除
 * 头节点也可以称为首元节点
 * 最后一个节点叫做尾元节点
 * */
typedef struct LinkList {
	Node *next; // 头指针（如果链表有头节点）
	int length;
}LinkList;

/*初始化链表*/
void InitLinkList(LinkList *linkList, ElementType *dataArray, int length);

/*在指定的位置pos处插入元素element
 * */
void InsertLinkList(LinkList *linkList, int pos, ElementType element);

void PrintLinkList(LinkList *linkList);

ElementType GetLinkListElement(LinkList *linkList, int pos);

int IsLinkListEmpty(LinkList *linkList);

/* 删除并返回指定位置的元素 */
ElementType DeleteLinkListElement(LinkList *linkList, int pos);

void ClearLinkList(LinkList *linkList);

#endif //DATASTRUCTURE_LINKLIST_H