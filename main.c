#include <stdio.h>

//ָ��Ľ���
/*
 * 1:�ַ�ָ��
 * 2:����ָ��
 * 3:ָ������
 * 4:���鴫�κ�ָ�봫��
 * 5:����ָ��
 * 6:����ָ������
 * 7:ָ����ָ�� �����ָ��
 * 8:�ص�����
 * 9:ָ�������������Ľ���
 */
/*void test(int arr[]) {
    int sz = sizeof(arr) / sizeof(arr[0]); //64Ϊƽ̨ ָ��Ϊ8���ֽ�
    printf("%d", sz);
}*/

int main1() {

//    int arr[10] = {0};
//    test(arr);

    char arr[] = "abcdef";
    char *pc = &arr;
    const char *p = "abcdef"; //����һ�������ַ�������ʵ�ǰ�a�ĵ�ַ������p
    printf("%s\n", arr);
    printf("%s\n", pc);
    printf("%c\n", *p);

//    *p = 'A';
    printf("%s\n", p); //�����޸�
    return 0;
}

int main2() {
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";


    char *p1 = "abcdef";
    char *p2 = "abcdef";

    //ע���ǣ������ַ��� �洢����һ��
    if (p1 == p2) {
        printf("hehe\n");
    } else {
        printf("haha\n");
    }


    if (arr1 == arr2) //����洢����Ԫ�ص�ַ������ڲ�ͬ�ĵ�ַ��
    {
        printf("hehe\n");
    } else {
        printf("haha\n");
    }
    return 0;
}

int main3() {
    //ָ�����飺���ָ�������
//    int a = 10;
//    int b =20;
//    int c = 30;
//    int d = 40;
//
//    int* arr[5] = {&a,&b,&c,&d};
//    char* arr2[5];
//

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 3, 4, 5};
    int arr3[] = {5, 4, 3, 2, 5};

    int *parr = {arr1, arr2, arr3};
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        for (j = 0; j < 5; j++) {
            printf("%d ", (parr[i] + j));
        }
        printf("\n");
    }

}

int main4() {
    //����ָ�룺ʵ�����Ǹ�ָ��
//    int *p = NULL; //����ָ��-ָ�����ε�ָ��
//    char* pc = NULL; //�ַ�ָ��

    //����ָ�룺ָ�������ָ��
//    int arr[10] = {1,2,3};
    //arr-��Ԫ�صĵ�ַ
    //&arr��0��- ��Ԫ�ص�ַ
    //&arr - ����ĵ�ַ
//    int (*p) [10] =&arr; //����ָ��


//    char* arr[5];
//    char* (*pa)[5] = &arr;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7};
    int(*pa) = &arr;

    int i = 0;
    for (i = 0; i < 10; i++) {

//        printf("%d ",*pa+i);
        printf("%d ", *(pa + i));
    }

//    int i= 0;
//    for(i = 0; i< 10;i++)
//    {
//       printf("%d ",*(pa)[i]);
//    }
}

void print1(int arr[3][5], int row, int col) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//��ʵ ���ݵ���һά����
void print2(int (*p)[5], int row, int col) {
    int i = 0;
    for (i = 0; i < row; i++) {
        int j = 0;
        for (j = 0; j < col; j++) {
//            printf("%d ",*(*(p+i) + j));
            printf("%d ", (*(p + i))[j]);
        }
        printf("\n");

    }
}

int main5() {
    int arr[3][5] = {{1, 2, 3, 4,  5},
                     {4, 5, 6, 7,  8},
                     {7, 8, 9, 10, 11}};
    print1(arr, 3, 5);

    printf("------------------\n");
    print2(arr, 3, 5);
    //������-��Ԫ�ص�ַ  �Ѷ�ά���鿴��һά����
    //��ʵ ���ݵ���һά����


}

//void test(int arr[])
//{
//
//}
//void test(int arr[10])
//{
//
//}
void test1(int *arr) {

}

//void test2(int* arr[20])
//{
//
//}
void test2(int **arr) {

}

//3��������� ָ�����
int main6() {
    int arr[10] = {0};

    int  (*p)[10] = &arr;

    int *arr2[20] = {0}; //ָ������ ���ָ�������
    test1(arr);
    test2(arr2);

}

//����ָ�룺 ָ������ָ��
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int div(int x, int y) {
    return x / y;
}


void print_1(char *str) {
    printf("%s ", str);
}

