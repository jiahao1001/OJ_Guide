import java.io.*;
import java.util.*;

public class h1851___¶þÎ¬SGº¯Êý {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int m[], l[];

	static int N = 20;
	static int sg[][] = new int[N + 1][N + 1];
	static boolean vis[] = new boolean[N];

	public static void main(String[] args) throws IOException {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j < i; j++) {
				Arrays.fill(vis, false);
				for (int k = 1; k <= j; k++)
					vis[sg[i - k][j]] = true;
				for (int k = 0;; k++)
					if (!vis[k]) {
						sg[i][j] = k;
						break;
					}
			}
			for (int j = i; j <= N; j++)
				sg[i][j] = i;
		}

		int test = scan.nextInt();
		while (test-- > 0) {
			n = scan.nextInt();
			int ans = 0;
			for (int i = 1; i <= n; i++)
				ans ^= sg[scan.nextInt()][scan.nextInt()];
			if (ans == 0)
				out.println("Yes");
			else
				out.println("No");
		}

		out.flush();
		out.close();
	}

}