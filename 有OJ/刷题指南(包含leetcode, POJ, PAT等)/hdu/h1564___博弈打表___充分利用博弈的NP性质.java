import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h1564___博弈打表___充分利用博弈的NP性质 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;
	static boolean vis[][];

	static int dir[][] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };

	static boolean dfs(int x, int y) {
		vis[x][y] = true;
		boolean ret;
		int i, j;
		for (int c = 0; c < 4; c++) {
			i = x + dir[c][0];
			j = y + dir[c][1];
			if (i >= 0 && j >= 0 && i < n && j < n && !vis[i][j]) {
				ret = dfs(i, j);
				if (!ret)// 如果下一点有必败点，那么当前点一定是必胜点，即为下一点有P点，当前点就是N点
					return true;
			}
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			vis = new boolean[n][n];

			if (dfs(0, 0))
				out.println("8600");
			else
				out.println("ailyanlu");
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