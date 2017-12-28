import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2188___»ù´¡BashGame {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		int n, m;
		while (test-- > 0) {
			n = nextInt();
			m = nextInt();
			if (n % (m + 1) == 0)
				out.println("Rabbit");
			else
				out.println("Grass");
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