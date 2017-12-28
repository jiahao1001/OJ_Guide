import java.io.*;
import java.util.*;

public class h1061___ˮ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(System.out);

	static int n;

	static int two[] = { 6, 2, 4, 8 };
	static int three[] = { 1, 3, 9, 7 };
	static int four[] = { 6, 4 };
	static int seven[] = { 1, 7, 9, 3 };
	static int eight[] = { 6, 8, 4, 2 };
	static int nine[] = { 1, 9 };

	public static void main(String[] args) throws IOException {
		int test = nextInt();
		while (test-- > 0) {
			n = nextInt();
			switch (n % 10) {
			case 1:
				out.println(1);
				break;
			case 2:
				out.println(two[n % 4]);
				break;
			case 3:
				out.println(three[n % 4]);
				break;
			case 4:
				out.println(four[n % 2]);
				break;
			case 5:
				out.println(5);
				break;
			case 6:
				out.println(6);
				break;
			case 7:
				out.println(seven[n % 4]);
				break;
			case 8:
				out.println(eight[n % 4]);
				break;
			case 9:
				out.println(nine[n % 2]);
				break;
			case 0:
				out.println(0);
				break;
			}
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