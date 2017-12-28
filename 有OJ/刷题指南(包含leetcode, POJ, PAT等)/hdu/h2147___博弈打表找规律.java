import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2147___博弈打表找规律 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static boolean vis[][], dp[][];
	static int dir[][] = { { 0, -1 }, { 1, 0 }, { -1, 1 } };

	static boolean dfs(int x, int y) {
		if (vis[x][y])
			return dp[x][y];
		vis[x][y] = true;
		int i, j;
		boolean ret = true;
		for (int c = 0; c < 3; c++) {
			i = x + dir[c][0];
			j = y + dir[c][1];
			if (i >= 0 && i < n && j >= 0 && j < m) {
				ret = dfs(i, j);
				if (!ret) {
					dp[x][y] = true;
					return true;
				}
			}
		}
		dp[x][y] = false;
		return false;
	}

	public static void main(String[] args) throws IOException {
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			vis = new boolean[n][m];
			dp = new boolean[n][m];
			if (dfs(0, m - 1))
				out.println("kiki");
			else
				out.println("zz");

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					if (dp[i][j])
						out.print(1 + "  ");
					else
						out.print(0 + "  ");
				out.println();
			}
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

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static float nextFloat() throws IOException {
		in.nextToken();
		return (float) in.nval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}