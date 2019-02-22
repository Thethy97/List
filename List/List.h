#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>  
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node,*pNode,*pList;

void PrintList(pList plist);
pNode BuyNode(DataType d);

void InitList(pList* pplist);
void DestroyList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PopFront(pList* pplist);
void PushFront(pList* pplist, DataType d);
int GetListLength(pList plist);
void Erase(pList *pplist, pNode pos);
void Insert(pList* pplist,pNode pos, DataType d);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
//比较链表和顺序表的优缺点
////顺序表支持随机访问，链表不行
////频繁的插入删除用链表，频繁的随机访问用顺序表
void PrintTailToHead(pList plist);//逆序打印单向链表
//删除一个无头单链表的非尾节点
void DelNodeNotTail(pNode pos);
//无头单链表前插入一个节点
void InsertNode(pNode pos, DataType d);
//单链表实现约瑟夫环
void JosephusCycle(pList* pplist,DataType k);
//逆序链表
void ReverseList(pList* pplist);
void ReverseList1(pList* pplist);//逆序，循环头插
void BubbleSort(pList plist);//冒泡排序
//合并两个链表
pList MergeList(pList p1, pList p2);
pList MergeList_R(pList p1, pList p2);//递归
//遍历一次找到链表的中间节点(快慢指针)
pNode FindMidNode(pList plist);
//查找单链表的倒数第k个节点，只遍历一次（快慢指针，先走k步）
pNode FindKNode(pList plist,int k);
//判断单链表是否带环？(快慢指针)若带环，求环长度
pNode IsCircle(pList plist);
int GetCircleLength(pNode meet);//环长度
//找环的入口点
//2*(x+y+ml) == x+y+nl
//x+y = nl-ml
//x+y = kl
//x = kl-y
pNode GetCycleEntryNode(pList plist, pNode meet);
//判断两条链表是否相交
int CheckCross(pList p1, pList p2);
//求交点
//如果一条链表带环，一条不带，绝对不可能相交
pNode GetCrossNode(pList p1, pList p2);
