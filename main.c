#include <stdio.h>

int main()
{
    double num1, num2, result;
    char op;

    printf("================================\n");
    printf("   C语言简易计算器 v1.0\n");
    printf("   支持: +  -  *  /\n");
    printf("   输入 q 退出\n");
    printf("================================\n\n");

    while (1)
    {
        printf("计算式 (如 3 + 5): ");

        // 读取第一个字符判断是否退出
        if (scanf(" %c", &op) != 1)
            break;
        if (op == 'q' || op == 'Q')
        {
            printf("👋 再见！\n");
            break;
        }

        // 回退字符，重新读取完整表达式
        ungetc(op, stdin);
        if (scanf("%lf %c %lf", &num1, &op, &num2) != 3)
        {
            printf("❌ 格式错误！请按 \"数字 运算符 数字\" 输入\n\n");
            while (getchar() != '\n')
                ; // 清空缓冲区
            continue;
        }

        // 计算
        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("❌ 除数不能为0！\n\n");
                continue;
            }
            result = num1 / num2;
            break;
        default:
            printf("❌ 不支持的运算符: %c\n\n", op);
            continue;
        }

        printf("✅ %.2f %c %.2f = %.2f\n\n", num1, op, num2, result);
    }

    return 0;
}