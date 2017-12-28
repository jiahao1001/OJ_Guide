import java.util.Scanner;


public class h1061 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int turn = scan.nextInt();
		int n, m;
		int r;
		for (int i = 0; i < turn; i++) {
			n = scan.nextInt();
			m = n;
			r = 1;
			while (m > 0) {
				if ((m & 1) == 1) {
					r *= (n % 10);
					r %= 10;
				}
				// n = n*n;
				n = (n % 10) * (n % 10);
				m >>= 1;
			}
			System.out.println(r);
		}
	}

}