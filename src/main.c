#include <stdio.h>
#include <stdlib.h>

void resizeArray(int **arr, size_t *size, size_t *capacity, int value) {
  if (*size == *capacity) {
    *capacity *= 2;

    int *temp = realloc(*arr, *capacity * sizeof(int));
    if (temp == NULL) {
      exit(1);
    }
    *arr = temp;
  }
  (*arr)[*(size)++] = value;
}

int main() {
  size_t size = 3;
  size_t capacity = 3;
  int *pArray = malloc(capacity * sizeof(int));

  if (pArray == NULL) {
    printf("Memory Allocation Failed :(\n");
    return 1;
  }

  pArray[0] = 0;
  pArray[1] = 10;
  pArray[2] = 20;

  for (int i = 0; i < capacity; i++) {
    printf("%d\n", pArray[i]);
  }

  resizeArray(&pArray, &size, &capacity, 30);
  resizeArray(&pArray, &size, &capacity, 40);
  resizeArray(&pArray, &size, &capacity, 50);
  resizeArray(&pArray, &size, &capacity, 60);

  for (int i = 0; i < capacity; i++) {
    printf("%d\n", pArray[i]);
  }

  free(pArray);
  pArray = NULL;
  return 0;
}
