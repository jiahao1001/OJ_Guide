#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int bits[400005];
int octs[140000];

int main(){

    int n;
    cin>>n;

    for(int p=0;p<n;p++){
        memset(bits,0,sizeof(bits));
        memset(octs,0,sizeof(octs));
        string s;
        cin>>s;

        int i,j,count=0;

        //将十六进制转为二进制
        for(i=s.length()-1;i>=0;i--){
            //十六进制转为数字
            int dec;
            if(s[i]<='9'){
                dec=s[i]-'0';
            }else{
                dec=s[i]-'A'+10;
            }


            //十进制转换为2进制
            for(int j = 0; j < 4; j++, count++)
            {
                bits[count]=dec%2;
                dec /= 2;
            }


        }


        int oct_count=0;
        for(j=0;j<count;j+=3,oct_count++){
            octs[oct_count]=bits[j]+bits[j+1]*2+bits[j+2]*4;
        }

        //去除前导0
        while(octs[oct_count]==0){
            oct_count--;
        }

        for(j=oct_count;j>=0;j--){
            cout<<octs[j];
        }
        cout<<endl;

    }


    return 0;
}