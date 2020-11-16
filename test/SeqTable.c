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
    if (i < 1 || i > L->length + 1) return ERROR;  // i�ķ�Χ����
    if (L->length >= L->listsize) {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType)); // �ı�L.elem�Ĵ�СΪ ָ����С
        if (!newbase) exit(OVERFLOW); // ���·���ռ�ʧ��
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = &(L->elem[i]);
    for(ElemType *p = &(L->elem[L->length]); p >= q; --p) 
        *(p+1) = *p;  // �����+1λ�ÿ�ʼ ÿһ��������ƶ�һ��

    *q = e;
    ++L->length;
    return OK;
}


Status ListDelete(SqList *L, int i, ElemType *e) {
    if ((i < 1) || (i > L->length)) return ERROR;
    ElemType *p = &(L->elem[i]);    // ��¼Ҫɾ���ĵ�ַ
    *e = *p;
    ElemType *q = L->elem + L->length;     // ���һ��Ԫ�صĵ�ַ
    for (; p <= q; ++p) *p = *(p+1);     //��ɾ����λ�ÿ�ʼ ֮���Ԫ�طֱ�����һ��
    --L->length;
    return OK;
}


int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    int i = 1;  // ��¼��ʼλ��
    ElemType *p = L.elem + 1;      // ��˳�����ײ���ʼ
    while (i <= L.length && !(*compare)(*p++, e)) ++i;     // ����compare �������Ƚ������Ƿ����
    if (i <= L.length) return i;       // ��С����󳤶�����Ϊ��Ч
    else return 0;
}

void MergeList(SqList La, SqList Lb, SqList *Lc){
    ElemType *pa = La.elem + 1, *pb = Lb.elem + 1;       // ��¼����˳����ͷ��
    Lc->listsize = La.listsize + Lb.listsize;        // ��˳���Ĵ�С
    Lc->length = La.length + Lb.length;
    Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType)); 
    ElemType *pc = Lc->elem + 1;
	if (!Lc->elem) exit(OVERFLOW);
    ElemType *pa_last = La.elem + La.length + 1;    // a���ĩβԪ�ص�ַ
    ElemType *pb_last = Lb.elem + Lb.length + 1;    // b���ĩβԪ��+1��ַ
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) *pc++ = *pa++;       // ��С��Ԫ�ط�ǰ��
        else *pc++ = *pb++;
    } 
    // ��ʣ���Ԫ���ٷ���c��
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}

Status DestroyList(SqList *L) {
    if (L == NULL || L->elem == NULL) return ERROR;  // ȷ��˳������
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
    if (L.elem == NULL || L.length < 2) return ERROR;   // �ж�L�ĳ����Ƿ�Ϸ�

    while (i <= L.length && L.elem[i] != cur_e) ++i;    // �ƶ��±�i,ֱ������L�ĳ��Ȼ��ߵ���cur_e
    
    if(i > L.length || i == 1) {
		*pre_e = -1;
		return ERROR;    // i�Ƿ�Ϸ�
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
