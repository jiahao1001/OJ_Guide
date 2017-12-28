import java.io.*;

import java.util.*;

public class h2509___anti_SG {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;
	static int N = 100;
	static int sg[] = new int[N + 1];
	static boolean vis[] = new boolean[N + 1];

	public static void main(String[] args) throws IOException {
		for (int i = 1; i <= N; i++) {
			Arrays.fill(vis, false);
			for (int j = 1; j < i; j++)
				for (int k = 1; k + j < i; k++)
					vis[sg[j] ^ sg[k]] = true;
			if (i > 1)
				vis[sg[i - 1]] = true;

			for (int j = 0;; j++)
				if (!vis[j]) {
					sg[i] = j;
					break;
				}
		}

		int temp;
		while (scan.hasNext()) {
			n = scan.nextInt();

			int ans = 0;
			boolean flag = true;
			boolean flag2 = false;

			for (int i = 1; i <= n; i++) {
				temp = scan.nextInt();
				ans ^= temp;
				if (sg[temp] > 0)
					flag = false;
				if (sg[temp] > 1)
					flag2 = true;
			}

			if (ans == 0 && flag)
				out.println("Yes");
			else if (ans > 0 && flag2)
				out.println("Yes");
			else
				out.println("No");
		}

		out.flush();
		out.close();
	}
}