import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class h3501___Å·À­º¯Êý {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static long mod = 1000000007;

	public static void main(String[] args) throws IOException {
		long n;
		while (true) {
			n = nextLong();
			if (n == 0)
				break;
			long ans = Euler(n);
			ans = n * (n - 1 - ans) / 2 % mod;
			out.println(ans);
		}

		out.flush();
		out.close();
	}

	static long Euler(long n) {
		long ans = n;

		if (n % 2 == 0) {
			while (n % 2 == 0)
				n /= 2;
			ans /= 2;
		}
		for (int i = 3; i * i <= n; i += 2)
			if (n % i == 0) {
				while (n % i == 0)
					n /= i;
				ans = ans * (i - 1) / i;
			}
		if (n > 1)
			ans -= ans / n;
		return ans;
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
