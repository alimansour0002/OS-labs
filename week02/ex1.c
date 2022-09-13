#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(){
  double D = DBL_MAX;
  int I = INT_MAX;
  float F = FLT_MAX;
  unsigned short int USI = USHRT_MAX;
  signed long int SLI = LONG_MAX;
  printf("maximum value of an integer: %i the size:%lu bytes\n", I,sizeof(I));
  printf("maximum value of an unsigned short integer: %hu the size: %lu bytes\n", USI, sizeof(USI));
  printf("maximum value of a signed long integer: %li the size: %lu bytes\n", SLI, sizeof(SLI));
  printf("maximum value of a float is : %f the size: %lu bytes\n", F, sizeof(F));
  printf("maximum value of a double is : %f the size: %lu bytes\n", D, sizeof(D));
  
  return 0;
}