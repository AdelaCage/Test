#include "linkList.h"

void test01()
{
    struct linkNode* header = initial_linkNode();

    printf("��һ�����\n");
    foreach_linkNode(header);
    count_linkNode(header);

    printf("�������\n");
    reverse_linkNode(header);
    foreach_linkNode(header);
    count_linkNode(header);

    InsertByValue_linkNode(header, 44, 33);

    printf("�ڶ������\n");
    foreach_linkNode(header);
    count_linkNode(header);

    clear_linkNode(header);
    InsertByValue_linkNode(header, 00, 11);
//    InsertByValue_linkNode(header, 22, 33);
//    InsertByValue_linkNode(header, 44, 55);
//    InsertByValue_linkNode(header, 66, 77);
    printf("���������\n");
    foreach_linkNode(header);
    count_linkNode(header);

    delete_linkNode(header, 11);
    printf("���ı����\n");
    foreach_linkNode(header);
    count_linkNode(header);

    destory_linkNode(&header);
    foreach_linkNode(header);
    count_linkNode(header);
}

int main()
{
    test01();

    return 0;
}
