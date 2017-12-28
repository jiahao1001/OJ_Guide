import java.awt.*;
import java.io.*;
import java.util.*;

public class h3632___一排选人___相邻比较___三维dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		int n, arr[], compete[][], dp[][];
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			arr = new int[n + 2];
			compete = new int[n + 2][n + 2];
			dp = new int[n + 2][n + 2];
			for (int i = 1; i <= n; i++)
				arr[i] = nextInt();
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					compete[i][j] = nextInt();
			for (int i = 0; i <= n; i++)
				dp[i][i + 1] = 1;

			int j;
			for (int step = 2; step <= n + 1; step++) {
				for (int i = 0; i + step <= n + 1; i++) {
					j = i + step;
					for (int k = i + 1; k < j; k++) {
						if (dp[i][k] == 1 && dp[k][j] == 1
								&& (compete[i][k] == 1 || compete[j][k] == 1)) {
							dp[i][j] = 1;
							break;

						}
					}
				}
			}

			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (dp[0][i] == 1 && dp[i][n + 1] == 1)
					ans = Math.max(ans, arr[i]);
			}

			out.println("Case " + test + ": " + ans);
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

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}