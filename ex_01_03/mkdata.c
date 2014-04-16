#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000000

int main()
{
    int i;
    int * p = (int *)malloc(MAX_SIZE * sizeof(int));
    
    srand((unsigned int)time(0));
    
    for( i = 0; i < MAX_SIZE; i++ )
    {
        p[i] = i;
    }
    
    for( i = 0; i < MAX_SIZE; i++ )
    {
        int n = rand() % MAX_SIZE;
        int temp = p[n];
        p[n] = p[i];
        p[i] = temp;
    }
    
    for( i = 0; i < MAX_SIZE; i++ )
    {
        printf("%07d\n", p[i]);
    }
    
    free(p);
    return 0;
}
