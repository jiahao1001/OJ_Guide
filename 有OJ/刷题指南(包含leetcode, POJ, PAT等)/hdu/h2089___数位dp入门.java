import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Set;
import java.util.TreeMap;

public class h2089___数位dp入门 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int dp[][] = new int[11][3];

	static void init() {
		dp[0][0] = 1;
		for (int i = 1; i <= 6; i++) {
			dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
			dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][0] + dp[i - 1][1];
		}
	}

	static int solve(int x) {
		int sum = x;
		int bit[] = new int[11], toll = 0;
		while (x > 0) {
			bit[++toll] = x % 10;
			x /= 10;
		}
		bit[toll + 1] = 0;
		int ans = 0;
		boolean flag = false;
		for (int i = toll; i > 0; i--) {
			ans += dp[i - 1][2] * bit[i];
			if (flag) {
				ans += dp[i - 1][0] * bit[i];
			} else {
				if (bit[i] > 4) // 高位可能出现4的情况
					ans += dp[i - 1][0];
				if (bit[i + 1] == 6 && bit[i] > 2) // 高位是6，后面一位可能出现2，这步debug了很久
					ans += dp[i][1];
				if (bit[i] > 6) // 高位可能出现6，要把后面最高位为2计入
					ans += dp[i - 1][1];
				if (bit[i] == 4 || (bit[i + 1] == 6 && bit[i] == 2)) // 高位已经出现4或者62
					flag = true;
			}
		}
		return sum - ans;
	}

	public static void main(String[] args) throws IOException {
		init();
		while (true) {
			int n = nextInt();
			int m = nextInt();
			if (n == 0 && m == n)
				break;
			out.println(solve(m + 1) - solve(n));
		}

		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}
