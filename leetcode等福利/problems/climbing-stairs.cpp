/**************************************************************
* problem id : 70
* problem title : Climbing Stairs
* problem link : https://leetcode.com/problems/climbing-stairs/description/
***************************************************************/

/* Recursion Versiion : Time Limit Exceeded */
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==0)
            return 1;
        if(n==2)
            return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

/* Dynamic programming */
class Solution {
public:
    int climbStairs(int n) {
        int a, b, c;

        if(n==0 || n==1)
            return 1;
        if(n==2)
            return 2;

        a = 1;
        b = 2;
        for(int i=3; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
