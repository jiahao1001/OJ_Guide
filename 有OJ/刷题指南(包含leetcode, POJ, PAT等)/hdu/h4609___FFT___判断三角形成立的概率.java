import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class h4609___FFT___判断三角形成立的概率 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StreamTokenizer in = new StreamTokenizer(br);
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	static class complex {
		double real, image;

		complex(double a, double b) {
			real = a;
			image = b;
		}

		void multiply(complex o) {
			double x = real * o.real - image * o.image;
			double y = real * o.image + image * o.real;
			real = x;
			image = y;
		}

	}

	static void swap(complex a, complex b) {
		double x = a.real;
		a.real = b.real;
		b.real = x;
		double y = a.image;
		a.image = b.image;
		b.image = y;
	}

	static void rev(complex[] y, int len) {
		int i, j, k;
		for (i = 1, j = len / 2; i < len - 1; i++) {
			if (i < j)
				swap(y[i], y[j]);
			k = len / 2;
			while (j >= k) {
				j -= k;
				k /= 2;
			}
			if (j < k)
				j += k;
		}
	}

	static double PI = Math.PI;
	static complex u = new complex(0, 0), t = new complex(0, 0);

	static void fft(complex[] y, int len, int op) {
		int i, j, k, h;

		rev(y, len);
		double real, image;

		for (h = 2; h <= len; h <<= 1) { // 控制层数
			complex wn = new complex(Math.cos(op * 2 * PI / h), Math.sin(op * 2
					* PI / h));// 该层单位复根,h为层数
			for (j = 0; j < len; j += h) {// 控制起始下标
				complex w = new complex(1, 0); // 初始化螺旋因子
				for (k = j; k < j + h / 2; k++) { // 配对
					// u=y[k];
					u.real = y[k].real;
					u.image = y[k].image;
					// t = multiply(w, y[k + h / 2]);
					real = w.real * y[k + h / 2].real - w.image
							* y[k + h / 2].image;
					image = w.real * y[k + h / 2].image + w.image
							* y[k + h / 2].real;
					t.real = real;
					t.image = image;
					// y[k]=u+t;
					y[k].real = u.real + t.real;
					y[k].image = u.image + t.image;
					// y[k+h/2]=u-t;
					y[k + h / 2].real = u.real - t.real;
					y[k + h / 2].image = u.image - t.image;
					w.multiply(wn); // 更新螺旋因子
				}
			}
		}

		// 求解插值
		if (op == -1)
			for (i = 0; i < len; i++)
				y[i].real /= len;
	}

	static String stra, strb;
	static int len1, len2, len;
	static int N = 1 << 18;
	static long num[] = new long[N];
	static complex x1[] = new complex[N], x2[] = new complex[N];

	static void init() {
		for (int i = 0; i < N; i++) {
			x1[i] = new complex(0, 0);
			x2[i] = new complex(0, 0);
		}
	}

	static int n;
	static long sum[] = new long[N];

	public static void main(String[] args) throws IOException {
		init();
		int test = nextInt(), t;
		while (test-- > 0) {
			n = nextInt();
			int mark[] = new int[n];
			for (int i = 0; i < n; i++)
				mark[i] = nextInt();
			Arrays.sort(mark);
			len = 1;
			len1 = mark[n - 1] + 1;
			while (len < len1 * 2)
				len <<= 1;

			for (int i = 0; i < len; i++)
				x1[i].real = x1[i].image = 0;
			for (int i = 0; i < n; i++) {
				t = mark[i];
				x1[t].real++;
			}
			fft(x1, len, 1);

			for (int i = 0; i < len; i++)
				x1[i].multiply(x1[i]);
			fft(x1, len, -1);
			for (int i = 0; i < len; i++)
				// num[i] = (long) (x1[i].real + 0.5);
				num[i] = (long) (Math.round(x1[i].real));

			len = 2 * mark[n - 1];

			// 1,3(1),3(2),4
			// 1,1;3(1),3(1);3(2),3(2);4,4是不可取的
			// 所以要删去
			for (int i = 0; i < n; i++)
				num[mark[i] + mark[i]]--;
			// 由于是排列，1,4;4,1会算两次
			// 实际上是组合，所以要除以二
			for (int i = 0; i <= len; i++)
				num[i] >>= 1;
			Arrays.fill(sum, 0);
			sum[0] = 0;
			for (int i = 1; i <= len; i++)
				sum[i] = sum[i - 1] + num[i];

			long cnt = 0;
			for (int i = 0; i < n; i++) {
				cnt += sum[len] - sum[mark[i]];

				// 减掉一个取大，一个取小的
				// a0,a1..aj..ai..ak..an-1
				cnt -= (long) (n - 1 - i) * i;
				// 减掉一个取本身，另外一个取其它
				// a0..aj..ai..an-1
				cnt -= (n - 1);
				// 减掉大于它的取两个的组合
				// a0..ai..aj..ak..an-1
				cnt -= (long) (n - 1 - i) * (n - i - 2) / 2;
			}

			long total = (long) n * (n - 1) * (n - 2) / 6;

			out.printf("%.7f", 1.0 * cnt / total);
			out.println();
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