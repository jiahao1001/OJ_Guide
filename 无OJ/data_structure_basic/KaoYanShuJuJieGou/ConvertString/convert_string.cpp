#include <iostream>
#include <cstring>
using namespace std;

bool matchs(char *str){
    for (int i = 0; i < strlen(str); ++i) {
        if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            ;
        }else{
            return false;
        }
    }
    return true;
}
void ConvertStr (char *str,  char* &output){
    int length = strlen(str);
    char outputtemp[length/2];
    if(length>20||!matchs(str)){
        char r[7] = "ERROR!";
        output = r;
        return ;
    }
    int index=0;
    for (int i = 0; i < length; ++i) {
        if (i % 2 == 1) {
            //ÊÇÅ¼Êý
            outputtemp[index++] = str[i];
        }
    }
    outputtemp[index] = '\0';
    output = outputtemp;
}
int main() {
    char *str;
    char s[50];
    cin>>s;
    str = s;
    int L = strlen(str);
    char *output;
    ConvertStr(str, output);
    for (int i = 0; output[i]!='\0'; ++i) {
        cout << *output;
    }
    return 0;
}