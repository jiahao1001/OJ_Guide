import java.io.*;

import java.util.*;

public class h4649___概率___统计 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	// 单独求出每一位是1的概率
	// 加权求和即可
	// sum( (1<<i) * 第i位是1的概率 )

	static int n, arr[];
	static char o[];
	static double p[];

	public static void main(String[] args) throws IOException {
		int test = 0;
		while (scan.hasNext()) {
			n = scan.nextInt();
			arr = new int[n + 1];
			for (int i = 0; i <= n; i++)
				arr[i] = scan.nextInt();
			o = new char[n + 1];
			for (int i = 1; i <= n; i++)
				o[i] = scan.next().charAt(0);
			p = new double[n + 1];
			for (int i = 1; i <= n; i++)
				p[i] = 1 - scan.nextDouble();

			double dp[][] = new double[2][2];
			double digit[] = new double[22];
			for (int i = 0; i < 20; i++) {
				int cur = 1, pre = 0;
				if (((1 << i) & arr[0]) == 0) {
					dp[pre][0] = 1;
					dp[pre][1] = 0;
				} else {
					dp[pre][0] = 0;
					dp[pre][1] = 1;
				}
				for (int j = 1; j <= n; j++) {
					char ch = o[j];
					double d = p[j];
					int num;
					if (((1 << i) & arr[j]) > 0)
						num = 1;
					else
						num = 0;
					dp[cur][0] = dp[pre][0] * (1 - d);
					dp[cur][1] = dp[pre][1] * (1 - d);
					if (ch == '&') {
						dp[cur][1 & num] += dp[pre][1] * d;
						dp[cur][0 & num] += dp[pre][0] * d;
					} else if (ch == '|') {
						dp[cur][1 | num] += dp[pre][1] * d;
						dp[cur][0 | num] += dp[pre][0] * d;
					} else {
						dp[cur][1 ^ num] += dp[pre][1] * d;
						dp[cur][0 ^ num] += dp[pre][0] * d;
					}
					pre = 1 - pre;
					cur = 1 - cur;
				}

				digit[i] = dp[pre][1];
			}

			double ans = 0;
			for (int i = 0; i < 20; i++) {
				ans += (1 << i) * digit[i];
			}

			test++;
			out.println("Case " + test + ":");
			out.printf("%.6f", ans);
			out.println();
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