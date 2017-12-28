import java.io.*;

import java.util.*;

public class h2999___SG´ò±í {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static int N;
	static int sg[];
	static boolean vis[];
	static int number[], stone[];

	public static void main(String[] args) throws IOException {
		while (scan.hasNext()) {
			n = scan.nextInt();
			number = new int[n + 1];
			for (int i = 1; i <= n; i++)
				number[i] = scan.nextInt();
			Arrays.sort(number);
			N = 0;
			m = scan.nextInt();
			stone = new int[m + 1];
			for (int i = 1; i <= m; i++) {
				stone[i] = scan.nextInt();
				N = Math.max(N, stone[i]);
			}

			sg = new int[N + 1];
			vis = new boolean[N + 1];
			for (int i = 1; i <= N; i++) {
				Arrays.fill(vis, false);
				for (int j = 1; j <= n && number[j] <= i; j++)
					for (int a = 0; a <= i - number[j]; a++)
						vis[sg[a] ^ sg[i - number[j] - a]] = true;
				for (int j = 0;; j++)
					if (!vis[j]) {
						sg[i] = j;
						break;
					}
			}

			for (int i = 1; i <= m; i++)
				if (sg[stone[i]] > 0)
					out.println(1);
				else
					out.println(2);
		}

		out.flush();
		out.close();
	}
}