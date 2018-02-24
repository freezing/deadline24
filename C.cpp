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

const int MAX_BOARD_HEIGHT = 100;
const int MAX_BOARD_WIDTH = 100;

char board[MAX_BOARD_HEIGHT][MAX_BOARD_WIDTH];

map<int, set<string>> dict_cache;

set<string>& read_dict(int dict_id) {
    if (dict_cache.find(dict_id) == dict_cache.end()) {
        stringstream ss;
        ss << "C_Crossword/dict" << dict_id << ".in";
        string filename = ss.str();

        ifstream infile(filename.c_str());
        IF_DEBUG printf("Dictionary %d not-cached. Rading from filename: %s\n", dict_id, filename.c_str());

        set<string> dict;
        string line;
        while (getline(infile, line)) {
            dict.insert(line);
        }
        dict_cache[dict_id] = dict;
    }
    return dict_cache[dict_id];
}

void run_test_case(int test_num) {
    IF_DEBUG printf("Running test case: %d\n", test_num);
    int dict_id;
    scanf("%d", &dict_id);

    IF_DEBUG printf("DictId: %d\n", dict_id);

    int board_height, board_width;
    scanf("%d%d", &board_width, &board_height);

    IF_DEBUG printf("Board size: (height=%d, width=%d)\n", board_height, board_width);

    for (int row = 0; row < board_height; row++) {
        scanf("%s", board[row]);
        IF_DEBUG printf("Board row: %s\n", board[row]);
    }

    int num_letters;
    scanf("%d", &num_letters);

    IF_DEBUG printf("Num letters: %d\n", num_letters);

    map<char, int> letters;

    for (int i = 0; i < num_letters; i++) {
        int letter;
        int letter_score;
        scanf("%s%d", &letter, &letter_score);
        letters[letter] = letter_score;
        IF_DEBUG printf("%c %d ", letter, letters[letter]);
    }
    IF_DEBUG printf("\n");

    int letter_buffer, total_num_letters;
    scanf("%d%d", &letter_buffer, &total_num_letters);

    char all_letters[total_num_letters + 10];
    scanf("%s", all_letters);
    IF_DEBUG printf("All letters: %s\n", all_letters);

    set<string>& dict = read_dict(dict_id);
    IF_DEBUG printf("Dictionary size: %d\n", dict.size());
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

    clock_t begin_time = clock();

    int num_test_cases;
    scanf("%d\n", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++) {
        run_test_case(i);
    }

    clock_t end_time = clock();
    double elapsed_secs = double(end_time - begin_time) / CLOCKS_PER_SEC;
    IF_DEBUG printf("Total execution time: %.3lf (s)\n", elapsed_secs);
    return 0;
}