//#define LOCAL

#pragma warning(disable:4996)

#include <cstdio>
#include <cctype>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    char cur;
    bool last_is_alpha = false;
    bool cur_is_alpha = false;
    int words = 0;
    while (EOF != scanf("%c", &cur)) {
        if ('\n' == cur) {
            printf("%d\n", words);
            words = 0;
            last_is_alpha = false;
        }
        else {
            cur_is_alpha = isalpha(cur) ? true : false;
            if (last_is_alpha && !cur_is_alpha)
                words++;
            last_is_alpha = cur_is_alpha;
        }
    }

    if (0 != words)
        printf("%d\n", words);

    return 0;
}
