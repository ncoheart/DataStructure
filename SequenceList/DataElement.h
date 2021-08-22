//
// Created by njupt on 2021/8/21.
// 数据元素
//

#ifndef DATASTRUCTURE_DATAELEMENT_H
#define DATASTRUCTURE_DATAELEMENT_H

#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

//1.定义数据元素
//typedef int ElementType;
typedef struct {
	int id;
	char *name;
}ElementType;

//2.定义顺序表结构
typedef struct {
	ElementType datas[MAX_SIZE];
	int length;
}SeqList;

#endif //DATASTRUCTURE_DATAELEMENT_H
