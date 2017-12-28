import java.io.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class h1404___sgº¯Êý {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int N = 1000000;
	static int sg[] = new int[N];
	static String str;

	static int length(int x) {
		if (x / 100000 > 0)
			return 6;
		if (x / 10000 > 0)
			return 5;
		if (x / 1000 > 0)
			return 4;
		if (x / 100 > 0)
			return 3;
		if (x / 10 > 0)
			return 2;
		return 1;
	}

	public static void main(String[] args) throws IOException {
		sg[0] = 1;
		for (int x = 1; x < N; x++) {
			if (sg[x] == 1)
				continue;
			int len = length(x);
			int i;
			for (i = len; i >= 1; i--) {
				int base = 1;
				int m = x;
				for (int j = 1; j < i; j++)
					base *= 10;
				int temp = (m % (base * 10)) / base;
				for (int j = temp; j < 9; j++) {
					m += base;
					sg[m] = 1;
				}
			}
			if (len < 6) {
				int m = x;
				int base = 1;
				for (i = len; i < 6; i++) {
					m *= 10;
					for (int b = 0; b < base; b++)
						sg[m + b] = 1;
					base *= 10;
				}
			}
		}

		while ((str = br.readLine()) != null) {
			if (str.charAt(0) == '0')
				out.println("Yes");
			else {
				int ans = sg[Integer.parseInt(str)];
				if (ans == 0)
					out.println("No");
				else
					out.println("Yes");
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