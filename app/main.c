#include <stdio.h>

#include "token.h"
#include "lexer.h"

int main()
{
    const char *source = "abc+def";

    Lexer *lexer = lexer_create(source);

    if (lexer == NULL) {
        fprintf(stderr, "Failed to create lexer\n");
        return 1;
    }

    Token token;

    while (1) {
        lexer_next(lexer, &token);

        token_print(&token);

        if (token.type == TOKEN_EOF)
            break;
    }

    lexer_destroy(lexer);

    return 0;
}