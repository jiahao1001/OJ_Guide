import java.io.*;
import java.util.*;

public class h4203___SG规律打表 {
	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, s, k;
	static int N = 1000;
	static boolean vis[] = new boolean[N];
	static int sg[] = new int[101];

	public static void main(String[] args) throws IOException {
		for (k = 2; k <= 100; k++) {
			Arrays.fill(sg, 0);
			out.print("k is  " + k + "    ");
			for (s = 1; s <= 15; s++) {
				Arrays.fill(vis, false);
				int m = 1;
				while (m <= s) {
					vis[sg[s - m]] = true;
					m *= k;
				}
				for (int j = 0;; j++)
					if (!vis[j]) {
						sg[s] = j;
						out.printf("%5d", j);
						break;
					}
			}
			out.println();
		}

		out.flush();
		out.close();
	}
}