import java.util.HashMap;
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int n = 0;
        int[] ns;
        HashMap<Integer,Integer> mp = new HashMap<Integer, Integer>();
        while(true){
            n = cin.nextInt();
            if(n==0)break;
            mp.clear();
            ns = new int[n];
            for(int i=0;i<n;i++) ns[i] = cin.nextInt();
            Arrays.sort(ns);
            for(int i=n-1;i>=0;i--)
                for(int j=i-1;j>=0;j--){
                    int k = ns[i]-ns[j];
                    if(mp.get(k)==null) {
                        mp.put(k, ns[i]);
                    }
                }
            int best = Integer.MIN_VALUE;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++){
                    int k = ns[i]+ns[j];
                    if(mp.get(k)==null) continue;
                    int D = mp.get(k);
                    int x = D-k;
                    if(ns[i]!=D && ns[i]!=x && ns[j]!=D && ns[j]!=x) {
                        best = Math.max(best,D);
                    }
                }
            if(best==Integer.MIN_VALUE) System.out.println("no solution");
            else System.out.println(best);
        }
    }
}
