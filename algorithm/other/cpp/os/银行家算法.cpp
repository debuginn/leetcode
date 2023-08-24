#define M 50
#include "stdio.h"
int max[M][M], allocation[M][M], need[M][M], available[M];    /*����ȫ�ֱ��� */
int i, j, n, m, r, t;
int main()
{
    void check();
    void print();
    int p, q;
    int req[M], allocation1[M][M], need1[M][M], available1[M];
    printf("�������������:");
    scanf("%d", &n);    /*����������� */
    printf("��������Դ��������:");
    scanf("%d", &m);    /*������Դ�������� */
    printf("����������:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%2d", &max[i][j]);
        }        /*���������� */
    printf("�����ѷ�����Դ��:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);    /*�����ѷ�����Դ�� */
    printf("����Ҫ����Դ��:\n");
    for (i = 0; i < n; i++){ 
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%2d", need[i][j]);
        }        /*�������Ҫ����Դ�� */
        printf("\n"); 
    } 
    printf("\n���������Դ��:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);    /*���������Դ�� */

    check();        /*�����֪��״̬�Ƿ�ȫ */
    if (r == 1) {        /*�����֪��״̬��ȫ��ִ�����´��� */
        do {
            t = 1;
            p = 0, q = 0;
            printf("\n����������Դ�Ľ��̺�: ");
            scanf("%d", &i);    /*����������Դ�Ľ��̺� */
            printf("����ý����������Դ��:");
            for (j = 0; j < m; j++)
                scanf("%d", &req[j]);    /*����ý����������Դ�� */

            for (j = 0; j < m; j++)
                if (req[j] > need[i][j])
                    p = 1;    /*�ж������Ƿ񳬹������Դ�� */
            if (p)
                printf("�������Դ������������������!");
            else {
                for (j = 0; j < m; j++)
                    if (req[j] > available[j])
                        q = 1;    /*�ж������Ƿ񳬹�������Դ�� */
                if (q)
                    printf("û���㹻�Ŀ�����Դ��");
                else {
                    for (j = 0; j < m; j++) {    /*������������ */
                        available1[j] = available[j];    /* ����ԭ�ѷ������Դ������Ҫ����Դ�����Ϳ��õ���Դ�� */
                        allocation1[i][j] = allocation[i][j];
                        need1[i][j] = need[i][j];

                        available[j] = available[j] - req[j];    /* ϵͳ���԰���Դ���������Ľ��� */
                        allocation[i][j] = allocation[i][j] + req[j];
                        need[i][j] = need[i][j] - req[j];
                    }
                    print();    /*���������Դ�� */
                    check();    /*���а�ȫ��� */
                    if (r == 0) {    /*�����״̬����ȫ */
                        for (j = 0; j < m; j++) {
                            available[j] = available1[j];    /* ��ԭ����ǰ���ѷ������ Դ��������Ҫ����Դ���Ϳ��õ���Դ�� */
                            allocation[i][j] = allocation1[i][j];
                            need[i][j] = need1[i][j];
                        }
                        printf("���ǲ���ȫ�Ĳ��ҷ���:\n");
                        print();
                    }
                }
            }

            printf("\n�Ƿ����������Դ���� y(1) or n(0):");    /*�ж��Ƿ����������Դ���� */
            scanf("%d", &t);
        } while (t == 1);
    }
    return 0;
}

void check()
{                /*��⺯�� */
    int k, f, v = 0;
    int work[M], a[M];
    char finish[M];
    r = 1;
    for (i = 0; i < n; i++)
        finish[i] = 'F';    /*��ʼ�������̾�û�õ��㹻��Դ����� */
    for (j = 0; j < m; j++)
        work[j] = available[j];    /*��work[j]��ʾ���ṩ���̼������еĸ�����Դ�� */
    k = n;
    do {
        for (i = 0; i < n; i++) {
            if (finish[i] == 'F') {
                f = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        f = 0;
                if (f == 1) {    /*�ҵ���û��ɵ���������С�ڿ��ṩ���̼������е� */
                    finish[i] = 'T';    /*��Դ���Ľ��� */
                    a[v++] = i;    /*��¼��ȫ���� */
                    for (j = 0; j < m; j++)
                        work[j] = work[j] + allocation[i][j];    /*�ͷŸý����ѷ������Դ */

                }
            }
        }
        k--;
    } while (k > 0);
    f = 1;
    for (i = 0; i < n; i++) {    /*�ж��Ƿ����еĽ��̶���� */
        if (finish[i] == 'F') {
            f = 0;
            break;
        }
    }
    if (f == 0) {        /*���н���û��ɣ���Ϊ����ȫ״̬ */
        printf("���ǲ���ȫ�� . \n");
        r = 0;
    } else {        /* ����Ϊ��ȫ״̬ */

        printf("���ǰ�ȫ�� .");
        printf("��ȫ����Ϊ:");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);    /*�����ȫ���� */

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
{                /*������� */
    int process[M];
    printf("������Դ: \n");
    for (j = 0; j < m; j++)
        printf("%2d ", available[j]);
    printf("\n");
}

