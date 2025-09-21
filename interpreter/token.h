#ifndef TOKEN_H
#define TOKEN_H

#include <any>
#include <string>
#include <utility>
#include "tokentype.h"

class Token {
public:
    const TokenType type;
    const std::string lexme;
    const std::any literal;
    const int line;

    Token(TokenType type, std::string lexme, std::any literal): 
        type{type}, lexme{std::move(lexme)}, literal{std::move(literal)}, line{line} {}
    
    std::string toString() const {
        std::string literal_text;

        return type + " " + lexme + " " + literal_text;
    }
};

#endif