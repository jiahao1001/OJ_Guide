//Main.java
import java.util.*;
import java.math.*;

public class Main
{
        public static void main(String args[]) throws Exception {
                Scanner cin=new Scanner(System.in);
                int base = cin.nextInt();
                while (base != 0)
                {
                	String s = cin.next();
                	BigInteger a = new BigInteger(s,base);
                	s = cin.next();
                	BigInteger b = new BigInteger(s,base);
                	a = a.mod(b);
                	System.out.println(a.toString(base));
                	base = cin.nextInt();
                }               
        }
}
