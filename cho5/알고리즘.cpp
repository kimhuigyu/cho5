#include <stdio.h>
#define VMAX 21

typedef struct {
    char name[20];
    int height;
    double vision;
}PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += dat[i].height;
    return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
    int i;
    for (i = 0; i < VMAX; i++)
        dist[i] = 0;
    for (i = 0; i < n; i++)
        if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
            dist[(int)(dat[i].vision * 10)]++;

}

int main(void)
{
    int i;
    PhysCheck x[] = {
       {"�����",184,0.5},
       {"������",170,0.7},
       {"������",180,0.8},
       {"������",188,0.3},
       {"����ȣ",190,0.1},
       {"����",175,1.0},
       {"���ֿ�",178,1.5},
       {"���ؼ�",169,1.0},
       {"��âȯ",177,0.4},
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int vdist[VMAX];
    puts("      ��ü �˻�ǥ    ");
    puts(" �̸�     Ű    �÷�");
    puts("_________________");
    for (i = 0; i < nx; i++)
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
    printf("\n ��� Ű : %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);
    printf("\n �÷� ���� \n");
    for (i = 0; i < VMAX; i++)
        printf("%3.1f ~ : %2d��\n", i / 10.0, vdist[i]);

    return 0;

}