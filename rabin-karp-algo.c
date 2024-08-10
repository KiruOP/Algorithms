#include <stdio.h>
#include <string.h>
void searchRabinKarp(char *pattern, char *text, int q)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int I, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for(I = 0; I < M - 1; I++)
    {
        h = (h * 256) % q;
    }
    int i;
    for(i = 0; i < M; i++)
    {
        p = (256 * p + pattern[i]) % q;
        t = (256 * t + text[i]) % q;
    }
    for(I = 0; I <= N - M; i++)
    {
        if(p == t)
        {
            for(j = 0; j < M; j++)
            {
                if(text[I + j] != pattern[j])
                    break;
            }
            if(j == M)
            {
                printf("Pattern found at index %d\n", i);
            }
        }
        if(I < N - M)
        {
            t = (256 * (t - text[i] * h) + text[I + M]) % q;
            if(t < 0)
            {
                t = (t + q);
            }
        }
    }
}
int main()
{
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";
    int q = 101;
    searchRabinKarp(pattern, text, q);
    return 0;
}