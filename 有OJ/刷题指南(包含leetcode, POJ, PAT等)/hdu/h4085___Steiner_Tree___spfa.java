import java.io.*;
import java.util.*;

public class h4085___Steiner_Tree___spfa {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int inf = 1 << 29;
	static int N = 100, M = 2000, head[] = new int[N], toll;
	static edge edge[] = new edge[M];
	static int S = 1 << 11, condition;
	static int dp[][] = new int[N][S];
	static boolean inQ[][] = new boolean[N][S];
	static int st[] = new int[N];
	static LinkedList<node> queue = new LinkedList<node>();

	static void init() {
		Arrays.fill(head, -1);
		toll = 0;
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], inf);
			Arrays.fill(inQ[i], false);
		}
		condition = (1 << nn) - 1;
	}

	static void addEdge(int u, int v, int val) {
		edge[toll] = new edge(v, val);
		edge[toll].next = head[u];
		head[u] = toll++;
	}

	static boolean update(int u, int state, int val) {
		if (dp[u][state] > val) {
			dp[u][state] = val;
			return true;
		}
		return false;
	}

	static class node {
		int vert, state;

		node(int v, int s) {
			vert = v;
			state = s;
		}
	}

	static class edge {
		int v, val, next;

		edge(int v, int val) {
			this.v = v;
			this.val = val;
		}
	}

	static void spfa() {
		node temp;
		int u, v, state, val, s;
		while (!queue.isEmpty()) {
			temp = queue.poll();
			u = temp.vert;
			state = temp.state;
			inQ[u][state] = false;
			for (int e = head[u]; e != -1; e = edge[e].next) {
				v = edge[e].v;
				val = edge[e].val;
				s = st[v] | state;
				if (update(v, s, dp[u][state] + val) && state == s
						&& !inQ[v][state]) {
					inQ[v][state] = true;
					queue.add(new node(v, state));
				}
			}
		}
	}

	static void steiner_tree() {
		for (int state = 0; state <= condition; state++) {
			for (int u = 0; u < n; u++) {
				for (int sub = (state - 1) & state; sub > 0; sub = (sub - 1)
						& state)
					dp[u][state] = Math.min(dp[u][state], dp[u][sub | st[u]]
							+ dp[u][(state - sub) | st[u]]);
				if (dp[u][state] < inf) {
					inQ[u][state] = true;
					queue.add(new node(u, state));
				}
			}
			spfa();
		}
	}

	static void solve() {
		int cost[] = new int[condition + 1];
		Arrays.fill(cost, inf);
		for (int i = 0; i <= condition; i++)
			for (int j = 0; j < n; j++)
				cost[i] = Math.min(cost[i], dp[j][i]);

		for (int i = 1; i <= condition; i++)
			if (check(i))
				for (int j = (i - 1) & i; j > 0; j = (j - 1) & i)
					if (check(j))
						cost[i] = Math.min(cost[i], cost[j] + cost[i - j]);

		if (cost[condition] == inf)
			out.println("No solution");
		else
			out.println(cost[condition]);
	}

	static boolean check(int x) {
		int r = 0;
		for (int i = 0; x > 0; i++, x >>= 1)
			r += (x & 1) * (i < k ? 1 : -1);
		return r == 0;
	}

	static int n, nn, k;

	public static void main(String[] args) throws IOException {
		int test = nextInt(), u, v, val, q;
		while (test-- > 0) {
			n = nextInt();
			q = nextInt();
			k = nextInt();
			nn = k * 2;
			init();
			while (q-- > 0) {
				u = nextInt() - 1;
				v = nextInt() - 1;
				val = nextInt();
				addEdge(u, v, val);
				addEdge(v, u, val);
			}

			Arrays.fill(st, 0);
			for (int i = 0; i < k; i++) {
				st[i] = 1 << i;
				dp[i][1 << i] = 0;
				st[i + n - k] = 1 << (i + k);
				dp[i + n - k][st[i + n - k]] = 0;
			}

			steiner_tree();
			solve();
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}
}