int main7() {

    int a = 10;
    int b = 20;
//    printf("%d ",add(a,b));

    //00007ff7077c1c62
    printf("%p\n", &add); //�����ĵ�ַ
    printf("%p\n", add); //**�ں�����&�������ͺ��������Ǻ����ĵ�ַ

    //�洢����
    //����ָ�������ָ��ķ�������
    int (*pa)(int, int) = add;
    //*paָ������ָ��
    int c = (*pa)(a, b);
    printf("%d\n", c);


    //�洢print����
    void (*pc)(char *) =print_1;
    //���ú���
    (*pc)("hello bite!");

    (*(void (*)()) 0)();
    //��0ǿ������ת��Ϊ(void(*)()) Ȼ������� Ȼ�����0��ַ���ĺ���



}

typedef void(*pfun_t)(int); //������

pfun_t signal(int, pfun_t); //�� signal

//signal()�����ķ�������Ϊ void*
void (*signal(int, void(*)(int)))(int);


int main8() {
//����ָ������
    int (*pa)(int, int) = add;
//��Ҫһ��������4�������ĵ�ַ-����ָ�������
    int (*parr[4])(int, int) = {add, sub, mul, div};

    int i = 0;
    for (i = 0; i < 4; i++) {
        int r = parr[i](2, 3); //parr[i]Ϊ����ָ��
        printf("%d ", r);
    }
}

//char *my_strcpy(char *dest, const char *src);

//дһ������ָ��pf��ָ��my_strcpy()
//char *(*pf)(char *, const char *) = my_strcpy;

//дһ������ָ�����飬���3��
//char *(*pfArr[3])(char *, const char *) = {};


void meun() {
    printf("***************************\n");
    printf("***1:add    2:sub       ***\n");
    printf("***3:mul    4:div       ***\n");
    printf("******** 0:exit ***********\n");
}

/*switch (input) {
case 1:
  calc(add);
  break;
case 2:
  calc(sub);
  break;
case 3:
printf("�������������\n");
scanf("%d", &x);
scanf("%d", &y);
rs = mul(x, y);
break;
case 4:
printf("�������������\n");
scanf("%d", &x);
scanf("%d", &y);
rs = div(x, y);
break;
case 0:
printf("�˳��ɹ�\n");
break;
default:
printf("ѡ�����\n");
break;
}*/
//��������ָ��  ʵ�ְ���
//����ָ����Ϊ�������д��ݣ�Ȼ��ִ�������ĺ���ָ�룬����������� ��֮Ϊ�ص�����
void calc(int(*p)(int, int)) {
    int x = 0;
    int y = 0;
    printf("�������������\n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d",p(x,y));
}

int main9() {
    int input = 1;
    int x = 0;
    int y = 0;
    //����ָ������  ��� ����ָ��
    int (*pfArr[5])(int, int) = {0, add, sub, mul, div};

    do {
        meun();
        printf("��ѡ��\n");
        scanf("%d", &input);
        if (input >= 1 && input <= 4) {


            printf("�������������\n");
            scanf("%d", &x);
            scanf("%d", &y);

//        pfArr[input]   //��ǰָ�뺯��
            int rs = pfArr[input](x, y);

            printf("%d\n", rs);
        } else if (input == 0) {
            printf("�˳�!\n");
        } else {
            printf("ѡ�����!\n");
        }

    } while (input);
}

//ָ����ָ�������ָ��
int main10()
{
    int arr[10] ={0};
    //����ָ��
    int(*p)[10] = &arr; //��������ĵ�ַ


    //����ָ��
    int (*pa)(int,int) = add;

    //����ָ������
    int (*pfArr[4])(int,int) ={0,add} ;
    //ָ��    ����ָ������  ��ָ��
//    (*ppfArr) ָ�� ---(*ppfArr)[4] ָ���ĸ�Ԫ�� Ԫ������int(*)(int,int)����ָ��
    int (*(*ppfArr)[4])(int,int) = &pfArr;

}

void print(char* str)
{
    printf("�Ǻ�:%s",str);
}
//���ղ���Ϊ��print������ָ��
void test(void (*pc)(char*))
{
    //*pcΪ������ָ��
    printf("test\n");
    (*pc)("hehe"); //ִ��print����

    //�ص���������һ��ͨ������ָ����õĺ�����������ָ����Ϊ�������ݸ���һ������ʱ��
    // �����ָ�뱻����������ָ��ĺ���ʱ�����ǳ�֮Ϊ�ص�����
}

//�ص�����
int main()
{
    test(print);
    return 0;

}

