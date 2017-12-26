//Main.java
import java.util.*;
import java.math.*;

public class Main
{
        public static void main(String args[]) throws Exception {
                Scanner cin=new Scanner(System.in);
                BigInteger n = cin.nextBigInteger();
                int d = cin.nextInt();
                while (n.intValue() != 0 || d != 0)
                {
                	n = n.pow(d);
                	System.out.println(n);
                	n = cin.nextBigInteger();
                    d = cin.nextInt();
                }
        }
}
