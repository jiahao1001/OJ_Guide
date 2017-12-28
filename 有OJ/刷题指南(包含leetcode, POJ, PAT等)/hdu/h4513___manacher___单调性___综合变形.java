import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4513___manacher___单调性___综合变形 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 200010, p[] = new int[N];
	static int list[] = new int[N];

	static int solve(int arr[], int len) {
		int n = len * 2 + 1;
		Arrays.fill(list, 1);
		Arrays.fill(p, 0);
		for (int i = 1; i <= len; i++)
			list[i * 2] = arr[i - 1];
		list[0] = 0;
		list[n + 1] = 2;

		int ret = 0;

		int max = 0, id = 0, left, right;
		for (int i = 1; i <= n; i++) {
			if (max > i)
				p[i] = Math.min(p[2 * id - i], max - i);
			else
				p[i] = 1;

			while (list[i - p[i]] == list[i + p[i]]) {
				if (list[i - p[i]] == 1) {
					p[i]++;
				} else {
					left = i - p[i];
					right = i + p[i];
					if (left + 2 > right - 2 || list[left] <= list[left + 2]) {
						p[i]++;
					} else {
						break;
					}
				}
			}
			if (p[i] + i > max) {
				max = p[i] + i;
				id = i;
			}
			ret = Math.max(ret, p[i]);
		}

		return ret - 1;
	}

	static int len, arr[] = new int[100010];

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			len = nextInt();
			for (int i = 0; i < len; i++)
				arr[i] = nextInt();
			out.println(solve(arr, len));
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