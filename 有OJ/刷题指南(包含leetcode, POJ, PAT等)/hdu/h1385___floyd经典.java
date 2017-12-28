//2711
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

public class h1385___floyd¾­µä {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, inf = Integer.MAX_VALUE, mat[][], tax[], trace[][];

	public static void main(String[] args) throws IOException {
		int s, t, temp;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			mat = new int[n + 1][n + 1];
			trace = new int[n + 1][n + 1];
			tax = new int[n + 1];

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					temp = nextInt();
					trace[i][j] = j;
					if (temp == -1)
						mat[i][j] = inf;
					else
						mat[i][j] = temp;
				}

			for (int i = 1; i <= n; i++)
				tax[i] = nextInt();

			for (int k = 1; k <= n; k++) {
				for (int i = 1; i <= n; i++) {
					if (mat[i][k] == inf)
						continue;
					for (int j = 1; j <= n; j++) {
						if (mat[k][j] == inf)
							continue;
						temp = mat[i][k] + mat[k][j] + tax[k];
						if (temp < mat[i][j]) {
							mat[i][j] = temp;
							trace[i][j] = trace[i][k];
						} else if (temp == mat[i][j]) {
							if (trace[i][j] > trace[i][k])
								trace[i][j] = trace[i][k];
						}
					}
				}
			}

			while ((s = nextInt()) != -1 & (t = nextInt()) != -1) {
				temp = mat[s][t];
				out.println("From " + s + " to" + " " + t + " :");
				out.print("Path: ");
				int xx = s;
				out.print(s);
				while (xx != t) {
					out.printf("-->%d", trace[xx][t]);
					xx = trace[xx][t];
				}
				out.println();
				out.println("Total cost : " + temp);
				out.println();
			}
		}
		out.flush();
		out.close();
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
