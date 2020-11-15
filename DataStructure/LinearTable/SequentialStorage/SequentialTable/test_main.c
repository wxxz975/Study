
#include "SeqTable.h"

int main (int argc, char * argv[]) {
    struct SeqTable *mylist;
    
    // 初始化
    Status ret = initList(mylist);

    ListInsert(mylist, 1, 15);

    ListTraverse(*mylist);


}