import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Set;
import java.util.TreeMap;

public class h3555___数位dp入门 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static long dp[][] = new long[22][3];

	static void init() {
		dp[0][0] = 1;
		for (int i = 1; i < 20; i++) {
			dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
			dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
		}
	}

	static long solve(long x) {
		long bit[] = new long[22];
		int toll = 0;
		while (x > 0) {
			bit[++toll] = x % 10;
			x /= 10;
		}
		bit[toll + 1] = 0;
		long ans = 0;
		boolean flag = false;
		for (int i = toll; i > 0; i--) {
			ans += dp[i - 1][2] * bit[i];
			if (flag) {
				ans += dp[i - 1][0] * bit[i];
			} else {
				if (bit[i] > 4)
					ans += dp[i - 1][1];
				if (bit[i + 1] == 4 && bit[i] == 9)
					flag = true;
			}
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		init();
		int test = nextInt();
		while (test-- > 0) {
			long num = nextLong();
			out.println(solve(num + 1));
		}

		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}
}
