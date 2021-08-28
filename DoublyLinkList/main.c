//
// Created by ncoheart on 2021/8/28.
//

#include "DoublyLinkList.h"

ElementType dataArray[] = {
        {1, "奇异博士"},
        {2, "托塔李天王"},
        {3, "菩提老祖"},
        {4, "弥勒佛"}
};

int main()
{
    DoublyLinkList dlList;
    dlList.next = NULL;
    dlList.length = 0;
    InsertDoublyLinkList(&dlList, 1, dataArray[0]);
    PrintDoublyLinkList(&dlList);
    return 0;
}