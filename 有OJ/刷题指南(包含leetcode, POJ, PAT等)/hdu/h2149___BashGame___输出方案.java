import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2149___BashGame___Êä³ö·½°¸ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int n, m;
		while (in.nextToken() != in.TT_EOF) {
			m = (int) in.nval;
			n = nextInt();
			if (m % (1 + n) == 0)
				out.println("none");
			else if (n > m) {
				for (int i = m; i < n; i++)
					out.print(i + " ");
				out.println(n);
			} else
				out.println(m % (n + 1));
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