#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        stack<int> s;

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
                    printf("%d\n", s.top());
                    s.pop();
                }
            }
        }
    }

    return 0;
}
