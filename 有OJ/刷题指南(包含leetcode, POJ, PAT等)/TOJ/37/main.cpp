#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        queue<int> s;

        while(n--) {
            int cmd;
            scanf("%d", &cmd);

            if(cmd == 1) {
                int num;
                scanf("%d", &num);

                s.push(num);
            } else{
                if(s.empty())
                    printf("empty!\n");
                else {
                    printf("%d\n", s.front());
                    s.pop();
                }
            }
        }
    }

    return 0;
}
