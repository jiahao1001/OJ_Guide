import java.io.*;

import java.util.*;

public class h4647___Í¼ÂÛ___´íÁË___ÊÇÂÒ¸ã___‡å {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, m;

	public static void main(String[] args) throws IOException {
		int u, v;
		double temp;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			double weight[] = new double[n];
			for (int i = 0; i < n; i++)
				weight[i] = nextInt();
			for (int i = 1; i <= m; i++) {
				u = nextInt() - 1;
				v = nextInt() - 1;
				temp = 1.0 * nextInt();
				weight[u] += 0.5 * temp;
				weight[v] += 0.5 * temp;
			}
			Arrays.sort(weight);
			double ans = 0;
			for (int i = 0; i < n; i += 2) {
				ans += weight[i + 1] - weight[i];
			}
			out.println((long) ans);
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