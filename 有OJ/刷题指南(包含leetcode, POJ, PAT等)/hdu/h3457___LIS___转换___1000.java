import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h3457___LIS___×ª»»___1000 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int n, a, b, c, d, dp[], longest, temp;
		rectangle list[];
		while ((n = nextInt()) != 0) {
			if (n == 0)
				break;
			list = new rectangle[n + 1];
			for (int i = 1; i <= n; i++) {
				a = nextInt();
				b = nextInt();
				c = nextInt();
				d = nextInt();
				list[i] = new rectangle(a, b, c, d);
			}
			Arrays.sort(list, 1, n + 1, null);

			dp = new int[n + 1];
			longest = 0;
			for (int i = 1; i <= n; i++) {
				temp = 0;
				for (int j = 1; j < i; j++) {
					if (list[i].x1 > list[j].x2 && list[i].y1 > list[j].y2)
						if (dp[j] > temp)
							temp = dp[j];
				}
				// if (list[i].x1 == list[i].x2 || list[i].y1 == list[i].y2)
				// dp[i] = temp;
				// else
				dp[i] = temp + 1;
				if (dp[i] > longest)
					longest = dp[i];
			}

			out.println(longest);
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

class rectangle implements Comparable<rectangle> {
	int x1, y1, x2, y2;

	rectangle(int a, int b, int c, int d) {
		this.x1 = a;
		this.y1 = b;
		this.x2 = c;
		this.y2 = d;
	}

	public int compareTo(rectangle o) {
		if (this.x1 < o.x1)
			return -1;
		else if (this.x1 > o.x1)
			return 1;
		else if (this.x2 > o.x2)
			return -1;
		else
			return 1;
	}
}
