import java.awt.*;
import java.io.*;
import java.util.*;

public class h3831___±‡º≠æ‡¿Î±‰–Œ___¬‘ƒ— {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int inf = 1000000000;

	public static void main(String[] args) throws IOException {
		String a, b;
		int arr[], brr[];
		int n, m, dp[][][];
		while (true) {
			a = br.readLine();
			if (a.equals("#"))
				break;
			b = br.readLine();
			n = a.length();
			m = b.length();
			arr = new int[n + 1];
			brr = new int[m + 1];
			for (int i = 1; i <= n; i++)
				if (a.charAt(i - 1) >= 'a')
					arr[i] = a.charAt(i - 1) - 'a' + 26;
				else
					arr[i] = a.charAt(i - 1) - 'A';
			for (int i = 1; i <= m; i++)
				if (b.charAt(i - 1) >= 'a')
					brr[i] = b.charAt(i - 1) - 'a' + 26;
				else
					brr[i] = b.charAt(i - 1) - 'A';

			dp = new int[n + 1][m + 1][53];
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= m; j++)
					Arrays.fill(dp[i][j], inf);

			dp[0][0][52] = 0;
			for (int i = 0; i <= n; i++)
				dp[i][0][52] = i;
			for (int j = 0; j <= m; j++)
				dp[0][j][52] = j;

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					for (int k = 0; k < 52; k++) {
						if (brr[j] == k) {
							dp[i][j][k] = Math.min(dp[i][j][k],
									dp[i - 1][j - 1][k]);
						} else {
							dp[i][j][k] = Math.min(dp[i - 1][j - 1][k], Math
									.min(dp[i - 1][j][k], dp[i][j - 1][k])) + 1;
							dp[i][j][brr[j]] = Math.min(dp[i][j][brr[j]],
									dp[i - 1][j - 1][k] + 1);
						}
					}
					if (arr[i] == brr[j])
						dp[i][j][52] = Math.min(dp[i][j][52],
								dp[i - 1][j - 1][52]);
					else {
						dp[i][j][52] = Math.min(dp[i - 1][j - 1][52], Math.min(
								dp[i - 1][j][52], dp[i][j - 1][52])) + 1;
						dp[i][j][brr[j]] = Math.min(dp[i][j][brr[j]],
								dp[i - 1][j - 1][52] + 1);
					}
				}
			}
			int min = inf;
			for (int i = 0; i <= 52; i++)
				min = Math.min(min, dp[n][m][i]);
			out.println(min);

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