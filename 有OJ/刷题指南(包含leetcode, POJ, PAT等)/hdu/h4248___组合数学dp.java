import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class h4248___组合数学dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n, arr[], sum[];
	static long mod = 1000000007;
	static long dp[][], c[][];

	static void init() {
		int N = 10010;
		dp = new long[110][N];
		c = new long[N][110];
		c[0][0] = 1;
		c[1][0] = 1;
		c[1][1] = 1;
		for (int i = 2; i < N; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i && j < 110; j++)
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}

	public static void main(String[] args) throws IOException {
		int index = 0;
		init();
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			arr = new int[n + 1];
			sum = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				arr[i] = nextInt();
				sum[i] = sum[i - 1] + arr[i];
			}
			for (int i = 0; i <= n; i++)
				Arrays.fill(dp[i], 0);

			dp[0][0] = 1;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= sum[i - 1]; j++) {
					for (int k = 0; k <= sum[i] - sum[i - 1]; k++) {
						dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]
								* c[j + k][k] % mod)
								% mod;
					}
				}
			}

			long ans = 0;
			for (int i = 1; i <= sum[n]; i++)
				ans = (ans + dp[n][i]) % mod;
			ans = ans % mod;
			while (ans < 0)
				ans += mod;
			index++;
			out.println("Case " + index + ": " + ans);
		}
		out.flush();
		out.close();
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}