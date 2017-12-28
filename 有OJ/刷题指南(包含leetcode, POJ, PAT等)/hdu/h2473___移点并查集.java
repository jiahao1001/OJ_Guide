import java.util.Scanner;


public class h2473___移点并查集 {
	static int[] father, hash, number;
	static int n, m, index;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		char ch;
		int a, b, case_num = 0, num;
		while (scan.hasNext()) {
			case_num++;
			index = n = scan.nextInt();
			m = scan.nextInt();
			if (n == 0 && m == 0)
				break;

			init();

			for (int i = 1; i <= m; i++) {
				ch = scan.next().charAt(0);
				if (ch == 'M') {
					a = scan.nextInt();
					b = scan.nextInt();
					union(hash[a], hash[b]);
				} else {
					a = scan.nextInt();
					number[find(hash[a])]--;
					hash[a] = index++;
				}
			}
			num = 0;
			for (int i = 0; i < index; i++)
				if (find(i) == i && number[i] > 0)
					num++;
			System.out.println("Case #" + case_num + ": " + num);
		}
	}

	static void init() {
		father = new int[n + m];
		number = new int[n + m];
		hash = new int[n + m];
		for (int i = 0; i < n + m; i++) {
			number[i] = 1;
			father[i] = hash[i] = i;
		}
	}

	static int find(int x) {
		if (father[x] == x)
			return x;
		father[x] = find(father[x]);
		return father[x];
	}

	static void union(int a, int b) {
		int ra = find(a);
		int rb = find(b);
		if (ra == rb)
			return;
		father[ra] = rb;
		number[rb] += number[ra];
	}
}
