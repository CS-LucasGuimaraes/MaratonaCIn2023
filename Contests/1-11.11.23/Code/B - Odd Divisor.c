#include <stdio.h> 

int main(){
    long int test_cases, n;
    int flag = 0;
    scanf("%i", &test_cases);

    for (long int i = 0; i < test_cases; i++)
    {
        flag = 0;
        scanf("%i", &n);

        if (n % 2 == 1)
        {
            printf("YES\n");
            continue;
        }

        n = n/2;

        for (long int c = 3; c < (n+2)/2; c = c+2)
        {
            if (n%c == 0)
            {
                printf("YES\n");
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            printf("NO\n");
        }
    }
}