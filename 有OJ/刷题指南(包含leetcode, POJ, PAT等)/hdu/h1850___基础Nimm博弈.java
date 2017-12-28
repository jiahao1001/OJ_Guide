import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h1850___»ù´¡Nimm²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int n, arr[];
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			arr = new int[n];
			int nim = 0, temp, ans = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
				nim = nim ^ arr[i];
			}
			for (int i = 0; i < n; i++) {
				temp = nim ^ arr[i];
				if (arr[i] > temp)
					ans++;
			}
			out.println(ans);
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