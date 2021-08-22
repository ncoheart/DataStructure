//
// Created by njupt on 2021/8/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"
ElementType dataArray[] = {
		{1, "奇异博士"},
		{2, "美国队长"},
		{3, "菩提老祖"},
		{4, "玉皇大帝"}
};

void TestSequenceList();

int main()
{
	TestSequenceList();
	return 0;
}

void TestSequenceList()
{
	SeqList seqList;
	InitList(&seqList, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
	ElementType *delElement = DeleteElement(&seqList, 2);
	printf("被删除的元素：%d %s\n", delElement->id, delElement->name);
	free(delElement);
	PrintList(&seqList);
	printf("顺序表的长度为%d\n", GetLength(&seqList));
}