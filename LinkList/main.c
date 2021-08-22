//
// Created by njupt on 2021/8/22.
//
#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"

ElementType dataArray[] = {
		{1, "奇异博士"},
		{2, "托塔李天王"},
		{3, "菩提老祖"},
		{4, "弥勒佛"}
};

void TestLinkList();

int main()
{
	TestLinkList();
	return 0;
}

void TestLinkList()
{
	LinkList linkList;
	linkList.length = 0; //容易忽略的地方
	InitLinkList(&linkList, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
	ElementType element = DeleteLinkListElement(&linkList, 4);
	if(element.id != -999)
		printf("删除的元素是：%d %s\n", element.id, element.name);
	PrintLinkList(&linkList);
	ClearLinkList(&linkList);
	PrintLinkList(&linkList);
}