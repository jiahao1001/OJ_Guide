import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class h1069___LIS—”…Ï {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int count = 0, n, a, b, c, f[], temp, ans;
		cube[] list;
		while ((n = nextInt()) != 0) {
			list = new cube[n * 3 + 1];
			for (int i = 0; i < n; i++) {
				a = nextInt();
				b = nextInt();
				c = nextInt();
				list[i * 3 + 1] = new cube(a, b, c);
				list[i * 3 + 2] = new cube(b, a, c);
				list[i * 3 + 3] = new cube(c, b, a);
			}
			Arrays.sort(list, 1, 3 * n + 1, null);

			f = new int[n * 3 + 1];

			ans = 0;
			for (int i = 1; i <= 3 * n; i++) {
				temp = 0;
				for (int j = 1; j < i; j++) {
					if (list[i].bigger(list[j]))
						if (temp < f[j])
							temp = f[j];
				}
				f[i] = temp + list[i].height;
				if (ans < f[i])
					ans = f[i];
			}

			out.println("Case " + (++count) + ": maximum height = " + ans);
		}

		out.flush();
		out.close();
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}

class cube implements Comparable<cube> {
	int height, width, length, square;

	cube(int a, int b, int c) {
		this.height = a;
		this.width = b;
		this.length = c;
		this.square = width * length;
	}

	public boolean bigger(cube a) {
		if ((this.width > a.width && this.length > a.length)
				|| (this.length > a.width && this.width > a.length))
			return true;
		else
			return false;
	}

	public int compareTo(cube o) {
		if (this.square < o.square)
			return -1;
		else
			return 1;
	}

}