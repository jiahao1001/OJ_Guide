import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class h3469___ˮ {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static int arr[] = new int[2000010];
	static int brr[] = new int[2000010];
	static int sum[] = new int[1000010];

	public static void main(String[] args) throws IOException {
		int t = nextInt(), ans = 0;
		for (int test = 1; test <= t; test++) {
			n = nextInt();
			if (n == 1)
				ans = 1;
			else if (n == 2)
				ans = 2;
			else {
				ans = (n - 2) * 2;
			}
			out.println("Case " + test + ": " + ans);
		}

		out.flush();
		out.close();
	}

	static int change(char ch) {
		if (ch == 'C')
			return 1;
		else
			return -1;
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