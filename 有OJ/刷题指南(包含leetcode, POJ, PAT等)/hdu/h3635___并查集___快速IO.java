import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class h3635___并查集___快速IO {
	static int n, q, a, b, ra, rb;
	// 一次是球所在的城市id，城市中所含有的球数目，球移动次数
	// static int[] father = new int[10001], changeTime = new int[10001],
	// ballNumber = new int[10001];
	static int[] father, changeTime, ballNumber;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(br.readLine());
		StringTokenizer temp;
		for (int time = 1; time <= t; time++) {
			pw.println("Case " + time + ":");
			temp = new StringTokenizer(br.readLine());
			n = Integer.parseInt(temp.nextToken());
			q = Integer.parseInt(temp.nextToken());
			init();
			for (int i = 1; i <= q; i++) {
				temp = new StringTokenizer(br.readLine());
				if (temp.nextToken().charAt(0) == 'T') {
					a = Integer.parseInt(temp.nextToken());
					b = Integer.parseInt(temp.nextToken());
					union(a, b);
				} else {
					a = Integer.parseInt(temp.nextToken());
					ra = find(a);
					pw.println(ra + " " + ballNumber[ra] + " " + changeTime[a]);
				}
			}
		}
		br.close();
		pw.close();
	}

	static void init() {
		father = new int[n + 1];
		ballNumber = new int[n + 1];
		changeTime = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			father[i] = i;
			ballNumber[i] = 1;
			changeTime[i] = 0;
		}
	}

	static int find(int x) {
		if (x == father[x])
			return father[x];
		int temp = father[x];
		father[x] = find(father[x]);
		changeTime[x] += changeTime[temp];
		return father[x];
	}

	static void union(int a, int b) {
		ra = find(a);
		rb = find(b);
		if (ra == rb)
			return;
		father[ra] = rb;
		ballNumber[rb] += ballNumber[ra];
		changeTime[ra] = 1;
	}

}
