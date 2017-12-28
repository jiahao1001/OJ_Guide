import java.io.*;
import java.util.*;

public class h1505___最大矩阵面积 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int ans, test = nextInt(), n, m, arr[], left[], right[];
		char ch;
		while (test-- > 0) {
			ans = 0;
			n = nextInt();
			m = nextInt();
			arr = new int[m + 1];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					ch = nextChar();
					if (ch == 'F')
						arr[j]++;
					else
						arr[j] = 0;
				}
				left = new int[m + 1];
				right = new int[m + 1];
				for (int x = 1; x <= m; x++)
					left[x] = right[x] = x;
				for (int x = 1; x <= m; x++)
					while (left[x] > 1 && arr[x] <= arr[left[x] - 1])
						left[x] = left[left[x] - 1];
				for (int x = n; x >= 1; x--)
					while (right[x] < m && arr[x] <= arr[right[x] + 1])
						right[x] = right[right[x] + 1];
				for (int x = 1; x <= m; x++)
					ans = Math.max(ans, arr[x] * (right[x] - left[x] + 1));
			}
			out.println(3 * ans);
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