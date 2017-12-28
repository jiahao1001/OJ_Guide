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

public class h3414___竞赛图___汉密尔顿回路___数组模拟邻接链表 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, ans, adj[][], head[], record[], cnt, write[], point;
	static h3414___path[] edge;

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
				point = 0;
				edge = new h3414___path[n * (n - 1) / 2 + 1];
				head = new int[n + 1];
				record = new int[n + 1];
				Arrays.fill(head, 0);
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						if (nextInt() == 1) {
							addEdge(i, j);
							if (j == 1) {
								record[i] = 1;
								point++;
							}
						}
					}
				}

				ans = 0;
				visit = new int[n + 1];
				path = new int[n + 1];
				write = new int[n + 1];
				visit[1] = 1;
				path[1] = 1;
				dfs(1, 1, visit, path, 0);
				if (ans == 0) {
					out.println(-1);
				}
			}

		}

		out.flush();
		out.close();
	}

	static void addEdge(int u, int v) {
		cnt++;
		edge[cnt] = new h3414___path(v);
		edge[cnt].next = head[u];
		head[u] = cnt;
	}

	static void dfs(int num, int depth, int visit[], int path[], int oneNum) {
		if (ans > 0)
			return;
		if (depth == n) {
			if (edge[num].v == 1) {
				ans = 1;
				for (int h = 1; h < n; h++)
					out.print(path[h] + " ");
				out.println(path[n]);
			}
			return;
		}
		if (oneNum < point) {
			int v;
			for (int i = head[num]; i > 0; i = edge[i].next) {
				v = edge[i].v;
				if (visit[v] == 0) {
					visit[v] = 1;
					path[depth + 1] = v;
					if (record[oneNum] == 1)
						dfs(v, depth + 1, visit, path, oneNum + 1);
					else
						dfs(v, depth + 1, visit, path, oneNum);
					path[depth + 1] = 0;
					visit[v] = 0;
				}
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

class h3414___path {
	int v, next;

	h3414___path(int v) {
		this.v = v;
	}
}