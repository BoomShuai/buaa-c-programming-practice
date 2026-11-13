# C 语言算法题解集（A–H）

[![CI](https://github.com/BoomShuai/buaa-c-programming-practice/actions/workflows/ci.yml/badge.svg)](https://github.com/BoomShuai/buaa-c-programming-practice/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

个人 C 语言算法练习归档，包含 8 个独立的标准输入/输出程序。仓库提供自写的输入约定、编译入口和回归检查，便于阅读、编译及复习。项目按 MIT 许可证公开。

| 程序 | 内容 | 主要方法 |
| --- | --- | --- |
| [A.c](A.c) | 最大两个数之和 | 单次扫描维护前两大值 |
| [B.c](B.c) | 按单词规则统计匹配行 | ASCII 大小写转换、前后缀与子串 |
| [C.c](C.c) | 轴对齐简单多边形面积 | 鞋带公式、64 位整数 |
| [D.c](D.c) | 经过至少一个指定点的最短路线 | 两次 Dijkstra、自实现最小堆 |
| [E.c](E.c) | 绝对值函数之和的动态最小值 | 离散化、树状数组、下中位数 |
| [F.c](F.c) | 恰好翻转若干指令后的最远距离 | 动态规划、修改次数奇偶性 |
| [G.c](G.c) | 斐波那契编号树的最近公共祖先 | 父节点映射、深度对齐 |
| [H.c](H.c) | 递归字符图案 | 二维数组复制与对称构造 |

## 编译与运行

需要 C11 编译器（GCC 或 Clang）；使用 Makefile 还需要 Make。macOS/Linux 可直接运行，Windows 可使用 WSL 或配置相应的 C 编译工具。

```bash
make
printf '1\n4\n8 2 7 1\n' | ./build/A
# 输出 15
```

也可单独编译一题，无需安装第三方库：

```bash
cc -std=c11 -O2 -Wall -Wextra -Wpedantic A.c -o solution
printf '1\n4\n8 2 7 1\n' | ./solution
```

每个文件都有自己的 `main`，请分别编译。输入格式和有效范围见 [题解说明](docs/PROBLEMS.md)。程序面向有效的竞赛输入，保留固定数组和简洁输入风格。

## 检查

Python 3.9+ 仅用于回归与隐私扫描，8 份题解本身均为 C。

```bash
make test
python3 scripts/privacy_check.py --history
```

CI 在 Linux 的 GCC/Clang 及 macOS Clang 下编译和运行样例，并在 Linux 使用 AddressSanitizer/UndefinedBehaviorSanitizer 检查。回归包含每个程序的输入输出、64 位面积、重复最大值、必须绕行的最短路线、负常数项、修改奇偶性，以及最大图案尺寸。测试覆盖明确的样例和边界，不代表已通过未知在线评测的所有数据。

## 归档边界

源码从个人练习目录整理而来，将无参函数声明规范为 `solve(void)` / `main(void)`，补充读取失败处理并限制指令串读取长度，保留有效输入下的算法实现与输出。原目录中的本机二进制、系统文件和混有旧对话的题面材料保留在本地；这里的说明为重新编写的摘要。项目为个人练习归档，不是学校官方发布。

[贡献说明](CONTRIBUTING.md) · [隐私说明](PRIVACY.md) · [安全反馈](SECURITY.md) · [更新记录](CHANGELOG.md)
