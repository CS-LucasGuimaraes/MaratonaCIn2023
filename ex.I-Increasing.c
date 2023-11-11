#include <stdio.h>

int main(){
    int a, b, c;
    char lixo;
    int flag = 0;
    scanf("%i", &a);

    for (size_t x = 0; x < a; x++)
    {
        scanf("%i ", &b);

        char list[b];
        for (size_t y = 0; y < b; y++)
        {
            scanf("%d", &c);
            list[y] = c;
            for (size_t z = 0; z < y; z++)
            {
                if (list[z] == list[y])
                {
                    if (flag != 1)
                    {
                        printf("NO\n");
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag != 1) printf("YES\n");
        flag = 0;
    }
}