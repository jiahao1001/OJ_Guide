import java.io.*;
import java.util.*;

public class h1505___最大矩阵面积dp___边界条件改进版 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;
	static int N = 1100;
	static long len[] = new long[N];
	static int l[] = new int[N], r[] = new int[N];

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			m = nextInt();

			Arrays.fill(len, 0);
			len[0] = len[m + 1] = -1;
			Arrays.fill(l, 0);
			Arrays.fill(r, 0);
			long ans = 0;
			for (int j = 1; j <= n; j++) {
				for (int i = 1; i <= m; i++) {
					if (nextChar() == 'R')
						len[i] = 0;
					else
						len[i]++;
					l[i] = r[i] = i;
				}

				for (int i = 1; i <= m; i++)
					while (len[i] <= len[l[i] - 1])
						l[i] = l[l[i] - 1];

				for (int i = m; i >= 1; i--)
					while (len[i] <= len[r[i] + 1])
						r[i] = r[r[i] + 1];

				for (int x = 1; x <= m; x++)
					ans = Math.max(ans, len[x] * (r[x] - l[x] + 1));
			}
			out.println(ans * 3);
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