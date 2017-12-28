import java.io.*;
import java.util.*;

public class h1506___最大矩阵面积dp___边界条件改进版 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int N = 100100;
	static long len[] = new long[N];
	static int l[] = new int[N], r[] = new int[N];

	public static void main(String[] args) throws IOException {
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			Arrays.fill(len, 0);
			Arrays.fill(l, 0);
			Arrays.fill(r, 0);
			for (int i = 1; i <= n; i++) {
				len[i] = nextInt();
				l[i] = r[i] = i;
			}
			len[0] = len[n + 1] = -10;
			l[0] = r[0] = 1;
			l[n + 1] = r[n + 1] = n;

			for (int i = 1; i <= n; i++)
				while (len[i] <= len[l[i] - 1])
					l[i] = l[l[i] - 1];

			for (int i = n; i >= 1; i--)
				while (len[i] <= len[r[i] + 1])
					r[i] = r[r[i] + 1];

			long ans = 0;
			for (int i = 1; i <= n; i++)
				ans = Math.max(ans, (len[i]) * (r[i] - l[i] + 1));
			out.println(ans);
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