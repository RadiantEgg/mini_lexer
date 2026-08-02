# mini_lexer

## mini_lexer v0.1

实现一个最基础词法分析器，将输入字符串转换成 Token 流

### 结构
mini_lexer/
- CMakeLists.txt
- README.md

- include/
    - token.h
    - lexer.h
- src/

    - main.c
    - lexer.c
    - token.c
- tests/
    - test_lexer.c

暂时不考虑：
- parser
- AST
- 文件输入
- 错误处理
- 行列定位

假设：
- 输入合法
- stdin来源
- Token类型有限

