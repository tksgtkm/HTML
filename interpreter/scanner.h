#ifndef SCANNER_H
#define SCANNER_H

#include <map>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include "error.h"
#include "token.h"

class Scanner {
    static const std::map<std::string, TokenType> keywords;

    std::string_view source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

public:
    Scanner(std::string_view source): source{source} {}

    std::vector<Token> scanTokens() {
        while (!isAtEnd()) {
            start = current;
            
        }
    }

private:
    void scanToken() {
        char c = advance();
        switch(c) {
            case '(':
                addToken(LEFT_PAREN);
                break;
            case ')':
                addToken(RIGHT_PAREN);
                break;
            case '{':
                addToken(LEFT_BRACE);
                break;
            case '}':
                addToken(RIGHT_BRACE);
                break;
        }
    }

    bool isAtEnd() {
        return current >= source.length();
    }

    char advance() {
        source[current++];
    }

    void addToken(TokenType type) {
        addToken(type, nullptr);
    }

    void addToken(TokenType type, std::any literal) {
        std::string text{source.substr(start, current - start)};
        tokens.emplace_back(type, std::move(text), std::move(literal), line);
    }

};

#endif