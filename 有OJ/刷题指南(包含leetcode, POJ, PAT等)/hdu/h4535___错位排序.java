import java.io.*;
import java.util.*;

public class h4535___´íÎ»ÅÅÐò {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int n;
	static int mod = 1000000007;
	static long mark[] = new long[101];

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		Arrays.fill(mark, -1);
		mark[1] = 0;
		mark[2] = 1;
		mark[3] = 2;
		while (test-- > 0) {
			n = nextInt();
			out.println(getCuoNum(n));
		}

		out.flush();
		out.close();
	}

	static long getCuoNum(int n) {
		if (mark[n] != -1)
			return mark[n];
		long l = n;
		long t = getCuoNum(n - 1);
		if ((n & 1) == 1)
			l = (l * t) % mod - 1;
		else
			l = (l * t) % mod + 1;
		mark[n] = l;
		return mark[n];
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