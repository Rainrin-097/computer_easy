# C语言增强版计算器（用于git连接练手）

一个功能丰富的命令行计算器，支持多种运算和高级功能。

## 💡 功能特性

- 基础运算：`+` `-` `*` `/` `%`（模运算）
- 科学函数：`sqrt`（平方根）`abs`（绝对值）`sin`（正弦）`cos`（余弦）
- 记忆功能：`m+` `m-` `mr` `mc`
- 计算历史：`h`
- 连续计算模式

## 🚀 使用方法

```bash
gcc main.c -o enhanced_calculator -lm    # 注意：-lm 链接数学库
./enhanced_calculator
