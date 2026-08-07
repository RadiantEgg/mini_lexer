#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token.h"

Token *token_create(TokenType type, const char *start, size_t length, size_t line, size_t column)
{
    Token *token = malloc(sizeof(Token));
    
    // 错误处理...

    token->type = type;
    token->start = start;
    token->length = length;

    token->line = line;
    token->column = column;

    return token;
}

void token_free(Token *token)
{
    free(token);
}

// 改进
// X Macro: 维护一次自动生成enum和string映射

static const char *token_type_to_string(TokenType type)
{
    switch(type)
    {
        case TOKEN_EOF:
            return "EOF";
        case TOKEN_IDENTIFIER:
            return "IDENTIFIER";
        case TOKEN_NUMBER:
            return "NUMBER";
        case TOKEN_PLUS:
            return "PLUS";
        case TOKEN_MINUS:
            return "MINUS";
        case TOKEN_STAR:
            return "STAR";
        case TOKEN_SLASH:
            return "SLASH";
        case TOKEN_LPAREN:
            return "LPAREN";
        case TOKEN_RPAREN:
            return "RPAREN";

        // 错误处理...

        default:
            return "Unknown TokenType";
    }
}


void token_print(const Token *token)    // print 只访问，readonly
{
    printf("line: %3zu, column: %3zu: ", token->line, token->column);
    printf("TokenType: %-12s\t", token_type_to_string(token->type));
    if (token->type != TOKEN_EOF)
        printf("TokenLexeme: %.*s\n", token->length,token->start);     // %*.s 输出字符串前*个字符,当EOF时候传入0，恰好不会创造字符串
    else 
        printf("\n");
}