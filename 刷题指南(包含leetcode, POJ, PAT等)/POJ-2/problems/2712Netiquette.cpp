#include <iostream>
#include <string>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <cctype>
using namespace std;
string line;
inline bool isp(char c){
	if(c==' ')return false;
	if(isdigit(c)) return false;
	if(isalpha(c)) return false;
	return true;
}
int main(){
	while(getline(cin,line),line!="#"){
		line = string(" ")+line+" "; //append a space;
		bool bad = false;
		for(int i=2;i<line.size();i++){
			char p = line[i-1], q = line[i];
			// rule 1
			if( p >='A' && p<='Z' && q>='A' && q<='Z') bad = true;
			//rule 2
			if( isdigit(p) && isalpha(q) || isalpha(p) && isdigit(q)) bad = true;
			if(q==' ' && line[i-2] ==' '&& p!='a' && p!='A' && p!='I') bad = true;
			//rule 4
			if(isp(p) && isp(q) && p!='\"' && q!='\"') bad = true;
		}
		if(bad)printf("suspicious\n");
		else printf("OK\n");
  	}
  	return 0; 
}
