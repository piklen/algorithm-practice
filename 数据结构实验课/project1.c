#include <stdio.h>
#include <malloc.h>
typedef struct
{
    double real;
    double img;
} ComplexNumber;

void CreateComplexNumber(ComplexNumber *c, double a, double b)
{
    c->real = a;
    c->img = b;
    return;
}

void AddComplexNumber(ComplexNumber *c, ComplexNumber c1, ComplexNumber c2)
{
    c->real = c1.real + c2.real;
    c->img = c1.img + c2.img;
    return;
}
void SubComplexNumber(ComplexNumber *c, ComplexNumber c1, ComplexNumber c2)
{
    c->real = c1.real - c2.real;
    c->img = c1.img - c2.img;
    return;
}

void MultiComplexNumber(ComplexNumber *c, ComplexNumber c1, ComplexNumber c2)
{
    c->real = c1.real * c2.real - c1.img * c2.img;
    c->img = c1.real * c2.img + c1.img * c2.real;
    return;
}

void ConComplexNumber(ComplexNumber *c, ComplexNumber c1)
{
    c->real = c1.real;
    c->img = c1.img * (-1);
    return;
}
void DisplayComplexNumber(double c1, double c2)
{
    if ((int)c1 == 0 && (int)c2 == 0)
        printf("\t结运算果为：0\n");
    if ((int)c1 == 0 && (int)c2 != 0)
        printf("\t运算结果为：%gi\n", c2);
    if ((int)c1 != 0 && (int)c2 == 0)
        printf("\t运算结果为：%g\n", c1);
    if ((int)c1 != 0 && (int)c2 != 0)
        printf("\t运算结果为：%g+%gi\n", c1, c2);
}

int main()
{
    int choice;
    double a1, b1, a2, b2;
    ComplexNumber *c1, *c2, *result;
    c1 = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    c2 = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    result = (ComplexNumber *)malloc(sizeof(ComplexNumber));
    printf("\t\t1----生成一个复数（实部与虚部由你输入）\t\n");
    printf("\t\t2----求2个复数的和\t\n");
    printf("\t\t3----求2个复数的差\t\n");
    printf("\t\t4----求2个复数的积\t\n");
    printf("\t\t5----求共轭复数\t\n");
    printf("\t\t0----退出程序\t\n\n");
    printf("请输入你要让计算机所做运算的代号！\t\n");
    while (scanf("%d", &choice) != EOF)
    {
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            goto A;
            break;
        case 2:
            goto B;
            break;
        case 3:
            goto C;
            break;
        case 4:
            goto D;
            break;
        }

    A:
    {
        printf("\t请输入实部和虚部\n");
        scanf("%lf%lf", &a1, &b1);
        CreateComplexNumber(c1, a1, b1);
        DisplayComplexNumber(c1->real, c1->img);
    }
        continue;
    B:
    {
        printf("\t请分别输入两个数的实部和虚部\n");
        scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
        CreateComplexNumber(c1, a1, b1);
        CreateComplexNumber(c2, a2, b2);
        AddComplexNumber(result, *c1, *c2);
        DisplayComplexNumber(result->real, result->img);
    }
        continue;
    C:
    {
        printf("\t请分别输入两个数的实部和虚部\n");
        scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
        CreateComplexNumber(c1, a1, b1);
        CreateComplexNumber(c2, a2, b2);
        SubComplexNumber(result, *c1, *c2);
        DisplayComplexNumber(result->real, result->img);
    }
        continue;

    D:
    {
        printf("\t请分别输入两个数的实部和虚部\n");
        scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
        CreateComplexNumber(c1, a1, b1);
        CreateComplexNumber(c2, a2, b2);
        MultiComplexNumber(result, *c1, *c2);
        DisplayComplexNumber(result->real, result->img);
    }
        continue;
    E:
    {
        printf("\t请输入该复数的实部和虚部\n");
        scanf("%lf%lf", &a1, &b1);
        CreateComplexNumber(c1, a1, b1);
        ConComplexNumber(result, *c1);
        DisplayComplexNumber(result->real, result->img);
    }
    }
    return 0;
}