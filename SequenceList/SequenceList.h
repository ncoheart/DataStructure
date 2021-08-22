//
// Created by njupt on 2021/8/21.
// 定义顺序表
//

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

#ifndef DATASTRUCTURE_SEQENCELIST_H
#define DATASTRUCTURE_SEQENCELIST_H

/*
 * 初始化链表
 * @param seqList   要初始化的顺序表
 * @param elemArray 初始化时要添加的元素内容数组
 * @param length    初始化时添加的元素个数
 * */
void InitList(SeqList *seqList, ElementType *elemArray, int length);

/*
 * 向顺序表中的index下标处插入某个元素
 * */
void InsertElement(SeqList *seqList, int index, ElementType element);

/*删除循序表中指定下标的元素
 * @return 返回删除的元素，如果删除失败，返回NULL
 * */
ElementType *DeleteElement(SeqList *seqList, int index);

ElementType *GetElement(SeqList *seqList, int index);

int GetLength(SeqList *seqList);

int IsEmpty(SeqList *seqList);

void PrintList(SeqList *seqList);

void ClearList(SeqList *seqList);

#endif //DATASTRUCTURE_SEQENCELIST_H
