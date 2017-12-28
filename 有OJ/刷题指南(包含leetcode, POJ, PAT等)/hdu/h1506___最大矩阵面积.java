import java.io.*;
import java.util.*;

public class h1506___最大矩阵面积 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int n;
		long arr[];
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			arr = new long[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextLong();

			int l[] = new int[n + 1];
			int r[] = new int[n + 1];
			for (int i = 1; i <= n; i++)
				l[i] = r[i] = i;
			for (int i = 1; i <= n; i++)
				while (l[i] > 1 && arr[i] <= arr[l[i] - 1])
					l[i] = l[l[i] - 1];
			for (int i = n; i >= 1; i--)
				while (r[i] < n && arr[i] <= arr[r[i] + 1])
					r[i] = r[r[i] + 1];

			long max = 0;
			for (int i = 1; i <= n; i++)
				max = Math.max(max, arr[i] * (r[i] - l[i] + 1));
			out.println(max);

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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}