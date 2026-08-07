#ifndef TOKEN_H
#define TOKEN_H

#define MAX_LEXEME_LENGTH 1024

typedef enum 
{
    TOKEN_UNKNOWN,
    
    TOKEN_EOF,

    TOKEN_IDENTIFIER,

    TOKEN_NUMBER,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,     // 没有用MUL，lexer描述字符，而不是数学意义
    TOKEN_SLASH,    // 同样没有采用DIV

    TOKEN_LPAREN,
    TOKEN_RPAREN
} TokenType;

typedef struct
{
    TokenType type;
    // char *lexeme;   // 词素，token在原始字符流中的原始格式
    //                 // 没有按照类型直接存double或者string，因为只识别序列，不计算含义

    // 升级为token保存source中的一段引用
    const char *start;
    size_t length;
    
} Token;

Token *token_create(TokenType type, const char *start, const size_t length);      // 创建一个 Token，利用token的start和长度信息，让 Token 获得所有权

void token_free(Token *token);

void token_print(const Token *token);

#endif