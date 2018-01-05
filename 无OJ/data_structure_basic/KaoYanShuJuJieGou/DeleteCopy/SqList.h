#ifndef KAOYANSHUJUJIEGOU_SQLIST_H
#define KAOYANSHUJUJIEGOU_SQLIST_H

#define Max 1000
#define MaxSize 100
template<typename ElemType>
class SqList{
public:
    ElemType *data;
    int length;
    int size;
    SqList (int initLength){
        data = new ElemType[initLength];
        length = 0;
        size = initLength;
    }
    void add(ElemType e){
        if (length + 1 > size) {
            ElemType *p = new ElemType[size];
            for (int i = 0; i < size; ++i) {
                p[i] = data[i];
            }
            int newsize = size / 2 + size;
            data = new ElemType[newsize];
            for (int j = 0; j < size; ++j) {
                data[j] = p[j];
            }
            size = newsize;
            delete []p;
        }
        data[length] = e;
        length++;
    }


    void show(SqList<ElemType> *L,void (*Visit)(const ElemType &)){
        for (int i = 0; i < L->length; ++i) {
            (*Visit)(L->data[i]);
        }
    }

    int getLength(){
        return length;
    }
    int getSize(){
        return size;
    }
};

template <typename ElemType>
void DeleteCopy(SqList<ElemType> *L){
    int k = 1;
    for (int i = 1; i < L->length; ++i) {
        if (L->data[i] != L->data[i - 1]) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}
template <typename ElemType>
void DeleteX(SqList<ElemType> *L,ElemType x){
    int k=0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}
template <typename ElemType>
void Combine(SqList<ElemType> *&L1,SqList<ElemType> *&L2,SqList<ElemType> *&R){
    int m=0,n=0;
    int l1 = L1->length, l2 = L2->length,l = R->size;
    for (int i = 0; i < l; ++i) {
        int e1 = m > l1 ? Max : L1->data[m];
        int e2 = n > l2 ? Max : L2->data[n];
        if (e1 < e2) {
            R->add(e1);
            m++;
        } else {
            R->add(e2);
            n++;
        }
    }
}
#endif //KAOYANSHUJUJIEGOU_SQLIST_H
