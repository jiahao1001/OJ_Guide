#include <iostream>
#include <cstring>
using namespace std;

int PatternMatch(string s,string t){
    int i=0,j=0;
	long m = s.length(),n = t.length();
	while(i<m&&j<n){
        if (j == -1) {
            j++;
        }else if(s[i]==t[j]){
			i++;j++;
		}else{
            i = i - j + 1;
            j = -1;
		}
	}
    if (j >= n) {
        return i - (int)n;
    }
    return 0;
}

int getNext(string t){
    int i=0,j=0;
    long n = t.length();
    while (j < n) {

    }
    if (j >= n) {
        return i - (int)n;
    }
    return 0;
}
int KMP(string s,string t,int next[]){
    int i=0,j=0;
    long m = s.length(),n = t.length();
    while (i < m && j < n) {
        if (j == -1) {
            j++;
        }else if(s[i]==t[j]){
            i++;j++;
        }else{
            j = next[j];
        }
    }
    if (j >= n) {
        return i - (int)n;
    }
    return 0;
}

int main() {
    string s = "abcabcddcc";
    string t = "abcd";
    int next[4] = {-1,0,0,0};
    cout<<KMP(s, t,next);
    return 0;
}