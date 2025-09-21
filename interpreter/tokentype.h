#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <string>

enum TokenType {
    // 単一文字のトークン
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // 一または二文字のトークン
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // リテラル
    IDENTIFIER, STRING, NUMBER,

    // キーワード
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    
    END_OF_FILE
};

std::string toString(TokenType type) {
    static const std::string strings[] = {
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
        "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR",
        "BANG", "BANG_EQUAL",
        "EQUAL", "EQUAL_EQUAL",
        "GREATER", "GREATER_EQUAL",
        "LESS", "LESS_EQUAL",
        "IDENTIFIER", "STRING", "NUMBER",
        "AND", "CLASS", "ELSE", "FALSE", "FUN", "FOR", "IF", "NIL", "OR",
        "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE",
        "END_OF_FILE"
    };

    return strings[static_cast<int>(type)];
}

#endif