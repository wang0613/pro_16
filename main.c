#include <stdio.h>

//指针的进阶
/*
 * 1:字符指针
 * 2:数组指针
 * 3:指针数组
 * 4:数组传参和指针传参
 * 5:函数指针
 * 6:函数指针数组
 * 7:指向函数指针 数组的指针
 * 8:回调函数
 * 9:指针和数组面试题的解析
 */
/*void test(int arr[]) {
    int sz = sizeof(arr) / sizeof(arr[0]); //64为平台 指针为8个字节
    printf("%d", sz);
}*/

int main1() {

//    int arr[10] = {0};
//    test(arr);

    char arr[] = "abcdef";
    char *pc = &arr;
    const char *p = "abcdef"; //这是一个常量字符串，其实是把a的地址赋给了p
    printf("%s\n", arr);
    printf("%s\n", pc);
    printf("%c\n", *p);

//    *p = 'A';
    printf("%s\n", p); //不能修改
    return 0;
}

int main2() {
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";


    char *p1 = "abcdef";
    char *p2 = "abcdef";

    //注意是：常量字符串 存储的是一份
    if (p1 == p2) {
        printf("hehe\n");
    } else {
        printf("haha\n");
    }


    if (arr1 == arr2) //数组存储的首元素地址，存放在不同的地址中
    {
        printf("hehe\n");
    } else {
        printf("haha\n");
    }
    return 0;
}

int main3() {
    //指针数组：存放指针的数组
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
    //数组指针：实际上是个指针
//    int *p = NULL; //整形指针-指向整形的指针
//    char* pc = NULL; //字符指针

    //数组指针：指向数组的指针
//    int arr[10] = {1,2,3};
    //arr-首元素的地址
    //&arr【0】- 首元素地址
    //&arr - 数组的地址
//    int (*p) [10] =&arr; //数组指针


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

//其实 传递的是一维数组
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
    //数组名-首元素地址  把二维数组看成一维数组
    //其实 传递的是一维数组


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

//3：数组参数 指针参数
int main6() {
    int arr[10] = {0};

    int  (*p)[10] = &arr;

    int *arr2[20] = {0}; //指针数组 存放指针的数组
    test1(arr);
    test2(arr2);

}

//函数指针： 指向函数的指针
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
    printf("%p\n", &add); //函数的地址
    printf("%p\n", add); //**在函数中&函数名和函数名都是函数的地址

    //存储函数
    //函数指针和数组指针的方法类似
    int (*pa)(int, int) = add;
    //*pa指向函数的指针
    int c = (*pa)(a, b);
    printf("%d\n", c);


    //存储print函数
    void (*pc)(char *) =print_1;
    //调用函数
    (*pc)("hello bite!");

    (*(void (*)()) 0)();
    //将0强制类型转换为(void(*)()) 然后解引用 然后调用0地址出的函数



}

typedef void(*pfun_t)(int); //重命名

pfun_t signal(int, pfun_t); //简化 signal

//signal()函数的返回类型为 void*
void (*signal(int, void(*)(int)))(int);


int main8() {
//函数指针数组
    int (*pa)(int, int) = add;
//需要一个数组存放4个函数的地址-函数指针的数组
    int (*parr[4])(int, int) = {add, sub, mul, div};

    int i = 0;
    for (i = 0; i < 4; i++) {
        int r = parr[i](2, 3); //parr[i]为函数指针
        printf("%d ", r);
    }
}

//char *my_strcpy(char *dest, const char *src);

//写一个函数指针pf，指向my_strcpy()
//char *(*pf)(char *, const char *) = my_strcpy;

//写一个函数指针数组，存放3个
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
printf("请输入操作数：\n");
scanf("%d", &x);
scanf("%d", &y);
rs = mul(x, y);
break;
case 4:
printf("请输入操作数：\n");
scanf("%d", &x);
scanf("%d", &y);
rs = div(x, y);
break;
case 0:
printf("退出成功\n");
break;
default:
printf("选择错误\n");
break;
}*/
//函数数组指针  实现案例
//函数指针作为参数进行传递，然后执行所传的函数指针，解决冗余问题 称之为回调函数
void calc(int(*p)(int, int)) {
    int x = 0;
    int y = 0;
    printf("请输入操作数：\n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d",p(x,y));
}

int main9() {
    int input = 1;
    int x = 0;
    int y = 0;
    //函数指针数组  存放 函数指针
    int (*pfArr[5])(int, int) = {0, add, sub, mul, div};

    do {
        meun();
        printf("请选择：\n");
        scanf("%d", &input);
        if (input >= 1 && input <= 4) {


            printf("请输入操作数：\n");
            scanf("%d", &x);
            scanf("%d", &y);

//        pfArr[input]   //当前指针函数
            int rs = pfArr[input](x, y);

            printf("%d\n", rs);
        } else if (input == 0) {
            printf("退出!\n");
        } else {
            printf("选择错误!\n");
        }

    } while (input);
}

//指向函数指针数组的指针
int main10()
{
    int arr[10] ={0};
    //数组指针
    int(*p)[10] = &arr; //整个数组的地址


    //函数指针
    int (*pa)(int,int) = add;

    //函数指针数组
    int (*pfArr[4])(int,int) ={0,add} ;
    //指向    函数指针数组  的指针
//    (*ppfArr) 指针 ---(*ppfArr)[4] 指向四个元素 元素类型int(*)(int,int)函数指针
    int (*(*ppfArr)[4])(int,int) = &pfArr;

}

void print(char* str)
{
    printf("呵呵:%s",str);
}
//接收参数为：print函数的指针
void test(void (*pc)(char*))
{
    //*pc为函数的指针
    printf("test\n");
    (*pc)("hehe"); //执行print函数

    //回调函数就是一个通过函数指针调用的函数，将函数指针作为参数传递给另一个函数时，
    // 当这个指针被用来调用其指向的函数时，我们称之为回调函数
}

//回调函数
int main()
{
    test(print);
    return 0;

}

