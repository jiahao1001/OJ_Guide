import java.io.*;
import java.util.*;

public class h1043___∞À ˝¬Î___A_star___¬¸π˛∂Ÿæ‡¿Î___øµÕÿ—πÀı___”≈œ»∂”¡–___TLE {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static int limit = 362880;
	static boolean hash[] = new boolean[limit];
	static int goal = 123456789;
	static int dir[][] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	static char invert[] = { 'r', 'l', 'd', 'u' };
	static int stack[], top;
	static int ans;
	static node node[] = new node[limit];
	static int inf = 1 << 20;

	static PriorityQueue<node> queue = new PriorityQueue<node>();

	static class node implements Comparable<node> {
		int state, g, h, preHash, op;

		node() {
		}

		public int compareTo(node o) {
			return this.h + this.g - o.g - o.h;
		}
	}

	static int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
	static int count;

	static void init() {
		queue.clear();
		Arrays.fill(hash, false);
		ans = -1;
		for (int i = 0; i < limit; i++) {
			node[i].g = inf;
			node[i].h = inf;
			node[i].preHash = -1;
			node[i].state = -1;
			node[i].op = -1;
		}
	}

	static int encodeHash(int state) {
		int neoHash = 0;
		int record[] = new int[9];
		for (int i = 8; i >= 0; i--) {
			record[i] = state % 10;
			state /= 10;
		}

		for (int i = 8; i >= 0; i--) {
			count = 0;
			for (int j = i + 1; j <= 8; j++)
				if (record[j] < record[i])
					count++;
			neoHash += count * fac[8 - i];
		}
		return neoHash;
	}

	static int encodeHash(int[] record) {
		int neoHash = 0;
		for (int i = 8; i >= 0; i--) {
			count = 0;
			for (int j = i + 1; j <= 8; j++)
				if (record[j] < record[i])
					count++;
			neoHash += count * fac[8 - i];
		}
		return neoHash;
	}

	static int encodeState(int[] record) {
		int neoState = 0;
		for (int i = 0; i <= 8; i++)
			neoState = neoState * 10 + record[i];
		return neoState;
	}

	static boolean isValid(int x, int y) {
		if (x >= 0 && x < 3 && y >= 0 && y < 3)
			return true;
		return false;
	}

	static void exchange(int arr[], int a, int b) {
		arr[a] = arr[a] + arr[b];
		arr[b] = arr[a] - arr[b];
		arr[a] = arr[a] - arr[b];
	}

	static int x, y, tx, ty;

	static int estimate(int record[]) {
		int ret = 0;
		for (int i = 0; i <= 8; i++) {
			if (record[i] == 9)
				continue;
			x = i / 3;
			y = i % 3;
			tx = (record[i] - 1) / 3;
			ty = (record[i] - 1) % 3;
			ret += Math.abs(x - tx) + Math.abs(y - ty);
		}
		return ret;
	}

	static String str;
	static StringTokenizer stoke;

	public static void main(String[] args) throws IOException {
		for (int i = 0; i < limit; i++)
			node[i] = new node();

		node old;
		char ch;
		int x = 0, y = 0, id = 0, tx, ty, tid, oldState, s, oldHash, neoState, neoHash, neoH, neoG, record[] = new int[9];
		while ((str = br.readLine()) != null) {
			stoke = new StringTokenizer(str);
			oldState = 0;
			for (int i = 0; i < 9; i++) {
				ch = stoke.nextToken().charAt(0);
				if (ch == 'x') {
					oldState = oldState * 10 + 9;
					record[i] = 9;
				} else {
					oldState = oldState * 10 + ch - '0';
					record[i] = ch - '0';
				}
			}
			oldHash = encodeHash(oldState);
			init();
			s = node[oldHash].state = oldState;
			for (int i = 8; i >= 0; i--) {
				record[i] = s % 10;
				s /= 10;
			}
			node[oldHash].h = estimate(record);
			node[oldHash].g = 0;
			node[oldHash].preHash = -1;
			queue.add(node[oldHash]);

			loop: while (!queue.isEmpty()) {
				old = queue.poll();
				oldState = s = old.state;
				oldHash = encodeHash(oldState);

				if (hash[oldHash])
					continue;
				hash[oldHash] = true;

				for (int i = 8; i >= 0; i--) {
					record[i] = s % 10;
					s /= 10;
					if (record[i] == 9) {
						x = i / 3;
						y = i % 3;
						id = i;
					}
				}

				for (int i = 0; i < 4; i++) {
					tx = x + dir[i][0];
					ty = y + dir[i][1];
					tid = tx * 3 + ty;
					if (isValid(tx, ty)) {
						exchange(record, id, tid);

						neoState = encodeState(record);
						neoHash = encodeHash(record);
						neoH = estimate(record);
						neoG = old.g + 1;
						if (!hash[neoHash]
								|| neoH + neoG < node[neoHash].g
										+ node[neoHash].h) {
							node[neoHash].state = neoState;
							node[neoHash].h = neoH;
							node[neoHash].g = neoG;
							node[neoHash].preHash = oldHash;
							node[neoHash].op = i;
							queue.add(node[neoHash]);

						}
						if (neoState == goal) {
							ans = node[0].g + node[0].h;
							break loop;
						}

						exchange(record, id, tid);
					}
				}

			}

			if (ans == -1) {
				out.println("unsolvable");
			} else {
				int temp = 0;
				stack = new int[ans + 100];
				top = 0;
				while (node[temp].preHash != -1) {
					stack[++top] = node[temp].op;
					temp = node[temp].preHash;
				}
				for (int i = top; i >= 1; i--)
					out.print(invert[stack[i]]);
				out.println();
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

	static int nextint() throws IOException {
		in.nextToken();
		return (int) in.nval;
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