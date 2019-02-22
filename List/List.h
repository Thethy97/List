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
//�Ƚ������˳������ȱ��
////˳���֧��������ʣ�������
////Ƶ���Ĳ���ɾ��������Ƶ�������������˳���
void PrintTailToHead(pList plist);//�����ӡ��������
//ɾ��һ����ͷ������ķ�β�ڵ�
void DelNodeNotTail(pNode pos);
//��ͷ������ǰ����һ���ڵ�
void InsertNode(pNode pos, DataType d);
//������ʵ��Լɪ��
void JosephusCycle(pList* pplist,DataType k);
//��������
void ReverseList(pList* pplist);
void ReverseList1(pList* pplist);//����ѭ��ͷ��
void BubbleSort(pList plist);//ð������
//�ϲ���������
pList MergeList(pList p1, pList p2);
pList MergeList_R(pList p1, pList p2);//�ݹ�
//����һ���ҵ�������м�ڵ�(����ָ��)
pNode FindMidNode(pList plist);
//���ҵ�����ĵ�����k���ڵ㣬ֻ����һ�Σ�����ָ�룬����k����
pNode FindKNode(pList plist,int k);
//�жϵ������Ƿ������(����ָ��)���������󻷳���
pNode IsCircle(pList plist);
int GetCircleLength(pNode meet);//������
//�һ�����ڵ�
//2*(x+y+ml) == x+y+nl
//x+y = nl-ml
//x+y = kl
//x = kl-y
pNode GetCycleEntryNode(pList plist, pNode meet);
//�ж����������Ƿ��ཻ
int CheckCross(pList p1, pList p2);
//�󽻵�
//���һ�����������һ�����������Բ������ཻ
pNode GetCrossNode(pList p1, pList p2);
