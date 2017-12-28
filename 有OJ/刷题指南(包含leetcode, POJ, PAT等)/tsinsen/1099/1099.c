#include <cstdio>

int week(char *s) {
    switch(s[0]) {
        case 'M':
        case 'm':
            return 1;
        case 'W':
        case 'w':
            return 3;
        case 'F':
        case 'f':
            return 5;
        case 'T':
        case 't':
            if(s[1] == 'u' || s[1] == 'U' )return 2;
            else return 4;
        case 'S':
        case 's':
        if(s[1] == 'a' || s[1] == 'A' )return 6;
            else return 7;
    }
    return -1;
}

char wk[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", 
                "Saturday", "Sunday"};

int main() {
    char a[10], b[10];
    int yes[8], no[8], i, ans;
    for(i = 0; i < 8; i++) {
        scanf("%s %s", a, b);
        yes[i] = week(a);
        no[i] = week(b);
    }
    for(ans = 1; ans <= 7; ans++) {
        for(i = 0; i < 8; i++) {
            if((ans == yes[i] && ans != no[i]) || (ans != yes[i] && ans == no[i]))
                break;
        }
        if(i == 8)
            break;
    }

    printf("%s\n", wk[ans - 1]);
    return 0;
}