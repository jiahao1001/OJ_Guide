import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.PriorityQueue;

public class h1116___欧拉通路 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	static int n, inDegree[] = new int[26], outDegree[] = new int[26];
	static boolean visit[] = new boolean[26];

	public static void main(String[] args) throws IOException {
		int testcase = nextInt(), x, y, ra, rb, cnt = 0, root, tmp;
		String str;
		while (testcase-- > 0) {
			n = nextInt();
			Arrays.fill(inDegree, 0);
			Arrays.fill(outDegree, 0);
			Arrays.fill(visit, false);
			init();
			for (int i = 1; i <= n; i++) {
				str = next();
				x = str.charAt(0) - 'a';
				y = str.charAt(str.length() - 1) - 'a';
				visit[x] = true;
				visit[y] = true;
				inDegree[x]++;
				outDegree[y]++;
				ra = find(x);
				rb = find(y);
				if (ra != rb)
					union(ra, rb);
				cnt = x;
			}

			root = find(cnt);
			cnt = 0;
			for (int i = 0; i <= 25; i++) {
				if (visit[i]) {
					tmp = find(i);
					if (tmp != root)
						cnt++;
				}
			}
			if (cnt > 0)
				out.println("The door cannot be opened.");
			else
				out.println(check());
		}

		out.flush();
		out.close();
	}

	static String check() {
		int num = 0, inOdd = 0, outOdd = 0;
		for (int i = 0; i <= 25; i++) {
			if (inDegree[i] != outDegree[i]) {
				num++;
				if (num > 2) {
					return "The door cannot be opened.";
				} else if (inDegree[i] == outDegree[i] + 1)
					inOdd++;
				else if (inDegree[i] + 1 == outDegree[i])
					outOdd++;
			}
		}
		// num==0切不能忘
		if (inOdd == 1 && outOdd == 1 || num == 0)
			return "Ordering is possible.";
		else
			return "The door cannot be opened.";
	}

	static int father[], rank[];

	static void init() {
		father = new int[26];
		rank = new int[26];
		for (int i = 0; i <= 25; i++) {
			father[i] = i;
			rank[i] = 1;
		}
	}

	static int find(int x) {
		if (father[x] == x)
			return x;
		father[x] = find(father[x]);
		return father[x];
	}

	static void union(int ra, int rb) {
		if (rank[ra] > rank[rb]) {
			father[rb] = ra;
		} else {
			if (rank[ra] == rank[rb])
				rank[rb]++;
			father[ra] = rb;
		}
	}

	static String next() throws IOException {
		in.nextToken();
		return in.sval;
	}

	static double nextDouble() throws IOException {
		in.nextToken();
		return in.nval;
	}

	static int nextInt() throws IOException {
		in.nextToken();
		return (int) in.nval;
	}

}
