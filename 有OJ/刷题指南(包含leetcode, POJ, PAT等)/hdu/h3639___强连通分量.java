import java.awt.*;
import java.io.*;
import java.util.*;

public class h3639___强连通分量 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int n, m, visit[];

	public static void main(String[] args) throws IOException {
		int ttt = nextInt(), u, v;
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			m = nextInt();

			init();

			for (int i = 1; i <= m; i++) {
				u = nextInt() + 1;
				v = nextInt() + 1;
				addEdge(u, v);
			}

			for (int i = 1; i <= n; i++) {
				if (dfn[i] == -1) {
					dfsTarjan(i);
				}
			}

			Arrays.fill(head, -1);
			Arrays.fill(indegree, 0);
			Arrays.fill(outdegree, 0);

			if (cnt == 1) {
				out.println("Case " + test + ": " + (n - 1));
				for (int i = 0; i < n - 1; i++)
					out.print(i + " ");
				out.println(n - 1);
			} else {
				int ans = 0, print[] = new int[cnt + 1], count = 0;
				int len = toll;
				toll = 0;
				visit = new int[n + 1];
				for (int i = 0; i < len; i++) {
					u = label[edge[i].u];
					v = label[edge[i].v];
					if (u != v) {
						outdegree[v]++;
						indegree[u]++;
						addEdge(v, u);
					}
				}
				int temp;
				for (int i = 1; i <= cnt; i++) {
					if (indegree[i] == 0) {
						labelnum[i]--;
						Arrays.fill(visit, 0);
						temp = dfs(i);
						if (temp > ans) {
							ans = temp;
							count = 0;
							print[count++] = i;
						} else if (temp == ans) {
							print[count++] = i;
						}
					}
				}
				out.println("Case " + test + ": " + ans);
				int i = 1;
				loop: for (i = 1; i <= n; i++)
					for (int j = 0; j < count; j++) {
						if (label[i] == print[j]) {
							out.print((i - 1));
							break loop;
						}
					}
				for (i = i + 1; i <= n; i++)
					for (int j = 0; j < count; j++) {
						if (label[i] == print[j]) {
							out.print(" " + (i - 1));
							break;
						}
					}
				out.println();
			}
		}

		out.flush();
		out.close();
	}

	static int dfs(int u) {
		if (visit[u] == 1)
			return 0;
		int ans = labelnum[u], v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			ans += dfs(v);
		}
		visit[u] = 1;
		return ans;
	}

	static int nlimit = 5010, mlimit = 30010;
	static int label[] = new int[nlimit], labelnum[] = new int[nlimit], cnt;
	static int head[] = new int[nlimit], toll;
	static edge edge[] = new edge[mlimit];
	static int dfn[] = new int[nlimit], low[] = new int[nlimit], tempdfn;
	static int stack[] = new int[nlimit], inStack[] = new int[nlimit], top;

	static int indegree[] = new int[nlimit], outdegree[] = new int[nlimit];

	static void init() {
		Arrays.fill(head, -1);
		toll = 0;
		Arrays.fill(dfn, -1);
		Arrays.fill(low, 0);
		tempdfn = 0;
		top = 0;
		Arrays.fill(inStack, 0);
		Arrays.fill(labelnum, 0);
		cnt = 0;
	}

	static void dfsTarjan(int u) {
		dfn[u] = low[u] = ++tempdfn;
		stack[++top] = u;
		inStack[u] = 1;
		int v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (dfn[v] == -1) {
				dfsTarjan(v);
				low[u] = Math.min(low[u], low[v]);
			} else if (inStack[v] == 1) {
				low[u] = Math.min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			cnt++;
			do {
				labelnum[cnt]++;
				v = stack[top--];
				inStack[v] = 0;
				label[v] = cnt;
			} while (v != u);
		}
	}

	static class edge {
		int u, v, next;

		edge(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	static void addEdge(int u, int v) {
		edge[toll] = new edge(u, v);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static char nextChar() throws IOException {
		in.nextToken();
		return in.sval.charAt(0);
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}