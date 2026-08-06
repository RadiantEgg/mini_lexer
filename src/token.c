#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token.h"

Token *token_create(TokenType type, const char *start, size_t length)
{
    Token *token = malloc(sizeof(Token));
    
    // 错误处理...

    token->type = type;
    token->lexeme = malloc(length + 1);

    // 错误处理...rollback

    strncpy(token->lexeme, start, length);     // 工程上会用 memcpy 来代替strncpy

    token->lexeme[length] = '\0';

    return token;
}

void token_free(Token *token)
{
    free(token->lexeme);

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
    printf("TokenType: %s\n", token_type_to_string(token->type));
    printf("TokenLexeme: %s\n", token->lexeme);
}