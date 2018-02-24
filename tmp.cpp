//
// Created by Nikola Stojiljkovic on 2/24/18.
//

#include <map>
#include <set>

using namespace std;

void print_set(const set<int>& s) {
    for (auto v : s) {
        printf("%d ", v);
    }
    printf("\n");
}

int main() {
    map<int, set<int>> m;

    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);

    set<int> s2;
    s2.insert(100);
    s2.insert(101);
    s2.insert(102);

    m[1] = s1;
    m[2] = s2;

    set<int>& s = m[1];

    m[1].erase(1);

    print_set(s);
    print_set(m[2]);

    return 0;
}