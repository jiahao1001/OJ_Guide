import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;

public class h3414___¾ºÈüÍ¼ {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, m, flag[], prev[], alpha[], maxn = 1010;
	static int arr[], ans;
	static boolean g[][];

	public static void main(String[] args) throws IOException {
		int[] arr;
		while (true) {
			n = nextInt();
			if (n == 0)
				break;
			g = new boolean[n][n];
			arr = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (nextInt() == 1)
						g[i][j] = true;
					else
						g[i][j] = false;
				}
			}
			if (n == 1) {
				out.println(1);
				continue;
			}
			ans = 0;
			for (int i = 0; i < n; i++) {
				construct(g, n, arr, i);
				if (g[arr[n - 1]][arr[0]]) {
					for (int j = 0; j < n; j++) {
						if (j != 0)
							out.printf(" ");
						out.printf("%d", arr[j] + 1);
					}
					out.printf("\n");
					ans = 1;
					break;
				}
			}
			if (ans == 0)
				out.printf("-1\n");
		}
		out.flush();
		out.close();
	}

	static void construct(boolean[][] g, int n, int[] arr, int start) {
		int nxt[] = new int[n];
		Arrays.fill(nxt, -1);

		int head = start;
		for (int i = 0; i < n; i++) {
			if (i == start)
				continue;
			if (g[i][head]) {
				nxt[i] = head;
				head = i;
			} else {
				int prev = head;
				int iter = nxt[head];
				while (true) {
					if (iter == -1 || g[i][iter]) {
						nxt[prev] = i;
						nxt[i] = iter;
						break;
					}
					prev = iter;
					iter = nxt[iter];
				}
			}
		}
		int i = 0;
		for (int x = head; x != -1; x = nxt[x]) {
			arr[i++] = x;
		}
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
