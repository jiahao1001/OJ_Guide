//3629
//1417
//2352

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h1243___LCS___dp {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int n, m, c[][];
		char chx, chy;
		String a, b, str;
		int table[];
		while (in.nextToken() != in.TT_EOF) {
			n = (int) in.nval;

			str = next();
			table = new int[123];
			for (int i = 0; i < n; i++)
				table[(int) str.codePointAt(i)] = nextInt();

			a = next();
			n = a.length();
			b = next();
			m = b.length();
			c = new int[n + 1][m + 1];
			for (int i = 1; i <= n; i++) {
				chx = a.charAt(i - 1);
				for (int j = 1; j <= m; j++) {
					chy = b.charAt(j - 1);
					if (chx == chy) {
						c[i][j] = c[i - 1][j - 1] + table[(int) chx];
					} else {
						c[i][j] = Math.max(c[i - 1][j - 1], Math.max(
								c[i - 1][j], c[i][j - 1]));
					}
				}
			}

			out.println(c[n][m]);
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