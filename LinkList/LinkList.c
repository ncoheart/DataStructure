//
// Created by njupt on 2021/8/22.
//
#include "LinkList.h"

void InitLinkList(LinkList *linkList, ElementType *dataArray, int length)
{
	for(int i = 0; i < length; ++i)
	{
		InsertLinkList(linkList,  i + 1, dataArray[i]);
	}
}

void InsertLinkList(LinkList *linkList, int pos, ElementType element)
{
	//1.创建空节点并为数据域赋值
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;
	//2.找到要插入位置的节点
	if(pos == 1)
	{
		linkList->next = node;
		linkList->length++;
		return;
	}
	//通过循环找到要插入的节点位置
	Node *currNode = linkList->next;
	for(int i = 1; currNode && i < pos - 1; ++i)
		currNode = currNode->next;
	//3.将节点插入并对接前面的节点
	if(currNode)
	{
		node->next = currNode->next;
		currNode->next = node;
		linkList->length++;
	}
}

void PrintLinkList(LinkList *linkList)
{
	Node *node = linkList->next;
	if(!node)
	{
		printf("链表为空！\n");
		linkList->length = 0;
		return;
	}
	for(int i = 0; i < linkList->length; ++i)
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
}

ElementType GetLinkListElement(LinkList *linkList, int pos)
{
	Node *node = linkList->next;
	for(int i = 1; node && i < pos; i++)
	{
		node = node->next;
	}
	return node->data;
}

int IsLinkListEmpty(LinkList *linkList)
{
	return linkList->length == 0 ? TRUE : FALSE;
}

ElementType DeleteLinkListElement(LinkList *linkList, int pos)
{
	ElementType element;	//被删除的元素
	element.id = -999;		//赋一个不可能的值，用来判断是否删除成功
	Node *node;
	if(pos == 1)
	{
		node = linkList->next;
		if(node)
		{
			element = node->data;
			linkList->next = node->next;
			free(node); //释放被删除节点的内存
			linkList->length--;
		}
		return element;
	}

	//1.找到要删除节点和它的前缀节点
	//2.要删除节点的next赋值给前缀节点的next
	//3.释放要删除的节点内存
	Node *preNode;	//前置节点
	node = linkList->next;
	for(int i = 1; node && i < pos; i++)
	{
		preNode = node;
		node = node->next;
	}
	if(node)
	{
		element = node->data;
		preNode->next = node->next;
		free(node);
		linkList->length--;
	}

	return element;
}

void ClearLinkList(LinkList *linkList)
{
	Node *node = linkList->next;
	Node *nextNode;
	while(node)
	{
		nextNode = node->next;
		free(node);
		node = nextNode;
	}
	linkList->next = NULL;
	linkList->length = 0;
	
}