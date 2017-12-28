//2711
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h2923___floyd___数据读入 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static Scanner scan = new Scanner(System.in);
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = 200000;
	static int dist[], visit[], head[];
	static int adj[][], time;

	static HashMap<String, Integer> map = new HashMap<String, Integer>();

	public static void main(String[] args) throws IOException {
		int c, a, b, val;
		String stra, strb, temp;
		// 这么写就对了？？？
		in.wordChars('-', '-');
		in.wordChars('<', '<');
		in.wordChars('>', '>');
		in.parseNumbers();
		time = 0;

		while (true) {
			// n = nextInt();
			// c = nextInt();
			// m = nextInt();
			n = scan.nextInt();
			c = scan.nextInt();
			m = scan.nextInt();
			if (n == 0 && c == 0 && m == 0)
				break;
			init();

			int index = 0;
			int[] mark = new int[c + 1];
			// map.put(next(), ++index);
			map.put(scan.next(), ++index);
			for (int i = 1; i <= c; i++) {
				// temp = next();
				temp = scan.next();
				if (!map.containsKey(temp))
					map.put(temp, ++index);
				mark[i] = map.get(temp);
			}

			for (int i = 1; i <= m; i++) {
				// stra = next();
				// temp = next();
				// strb = next();
				stra = scan.next();
				temp = scan.next();
				strb = scan.next();
				if (!map.containsKey(stra))
					map.put(stra, ++index);
				if (!map.containsKey(strb))
					map.put(strb, ++index);
				a = map.get(stra);
				b = map.get(strb);
				val = 0;
				for (int j = 0; j < temp.length(); j++)
					if (temp.charAt(j) >= '0' && temp.charAt(j) <= '9') {
						val = val * 10 + (temp.charAt(j) - '0');
					}
				if (temp.charAt(0) == '<' && val < adj[b][a])
					adj[b][a] = val;
				if (temp.charAt(temp.length() - 1) == '>' && val < adj[a][b])
					adj[a][b] = val;
			}

			floyd();

			long ans = 0;
			for (int i = 1; i <= c; i++)
				ans += adj[1][mark[i]] + adj[mark[i]][1];
			out.println(time + ". " + ans);
		}
		out.flush();
		out.close();
	}

	static void init() {
		map.clear();
		time++;
		adj = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			Arrays.fill(adj[i], inf);
			adj[i][i] = 0;
		}
	}

	static void floyd() {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (adj[i][k] == inf)
					continue;
				for (int j = 1; j <= n; j++) {
					if (adj[k][j] == inf)
						continue;
					if (adj[i][k] + adj[k][j] < adj[i][j])
						adj[i][j] = adj[i][k] + adj[k][j];
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

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

}