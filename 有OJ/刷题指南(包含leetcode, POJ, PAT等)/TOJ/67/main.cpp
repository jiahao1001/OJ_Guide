#include <cstdio>

int actual;
void initialize()
{
    actual = 10;
}

int throw_egg(int x)
{
    return x <= actual ? 1 : 0;
}

void answer(int x)
{
    printf("%d %d %s\n", x, actual, x == actual ? "AC" : "WA");
}

int main()
{
    initialize();

    long long int left = 1, right = (1LL << 31) - 1;

    while (right - left > 1) {
        long long int mid = (left + right) / 2;
        if (throw_egg(mid) == 0)
            right = mid;
        else
            left = mid;
    }

    if (left == right - 1)
        if (throw_egg(left) == 1)
            answer(left);
        else
            answer(right);
    else
        answer(left);

    return 0;
}
