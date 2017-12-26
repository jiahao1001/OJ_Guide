#include <iostream>

using namespace std;

char str[8010];
int main(){

    int n,i,j,k,m,dif=0,sum=0;
    scanf("%d%s", &n, str);  

    j=n-1; //j point last one 
    for(i=0;i<j;i++){
        k=j;
        while(str[i]!=str[k])
            k--;
        if(k==i){
            dif++;
            if(n%2==0||dif>1){
                cout<<"Impossible"<<endl;
                return 0;
            }else {
                sum+= n/2-i;
            }
        }else{
            for(m=k;m<j;m++){
                str[m]=str[m+1];
            }
            sum+=j-k;
            j--;
        }
    }

    cout<<sum<<endl;




    return 0;
}