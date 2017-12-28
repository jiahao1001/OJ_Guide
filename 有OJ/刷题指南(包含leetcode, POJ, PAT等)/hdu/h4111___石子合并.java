import java.io.*;

import java.util.*;

public class h4111___石子合并 {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int N = 50, M = 1000;
	static int dp[][] = new int[N + 1][N * M + 1];

	static void dfs(int one, int sum) {
		if (dp[one][sum] >= 0)
			return;
		if (one == 0) {
			dp[one][sum] = sum & 1;
			return;
		}
		if (one == 1) {
			dp[one][sum] = 1;
			return;
		}
		if (sum == 1) {
			dfs(one + 1, 0);
			dp[one][1] = dp[one + 1][0];
			return;
		}

		dp[one][sum] = 0;

		if (true) {
			dfs(one - 1, sum);
			if (dp[one - 1][sum] == 0) {
				dp[one][sum] = 1;
				return;
			}
		}
		if (sum > 1) {
			dfs(one, sum - 1);
			if (dp[one][sum - 1] == 0) {
				dp[one][sum] = 1;
				return;
			}
		}
		if (sum > 1) {
			dfs(one - 1, sum + 1);
			if (dp[one - 1][sum + 1] == 0) {
				dp[one][sum] = 1;
				return;
			}
		}
		if (sum == 0) {
			dfs(one - 2, sum + 2);
			if (dp[one - 2][sum + 2] == 0) {
				dp[one][sum] = 1;
				return;
			}
		}
		if (sum > 0) {
			dfs(one - 2, sum + 3);
			if (dp[one - 2][sum + 3] == 0) {
				dp[one][sum] = 1;
				return;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		for (int i = 0; i <= N; i++)
			Arrays.fill(dp[i], -1);

		int ttt = scan.nextInt(), temp;
		for (int test = 1; test <= ttt; test++) {
			out.print("Case #" + test + ": ");

			n = scan.nextInt();
			int one = 0, sum = 0;
			for (int i = 1; i <= n; i++) {
				temp = scan.nextInt();
				if (temp == 1)
					one++;
				else
					sum += (temp + 1);
			}
			if (sum > 0)
				sum--;
			dfs(one, sum);
			if (dp[one][sum] > 0)
				out.println("Alice");
			else
				out.println("Bob");
		}

		out.flush();
		out.close();
	}
}