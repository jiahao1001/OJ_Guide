import java.io.*;
import java.util.*;

public class h2476___区间dp___编辑距离变形 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, str1[], str2[], dp[][];
	static int i, j, k, len;

	public static void main(String[] args) throws IOException {
		String a, b;
		while ((a = br.readLine()) != null) {
			b = br.readLine();
			n = a.length();
			str1 = new int[n + 10];
			str2 = new int[n + 10];
			for (i = 1; i <= n; i++) {
				str1[i] = a.charAt(i - 1) - 'a' + 1;
				str2[i] = b.charAt(i - 1) - 'a' + 1;
			}

			dp = new int[n + 10][n + 10];
			for (i = 1; i <= n; i++)
				for (j = i; j <= n; j++)
					dp[i][j] = j - i + 1;

			// 第一步： 假设A,B完全不等，没有位置上的字符相等，那么可以进行区间dp
			// DP[I][J]表示从I到J最少需要多少步
			// DP[I][J]=DP[I+1][J]+1;
			// DP[I][J]=MIN(DP[I][J],DP[I+1][K]+DP[K+1][J]) I+1
			for (len = 1; len <= n; len++) {
				for (i = 1; i + len <= n; i++) {
					j = i + len;
					dp[i][j] = dp[i + 1][j] + 1;
					for (k = i + 1; k <= j; k++) {
						if (str2[i] == str2[k])
							dp[i][j] = Math.min(dp[i][j], dp[i + 1][k]
									+ dp[k + 1][j]);
					}
				}
			}

			// 第二步：考虑A和B某些位置会相等
			// F[I]=DP[0][I]
			// F[I]=F[I-1] A[I]==B[I]
			// F[I]=MIN(F[I],F[J]+DP[J+1][I]) 0<=J
			int f[] = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				f[i] = dp[1][i];
				if (str1[i] == str2[i])
					f[i] = f[i - 1];
				for (int j = 1; j < i; j++)
					f[i] = Math.min(f[i], f[j] + dp[j + 1][i]);
			}

			System.out.println(f[n]);

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