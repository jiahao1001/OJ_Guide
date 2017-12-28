//Main.java
import java.util.*;
import java.math.*;

public class Main
{
        public static void main(String args[]) throws Exception {
                Scanner cin=new Scanner(System.in);
                BigInteger game[]=new BigInteger[102];
                game[1]=BigInteger.valueOf(1);
                for (int i=2;i<=101;i++)
                {
                	game[i]=BigInteger.valueOf(0);
                	for (int j=1;j<i;j++)
                		game[i]=game[i].add(game[j].multiply(game[i-j]));
                }
                int d = cin.nextInt();
                while (d != -1)
                {
                	System.out.println(game[d+1]);
                    d = cin.nextInt();
                }
        }
}
