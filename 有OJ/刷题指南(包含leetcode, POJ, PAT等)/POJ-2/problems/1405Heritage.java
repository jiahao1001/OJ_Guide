import java.math.BigInteger;
import java.util.Scanner;
class Main{
    //Sylvester's sequence
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        BigInteger[] seq = new BigInteger[18];
        seq[0]=BigInteger.valueOf(2);
        seq[1]=BigInteger.valueOf(3);
        for(int i=2;i<n;i++){
            seq[i]=BigInteger.valueOf(1);
            for(int j=0;j<i;j++)
                seq[i]=seq[i].multiply(seq[j]);
            seq[i]=seq[i].add(BigInteger.valueOf(1));
        }
        for(int i=0;i<n;i++)
            System.out.println(seq[i]);
    }
}
