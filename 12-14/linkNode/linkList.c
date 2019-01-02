#include "linkList.h"

struct linkNode *initial_linkNode()
{
    //Ϊͷ�ڵ�����ڴ�ռ䣬Ĭ��ָ���
    struct linkNode* header = malloc(sizeof (struct linkNode));
    header->data = 0;
    header->next = NULL;

    //����β�ڵ㣬Ĭ�ϵ���ͷ�ڵ�
    struct linkNode* pRear = header;
    int val = -1;

    //��������
    while (true) {
        printf("�������%d������: ", ++header->data);
        scanf("%d", &val);
        if(-1 == val)
        {
            --header->data;
            break;
        }
        //�����½ڵ㣬�����ڴ棬���ݸ�ֵ��ָ���
        struct linkNode* newNode = malloc(sizeof (struct linkNode));
        newNode->data = val;
        newNode->next = NULL;

        //ԭ��βָ��ָ���½ڵ�
        pRear->next = newNode;

        //βָ��������½ڵ�
        pRear = newNode;
    }
    return header;
}

void foreach_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }

    struct linkNode* pCurrent = header->next;

    while(NULL !=pCurrent)
    {
        printf("%d\t", pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}


void InsertByValue_linkNode(struct linkNode* header, int oldval, int newval)
{
    if(NULL == header)
        return;

    //����ǰ���ͺ�̸����ڵ�
    struct linkNode* pPre = header;
    struct linkNode* pNext = pPre->next;

    //�ж�oldval������
    while (NULL != pNext) {
        if(oldval == pNext->data)
            break;
        pPre = pPre->next;
        pNext = pPre->next;
    }

#if 0
    if(NULL == pNext)
        return;
#endif

    //��������ڵ㣬��ֵ
    struct linkNode* pInsert = malloc(sizeof (struct linkNode));
    pInsert->data = newval;

    //ǰ���ڵ�ָ�����ڵ㣬����ڵ�ָ���̽ڵ�
    pPre->next = pInsert;
    pInsert->next = pNext;
    header->data++;
}


void clear_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }

    //���������ڵ㣬ͷ�ڵ�ָ��ǰ�����ڵ�
    struct linkNode* pCurrent = header->next;

    //�жϵ�ǰ�ڵ��Ƿ�Ϊ��
    while (NULL != pCurrent) {
        //��������NEXT�ڵ㣬ָ��ǰ�ڵ����һ���ڵ�
        struct linkNode* pNext = pCurrent->next;
        //�ͷŵ�ǰ�ڵ㣬������ǰ�ڵ㵽NEXT�ڵ�
        free(pCurrent);
        pCurrent = pNext;
    }
    //ͷ�ڵ�ָ���
    header->next = NULL;
    header->data = 0;
}

void delete_linkNode(struct linkNode* header, int denumber)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }


    //����ǰ���ͺ�̸����ڵ�
    struct linkNode* pPre = header;
    struct linkNode* pNext = pPre->next;

    //ƥ���̽ڵ��ֵ������denumber����
    while (NULL != pNext) {
        if(denumber == pNext->data)
            break;
        pPre = pNext;
        pNext = pPre->next;
    }
    if(NULL == pNext)
        return;
    //ǰ���ڵ�ָ���̽ڵ�ָ��Ľڵ㣬֮���ͷź�̽ڵ㣬�ÿ�
    pPre->next = pNext->next;
    free(pNext);
    pNext = NULL;
    --header->data;
}

void destory_linkNode(struct linkNode** header)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }
    //���������ڵ����ͷ�ڵ�
    struct linkNode* pCurrent = *header;
    //�ͷ������ڵ�
    while (NULL != pCurrent) {
        struct linkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    //ͷ�ڵ��ÿ�
    *header = NULL;
    printf("��������\n");
}

void count_linkNode(struct linkNode *header)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }
    printf("��ǰ����Ԫ�ظ���Ϊ%d\n",header->data);
}

void reverse_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("����δ��ʼ��\n");
        return;
    }

    struct linkNode* pPre = NULL;
    struct linkNode* pNext = NULL;
    struct linkNode* pCurrent = header->next;

    while (NULL != pCurrent) {
        pNext = pCurrent->next;
        pCurrent->next = pPre;

        pPre = pCurrent;
        pCurrent = pNext;
    }
    header->next = pPre;
}
