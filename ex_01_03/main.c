#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000000

static int g_room[MAX_SIZE / 32] = {0, };

void set(int n)
{
    g_room[n >> 5] |= 1 << (n & 0x1F);
}

int check(int n)
{
    return g_room[n >> 5] & (1 << (n & 0x1F));
}

int main()
{
    int i;
    FILE * fp = 0;
    
    fp = fopen("data.txt", "r");
    if( fp )
    {
        while( !feof(fp) )
        {
            char line[8] = {0, };
            fread(line, 8, 1, fp);
            
            set(atoi(line));
        }
        
        fclose(fp);
    }
    
    printf("sorting has been completed.\n");
    
    fp = fopen("result.txt", "w+" );
    if( fp )
    {
        for( i = 0; i < MAX_SIZE; i++ )
        {
            if( check(i) )
            {
                fprintf(fp, "%08d\n", i);
            }
        }
        
        fclose(fp);
    }
    
    printf("done.\n");
    
    return 0;
}

