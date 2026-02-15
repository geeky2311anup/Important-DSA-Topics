#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

char buffer[100001];

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  while (cases--) {
    assert(scanf("%s", buffer) == 1);
    int n = strlen(buffer);
    bool is_palindrome = true;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      if (buffer[i] != buffer[j]) {
        is_palindrome = false;
        break;
      }
    }
    puts(is_palindrome ? "1" : "2");
  }
  return 0;
}
