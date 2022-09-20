#include <stdio.h>
#include <stdlib.h>

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b)
{
    int *x = b,*y = a;
    *x = *x + *y;
    return x;
}

void *addDouble(const void *a, const void *b)
{
    double *x = a,*y = b;
    *x = *x + *y;
    return x;
}

void *mulInt(const void *a, const void *b)
{
    int *x = a,*y = b;
    *x = (*x) * (*y);
    return x;
}

void *mulDouble(const void *a, const void *b)
{
    double *x = a,*y = b;
    *x = (*x) * (*y);
    return x;
}

void *meanInt(const void *a, const void *b)
{
    int *x = a,*y = b;
    *x = (*x) + (*y)/5;
    return x;
}

void *meanDouble(const void *a, const void *b)
{
   double *x = a,*y = b;
    *x = (*x) + (*y)/5;
    return x;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{

    void *output;

    if (size == sizeof(int))
    {
        int *pointer = base;
        int *init = initial_value;
        for (int i = 0; i < n; i++)
        {
            init = opr(init, pointer);
            pointer++;
        }
        return init;
    }
    else
    {
        double *pointer = base;
        int *init = initial_value;
        for (int i = 0; i < n; i++)
        {

            init = opr(init, pointer);
            pointer++;
        }
        return init;
    }
}
int main()
{

    int *ints = malloc(sizeof(int) * 5);
    double *doubles = malloc(sizeof(double) * 5);
    int *pointerint = ints;
    double *pointerdoubles = doubles;

    int *zeroint = malloc(sizeof(int));
    *zeroint = 0;
    double *zerodouble = malloc(sizeof(double));

    int *oneint = malloc(sizeof(int));
    *oneint = 1;
    double *onedouble = malloc(sizeof(double));
    *zerodouble = 0;
    *onedouble=1;

    for (int i = 0; i < 5; i++)
    {
        *pointerint = 1;
        pointerint++;
    }
    for (int i = 0; i < 5; i++)
    {
        *pointerdoubles = 1;
        pointerdoubles++;
    }
    // Addition

    int *result1a;
    result1a = aggregate(ints, sizeof(int), 5, zeroint, addInt);

     printf("%d\n", *result1a);
    
    double *result2a;
    result2a = aggregate(doubles, sizeof(double), 5, zerodouble, addDouble);
    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2a);

    // Multiplication

    int *result1m;

    result1m = aggregate(ints, sizeof(int), 5, oneint, mulInt);
    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1m);

    double *result2m;

    result2m = aggregate(doubles, sizeof(double), 5, onedouble, mulDouble);
    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2m);

    // Mean
    *zerodouble=0;
    *zeroint=0;
    int *result1mean;

    result1mean = aggregate(ints, sizeof(int) , 5, zeroint, meanInt);
    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1mean);

    double *result2mean;

    result2mean = aggregate(doubles, sizeof(double) , 5, zerodouble, meanDouble);
    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2mean);

    // free the pointers
    //<WRITE YOUR CODE HERE>;
    free(zerodouble);
    free(zeroint);
    free(onedouble);
    free(oneint);
    free(ints);
    free(doubles);
    free(pointerdoubles);
    free(pointerint);
    return EXIT_SUCCESS;
}