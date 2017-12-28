import java.util.Scanner;

public class h1003 {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int turn = cin.nextInt();
		int[] arr;
		int n, sum, begin, end;
		for (int tt = 1; tt <= turn; tt++) {
			n = cin.nextInt();
			arr = new int[n + 1];
			for (int i = 1; i <= n; i++)
				arr[i] = cin.nextInt();
			sum = arr[1];

			begin = 1;
			end = 1;
			for (int i = 1; i <= n; i++) {
				if (0 <= arr[i - 1]) {
					arr[i] += arr[i - 1];
					if (arr[i] > sum) {
						sum = arr[i];
						end = i;
					}
				} else {
					if (arr[i] > sum) {
						sum = arr[i];
						end = i;
					}
				}
			}

			for (int i = end - 1; i >= 1; i--)
				if (arr[i] < 0) {
					begin = i + 1;
					break;
				}

			// if (tt < turn) {
			// System.out.println("Case " + tt + ":\n" + sum + " " + begin
			// + " " + end + "\n");
			// } else
			// System.out.println("Case " + tt + ":\r\n" + sum + " " + begin +
			// " "
			// + end);

			System.out.println("Case " + tt + ":");
			System.out.println(sum + " " + begin + " " + end);
			if (tt < turn)
				System.out.println();
		}
	}
}
