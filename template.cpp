#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

#define DEBUG_LOGS

#ifdef DEBUG_LOGS
#define IF_DEBUG if(true)
#else
#define IF_DEBUG if(false)
#endif

void run_test_case(int test_num) {
    IF_DEBUG printf("Running test case: %d\n", test_num);

    char buffer[10000];
    // Read line.
    gets(buffer);
    string first_line(buffer);
    printf("Read line of length %d: %s\n", first_line.length(), first_line.c_str());

    // Read two numbers.
    int a, b;
    scanf("%d%d\n", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);

    // Read line again.
    gets(buffer);
    string last_line(buffer);
    printf("Read line of length %d: %s\n", last_line.length(), last_line.c_str());

    // Empty line.
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc == 3) {
        printf("Redirecting stdin to: %s\n", argv[1]);
        freopen(argv[1], "r", stdin);
        printf("Redirecting stdout to: %s\n", argv[2]);
        freopen(argv[2], "w", stdout);
    } else if (argc != 1) {
        perror("Usage: template    OR    template <input_file> <output_file>");
        return 1;
    }

    int num_test_cases;
    scanf("%d\n", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++) {
        run_test_case(i);
    }
    return 0;
}