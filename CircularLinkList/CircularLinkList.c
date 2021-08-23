#include "CircularLinkList.h"
#include <string.h>

void InsertCircularLinkList(CircularLinkList *circularLinkList, int pos, ElementType element)
{
    CircularNode *node = (CircularNode*)malloc(sizeof(CircularNode));
    node->data = element;
    node->next = NULL;
    if(pos == 1)
    {
        node->next = circularLinkList->next;
        if(!node->next) //如果插入的链表长度为0
        {
            node->next = node;
        }else
        {
            //如果长度不为0，就要修改链表最后一个节点的指针域
            CircularNode *lastNode = circularLinkList->next;
            for(int i = 1; i < circularLinkList->length; i++)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
        circularLinkList->next = node;
        circularLinkList->length++;
        return;
    }
    //插入的不是第一个节点
    CircularNode *currNode = circularLinkList->next;
    for(int i = 1; currNode && i < pos - 1; i++)
    {
        currNode = currNode->next;
    }
    if(currNode)
    {
        node->next = currNode->next;
        currNode->next = node;
        circularLinkList->length++;
        if(pos == circularLinkList->length)
        {
            node->next = circularLinkList->next;
        }
    }
}

void InitCircularLinkList(CircularLinkList *clList, ElementType *dataArray, int length)
{
    for(int i = 0; i < length; i++)
    {
        InsertCircularLinkList(clList, i + 1, dataArray[i]);
    }
}

ElementType DeleteCircularLinkList(CircularLinkList *clList, int pos)
{
    ElementType element;
    element.id = -999;
    if(pos == 1)
    {
        CircularNode *node = clList->next;
        if(node)
        {
            element = node->data;
            //找到最后一个节点，改变其指针域的指向
            CircularNode *lastNode = clList->next;
            for(int i = 1;i < clList->length; i++)
            {
                lastNode = lastNode->next;
            }
            clList->next = node->next;
            lastNode->next = clList->next;
            free(node);
            clList->length--;
        }
        return element;
    }
    CircularNode *preNode;
    CircularNode *node = clList->next;
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
        clList->length--;
    }
    return element;
}

void PrintCircularLinkList(CircularLinkList *circularLinkList)
{
    if(circularLinkList->length == 0 || !circularLinkList->next)
    {
        printf("链表长度为空，没有内容可以打印！\n");
        circularLinkList->length = 0;
        return;
    }
    CircularNode *node = circularLinkList->next;
    for(int i = 0; i < circularLinkList->length; i++)
    {
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }      
}

CircularNode *GetCircularLinkListNode(CircularLinkList *clList, ElementType element)
{
    CircularNode *node = clList->next;
    if(!node)
        return NULL;
    //不用循环变量i来遍历
    do
    {
        if(element.id == node->data.id && !strcmp(element.name, node->data.name))
        {
            return node;
        }
        node = node->next;
    } while (node != clList->next);
    
    return NULL;
}

void PrintCircularLinkListByNode(CircularLinkList *clList, CircularNode *node)
{
    if(!clList->next)
    {
        printf("链表长度为空，没有内容可以打印！\n");
        return;
    }
    // 记录初始的node节点
    CircularNode *oriNode = node;
    do
    {
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    } while (node != oriNode);
    
}