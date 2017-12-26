/*******************************************************
* problem id : 461
* problem title : Hamming Distance
* problem link : https://leetcode.com/problems/hamming-distance/description/
********************************************************/

int hammingDistance(int x, int y) {
    int z = x^y;
    int ans = 0;

    while(z!=0) {
        if(z%2==1)  ans ++;
        z /= 2;
    }

    return ans;
}
