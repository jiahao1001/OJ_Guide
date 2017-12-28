import java.io.*;
import java.util.*;

public class h3032___Lasker_Nim___SGÕÒ¹æÂÉ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, arr[];

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			arr = new int[n];
			int ans = 0, temp, mod;
			for (int i = 0; i < n; i++) {
				temp = nextInt();
				mod = temp % 4;
				if (mod == 1 || mod == 2)
					ans = ans ^ temp;
				else if (mod == 0)
					ans = ans ^ (temp - 1);
				else
					ans = ans ^ (temp + 1);
			}
			if (ans > 0)
				out.println("Alice");
			else
				out.println("Bob");
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