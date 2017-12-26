/*************************************************
* problem id : 58
* problem title : Length of Last word
* problem link : https://leetcode.com/problems/length-of-last-word/description/
**************************************************/

int lengthOfLastWord(string s) {
    int flag = 0, sum = 0;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]==' ' && flag==0)
            continue;
        if(s[i]!=' ') {
            if(flag==0)
                flag = 1;
            sum ++;
        }
        if(s[i]==' ' && flag==1)
            return sum;
    }
    return sum;
}
