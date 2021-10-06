#include "stdio.h"
#include "stdlib.h"

#define SUCCESS 1
#define FAILURE 0
#define HASH_SIZE 6 //hash ��ĳ���
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
    int addr = hash(key); // �õ���Ҫ�洢�ĵ�ַ  ��ʵ���Ͼ�����������
    while (hashtable->eles[addr] != NULL_KEY)
    {
        //  ���Ŷ�ַ��   ����̽�ⷨ
        addr = (addr + 1) % HASH_SIZE;
    }

    hashtable->eles[addr] = key;
}

Status seach_hash(HashTable *hashtable, int key, int *addr)
{
    *addr = hash(key);
    //  ָ���ĵ�ַ(����)�洢�Ĳ�������Ҫ�ҵ�Ԫ�أ� ˵���洢��ʱ����ڳ�ͻ
    //  ��ǰ��Ҫ������Ԫ���ڴ洢��ʱ�򱻰��ŵ��������ĵط�
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
        printf("--------��������Ҫ������Ԫ��:--------\n");
        scanf("%d", &key);
        if (seach_hash(hashtable, key, addr))
        {
            printf("����ҵ�Ԫ�ص�λ����:  %d\n", *addr);
        }else{
            printf("�������Ԫ��δ�ҵ�\n");
        }
    }
    system("pause");
    return 0;
}