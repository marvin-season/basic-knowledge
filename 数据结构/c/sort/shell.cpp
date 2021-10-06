#include "stdio.h"
#include "stdlib.h"

#define N 10

void sort(int *nums);
void show(int *nums);

int main()
{
    int nums[N];
    printf("����10����Ҫ�������\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    sort(nums);
    show(nums);

    system("pause");
    return 0;
}

void sort(int *nums)
{
    int increment = N; //��ʼ������, ���ھ��ȷ���

    do
    {
        increment = increment / 3 + 1; // 4
        for (int i = increment; i < N; i++)
        {
            //  С��������
            if (nums[i] < nums[i - increment])
            {
                printf("%d <-----> %d\n", nums[i], nums[i - increment]);

                int temp = nums[i];
                // С��ģ��������
                int j;
                for (j = i - increment; j >= 0 && temp < nums[j]; j -= increment)
                {
                    nums[j + increment] = nums[j];
                }
                nums[j + increment] = temp;
                show(nums);
            }
        }
        printf("round ...\n");
    } while (increment > 1);
}

void show(int *nums)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}