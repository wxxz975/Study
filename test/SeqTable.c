#include "SeqTable.h"
#include <stdio.h>
#include <stdlib.h>

Status initList(SqList *L) {
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}


Status ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return ERROR;  // i的范围不对
    if (L->length >= L->listsize) {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType)); // 改变L.elem的大小为 指定大小
        if (!newbase) exit(OVERFLOW); // 重新分配空间失败
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = &(L->elem[i]);
    for(ElemType *p = &(L->elem[L->length]); p >= q; --p) 
        *(p+1) = *p;  // 从最后+1位置开始 每一个都向后移动一个

    *q = e;
    ++L->length;
    return OK;
}


Status ListDelete(SqList *L, int i, ElemType *e) {
    if ((i < 1) || (i > L->length)) return ERROR;
    ElemType *p = &(L->elem[i]);    // 记录要删除的地址
    *e = *p;
    ElemType *q = L->elem + L->length;     // 最后一个元素的地址
    for (; p <= q; ++p) *p = *(p+1);     //从删除的位置开始 之后的元素分别左移一个
    --L->length;
    return OK;
}


int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    int i = 1;  // 记录初始位置
    ElemType *p = L.elem + 1;      // 从顺序表的首部开始
    while (i <= L.length && !(*compare)(*p++, e)) ++i;     // 利用compare 函数来比较两者是否相等
    if (i <= L.length) return i;       // 若小于最大长度则认为有效
    else return 0;
}

void MergeList(SqList La, SqList Lb, SqList *Lc){
    ElemType *pa = La.elem + 1, *pb = Lb.elem + 1;       // 记录两个顺序表的头部
    Lc->listsize = La.listsize + Lb.listsize;        // 新顺序表的大小
    Lc->length = La.length + Lb.length;
    Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType)); 
    ElemType *pc = Lc->elem + 1;
	if (!Lc->elem) exit(OVERFLOW);
    ElemType *pa_last = La.elem + La.length + 1;    // a表的末尾元素地址
    ElemType *pb_last = Lb.elem + Lb.length + 1;    // b表的末尾元素+1地址
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) *pc++ = *pa++;       // 将小的元素放前面
        else *pc++ = *pb++;
    } 
    // 将剩余的元素再放入c中
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}

Status DestroyList(SqList *L) {
    if (L == NULL || L->elem == NULL) return ERROR;  // 确保顺序表存在
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;

    return OK;
}

Status ClearList(SqList *L) {
    if (L == NULL || L->elem == NULL) return ERROR;
    L->length = 0;

    return OK;
}

Bool ListEmpty(SqList L) {
    return L.length == 0 ? True:False;
}

int ListLength(SqList L) {
    return L.length;
}

Status getElem(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length) return ERROR;
    *e = L.elem[i];

    return OK;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    int i = 1;
    if (L.elem == NULL || L.length < 2) return ERROR;   // 判断L的长度是否合法

    while (i <= L.length && L.elem[i] != cur_e) ++i;    // 移动下标i,直到大于L的长度或者等于cur_e
    
    if(i > L.length || i == 1) {
		*pre_e = -1;
		return ERROR;    // i是否合法
	}
    *pre_e = L.elem[i-1];   

    return OK;
}


Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int i = 1;

    if (L.length < 2 || L.elem == NULL) return ERROR;

    while (i < L.length && L.elem[i] != cur_e) ++i;

    if(i > L.length - 1) {
    	*next_e = -1;
		return ERROR;	
	}

    *next_e = L.elem[i+1];
    
    return OK;
}

void ListTraverse(SqList L) {
    for (size_t i = 1; i <= L.length; i++)
    {
        printf("%d\t",L.elem[i]);
    }
    printf("\n");
    
}
