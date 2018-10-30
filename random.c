#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int random_num() {
  int * num = malloc(4);
  int random_dest = open("/dev/random",O_RDONLY);
  if (random_dest < 0) {
    printf("Did not open file correctly.");
  }
  read(random_dest,num,4);
  int output = *num;
  free(num);
  return output;
}


int main() {
  printf("Generating random numbers:\n");
  int rand_list[10];
  int i;
  for (i=0; i<10; i++){
    rand_list[i] = random_num();
    printf("random %d: %d\n",i,rand_list[i]);
  }

  printf("\nWriting numbers to file...\n");

  int output_dest = open("output.txt",
                         O_RDWR | O_TRUNC | O_APPEND,
                         S_IRUSR | S_IWUSR );

  if (output_dest < 0){
    printf("Did not read output.txt correctly");
    return 1;
  }

  if (write(output_dest,rand_list,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+1,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+2,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+3,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+4,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+5,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+6,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+7,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+8,4) != 4) {printf("Could not write properly"); return 1;}
  if (write(output_dest,rand_list+9,4) != 4) {printf("Could not write properly"); return 1;}

  close(output_dest);

  printf("\nReading numbers from file...\n");

  int new_output_dest = open("output.txt",O_RDONLY);

  int read_list[10];

  if (read(new_output_dest,read_list,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+1,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+2,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+3,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+4,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+5,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+6,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+7,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+8,4) < 0) {printf("Could not read properly"); return 1;}
  if (read(new_output_dest,read_list+9,4) < 0) {printf("Could not read properly"); return 1;}

  printf("Verification that the written values are the same:\n");

  for(i=0; i<10;i++){
    printf("random %d: %d\n",i,read_list[i]);
  }

  return 0;
}
