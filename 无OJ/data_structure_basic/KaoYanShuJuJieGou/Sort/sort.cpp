#include <iostream>
using namespace std;
void bublle(int a[]){
    bool flag = false;
    int n = sizeof(a);
    for (int i=0;i < n-1;i++){
        flag = false;
        for(int j = n-1;j > i;j--){
            if(a[j] > a[j-1]){
                int t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}
int main() {
    int *a = new int[5]{1,3,4,2,9};
    bublle(a);
    cout<<sizeof(a);
    for (int i = 0; i < sizeof(a); ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}