#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "token.h"
#include "lexer.h"

struct Lexer
{
    const char *source;
    size_t position;
    char curr;
};

Lexer *lexer_create(const char *source)
{
    Lexer *lexer = malloc(sizeof(Lexer));

    // 错误处理...

    lexer->source = source;
    lexer->position = 0;
    lexer->curr = source[0];    // 合法，判断交给main

    return lexer;
}

void lexer_destroy(Lexer *lexer)
{
    free(lexer);
}

// 查看当前字符
static char lexer_peek(Lexer *lexer)
{
    return lexer->curr;
}

// 推进字符流：更改位置及当前字符
static void lexer_advance(Lexer *lexer)
{
    lexer->position += 1;
    lexer->curr = peek(lexer);
}

// 判断是否到达字符流末尾
static int lexer_is_at_end(Lexer *lexer)
{
    return peek(lexer) == '\0';      // 文件的EOF先不考虑
}

// 跳过空白
static void lexer_skip_whitespace(Lexer *lexer)
{
    while (isspace(peek(lexer)))
        advance(lexer);
}

static void read_identifier(Lexer *lexer, char *identifier)
{
    int i = 0;

    while (i < MAX_LEXEME_LENGTH && !is_at_end(lexer)) {
        identifier[i++] = lexer->curr;
        advance(lexer);
    }

    if (i == MAX_LEXEME_LENGTH) {

        // 错误处理...

    } else {
        identifier[i] = '\0';
    }
}

static void read_number(Lexer *lexer, char *identifier)
{

}

Token *lexer_next(Lexer *lexer)
{
    lexer_skip_whitespace(lexer);

}





