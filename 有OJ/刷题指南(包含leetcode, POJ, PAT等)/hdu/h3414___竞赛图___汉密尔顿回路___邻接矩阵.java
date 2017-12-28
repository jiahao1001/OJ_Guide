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

public class h3414___¾ºÈüÍ¼___ººÃÜ¶û¶Ù»ØÂ·___ÁÚ½Ó¾ØÕó {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, ans, adj[][], outPut[];

	public static void main(String[] args) throws IOException {
		int visit[], path[];
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			if (n == 1) {
				nextInt();
				out.println(1);
			} else if (n == 2) {
				nextInt();
				nextInt();
				nextInt();
				nextInt();
				out.println(-1);
			} else {
				adj = new int[n + 1][n + 1];
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						adj[i][j] = nextInt();

				visit = new int[n + 1];
				path = new int[n + 1];
				ans = 0;
				Arrays.fill(adj[0], 1);
				outPut = new int[n + 1];
				path[1] = 1;
				dfs(1, 1, visit, path, 1);
				if (ans == 0)
					out.println(-1);
			}
		}

		out.flush();
		out.close();
	}

	static void dfs(int num, int depth, int visit[], int path[], int begin) {
		if (ans > 0)
			return;
		if (depth == n) {
			if (adj[num][begin] == 1) {
				ans = 1;
				for (int h = 1; h < n; h++)
					out.print(path[h] + " ");
				out.println(path[n]);
			}
			return;
		}
		for (int line = 1; line <= n; line++) {
			if (visit[line] == 0 && adj[num][line] == 1) {
				visit[line] = 1;
				path[depth + 1] = line;
				dfs(line, depth + 1, visit, path, begin);
				if (ans > 0)
					return;
				visit[line] = 0;
			}
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
