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
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h1102___¬„Ã‚MST {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n;

	public static void main(String[] args) throws IOException {
		h1102___edge tmp;
		PriorityQueue<h1102___edge> queue;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			queue = new PriorityQueue<h1102___edge>();
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i < j) {
						tmp = new h1102___edge(i, j);
						tmp.w = nextInt();
						queue.add(tmp);
					} else
						nextInt();
				}
			}

			init(n);
			for (int i = 1; i <= n; i++)
				initOne(i);

			int m = nextInt();
			int a, b, ra, rb, cnt = 1;
			for (int i = 1; i <= m; i++) {
				a = nextInt();
				b = nextInt();
				ra = find(a);
				rb = find(b);
				if (ra != rb) {
					union(ra, rb);
					cnt++;
				}
			}

			int ans = 0;
			while (cnt < n) {
				tmp = queue.poll();
				a = tmp.u;
				b = tmp.v;
				ra = find(a);
				rb = find(b);

				if (ra != rb) {
					cnt++;
					ans += tmp.w;
					union(ra, rb);
				}
			}
			out.println(ans);
		}
		out.flush();
		out.close();
	}

	static int father[], rank[];

	static void init(int n) {
		father = new int[n + 1];
		rank = new int[n + 1];
	}

	static void initOne(int x) {
		father[x] = x;
		rank[x] = 1;
	}

	static int find(int x) {
		if (x == father[x])
			return x;
		father[x] = find(father[x]);
		return father[x];
	}

	static void union(int ra, int rb) {
		if (rank[ra] > rank[rb]) {
			father[rb] = ra;
		} else {
			if (rank[ra] == rank[rb])
				rank[rb]++;
			father[ra] = rb;
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

class h1102___node {
	int x, y;

	h1102___node(int x, int y) {
		this.x = x;
		this.y = y;
	}

}

class h1102___edge implements Comparable<h1102___edge> {
	int u, v;
	double w;

	h1102___edge(int u, int v) {
		this.u = u;
		this.v = v;
	}

	public int compareTo(h1102___edge o) {
		if (this.w < o.w)
			return -1;
		else if (this.w > o.w)
			return 1;
		else
			return 0;
	}

}