#include<stdio.h>
#include<string.h>
char mem[300];
int A,B;
int ip;
int instr;
int ti(char c){
    if(c<='9' && c>='0') return c-'0';
    return c-'A'+10;
}
int get_addr(){
    int p = ti(mem[ip])*16+ti(mem[ip+1]);
    ip+=2;
    return p;
}
char tc(int i){
    if(i<=9) return '0'+i;
    return i-10+'A';
}
void get_instr(){
    instr = ti(mem[ip]);
    ip++;
}
void f0(){
    int p = get_addr();
    A = ti(mem[p]);
}
void f1(){
    int p = get_addr();
    mem[p] = tc(A);
}
void f2(){
    int C= A;
    A=B, B=C;
}
void f3(){
    //add
    int C = A+B;
    A = C%16;
    B = C/16;
}
void f4(){
    A++;
    if(A>=16) A-=16;
}
void f5(){
    A--;
    if(A<0) A+=16;
}
void f6(){
    //BZ
    int p = get_addr();
    if(!A) ip = p;
}
void f7(){
    int p = get_addr();
    ip = p;
}
int main()
{
    while(scanf("%s",mem),mem[0]!='8'){
        A = B = 0;
        ip = 0;
        while(get_instr(),instr!=8){
            switch(instr){
            case 0:f0();
                break;
            case 1:f1();
                break;
            case 2:f2();
                break;
            case 3:f3();
                break;
            case 4:f4();
                break;
            case 5:f5();
                break;
            case 6:f6();
                break;
            case 7:f7();
                break;
            }
        }
        printf("%s\n",mem);
    }
    return 0;
}
