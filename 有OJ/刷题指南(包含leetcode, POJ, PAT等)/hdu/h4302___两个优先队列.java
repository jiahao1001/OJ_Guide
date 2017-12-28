import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.TreeMap;

public class h4302___两个优先队列 {
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
			new InputStreamReader(System.in)));
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, ans;

	public static void main(String[] args) throws Exception {
		int t = nextInt(), m, ch, x, y, a, b, f1;

		PriorityQueue<Integer> left = new PriorityQueue();
		PriorityQueue<Integer> right = new PriorityQueue<Integer>(11,
				new Comparator<Integer>() {
					public int compare(Integer a, Integer b) {
						if (a > b)
							return -1;
						else
							return 1;
					}
				});
		for (int gh = 1; gh <= t; gh++) {
			right.clear();
			left.clear();
			n = nextInt();
			m = nextInt();
			f1 = 0;
			ans = 0;
			y = 0;
			while (m-- > 0) {
				ch = nextInt();
				if (ch == 0) {
					x = nextInt();
					if (x > y)
						left.add(x);
					else
						right.add(x);
				} else {
					a = b = -1;
					if (!right.isEmpty())
						b = right.peek();
					if (!left.isEmpty())
						a = left.peek();
					if (b == y) {
						right.poll();
						continue;
					}
					if (a != -1 && b != -1) {
						if (a - y > y - b) {
							ans += y - b;
							y = b;
							right.poll();
							f1 = 0;
						} else if (a - y == y - b) {
							ans += a - y;
							if (f1 != 0) {
								y = a;
								left.poll();
							} else {
								y = b;
								right.poll();
							}
						} else {
							ans += a - y;
							y = a;
							left.poll();
							f1 = 1;
						}
					} else if (a != -1) {
						ans += a - y;
						y = a;
						left.poll();
						f1 = 1;
					} else if (b != -1) {
						ans += y - b;
						y = b;
						right.poll();
						f1 = 0;
					}
				}
			}
			pw.println("Case " + gh + ": " + ans);
		}
		pw.flush();
		pw.close();
	}

	static int nextInt() throws Exception {
		in.nextToken();
		return (int) in.nval;
	}

	static String next() throws IOException {
		in.nextToken();
		return (String) in.sval;
	}

}