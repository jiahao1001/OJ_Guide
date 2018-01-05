#include <iostream>
#include "SqList.h"
using namespace std;
template <typename ElemType>
void Write(const ElemType &e);
//测试合并两个数组
int main(int argc, char *argv[])
{
    int x = 0,i = 0;
    SqList<int> *L1 = new SqList<int>(10);
    SqList<int> *L2 = new SqList<int>(10);
    while (cin >> x && x != 0) {
        L1->add(x);
    }
    cout << "输入L2：" << endl;
    while (cin >> x && x != 0) {
        L2->add(x);
    }
    int l = L1->length + L2->length;
    SqList<int> *L = new SqList<int>(l);
    Combine(L1, L2, L);
    cout << L->getLength() << endl;
    cout << L->getSize() << endl;
    L->show(L,Write<int>);
    getchar();
    return EXIT_SUCCESS;
}
//测试Delete
//int main(int argc, char *argv[])
//{
//    int x = 0,i = 0;
//    SqList<int> *L = new SqList<int>(10);
//    while (cin >> x && x != 0) {
//        L->add(x);
//    }
//    cout << L->getLength() << endl;
//    cout << L->getSize() << endl;
//    DeleteCopy(L);
//    DeleteX(L, 2);
//    L->show(L,Write<int>);
//    getchar();
//    return EXIT_SUCCESS;
//}

template <typename ElemType>
void Write(const ElemType &e)
{
    cout << e << "  ";
}





