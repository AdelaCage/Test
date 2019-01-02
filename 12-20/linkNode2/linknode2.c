#include "linknode2.h"


LinkList Init_LinkList()
{
    struct LList* list = malloc(sizeof (struct LList));
    if(NULL == list)
    {
        return NULL;
    }

    list->header.next = NULL;
    list->size = 0;
    return list;
}

void InsertByPos(LinkList list, int pos, void *data)
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == data)
    {
        return;
    }
    struct LList* myList = (struct LList*)list;
    if(pos<0 || pos>myList->size)
    {
        pos = myList->size;
    }

    //�ҵ�Ҫ����λ�õ�ǰһ��λ��
    struct LinkNode* pCurrent = &(myList->header);
    for (int i=0; i<pos; ++i) {
        pCurrent = pCurrent->next;
    }

    //��������ڵ�
    struct LinkNode* InsNode = (struct LinkNode*)data;
    //����ָ��
    InsNode->next = pCurrent->next;
    pCurrent->next = InsNode;
    //���¼�����
    myList->size++;
}

void foreach(LinkList list, void (*foreach)(void *))
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == foreach)
    {
        return;
    }

    struct LList* myList = (struct LList*)list;
    struct LinkNode* pCurrent = myList->header.next;
    while (NULL != pCurrent) {
        struct LinkNode* pNext = pCurrent->next;
        foreach(pCurrent);
        pCurrent = pNext;
    }
    printf("��ǰԪ�ظ���: %d\n", myList->size);
}

void RemoveByPos(LinkList list, int pos)
{
    if(NULL == list)
    {
        return;
    }
    struct LList* myList = (struct LList*)list;
    if(pos<0 || pos>myList->size-1)
    {
        return;
    }

    struct LinkNode* pCurrent = &(myList->header);
    for (int i=0; i<pos; ++i) {
        pCurrent = pCurrent->next;
    }

    struct LinkNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    myList->size--;
}

void Destory_LinkList(LinkList* list)
{
    if(NULL == *list)
    {
        return;
    }
    free(*list);
    *list = NULL;
}
