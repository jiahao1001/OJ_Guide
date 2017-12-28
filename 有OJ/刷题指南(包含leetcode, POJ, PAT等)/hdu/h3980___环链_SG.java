import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h3980___»·Á´_SG {
    static BufferedReader br = new BufferedReader(new InputStreamReader(
            System.in));
    static StreamTokenizer in = new StreamTokenizer(br);
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static int N = 1010;
    static int n, m, sg[] = new int[N];

    static int solve(int l) {
        if (sg[l] > -1)
            return sg[l];
        if (l < m)
            return (sg[l] = 0);

        boolean vis[] = new boolean[N];
        for (int i = 0; i + m <= l; i++)
            vis[solve(i) ^ solve(l - m - i)] = true;

        int i = 0;
        for (; i < N; i++)
            if (!vis[i])
                return (sg[l] = i);
        return sg[l];
    }

    public static void main(String[] args) throws IOException {
        int ttt = nextInt();
        for (int test = 1; test <= ttt; test++) {
            n = nextInt();
            m = nextInt();

            out.print("Case #" + test + ": ");

            if (n < m) {
                out.println("abcdxyzk");
            } else {
                Arrays.fill(sg, -1);
                n -= m;
                if (solve(n) == 0)
                    out.println("aekdycoin");
                else
                    out.println("abcdxyzk");
            }
        }
        out.flush();
        out.close();
    }

    static String next() throws IOException {
        in.nextToken();
        return in.sval;
    }

    static char nextChar() throws IOException {
        in.nextToken();
        return in.sval.charAt(0);
    }

    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    static long nextLong() throws IOException {
        in.nextToken();
        return (long) in.nval;
    }

    static float nextFloat() throws IOException {
        in.nextToken();
        return (float) in.nval;
    }

    static double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }
}