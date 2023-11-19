#define M 50
#include "stdio.h"
int max[M][M], allocation[M][M], need[M][M], available[M];    /*定义全局变量 */
int i, j, n, m, r, t;
int main()
{
    void check();
    void print();
    int p, q;
    int req[M], allocation1[M][M], need1[M][M], available1[M];
    printf("请输入进程总数:");
    scanf("%d", &n);    /*输入进程总数 */
    printf("请输入资源种类总数:");
    scanf("%d", &m);    /*输入资源种类总数 */
    printf("输入最大矩阵:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%2d", &max[i][j]);
        }        /*输入最大矩阵 */
    printf("输入已分配资源数:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);    /*输入已分配资源数 */
    printf("还需要的资源数:\n");
    for (i = 0; i < n; i++){ 
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%2d", need[i][j]);
        }        /*输出还需要的资源数 */
        printf("\n"); 
    } 
    printf("\n输入可用资源数:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);    /*输入可用资源数 */

    check();        /*检测已知的状态是否安全 */
    if (r == 1) {        /*如果已知的状态安全则执行以下代码 */
        do {
            t = 1;
            p = 0, q = 0;
            printf("\n输入请求资源的进程号: ");
            scanf("%d", &i);    /*输入请求资源的进程号 */
            printf("输入该进程所需的资源数:");
            for (j = 0; j < m; j++)
                scanf("%d", &req[j]);    /*输入该进程所需的资源数 */

            for (j = 0; j < m; j++)
                if (req[j] > need[i][j])
                    p = 1;    /*判断请求是否超过最大资源数 */
            if (p)
                printf("请求的资源超出了所需的最大数量!");
            else {
                for (j = 0; j < m; j++)
                    if (req[j] > available[j])
                        q = 1;    /*判断请求是否超过可用资源数 */
                if (q)
                    printf("没有足够的可用资源！");
                else {
                    for (j = 0; j < m; j++) {    /*请求满足条件 */
                        available1[j] = available[j];    /* 保存原已分配的资源数，需要的资源数，和可用的资源数 */
                        allocation1[i][j] = allocation[i][j];
                        need1[i][j] = need[i][j];

                        available[j] = available[j] - req[j];    /* 系统尝试把资源分配给请求的进程 */
                        allocation[i][j] = allocation[i][j] + req[j];
                        need[i][j] = need[i][j] - req[j];
                    }
                    print();    /*输出可用资源数 */
                    check();    /*进行安全检测 */
                    if (r == 0) {    /*分配后状态不安全 */
                        for (j = 0; j < m; j++) {
                            available[j] = available1[j];    /* 还原分配前的已分配的资 源数，仍需要的资源数和可用的资源数 */
                            allocation[i][j] = allocation1[i][j];
                            need[i][j] = need1[i][j];
                        }
                        printf("这是不安全的并且返回:\n");
                        print();
                    }
                }
            }

            printf("\n是否继续进行资源分配 y(1) or n(0):");    /*判断是否继续进行资源分配 */
            scanf("%d", &t);
        } while (t == 1);
    }
    return 0;
}

void check()
{                /*检测函数 */
    int k, f, v = 0;
    int work[M], a[M];
    char finish[M];
    r = 1;
    for (i = 0; i < n; i++)
        finish[i] = 'F';    /*初始化各进程均没得到足够资源并完成 */
    for (j = 0; j < m; j++)
        work[j] = available[j];    /*用work[j]表示可提供进程继续运行的各类资源数 */
    k = n;
    do {
        for (i = 0; i < n; i++) {
            if (finish[i] == 'F') {
                f = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        f = 0;
                if (f == 1) {    /*找到还没完成的且需求数小于可提供进程继续运行的 */
                    finish[i] = 'T';    /*资源数的进程 */
                    a[v++] = i;    /*记录安全序列 */
                    for (j = 0; j < m; j++)
                        work[j] = work[j] + allocation[i][j];    /*释放该进程已分配的资源 */

                }
            }
        }
        k--;
    } while (k > 0);
    f = 1;
    for (i = 0; i < n; i++) {    /*判断是否所有的进程都完成 */
        if (finish[i] == 'F') {
            f = 0;
            break;
        }
    }
    if (f == 0) {        /*若有进程没完成，则为不安全状态 */
        printf("这是不安全的 . \n");
        r = 0;
    } else {        /* 否则为安全状态 */

        printf("这是安全的 .");
        printf("安全序列为:");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);    /*输出安全序列 */

        printf("\n");
        for (i = 0; i < n; i++) {
            printf("%2d", i);
            printf("     ");
            for (j = 0; j < m; j++)
                printf("%2d", allocation[i][j]);
            printf("     ");
            for (j = 0; j < m; j++)
                printf("%2d", need[i][j]);
            printf("\n");
        }

    }
}

void print()
{                /*输出函数 */
    int process[M];
    printf("可用资源: \n");
    for (j = 0; j < m; j++)
        printf("%2d ", available[j]);
    printf("\n");
}

