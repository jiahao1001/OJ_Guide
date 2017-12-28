import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h1527___Wythoff_Game___»ù´¡ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int solve(int k) {
		return (int) Math.floor(((1.0 + Math.sqrt(5)) / 2 * k));
	}

	static int a, b;

	public static void main(String[] args) throws IOException {
		while (in.nextToken() != in.TT_EOF) {
			a = (int) in.nval;
			b = nextInt();
			if (a > b) {
				a = a + b;
				b = a - b;
				a = a - b;
			}
			int k = b - a;
			int ak = solve(k);
			if (ak == a)
				out.println(0);
			else
				out.println(1);
		}
		out.flush();
		out.close();
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

	static long nextLong() throws IOException {
		in.nextToken();
		return (long) in.nval;
	}

}