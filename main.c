#include <stdio.h>
#include <math.h>   // 添加数学函数支持
#include <string.h> // 字符串处理

int main()
{
    double num1, num2, result, memory = 0; // 添加内存变量
    char op, command[20];
    int history_count = 0;
    char history[10][100]; // 简单的历史记录（最多10条）

    printf("=========================================\n");
    printf("   Enhanced Calculator v2.0\n");
    printf("   Commands: + - * / sqrt pow abs mod\n");
    printf("   Memory: m+ m- mr mc\n");
    printf("   History: h\n");
    printf("   Type 'q' to quit\n");
    printf("=========================================\n\n");

    while (1)
    {
        printf("Enter command or calculation: ");

        if (scanf("%s", command) != 1)
            break;

        // 退出命令
        if (strcmp(command, "q") == 0 || strcmp(command, "quit") == 0)
        {
            printf("👋 Goodbye!\n");
            break;
        }

        // 历史记录命令
        else if (strcmp(command, "h") == 0 || strcmp(command, "history") == 0)
        {
            printf("--- Calculation History ---\n");
            for (int i = 0; i < history_count; i++)
            {
                printf("%d: %s\n", i + 1, history[i]);
            }
            printf("-------------------------\n\n");
            continue;
        }

        // 内存操作命令
        else if (strcmp(command, "mr") == 0)
        {
            printf("Memory recall: %.2f\n\n", memory);
            continue;
        }
        else if (strcmp(command, "mc") == 0)
        {
            memory = 0;
            printf("Memory cleared.\n\n");
            continue;
        }

        // 单操作数函数
        else if (strcmp(command, "sqrt") == 0 ||
                 strcmp(command, "abs") == 0 ||
                 strcmp(command, "sin") == 0 ||
                 strcmp(command, "cos") == 0)
        {

            printf("Enter number: ");
            if (scanf("%lf", &num1) != 1)
            {
                printf("❌ Invalid input!\n\n");
                continue;
            }

            if (strcmp(command, "sqrt") == 0)
            {
                if (num1 < 0)
                {
                    printf("❌ Cannot calculate square root of negative number!\n\n");
                    continue;
                }
                result = sqrt(num1);
                snprintf(history[history_count], 100, "sqrt(%.2f) = %.2f", num1, result);
            }
            else if (strcmp(command, "abs") == 0)
            {
                result = fabs(num1);
                snprintf(history[history_count], 100, "abs(%.2f) = %.2f", num1, result);
            }
            else if (strcmp(command, "sin") == 0)
            {
                result = sin(num1);
                snprintf(history[history_count], 100, "sin(%.2f) = %.2f", num1, result);
            }
            else if (strcmp(command, "cos") == 0)
            {
                result = cos(num1);
                snprintf(history[history_count], 100, "cos(%.2f) = %.2f", num1, result);
            }

            printf("✅ Result: %.2f\n\n", result);
            if (history_count < 9)
                history_count++;
            continue;
        }

        // 双操作数运算
        else
        {
            // 读取第一个数字
            if (sscanf(command, "%lf", &num1) == 1)
            {
                if (scanf(" %c %lf", &op, &num2) != 2)
                {
                    printf("❌ Invalid format!\n\n");
                    continue;
                }
            }
            else
            {
                // 如果第一个不是数字，可能是内存操作
                if (strcmp(command, "m+") == 0)
                {
                    printf("Enter value to add to memory: ");
                    scanf("%lf", &num1);
                    memory += num1;
                    printf("✅ Added %.2f to memory. New value: %.2f\n\n", num1, memory);
                    continue;
                }
                else if (strcmp(command, "m-") == 0)
                {
                    printf("Enter value to subtract from memory: ");
                    scanf("%lf", &num1);
                    memory -= num1;
                    printf("✅ Subtracted %.2f from memory. New value: %.2f\n\n", num1, memory);
                    continue;
                }
                else
                {
                    printf("❌ Unknown command: %s\n", command);
                    continue;
                }
            }

            // 执行运算
            switch (op)
            {
            case '+':
                result = num1 + num2;
                snprintf(history[history_count], 100, "%.2f + %.2f = %.2f", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                snprintf(history[history_count], 100, "%.2f - %.2f = %.2f", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                snprintf(history[history_count], 100, "%.2f * %.2f = %.2f", num1, num2, result);
                break;
            case '/':
                if (num2 == 0)
                {
                    printf("❌ Error: Division by zero!\n\n");
                    continue;
                }
                result = num1 / num2;
                snprintf(history[history_count], 100, "%.2f / %.2f = %.2f", num1, num2, result);
                break;
            case '%': // 模运算
                if (num2 == 0)
                {
                    printf("❌ Error: Modulo by zero!\n\n");
                    continue;
                }
                result = fmod(num1, num2);
                snprintf(history[history_count], 100, "%.2f %% %.2f = %.2f", num1, num2, result);
                break;
            default:
                printf("❌ Unsupported operator: %c\n\n", op);
                continue;
            }

            printf("✅ Result: %.2f\n\n", result);
            if (history_count < 9)
                history_count++;
        }
    }

    return 0;
}