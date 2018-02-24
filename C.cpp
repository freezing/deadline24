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

set<string> read_dict(int numDict) {
    stringstream ss;
    ss << "C_Crossword/" << numDict << ".in";
    string filename = ss.str();
    ifstream infile(filename.c_str());

    set<string> dict;
    string line;
    while (getline(infile, line)) {
        dict.insert(line);
    }
    return dict;
}

void run_test_case(int test_num) {
    IF_DEBUG printf("Running test case: %d\n", test_num);
}

int main(int argc, char** argv) {
    if (argc == 3) {
        printf("Redirecting stdin to: %s\n", argv[1]);
        freopen(argv[1], "r", stdin);
        printf("Redirecting stdout to: %s\n", argv[2]);
        freopen(argv[2], "w", stdout);
    } else if (argc != 1) {
        perror("Usage: C    OR    C <input_file> <output_file>");
        return 1;
    }

    int num_test_cases;
    scanf("%d\n", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++) {
        run_test_case(i);
    }
    return 0;
}