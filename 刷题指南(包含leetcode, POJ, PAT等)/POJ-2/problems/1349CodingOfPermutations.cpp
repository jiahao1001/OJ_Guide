import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static BigInteger[] dp  = new BigInteger[51];
    public static BigInteger fact(int n){
        if(dp[n]!=null) return dp[n];
        if(n<=1) return BigInteger.ONE;
        else dp[n] = fact(n-1).multiply(BigInteger.valueOf(n));
        return dp[n];
    }
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        boolean first =true;
        while(cin.hasNext()){
            String s = cin.next();
            if(s.equals("-1")) break;
            if(first) first =false;
            else System.out.print(",");
            StringTokenizer st = new StringTokenizer(s,",()");
            int n = Integer.parseInt(st.nextToken());
            int[] p = new int[n];
            for(int i=0;i<n;i++) p[i] = Integer.parseInt(st.nextToken());
            BigInteger ans = BigInteger.ZERO;
            for(int i=0;i<n;i++){
                int cnt = 0;
                for(int j=i+1;j<n;j++)
                    if(p[i]>p[j]) cnt++;
                ans = ans.add(fact(n-1-i).multiply(BigInteger.valueOf(cnt)));
            }
            System.out.print(ans.add(BigInteger.ONE));
        }
        System.out.println();
    }
}
