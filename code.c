/* Name: Jaskirat kaur */
/* Student ID: n01612805 */

#include <stdio.h>

struct Account {
    unsigned int account_number;
    char account_type;
    char *last_name;
    char *first_name;
    float balance;
    char reserved[6];
};

int main() {
    char apple;
    short banana;
    int cherry;
    long date;
    float elderberry;
    double fig;

    int *grape;
    long *honeydew;
    float *kiwi;
    double *lemon;

    struct Account mango;
    struct Account *nectarine;

    printf("char: %zu\n", sizeof(apple));
    printf("short: %zu\n", sizeof(banana));
    printf("int: %zu\n", sizeof(cherry));
    printf("long: %zu\n", sizeof(date));
    printf("float: %zu\n", sizeof(elderberry));
    printf("double: %zu\n", sizeof(fig));
    printf("A pointer to int: %zu\n", sizeof(grape));
    printf("A pointer to long: %zu\n", sizeof(honeydew));
    printf("A pointer to float: %zu\n", sizeof(kiwi));
    printf("A pointer to double: %zu\n", sizeof(lemon));
    printf("struct Account defined above: %zu\n", sizeof(mango));
    printf("A pointer to the struct Account: %zu\n", sizeof(nectarine));

    return 0;
}
