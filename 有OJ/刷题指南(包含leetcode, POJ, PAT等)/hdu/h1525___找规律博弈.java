import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h1525___ÕÒ¹æÂÉ²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int a, b;

	static boolean solve(int a, int b) {
		boolean flag = false;
		if (a < b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		while (b > 0) {
			flag = !flag;
			if (a / b >= 2)
				break;
			a -= b;
			if (a < b) {
				a = a ^ b;
				b = a ^ b;
				a = a ^ b;
			}
		}
		return flag;
	}

	public static void main(String[] args) throws IOException {
		while (true) {
			a = nextInt();
			b = nextInt();
			if (a == 0 && b == 0)
				break;
			if (solve(a, b))
				out.println("Stan wins");
			else
				out.println("Ollie wins");
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