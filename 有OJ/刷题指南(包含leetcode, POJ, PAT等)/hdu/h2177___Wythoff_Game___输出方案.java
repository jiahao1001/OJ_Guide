import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2177___Wythoff_Game___Êä³ö·½°¸ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int solve(int k) {
		return (int) Math.floor(((1.0 + Math.sqrt(5)) / 2 * k));
	}

	static int a, b;

	public static void main(String[] args) throws IOException {
		while (true) {
			a = nextInt();
			b = nextInt();
			if (a == 0 && b == 0)
				break;
			if (a > b) {
				a = a ^ b;
				b = a ^ b;
				a = a ^ b;
			}

			int temp = solve(b - a);
			if (temp >= a)
				out.println(0);
			else {
				out.println(1);
				out.println(temp + " " + (temp + b - a));
				for (int i = b; i > a; i--)
					if (solve(i - a) == a) {
						out.println(a + " " + i);
						break;
					}
				for (int i = a; i >= 0; i--)
					if (solve(a - i) == i) {
						out.println(i + " " + a);
						break;
					}
			}
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