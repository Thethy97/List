#include"List.h"

void InitList(pList* pplist)//pplist为指向头节点的地址的指针
{
	assert(pplist != NULL);//plist中存放一节点的地址
	*pplist = NULL;
}
void PrintList(pList plist)
{
	pNode cur = plist;
	while (cur != NULL)
	{	
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
void DestroyList(pList* pplist)
{
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}


pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}
void PushBack(pList* pplist, DataType d)
{
	if (*pplist == NULL)//空链表
	{
		pNode newNode = BuyNode(d);
		*pplist = newNode;
	}
	else//非空
	{
		pNode cur = *pplist;
		pNode newNode = BuyNode(d);
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PopBack(pList* pplist)//尾删
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
void PushFront(pList* pplist, DataType d)
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	newNode	= BuyNode(d);
	newNode->next = *pplist;
	*pplist = newNode;
}
void PopFront(pList* pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		pNode del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
	}
}
int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void Insert(pList* pplist,pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	pNode cur = *pplist;
	if (pos == cur)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;//*pplist为指针，存放第一个节点的地址
		*pplist = newNode;
	}
	else
	{
		while (cur && cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			newNode = BuyNode(d);
			newNode->next = pos;
			cur->next = newNode;
		}
	}
}
void Erase(pList *pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);

	if (pos == *pplist)
	{
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else 
	{	
		pNode cur = *pplist;
		while (cur && cur->next!= pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = pos->next;
			free(pos);
		}
	}
}
void Remove(pList *pplist, DataType d)//删除
{
	assert(pplist != NULL);
	/*assert(*pplist != NULL);
	pNode del = *pplist;
	if (del->data == d)
	{
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else
	{
		pNode cur = *pplist;
		pNode prev = NULL;
		while (cur && cur->next->data != d)
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = 
		}
	}*/
	pNode cur = NULL;
	pNode prev = NULL;
	*pplist = cur;
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist = cur)//是第一个节点
			{
				PopFront(pplist);
			}
			else//不是
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode cur = NULL;
	pNode prev = NULL;
	*pplist = cur;
	while (cur)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//是第一个节点
			{
				PopFront(pplist);
				cur = *pplist;
			}
			else//不是
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
//面试题
void PrintTailToHead(pList plist)//逆序打印单向链表
{
	////递归
	////4，3，2，1
	//if (plist == NULL)
	//	return;
	//PrintTailToHead(plist->next);
	//printf("%d", plist->data);
	//非递归
	if (plist == NULL)
		return;
	if (plist->next == NULL)
	{
		printf("%d\n", plist->data);
		return;
	}
	pNode cur = plist;
	pNode tail = NULL;
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)//让cur指向最后一个节点
		{
			cur = cur->next;
		}
		printf("%d", cur->data);
		tail = cur;//更新节点tail，让tail向前一位
	}
}
void DelNodeNotTail(pNode pos)
{
	assert(pos != NULL);
	assert(pos->next != NULL);
	//替换删除法
	pNode del = pos->next;
	//移动数据
	pos->data = pos->next->data;
	//删除下一个节点
	pos->next = del->next;
	free(del);
	del = NULL;
}
//无头单链表前插入一个节点
void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	//替换法（把当前节点替换成后一个节点，删除或插入后一个节点）
	assert(pos != NULL);
	
	/*newNode =BuyNode(d);
	newNode->next = pos->next;
	pos->next = newNode;

	int tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;*/

	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;

	pos->data = d;
}
void JosephusCycle(pList* pplist, DataType k)
{
	pNode cur = *pplist;

	while (cur != cur->next)
	{
		int count = k;
		pNode del = NULL;
		while (--k)
		{
			cur = cur->next;
		}
		printf("删除:%d\n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
}
void ReverseList(pList* pplist)//逆序
{
	assert(pplist != NULL);
	/*pNode cur = *pplist;
	pNode tail = NULL;
	while (cur->next != NULL)
	{
		tail = cur->next;
	}
	while (cur->next != tail)
	{
		
	}*/
	pNode n1, n2, n3;
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)
		return;
	n1 = *pplist;
	n2 = n1->next;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;//n2指向n1
		n1 = n2;//指针整体后移
		n2 = n3;
		if(n3 != NULL)
			n3 = n3->next;
	}
	(*pplist)->next = NULL;
	*pplist = n1;
}
void ReverseList1(pList* pplist)//逆序
{
	pNode head = NULL;
	pNode cur = NULL;
	pNode tmp = NULL;

	assert(pplist != NULL);
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)
		return;
	cur = *pplist;//指向链表的第一个节点
	tmp = cur->next;

	while (cur != NULL)
	{
		cur->next = head;//cur指向的节点头插到链表，下一个节点继续头插
		head = cur;
		cur = tmp;
		if (tmp != NULL)
			tmp = tmp->next;
	}
	*pplist = head;
}
void BubbleSort(pList plist)
{
	pNode tail = NULL;
	if ((plist == NULL) || (plist->next == NULL))
		return;
	while (plist != tail)//趟数
	{
		pNode cur = plist;
		pNode next = cur->next;
		int flag = 0;
		while (next != tail)
		{
			if (cur->data > next->data)
			{
				DataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
				flag = 1;
			}
			cur = next;
			next = cur->next;
		}
		tail = cur;
		if (flag == 0)
			return;
	}
}
pList MergeList(pList p1, pList p2)
{
	if (p1 == NULL && p2 != NULL)
		return p2;
	if (p1 != NULL && p2 == NULL)
		return p1;
	if (p1 == NULL && p2 == NULL)
		return NULL;
	if (p1 == p2)
		return NULL;
	pList newlist = NULL;
	pNode tail = NULL;
	if (p1->data < p2->data)
	{
		newlist = p1;
		p1 = p1->next;
	}
	else
	{
		newlist = p2;
		p2 = p2->next;
	}
	tail = newlist;
	//两条链表找小的元素尾插
	while ((p1!= NULL) && (p2!= NULL))
	{
		if (p1->data < p2->data)
		{
			tail->next = p1;
			p1 = p1->next;
		}
		else
		{
			tail->next = p2;
			p2 = p2->next;
		}
		tail = tail->next;
	}
	//追加剩余元素
	if (p1 == NULL)
	{
		tail->next = p2;
	}
	else if (p2 == NULL)
	{
		tail->next = p1;
	}
	return newlist;
}
pList MergeList_R(pList p1, pList p2)
{
	if (p1 == NULL && p2 != NULL)
		return p2;
	if (p1 != NULL && p2 == NULL)
		return p1;
	if (p1 == NULL && p2 == NULL)
		return NULL;
	if (p1 == p2)
		return NULL;
	pList newlist = NULL;
	pNode tail = NULL;
	if (p1->data < p2->data)
	{
		newlist = p1;
		newlist->next = MergeList_R(p1->next, p2);
	}
	else
	{
		newlist = p2;
		newlist->next = MergeList_R(p1, p2->next);
	}
}
//遍历一次找到链表的中间节点(快慢指针)
pNode FindMidNode(pList plist)
{
	if ((plist == NULL) || (plist->next == NULL))
		return plist;
	pNode fp = NULL;//快指针走两格
	pNode sp = NULL;//慢指针走一格
	fp = plist;
	sp = plist;
	while ((fp != NULL) && (fp->next != NULL))
	{
		fp = fp->next->next;
		sp = sp->next;
	}
	return sp;
}

