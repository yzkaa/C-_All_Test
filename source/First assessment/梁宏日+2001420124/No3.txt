#include<stdio.h>
float matrix[3][3];
void insert(int H, int L, float sz) {
  matrix[H][L] = sz;
};
int check() {
  int i;
  for (i = 0; i < 9; i++) {
    float dq = matrix[i / 3][i % 3];
    if ((dq-3.14)<1.0e-6 && (dq-3.14)>-1.0e-6) {
      printf("行%d,列%d\n",i/3+1,i%3+1);
    }
  }
};
int main() {
  int i;
  float sr;
  printf("请输入九个数");
  for (i = 0; i < 9; i++) {
    scanf("%f", &sr);
    insert(i/3,i%3, sr);
  }
  check();
  
    // out
    for (i = 0; i < 9; i++) {
    printf("%4.2f\t", matrix[i/3][i%3]);
    if (i==2||i==5||i==8) {
      printf("\n");
    };
  }
  return 0;
}
  // %shu /heng
