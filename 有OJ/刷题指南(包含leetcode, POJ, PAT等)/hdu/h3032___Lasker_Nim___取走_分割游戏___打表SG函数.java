import java.io.*;
import java.util.*;

public class h3032___Lasker_Nim___取走_分割游戏___打表SG函数 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, arr[];

	static int N = 1000;
	static int sg[] = new int[N];

	static void dfs(int left) {
		if (sg[left] > -1)
			return;
		boolean vis[] = new boolean[N];
		for (int i = 0; i < left; i++) {
			dfs(i);
			vis[sg[i]] = true;
		}
		for (int i = 1; i < left; i++) {
			dfs(i);
			dfs(left - i);
			vis[sg[i] ^ sg[left - i]] = true;
		}
		for (int i = 0; i <= N; i++)
			if (!vis[i]) {
				sg[left] = i;
				return;
			}
	}

	public static void main(String[] args) throws IOException {
		Arrays.fill(sg, -1);
		sg[0] = 0;
		sg[1] = 1;
		for (int i = 0; i < 100; i++) {
			dfs(i);
			System.out.println(i + " finish   " + sg[i]);
		}
		for (int i = 0; i < 100; i++)
			out.println(i + " " + sg[i]);
		out.println();

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