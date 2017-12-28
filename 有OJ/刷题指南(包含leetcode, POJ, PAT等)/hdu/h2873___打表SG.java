import java.io.*;

import java.util.*;

public class h2873___¥Ú±ÌSG {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static int N = 50;
	static int sg[][] = new int[N + 1][N + 1];
	static boolean vis[] = new boolean[N * N + 1];

	public static void main(String[] args) throws IOException {
		for (int i = 0; i < N; i++)
			sg[i][0] = sg[0][i] = i;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				Arrays.fill(vis, false);
				for (int a = 0; a < i; a++)
					for (int b = 0; b < j; b++)
						vis[sg[a][j] ^ sg[i][b]] = true;
				for (int k = 0;; k++)
					if (!vis[k]) {
						sg[i][j] = k;
						break;
					}
			}

		String str;
		while (scan.hasNext()) {
			n = scan.nextInt();
			m = scan.nextInt();
			if (n == 0 && m == 0)
				break;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				str = scan.next();
				for (int j = 0; j < m; j++)
					if (str.charAt(j) == '#')
						ans ^= sg[i][j];
			}
			if (ans > 0)
				out.println("John");
			else
				out.println("Jack");
		}

		out.flush();
		out.close();
	}
}