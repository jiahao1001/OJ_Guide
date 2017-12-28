import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2147___ÕÒ¹æÂÉ²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, m;

	public static void main(String[] args) throws IOException {
		while (true) {
			n = nextInt();
			m = nextInt();
			if (n == 0 && m == 0)
				break;
			if ((n & 1) == 0)
				out.println("Wonderful!");
			else if ((m & 1) == 0)
				out.println("Wonderful!");
			else
				out.println("What a pity!");
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