import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        int N,K;
        Scanner cin = new Scanner(System.in);
        N = cin.nextInt();
        K = cin.nextInt();
        BigInteger[][] dp = new BigInteger[N+1][K+1];
        for(int i=0;i<=N;i++)
            for(int j=0;j<=K;j++) dp[i][j] = BigInteger.ZERO;
        for(int j=0;j<=K;j++) dp[0][j] = BigInteger.ONE;
        for(int j=1;j<=K;j++)
            for(int i=1;i<=N;i++)
                for(int x=0;i-x*j>=0;x++)
                dp[i][j] = dp[i][j].add(dp[i-x*j][j-1]);
        System.out.println(dp[N][K]);
    }
}
