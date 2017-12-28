import java.io.*;
import java.math.BigInteger;
import java.util.*;

//思路是缩点，然后根据公式，发现我们最后球的结果实际上就是n^2-n-m-v1*v2，v1+v2=n,所有二者的差值应该尽量大
//所以就要找出最小的v1
//有一个小bug
//只有所点之后入读或者出度为0的点才能够作为v1

public class h4635___Tarjan {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 100100, M = 101000;
	static int head[] = new int[N], toll;
	static edge edge[] = new edge[M];
	static int dfn[] = new int[N], low[] = new int[N], tempdfn;
	static int stack[] = new int[N], inStack[] = new int[N], top;
	static int cnt, label[] = new int[N], component[] = new int[N];

	static void dfsTarjan(int u) {
		dfn[u] = low[u] = ++tempdfn;
		stack[++top] = u;
		inStack[u] = 1;
		int v;
		for (int e = head[u]; e != -1; e = edge[e].next) {
			v = edge[e].v;
			if (dfn[v] == -1) {
				dfsTarjan(v);
				low[u] = (int) Math.min(low[u], low[v]);
			} else if (inStack[v] == 1) {
				low[u] = (int) Math.min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			cnt++;
			do {
				v = stack[top--];
				inStack[v] = 0;
				label[v] = cnt;
				component[cnt]++;
			} while (v != u);
		}
	}

	static int getComponentNum(int n) {
		for (int i = 1; i <= n; i++)
			if (dfn[i] == -1)
				dfsTarjan(i);
		return cnt;
	}

	// m表示边数,这一步进行缩点
	static void getShortened(int m) {
		int u, v;
		int mark[][] = new int[cnt + 1][cnt + 1];
		for (int i = 1; i <= m; i++) {
			u = component[edge[i - 1].u];
			v = component[edge[i - 1].v];
			if (u != v && mark[u][v] == 0) {
				mark[u][v] = 1;
			}
		}
	}

	static void init() {
		Arrays.fill(head, -1);
		toll = 0;
		Arrays.fill(dfn, -1);
		tempdfn = 0;
		Arrays.fill(inStack, 0);
		top = 0;
		Arrays.fill(component, 0);
		Arrays.fill(label, 0);
		cnt = 0;
	}

	static void addEdge(int u, int v) {
		edge[toll] = new edge(u, v);
		edge[toll].next = head[u];
		head[u] = toll;
		toll++;
	}

	static class edge {
		int u, v, next;

		edge(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	static int n, m;

	public static void main(String[] args) throws IOException {
		int ttt = nextInt();
		init();
		int u, v;
		for (int test = 1; test <= ttt; test++) {
			n = nextInt();
			m = nextInt();
			init();

			for (int i = 1; i <= m; i++) {
				u = nextInt();
				v = nextInt();
				addEdge(u, v);
			}

			int ans = getComponentNum(n);
			if (ans == 1)
				out.println("Case " + test + ": -1");
			else {
				int indeg[] = new int[cnt + 1], outdeg[] = new int[cnt + 1];
				for (int i = 1; i <= m; i++) {
					u = label[edge[i - 1].u];
					v = label[edge[i - 1].v];
					if (u != v) {
						outdeg[u]++;
						indeg[v]++;
					}
				}
				int min = n;
				for (int i = 1; i <= cnt; i++)
					if (indeg[i] == 0 || outdeg[i] == 0)
						min = Math.min(min, component[i]);

				ans = n * n - n - m - min * (n - min);
				out.println("Case " + test + ": " + ans);
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