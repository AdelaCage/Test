#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

//����ڵ����ݽṹ
struct LinkNode{
    struct LinkNode* next;
};

//����ṹ��
struct LList{
    struct LinkNode header;
    int size;
};

typedef void* LinkList;

//��ʼ������
LinkList Init_LinkList();

//��λ�ò�������
void InsertByPos(LinkList list, int pos, void* data);

//��������
void foreach (LinkList list, void(*foreach)(void*));

//��λ��ɾ������
void RemoveByPos(LinkList list, int pos);

//���ٽڵ�
void Destory_LinkList(LinkList* list);

#ifdef __cplusplus
}
#endif
