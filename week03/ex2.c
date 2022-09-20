#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 
struct Point{
  float x;
  float y;
};

float squareOfNumber(float num){
    return (num * num);
}

float distance(struct Point A, struct Point B){
  return sqrt( squareOfNumber(A.x-B.x) + squareOfNumber(A.y-B.y));
}

float area(struct Point A, struct Point B, struct Point C){
    
  float result = fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y) / 2; // cross product of the two vectors
  return result;
}

int main(void){
    
    struct Point A = {3.4, 5.1};
    struct Point B = {2.1, 3.7};
    
    float f = distance(A, B);
    printf("A -- B distance is %f\n", f);
    
    struct Point C = {11.3, 7.2};
    
    float a = area(A, B, C);
    printf("Area of triangle ABC is %f\n", a);
    
    return EXIT_SUCCESS;
}
