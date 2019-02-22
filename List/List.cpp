#include"List.h"

void InitList(pList* pplist)//pplistΪָ��ͷ�ڵ�ĵ�ַ��ָ��
{
	assert(pplist != NULL);//plist�д��һ�ڵ�ĵ�ַ
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
	if (*pplist == NULL)//������
	{
		pNode newNode = BuyNode(d);
		*pplist = newNode;
	}
	else//�ǿ�
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
void PopBack(pList* pplist)//βɾ
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
		newNode->next = *pplist;//*pplistΪָ�룬��ŵ�һ���ڵ�ĵ�ַ
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
void Remove(pList *pplist, DataType d)//ɾ��
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
			if (*pplist = cur)//�ǵ�һ���ڵ�
			{
				PopFront(pplist);
			}
			else//����
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
			if (*pplist == cur)//�ǵ�һ���ڵ�
			{
				PopFront(pplist);
				cur = *pplist;
			}
			else//����
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
//������
void PrintTailToHead(pList plist)//�����ӡ��������
{
	////�ݹ�
	////4��3��2��1
	//if (plist == NULL)
	//	return;
	//PrintTailToHead(plist->next);
	//printf("%d", plist->data);
	//�ǵݹ�
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
		while (cur->next != tail)//��curָ�����һ���ڵ�
		{
			cur = cur->next;
		}
		printf("%d", cur->data);
		tail = cur;//���½ڵ�tail����tail��ǰһλ
	}
}
void DelNodeNotTail(pNode pos)
{
	assert(pos != NULL);
	assert(pos->next != NULL);
	//�滻ɾ����
	pNode del = pos->next;
	//�ƶ�����
	pos->data = pos->next->data;
	//ɾ����һ���ڵ�
	pos->next = del->next;
	free(del);
	del = NULL;
}
//��ͷ������ǰ����һ���ڵ�
void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	//�滻�����ѵ�ǰ�ڵ��滻�ɺ�һ���ڵ㣬ɾ��������һ���ڵ㣩
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
		printf("ɾ��:%d\n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
}
void ReverseList(pList* pplist)//����
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
		n2->next = n1;//n2ָ��n1
		n1 = n2;//ָ���������
		n2 = n3;
		if(n3 != NULL)
			n3 = n3->next;
	}
	(*pplist)->next = NULL;
	*pplist = n1;
}
void ReverseList1(pList* pplist)//����
{
	pNode head = NULL;
	pNode cur = NULL;
	pNode tmp = NULL;

	assert(pplist != NULL);
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)
		return;
	cur = *pplist;//ָ������ĵ�һ���ڵ�
	tmp = cur->next;

	while (cur != NULL)
	{
		cur->next = head;//curָ��Ľڵ�ͷ�嵽������һ���ڵ����ͷ��
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
	while (plist != tail)//����
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
	//����������С��Ԫ��β��
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
	//׷��ʣ��Ԫ��
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
//����һ���ҵ�������м�ڵ�(����ָ��)
pNode FindMidNode(pList plist)
{
	if ((plist == NULL) || (plist->next == NULL))
		return plist;
	pNode fp = NULL;//��ָ��������
	pNode sp = NULL;//��ָ����һ��
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
	pNode fp = plist;//��ָ������k��
	pNode sp = plist;//��ָ����һ��
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
pNode IsCircle(pList plist)//����
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

int GetCircleLength(pNode meet)//������
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
pNode GetCycleEntryNode(pList plist, pNode meet)//������ڵ�
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
int CheckCross(pList p1, pList p2)//�����Ƿ��ཻ
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
//�󽻵�
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