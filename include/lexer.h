#ifndef LEXER_H
#define LEXER_H

#include "token.h"

// opaque struct
typedef struct Lexer Lexer;

Lexer *lexer_create(const char *source);      // 需要来源

void lexer_next(Lexer *lexer, Token *token);

void lexer_destroy(Lexer *lexer);

#endif