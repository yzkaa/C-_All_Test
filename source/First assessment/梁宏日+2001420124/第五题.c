#include <stdio.h>

int sz[] = { 9, 8, 7, 5, 4, 3, 2, 0 };
main() {
  int bhls = 0;                 // 不合理数
  int dqzd = sz[0];             // 当前最大
  int k = sizeof(sz) / sizeof(sz[0]);
  for (int r = 1; r < k; r++) {
    if (sz[r] > dqzd)
      dqzd = sz[r];
    if (dqzd > sz[r])
      bhls++;
  };
//  printf("    %d\n", bhls);
  if (bhls > 1) {
    printf("\tfalse");
  } else {
    printf("\ttrue");
  }
};

//题目还是有点不理解，这是我觉得最合适的答案了。