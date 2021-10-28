#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int my_Rand(){
  int file = open("/dev/random", O_RDONLY);
  unsigned int rand;
  int randNum = read(file, &rand, sizeof(rand));
  return rand;
}

int main(){
  int array[10];
  int i;
  int result[10];
  printf("%s\n", "Random Numbers:");
  for (i = 0; i < 10; i++){
    array[i] = my_Rand();
    printf("%s %i: ", "Random Int", i);
    printf("%u\n", array[i]);
  }
  int p = open("file.txt", O_RDWR | O_CREAT, 0644);
  int written = write(p, array, sizeof(array));
  p = open("file.txt", O_RDWR | O_CREAT, 0);
  int readden = read(p, result, sizeof(result));
  printf("\n%s\n", "Verification of Numbers: ");
  for (i = 0; i < 10; i++){
    printf("%u\n", result[i]);
  }
  return 0;
}
