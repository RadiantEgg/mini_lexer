#ifndef TOKEN_H
#define TOKEN_H

#define MAX_LEXEME_LENGTH 1024

typedef enum 
{
    TOKEN_ERROR,
    
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

    const char *start;
    size_t length;

    size_t line;
    size_t column;

} Token;

void token_init(Token *token, TokenType type, const char *start, const size_t length, size_t line, size_t column);      // 创建一个 Token，利用token的start和长度信息，让 Token 获得所有权

void token_print(const Token *token);

#endif