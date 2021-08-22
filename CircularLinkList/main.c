#include<stdio.h>
#include "CircularLinkList.h"

void TestCircularLinkList();

ElementType dataArray[] = {
		{1, "奇异博士"},
		{2, "托塔李天王"},
		{3, "菩提老祖"},
		{4, "弥勒佛"},
        {5, "奇异博士"},
		{6, "托塔李天王"},
		{7, "菩提老祖"},
		{8, "弥勒佛"}
};

int main()
{
    TestCircularLinkList();
    return 0;
}

void TestCircularLinkList()
{
    CircularLinkList *clList = (CircularLinkList*)malloc(sizeof(CircularLinkList));
    clList->length = 0;
    clList->next = NULL;
    InitCircularLinkList(clList, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
    DeleteCircularLinkList(clList, 4);
    PrintCircularLinkList(clList);
}