#include"../../../Common/common.h"
#define LIST_INIT_SIZE  100     // 线性表初始分配空间
#define LISTINCREMENT   10      // 线性表存储空间的分配增量


/* 知识盲点:c语言中没有&引用 而是取地址符、所以导致在函数的传参的时候不能使用&来直接引用参数的本体 */
typedef int ElemType;       // 存储类型

typedef struct SeqTable
{
    ElemType    *elem;      //  存储空间地址
    int         length;     //  当前长度
    int         listsize;   //  当前分配的存储容量(capicity)
}SqList;


/* 初始化顺序表L */
Status InitList(SqList *L);

/* 在顺序L的第i个位置之前插入元素e */
Status ListInsert(SqList *L, int i, ElemType e);

/* 删除顺序L的第i个元素，并用e返回其的值(pop类似) */
Status ListDelete(SqList *L, int i, ElemType *e);

/* 在顺序表L中查找第1个与e满足compare()元素的位置 */
int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));

/*  已知顺序表La、Lb的元素按照非递减排列
    归并La、Lb的到新的顺序表Lc，Lc的元素也按照非递减排列*/
void MergeList(SqList La, SqList Lb, SqList *Lc);

/* 销毁线性表L */
Status DestroyList(SqList *L);

/* 将顺序表L置空 */
Status ClearList(SqList *L);

/* 判断顺序表L是否为空 */ 
bool ListEmpty(SqList L);

/* 返回顺序表现存的元素个数 */ 
int ListLength(SqList L);

/* 以e返回顺序表L中下标为i的元素 */
Status getElem(SqList L, int i, ElemType *e);

/* 若cur_e为L的元素,且不是第一个,则用pre_e返回该元素的前驱,否则操作无效、pre_e无定义 */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

/* 若cur_e为L的元素,且不是最后一个,则用next_e返回该元素的后继,否则操作无效、next_e无定义 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

/* 依次对L中每个元素调用visit()函数 */
void ListTraverse(SqList L);
//void ListTraverse(SqList L, (*visit()));


