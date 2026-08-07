#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "token.h"
#include "lexer.h"

struct Lexer
{
    const char *source;

    const char *start;    // Token 的起点
    const char *current;     // 当前扫描字符

    size_t line;
    size_t column;
};

Lexer *lexer_create(const char *source)
{
    Lexer *lexer = malloc(sizeof(Lexer));

    // 错误处理...

    lexer->source = source;
    lexer->start = source;
    lexer->current = source;    // 合法，判断交给main

    lexer->line = 1;
    lexer->column = 1;
    return lexer;
}

void lexer_destroy(Lexer *lexer)
{
    free(lexer);
}

// 查看当前字符
static char lexer_peek(Lexer *lexer)
{
    return *lexer->current;
}

// 推进字符流：更改位置及当前字符
// 所有针对字符流变化的操作都经由advance(),统一update lexer的接口
static void lexer_advance(Lexer *lexer)
{    
    if (lexer_peek(lexer) == '\n') {
        lexer->line++;
        lexer->column = 1;
    } else {
        lexer->column++;
    }

    lexer->current++;
}

// 判断是否到达字符流末尾
static int lexer_is_at_end(Lexer *lexer)
{
    return lexer_peek(lexer) == '\0';      // 文件的EOF先不考虑
}

// 跳过空白
static void lexer_skip_whitespace(Lexer *lexer)
{
    while (isspace(lexer_peek(lexer)))
        lexer_advance(lexer);
}


static int is_legal_identifier_char(int c)
{
    return isalnum(c) || c == '_';
}

// 按照标识符命名规范
static void scan_identifier(Lexer *lexer)
{
    // 反复扫描字符，合法推进，不合法停止
    while (is_legal_identifier_char(lexer_peek(lexer)))
        lexer_advance(lexer);
}

static void scan_number(Lexer *lexer)   // 开头为.或数字，中间是数字，结尾可以直接带.  || 考虑简单情况如 1.   .5  1.5 等等
{
    while (lexer_peek(lexer) != '.' && isdigit(lexer_peek(lexer))) 
        lexer_advance(lexer);
    
    if (lexer_peek(lexer) == '.') {
        lexer_advance(lexer);

        while (isdigit(lexer_peek(lexer)))
            lexer_advance(lexer);
    }
}

static TokenType lexer_scan_single_char(Lexer *lexer)
{
    switch(lexer_peek(lexer)) 
    {
        case '+':
            lexer_advance(lexer);
            return TOKEN_PLUS;
        case '-':
            lexer_advance(lexer);
            return TOKEN_MINUS;
        case '*':
            lexer_advance(lexer);
            return TOKEN_STAR;
        case '/':
            lexer_advance(lexer);
            return TOKEN_SLASH;
        case '(':
            lexer_advance(lexer);
            return TOKEN_LPAREN;
        case ')':
            lexer_advance(lexer);
            return TOKEN_RPAREN;

        // 错误处理...
        default:
            lexer_advance(lexer);
            return TOKEN_ERROR;
    }
}

void lexer_next(Lexer *lexer, Token *token)
{
    lexer_skip_whitespace(lexer);

    lexer->start = lexer->current;
    size_t start_line = lexer->line;
    size_t start_column = lexer->column;

    char c = lexer_peek(lexer);
    
    if (lexer_is_at_end(lexer)) {
        token_init(token, TOKEN_EOF, lexer->start, 0, start_line, start_column);
        return;
    }
    
    if (c == '_' || isalpha(c)) {
        scan_identifier(lexer);
        token_init(token, TOKEN_IDENTIFIER, lexer->start, lexer->current - lexer->start, start_line, start_column);
        return;
    }

    if (isdigit(c) || c == '.') {
        scan_number(lexer);
        token_init(token, TOKEN_NUMBER, lexer->start, lexer->current - lexer->start, start_line, start_column);
        return;
    }

    // 假设剩下的是单字符
    TokenType type = lexer_scan_single_char(lexer);

    if (type != TOKEN_ERROR) {
        token_init(token, type, lexer->start, 1, start_line, start_column);
        return;
    }

    // error
    token_init(token, type, lexer->start, 1, start_line, start_column);
    return;
}





