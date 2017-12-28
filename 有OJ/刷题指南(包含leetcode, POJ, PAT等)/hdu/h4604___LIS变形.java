import java.io.*;
import java.util.*;

public class h4604___LIS变形 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[];
	// mark1表示以a[x]开头的非减序列的最长长度
	// mark1表示以a[x]开头的非增序列的最长长度
	// count表示以a[x]开头的非减序列的与a[x]值相同的a[i]个数
	// mark1表示以a[x]开头的非增序列的最长长度
	static int dp[], mark1[], mark2[], count1[], count2[];

	public static void main(String[] args) throws IOException {
		int test = nextInt(), index, l, r, mid, max;

		while (test-- > 0) {
			n = nextInt();
			arr = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();
			dp = new int[n + 1];
			mark1 = new int[n + 1];
			mark2 = new int[n + 1];
			count1 = new int[n + 1];
			count2 = new int[n + 1];

			dp[1] = arr[n];
			index = 1;
			count1[n] = 1;
			mark1[n] = 1;
			for (int i = n - 1; i >= 1; i--) {
				if (arr[i] <= dp[index]) {
					dp[++index] = arr[i];
					mark1[i] = index;
				} else {
					l = 1;
					r = index;
					while (l <= r) {
						mid = (l + r) >> 1;
						if (dp[mid] >= arr[i])
							l = mid + 1;
						else
							r = mid - 1;
					}
					dp[l] = arr[i];
					mark1[i] = l;
				}

				l = 1;
				r = mark1[i];
				while (l <= r) {
					mid = (l + r) >> 1;
					if (dp[mid] > arr[i])
						l = mid + 1;
					else
						r = mid - 1;
				}
				count1[i] = mark1[i] - l + 1;
			}

			dp[1] = arr[n];
			index = 1;
			mark2[n] = 1;
			count2[n] = 1;
			for (int i = n - 1; i >= 1; i--) {
				if (arr[i] >= dp[index]) {
					dp[++index] = arr[i];
					mark2[i] = index;
				} else {
					l = 1;
					r = index;
					while (l <= r) {
						mid = (l + r) >> 1;
						if (dp[mid] <= arr[i])
							l = mid + 1;
						else
							r = mid - 1;
					}
					dp[l] = arr[i];
					mark2[i] = l;
				}

				l = 1;
				r = mark2[i];
				while (l <= r) {
					mid = (l + r) >> 1;
					if (dp[mid] > arr[i])
						l = mid + 1;
					else
						r = mid - 1;
				}
				count2[i] = mark2[i] - l + 1;
			}

			max = 1;
			for (int i = 1; i <= n; i++) {
				max = Math.max(max, mark1[i] + mark2[i]
						- Math.min(count1[i], count2[i]));
			}

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

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}