import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h2894___Å·À­»ØÂ·___DFS {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int k, n, ans;

	public static void main(String[] args) throws IOException {
		int visit[], path[], cnt = 0;
		while (in.nextToken() != in.TT_EOF) {
			k = (int) in.nval;
			n = (1 << k) - 1;
			visit = new int[n + 1];
			visit[0] = 1;
			path = new int[n + 1];
			path[0] = 0;
			Arrays.fill(path, -1);
			ans = 0;
			out.print(n + 1 + " ");
			dfs(0, visit, path, 1);
		}

		out.flush();
		out.close();
	}

	static void dfs(int num, int[] visit, int[] path, int cnt) {
		if (ans > 0)
			return;
		int zero = (num << 1) & n;
		if (visit[zero] == 0) {
			visit[zero] = 1;
			path[cnt] = 0;
			if (cnt == n) {
				ans = 1;
				for (int i = 1; i <= k; i++)
					out.print(0);
				for (int i = 1; i <= n - k + 1; i++)
					out.print(path[i]);
				out.println();
			}
			dfs(zero, visit, path, cnt + 1);
			visit[zero] = 0;
		}
		int one = ((num << 1) | 1) & n;
		if (visit[one] == 0) {
			visit[one] = 1;
			path[cnt] = 1;
			dfs(one, visit, path, cnt + 1);
			visit[one] = 0;
		}
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}
