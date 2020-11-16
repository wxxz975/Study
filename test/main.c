#include<stdio.h>
#include <stdlib.h>
#include "SeqTable.h"
#include<string.h>

Status compare(ElemType a, ElemType b) {
	return a == b ? 1 : 0;
}



int main (int argc, char * argv[]) {
    struct SeqTable *mylist = (struct SeqTable*)malloc(sizeof(SeqTable));
    
    //printf("test");
    // ��ʼ��
	//char *p = (char *)malloc(100 * sizeof(int));
	//strcpy(p, "hello world");
	//printf("%s",p);
	
    Status ret = initList(mylist);

    ListInsert(mylist, 1, 11);
	ListInsert(mylist, 2, 22); 
	ListInsert(mylist, 3, 33);
	ListInsert(mylist, 4, 44);
	ListInsert(mylist, 5, 55);
	ListInsert(mylist, 6, 66);
	//ListInsert(mylist, 1, 9);
	
	
	
    ListTraverse(*mylist);

	ElemType *t = (ElemType *)malloc(sizeof(ElemType));
	ListDelete(mylist, 6, t);
	printf("ɾ����t��ֵ��:%d\n", *t);
	
	
	ListTraverse(*mylist);
	
	
	*t = 55;
	// ���庯��ָ�� 
	Status (*p)(ElemType a, ElemType b);
	p = compare; 
	int index = LocateElem(*mylist, *t, p);
	printf("t=%d��mylist�еĵ��±�Ϊ%d\n", *t, index);
	
	ListTraverse(*mylist);
	
//	Bool ret1 = ListEmpty(*mylist);
//	printf("�Ƿ�Ϊ��:%d\n", ret1);
//	ClearList(mylist);
//	ret1 = ListEmpty(*mylist);
//	printf("�Ƿ�Ϊ��:%d\n", ret1);
	
	int len = ListLength(*mylist);
	printf("��seq�ĳ���Ϊ:%d\n", len);
	
	
	getElem(*mylist, 4, t);
	printf("ȡ����ֵΪ:%d\n", *t);
	
	PriorElem(*mylist, 11, t); // ����-1��ʾδ�ҵ� 
	printf("�����ĵ�ǰ����:%d\n", *t);
	
	
	
	NextElem(*mylist, 55, t);
	printf("�����ĺ����%d\n", *t);
	
	
	
	printf("***********************************************************************\n");
	struct SeqTable *mylist_2 = (struct SeqTable*)malloc(sizeof(SeqTable));
	struct SeqTable *mylist_3 = (struct SeqTable*)malloc(sizeof(SeqTable));
	initList(mylist_2);
	initList(mylist_3);
	ListInsert(mylist_2, 1, 11);
	ListInsert(mylist_2, 2, 22); 
	ListInsert(mylist_2, 3, 33);
	ListInsert(mylist_2, 4, 44);
	ListInsert(mylist_2, 5, 55);
	
	
	MergeList(*mylist, *mylist_2, mylist_3);
	
	ListTraverse(*mylist_3);
	
	//DestroyList(mylist);
	
	//ListTraverse(*mylist);
	
//	ListTraverse(*mylist);
}
