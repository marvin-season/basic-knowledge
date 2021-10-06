#include "stdio.h"
#include "stdlib.h"

#define SUCCESS 1
#define FAILURE 0
#define HASH_SIZE 6 //hash 表的长度
#define NULL_KEY -65535

typedef int Status;

typedef struct HashTable
{
    int *eles;

} HashTable;

void init(HashTable *hashtable)
{
    // m = HASH_SIZE;
    hashtable->eles = (int *)malloc(sizeof(int));

    for (int i = 0; i < HASH_SIZE; i++)
    {
        hashtable->eles[i] = NULL_KEY;
    }
}

int hash(int key)
{
    return key % HASH_SIZE + 1;
}

void insert_hash(HashTable *hashtable, int key)
{
    int addr = hash(key); // 得到需要存储的地址  、实际上救赎数组索引
    while (hashtable->eles[addr] != NULL_KEY)
    {
        //  开放定址法   线性探测法
        addr = (addr + 1) % HASH_SIZE;
    }

    hashtable->eles[addr] = key;
}

Status seach_hash(HashTable *hashtable, int key, int *addr)
{
    *addr = hash(key);
    //  指定的地址(索引)存储的不是我们要找的元素， 说明存储的时候存在冲突
    //  当前索要搜索的元素在存储的时候被安排到了其他的地方
    while (hashtable->eles[*addr] != key)
    {
        *addr = (*addr + 1) % HASH_SIZE;
        if (*addr == hash(key) || hashtable->eles[*addr] == NULL_KEY)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}

int main()
{
    HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));
    init(hashtable);
    insert_hash(hashtable, 3);
    insert_hash(hashtable, 4);
    insert_hash(hashtable, 5);
    insert_hash(hashtable, 6);
    insert_hash(hashtable, 7);
    insert_hash(hashtable, 8);

    int *addr;
    int key;
    while (1)
    {
        printf("--------请输入您要搜索的元素:--------\n");
        scanf("%d", &key);
        if (seach_hash(hashtable, key, addr))
        {
            printf("你查找的元素的位置是:  %d\n", *addr);
        }else{
            printf("您输入的元素未找到\n");
        }
    }
    system("pause");
    return 0;
}