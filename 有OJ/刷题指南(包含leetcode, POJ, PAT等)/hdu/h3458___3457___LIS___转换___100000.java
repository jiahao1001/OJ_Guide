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

public class h3458___3457___LIS___×ª»»___100000 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int pos[], queue[], longest;

	public static void main(String[] args) throws IOException {
		int n, a, b;
		coordinate list[];
		while ((n = nextInt()) != 0) {
			list = new coordinate[n * 2 + 1];
			for (int i = 1; i <= n; i++) {
				a = nextInt();
				b = nextInt();
				list[i * 2 - 1] = new coordinate(a, b, i, 1);
				a = nextInt();
				b = nextInt();
				list[i * 2] = new coordinate(a, b, i, 0);
			}

			Arrays.sort(list, 1, n * 2, null);
			pos = new int[n + 1];
			queue = new int[n + 1];
			queue[0] = Integer.MAX_VALUE;
			longest = -1;
			for (int i = 1; i <= 2 * n; i++) {
				if (list[i].pos == 0) {// right
					if (longest < pos[list[i].id])
						queue[++longest] = list[i].y;
					else
						queue[pos[list[i].id]] = Math.min(
								queue[pos[list[i].id]], list[i].y);
				} else {// left
					if (queue[0] > list[i].y)
						pos[list[i].id] = 0;
					else if (queue[longest] < list[i].y)
						pos[list[i].id] = longest + 1;
					else
						pos[list[i].id] = BinarySearch(list[i].y);
				}
			}
			out.println(longest + 1);
		}

		out.flush();
		out.close();
	}

	static int BinarySearch(int val) {
		int begin = 0, end = longest, mid;
		while (begin < end) {
			mid = (begin + end) >> 1;
			if (queue[mid] >= val)
				end = mid;
			else
				begin = mid + 1;
		}
		return begin;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}
}

class coordinate implements Comparable<coordinate> {
	int x, y, id, pos;// posÎª1×óÏÂ½Ç

	coordinate(int x, int y, int id, int pos) {
		this.x = x;
		this.y = y;
		this.id = id;
		this.pos = pos;
	}

	public int compareTo(coordinate o) {
		if (this.x < o.x)
			return -1;
		else if (this.x > o.x)
			return 1;
		else if (this.pos > o.pos)
			return -1;
		else if (this.y > o.y)
			return -1;
		else
			return 1;
	}

}