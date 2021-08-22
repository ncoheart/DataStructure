cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_executable(SequenceList SequenceList/SequenceList.c SequenceList/DataElement.h SequenceList/SequenceList.h SequenceList/main.c)
add_executable(LinkList LinkList/LinkList.h LinkList/main.c SequenceList/DataElement.h LinkList/LinkList.c)
add_executable(CircularLinkList CircularLinkList/CircularLinkList.c CircularLinkList/CircularLinkList.h CircularLinkList/main.c)