#include"common.h"
#define LIST_INIT_SIZE  100     // ���Ա��ʼ����ռ�
#define LISTINCREMENT   10      // ���Ա�洢�ռ�ķ�������


/* ֪ʶä��:c������û��&���� ����ȡ��ַ�������Ե����ں����Ĵ��ε�ʱ����ʹ��&��ֱ�����ò����ı��� */
typedef int ElemType;       // �洢����

typedef struct SeqTable
{
    ElemType    *elem;      //  �洢�ռ��ַ   ע: ����±�0λ�ò��洢���� 
    int         length;     //  ��ǰ����
    int         listsize;   //  ��ǰ����Ĵ洢����(capicity)
}SqList;


/* ��ʼ��˳���L */
Status initList(SqList *L);

/* ��˳���L�ĵ�i��λ�ò���Ԫ��e */
Status ListInsert(SqList *L, int i, ElemType e);

/* ɾ��˳��L�ĵ�i��Ԫ�أ�����e�������ֵ(pop����) */
Status ListDelete(SqList *L, int i, ElemType *e);

/* ��˳���L�в��ҵ�1����e����compare()Ԫ�ص�λ�� */
int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));

/*  ��֪˳���La��Lb��Ԫ�ذ��շǵݼ�����
    �鲢La��Lb�ĵ��µ�˳���Lc��Lc��Ԫ��Ҳ���շǵݼ�����*/
void MergeList(SqList La, SqList Lb, SqList *Lc);

/* �������Ա�L */
Status DestroyList(SqList *L);

/* ��˳���L�ÿ� */
Status ClearList(SqList *L);

/* �ж�˳���L�Ƿ�Ϊ�� */ 
Bool ListEmpty(SqList L);

/* ����˳����ִ��Ԫ�ظ��� */ 
int ListLength(SqList L);

/* ��e����˳���L���±�Ϊi��Ԫ�� */
Status getElem(SqList L, int i, ElemType *e);

/* ��cur_eΪL��Ԫ��,�Ҳ��ǵ�һ��,����pre_e���ظ�Ԫ�ص�ǰ��,���������Ч��pre_e�޶��� */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

/* ��cur_eΪL��Ԫ��,�Ҳ������һ��,����next_e���ظ�Ԫ�صĺ��,���������Ч��next_e�޶��� */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

/* ���ζ�L��ÿ��Ԫ�ص���visit()���� */
void ListTraverse(SqList L);
//void ListTraverse(SqList L, (*visit()));