pNode FindKNode(pList plist,int k)
{
	if ((plist == NULL) || (plist->next == NULL))
		return plist;
	pNode fp = plist;//快指针先走k格
	pNode sp = plist;//慢指针走一格
	while(k--)
	{
		if (fp == NULL)
			return NULL;
		fp = fp->next;
	}
	while (fp != NULL)
	{
		fp = fp->next;
		sp = sp->next;
	}
	return sp;
}
pNode IsCircle(pList plist)//带环
{
	pNode fp = plist;
	pNode sp = plist;
	if (plist == NULL)
		return plist;
	while ((fp != NULL) && (fp->next != NULL))
	{
		fp = fp->next->next;
		sp = sp->next;
		if (fp = sp)
			return sp;
	}
	return NULL;
}

int GetCircleLength(pNode meet)//环长度
{
	pNode cur = NULL;
	int len = 1;
	assert(meet != NULL);
	cur = meet->next;
	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
//2*(x+y+ml) == x+y+nl
//x+y = nl-ml
//x+y = kl
//x = kl-y
pNode GetCycleEntryNode(pList plist, pNode meet)//环的入口点
{
	pNode cur = plist;
	if (plist == NULL)
		return plist;
	assert(meet != NULL);
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return cur;
}
int CheckCross(pList p1, pList p2)//链表是否相交
{
	pNode end1 = p1;
	pNode end2 = p2;
	if ((p1 == NULL) || (p2 == NULL))
		return 0;
	while (end1->next != NULL)
	{
		end1 = end1->next;
	}while (end2->next != NULL)
	{
		end2 = end2->next;
	}
	return end1 == end2;
}
//求交点
pNode GetCrossNode(pList p1, pList p2)
{
	pNode cur1 = p1;
	pNode cur2 = p1;
	int len1 = 0,len = 0,len2 = 0;
	while (cur1->next != NULL)
	{
		len1++;
		cur1 = cur1->next;
	}
	cur1 = p1;
	while (cur2->next != NULL)
	{
		len2++;
		cur2 = cur2->next;
	}
	cur2 = p2;
	//len = abs(len1-len2);
	if (len1 > len2)
	{
		len = len1 - len2;
		while (len--)
		{
			cur1 = cur1->next;
		}
	}
	else
	{
		len = len2 - len1;
		while (len--)
		{
			cur2 = cur2->next;
		}
	}
	while(cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}