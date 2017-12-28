import java.io.*;
import java.util.*;

import javax.sound.sampled.AudioFormat.Encoding;

public class h2176___»ù´¡Nimm²©ÞÄ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n, arr[], nimm, record[], index;

	public static void main(String[] args) throws IOException {
		int temp;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			arr = new int[n];
			nimm = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
				nimm = nimm ^ arr[i];
			}

			index = 0;
			record = new int[n * 2];
			for (int i = 0; i < n; i++) {
				temp = arr[i] ^ nimm;
				if (arr[i] > temp) {
					record[index++] = arr[i];
					record[index++] = temp;
				}
			}

			if (index == 0)
				out.println("No");
			else {
				out.println("Yes");
				for (int i = 0; i < index; i += 2)
					out.println(record[i] + " " + record[i + 1]);
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