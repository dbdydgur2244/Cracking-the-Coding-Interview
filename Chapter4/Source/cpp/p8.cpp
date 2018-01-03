#include <cstdio>
#include <algorithm>

inline int CLIMB(int child) {
    return  (child - 1) / 2;
}

int get_depth(int x) {
    int dep = 0;
    while (x) {
        x = CLIMB(x); // climb
        ++dep;
    }
    return dep;
}

int main(void) {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    for (int q_i = 0; q_i < q; ++q_i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;

        int cnt = 0;
        int x_dep = get_depth(x),
            y_dep = get_depth(y);

        if (x_dep < y_dep) {
            int temp = y_dep - x_dep;

            for (int c_i = 0; c_i < temp; ++c_i) {
                y = CLIMB(y);
                ++cnt;
            }
        }
        else if (x_dep > y_dep) {
            int temp = x_dep - y_dep;

            for (int c_i = 0; c_i < temp; ++c_i) {
                x = CLIMB(x);
                ++cnt;
            }
        }

        while (x != y) {
            x = CLIMB(x);
            y = CLIMB(y);
            cnt += 2;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
