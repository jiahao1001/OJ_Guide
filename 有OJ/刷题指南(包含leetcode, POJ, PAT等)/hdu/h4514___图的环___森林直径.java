import java.io.*;
import java.util.*;

public class h4514___图的环___森林直径 {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(
            new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static int N = 100100, M = 1000100, toll;
    static int father[] = new int[N], rank[] = new int[N];
    static int n, m;

    static int head[] = new int[N];
    static edge edge[] = new edge[M];

    static void init() {
        for (int i = 1; i <= n; i++)
            father[i] = i;
        Arrays.fill(rank, 1);
        toll = 0;
        Arrays.fill(head, -1);
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

    public static void main(String[] args) throws IOException {
        while (in.nextToken() != in.TT_EOF) {
            n = (int) in.nval;
            m = nextInt();
            int ra, rb, u, v, val;
            boolean mark = false;
            int i;
            init();
            for (i = 1; i <= m; i++) {
                u = nextInt();
                v = nextInt();
                val = nextInt();
                ra = find(u);
                rb = find(v);
                if (ra == rb) {
                    mark = true;
                    break;
                }
                union(ra, rb);
                addEdge(u, v, val);
            }
            for (i = i + 1; i <= m; i++) {
                u = nextInt();
                v = nextInt();
                val = nextInt();
            }

            if (mark) {
                out.println("YES");
            } else {
                Arrays.fill(record, 0);
                int ans = 0;
                for (i = 1; i <= n; i++) {
                    if (record[i] == 1)
                        continue;
                    Arrays.fill(visit, 0);
                    max = 0;
                    dfs(i, 0);

                    Arrays.fill(visit, 0);
                    max = 0;
                    dfs(vert, 0);
                    ans = Math.max(ans, max);
                }
                out.println(ans);
            }
        }

        out.flush();
        out.close();
    }

    static int visit[] = new int[N];
    static int max = 0, vert;
    static int record[] = new int[N];

    static void dfs(int u, int dis) {
        visit[u] = 1;
        record[u] = 1;
        if (max < dis) {
            vert = u;
            max = dis;
        }
        int v;
        for (int e = head[u]; e != -1; e = edge[e].next) {
            v = edge[e].v;
            if (visit[v] == 0) {
                dfs(v, dis + edge[e].val);
            }
        }
    }

    static void addEdge(int u, int v, int val) {
        edge[toll] = new edge(v, val);
        edge[toll].next = head[u];
        head[u] = toll++;
        edge[toll] = new edge(u, val);
        edge[toll].next = head[v];
        head[v] = toll++;
    }

    static class edge {
        int v, val, next;

        edge(int v, int val) {
            this.v = v;
            this.val = val;
        }
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

    static double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }
}