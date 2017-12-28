import java.awt.Stroke;
import java.io.*;
import java.util.*;

public class h1269___裸的强连通分量 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static StringTokenizer stoke;
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static Scanner scan = new Scanner(System.in);

	static int n, m;

	public static void main(String[] args) throws IOException {
		Tarjan tar = new Tarjan(10000, 100000);
		int a, b;
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			tar.init();
			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				tar.addEdge(a, b);
			}
			int ans = tar.getComponentNum(n);
			if (ans > 1)
				out.println("No");
			else
				out.println("Yes");
		}

		out.flush();
		out.close();
	}

	static class Tarjan {
		int n, m;
		int head[], toll;
		edge edge[];
		int dfn[], low[], tempdfn;
		int stack[], inStack[], top;
		int cnt, label[], max[];

		Tarjan(int nn, int mm) {
			this.n = nn;
			this.m = mm;
			head = new int[n + 1];
			edge = new edge[m];
			dfn = new int[n + 1];
			low = new int[n + 1];
			stack = new int[n + 1];
			inStack = new int[n + 1];
			label = new int[n + 1];
			max = new int[n + 1];
		}

		void dfsTarjan(int u) {
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
				} while (v != u);
			}
		}

		int getComponentNum(int n) {
			for (int i = 1; i <= n; i++)
				if (dfn[i] == -1)
					dfsTarjan(i);
			return cnt;
		}

		void init() {
			Arrays.fill(head, -1);
			toll = 0;

			Arrays.fill(dfn, -1);
			tempdfn = 0;

			Arrays.fill(inStack, 0);
			top = 0;

			Arrays.fill(label, 0);
			cnt = 0;

			Arrays.fill(max, 0);
		}

		void addEdge(int u, int v) {
			edge[toll] = new edge(u, v);
			edge[toll].next = head[u];
			head[u] = toll;
			toll++;
		}

		class edge {
			int u, v;
			int next;

			edge(int u, int v) {
				this.u = u;
				this.v = v;
			}

		}
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