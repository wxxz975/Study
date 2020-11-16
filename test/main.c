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
    // 初始化
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
	printf("删除的t的值是:%d\n", *t);
	
	
	ListTraverse(*mylist);
	
	
	*t = 55;
	// 定义函数指针 
	Status (*p)(ElemType a, ElemType b);
	p = compare; 
	int index = LocateElem(*mylist, *t, p);
	printf("t=%d在mylist中的的下标为%d\n", *t, index);
	
	ListTraverse(*mylist);
	
//	Bool ret1 = ListEmpty(*mylist);
//	printf("是否为空:%d\n", ret1);
//	ClearList(mylist);
//	ret1 = ListEmpty(*mylist);
//	printf("是否为空:%d\n", ret1);
	
	int len = ListLength(*mylist);
	printf("该seq的长度为:%d\n", len);
	
	
	getElem(*mylist, 4, t);
	printf("取到的值为:%d\n", *t);
	
	PriorElem(*mylist, 11, t); // 返回-1标示未找到 
	printf("该数的的前驱是:%d\n", *t);
	
	
	
	NextElem(*mylist, 55, t);
	printf("该数的后继是%d\n", *t);
	
	
	
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
