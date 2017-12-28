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

public class h1217___floyd {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = Integer.MAX_VALUE;
	static int dist[], visit[], head[];
	static double adj[][];

	static HashMap<String, Integer> map = new HashMap<String, Integer>();

	public static void main(String[] args) throws IOException {
		String stra, strb;
		double temp;
		int index = 0;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			index++;
			adj = new double[n + 1][n + 1];

			for (int i = 1; i <= n; i++)
				map.put(next(), i);

			m = nextInt();
			for (int i = 1; i <= m; i++) {
				stra = next();
				temp = nextDouble();
				strb = next();
				adj[map.get(stra)][map.get(strb)] = temp;
			}

			if (floyd())
				out.println("Case " + index + ": Yes");
			else
				out.println("Case " + index + ": No");

		}

		out.flush();
		out.close();
	}

	static boolean floyd() {
		for (int mid = 1; mid <= n; mid++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (adj[i][mid] * adj[mid][j] > adj[i][j])
						adj[i][j] = adj[i][mid] * adj[mid][j];
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (adj[i][i] > 1)
				return true;
		return false;
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