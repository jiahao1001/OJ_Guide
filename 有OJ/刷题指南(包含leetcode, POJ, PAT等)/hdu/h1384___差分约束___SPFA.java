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

public class h1384___差分约束___SPFA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, max, dis[], head[];
	static h1384___path edge[];
	static boolean visit[];
	// 此处不需要排序，LinkedList比PriorityQueue快
	static LinkedList<Integer> queue;

	public static void main(String[] args) throws IOException {
		int i, j, val;
		head = new int[50001];
		queue = new LinkedList<Integer>();
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;
			Arrays.fill(head, -1);
			max = 0;
			edge = new h1384___path[n + 100001];
			for (int k = 0; k < n; k++) {
				i = nextInt();
				j = nextInt();
				val = nextInt();
				edge[k] = new h1384___path(i - 1, -val);
				edge[k].next = head[j];
				head[j] = k;
				max = Math.max(max, j);
			}
			int cnt = n - 1;
			for (int k = 1; k <= max; k++) {
				cnt++;
				edge[cnt] = new h1384___path(k - 1, 0);
				edge[cnt].next = head[k];
				head[k] = cnt;
				cnt++;
				edge[cnt] = new h1384___path(k, 1);
				edge[cnt].next = head[k - 1];
				head[k - 1] = cnt;
			}
			n += 2 * max - 1;

			SPFA();

		}
		out.flush();
		out.close();
	}

	static void SPFA() {
		queue.clear();
		queue.add(max);
		visit = new boolean[max + 1];
		dis = new int[max + 1];
		Arrays.fill(visit, false);
		Arrays.fill(dis, max);
		visit[max] = true;
		dis[max] = 0;

		int id;
		while (!queue.isEmpty()) {
			id = queue.poll();
			visit[id] = false;
			for (int i = head[id]; i >= 0; i = edge[i].next) {
				if (dis[edge[i].v] > dis[id] + edge[i].val) {
					dis[edge[i].v] = dis[id] + edge[i].val;
					if (!visit[edge[i].v]) {
						visit[edge[i].v] = true;
						queue.add(edge[i].v);
					}
				}
			}
		}

		out.println(-dis[0]);
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

class h1384___path {
	int v, val, next;

	h1384___path(int v, int val) {
		this.v = v;
		this.val = val;
		this.next = -1;
	}
}
