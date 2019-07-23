#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int testcases;
    scanf("%d", &testcases);
    for(int j = 1; j <= testcases; j++)
    {
        long int size;
        scanf("%ld", &size);
        char* path = (char *)malloc((2*size - 2 + 1) * sizeof(char) );
        scanf("%s", path);
        char* path2 = (char*)malloc((2*size - 2 + 1) * sizeof(char) );
        for(long int i = 0; i < 2*size - 2; i++)
        {
            if(path[i] == 'E')
                path2[i] = 'S';
            else 
                path2[i] = 'E';
        }
        printf("Case #%d: %s\n", j, path2);

    }
    return 0;
}