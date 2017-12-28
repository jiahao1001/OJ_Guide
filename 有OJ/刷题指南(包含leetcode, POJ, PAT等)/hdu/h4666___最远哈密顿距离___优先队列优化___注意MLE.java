import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4666___最远哈密顿距离___优先队列优化___注意MLE {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int N = 60010, M = 32;
	static int point[] = new int[M];
	static boolean vis[] = new boolean[N];
	static Node node[][] = new Node[M][N];

	static PriorityQueue<Node> max[] = new PriorityQueue[M];
	static PriorityQueue<Node> min[] = new PriorityQueue[M];

	static class Node {
		int id, v;

		Node(int a, int b) {
			id = a;
			v = b;
		}
	}

	static void add(int i) {
		vis[i] = true;
		for (int state = 0; state < (1 << m); state++) {
			int temp = 0;
			for (int j = 0; j < m; j++)
				if (((state >> j) & 1) > 0)
					temp += point[j];
				else
					temp -= point[j];
			node[state][i].v = temp;
			max[state].add(node[state][i]);
			min[state].add(node[state][i]);
		}
	}

	static void delete(int i) {
		vis[i] = false;
	}

	static void print() {
		int ans = 0;
		Node nmax = null;
		Node nmin = null;
		for (int state = 0; state < (1 << m); state++) {
			while (!max[state].isEmpty()) {
				nmax = max[state].peek();
				if (vis[nmax.id])
					break;
				max[state].poll();
			}
			while (!min[state].isEmpty()) {
				nmin = min[state].peek();
				if (vis[nmin.id])
					break;
				min[state].poll();
			}
			if (max[state].isEmpty())
				return;
			else
				ans = Math.max(ans, nmax.v - nmin.v);
		}
		out.println(ans);
	}

	static Comparator<Node> comp1 = new Comparator<Node>() {
		public int compare(Node o1, Node o2) {
			if (o1.v > o2.v)
				return -1;
			else if (o1.v < o2.v)
				return 1;
			return 0;
		}
	};

	static Comparator<Node> comp2 = new Comparator<Node>() {
		public int compare(Node o1, Node o2) {
			return o1.v - o2.v;
		}
	};

	static void prework() {
		for (int i = 0; i < M; i++) {
			max[i] = new PriorityQueue<Node>(N, comp1);
			min[i] = new PriorityQueue<Node>(N, comp2);
		}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				node[i][j] = new Node(j, 0);
	}

	static void init() {
		Arrays.fill(vis, false);
		for (int i = 0; i < (1 << m); i++) {
			while (!max[i].isEmpty())
				max[i].poll();
			while (!min[i].isEmpty())
				min[i].poll();
		}
	}

	static int n, m;

	public static void main(String[] args) throws IOException {
		int op;
		prework();
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			init();

			for (int i = 1; i <= n; i++) {
				op = nextInt();
				if (op == 0) {
					for (int j = 0; j < m; j++)
						point[j] = nextInt();
					add(i);
				} else {
					int x = nextInt();
					delete(x);
				}
				print();
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