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

public class h4337___Å·À­»ØÂ·___DFS {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, ans, head[], outPut[], record[];
	static h4337___path edge[];
	static boolean mark;

	public static void main(String[] args) throws IOException {
		int visit[], h4337___path[], a, b;
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			m = nextInt();
			head = new int[n + 1];
			Arrays.fill(head, -1);
			edge = new h4337___path[2 * m];
			record = new int[n + 1];
			for (int i = 0; i < m; i++) {
				a = nextInt();
				b = nextInt();
				edge[i * 2] = new h4337___path(b);
				edge[i * 2].next = head[a];
				head[a] = i * 2;
				edge[i * 2 + 1] = new h4337___path(a);
				edge[i * 2 + 1].next = head[b];
				head[b] = i * 2 + 1;
				if (a == 1)
					record[b] = 1;
				else if (b == 1)
					record[a] = 1;
			}
			visit = new int[n + 1];
			visit[1] = 1;
			h4337___path = new int[n + 1];
			h4337___path[1] = 1;
			ans = 0;
			outPut = new int[n + 1];
			dfs(1, visit, h4337___path, 1);
			if (ans == 0) {
				out.println("no solution");
			} else {
				for (int i = 1; i < n; i++)
					out.print(outPut[i] + " ");
				out.println(outPut[n]);
			}
		}

		out.flush();
		out.close();
	}

	static void dfs(int num, int[] visit, int[] h4337___path, int cnt) {
		if (ans > 0)
			return;
		if (cnt == n) {
			if (record[num] == 1) {
				ans = 1;
				for (int h = 1; h <= n; h++) {
					outPut[h4337___path[h]] = h;
				}
				return;
			}
		}
		for (int i = head[num]; i >= 0; i = edge[i].next) {
			int v = edge[i].v;
			if (visit[v] == 0) {
				visit[v] = 1;
				h4337___path[v] = cnt + 1;
				dfs(v, visit, h4337___path, cnt + 1);
				h4337___path[v] = 0;
				visit[v] = 0;
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

class h4337___path {
	int v, next;

	h4337___path(int v) {
		this.v = v;
	}
}