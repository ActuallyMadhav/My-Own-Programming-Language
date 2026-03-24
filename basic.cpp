#include <iostream>
#include <vector>
#include <optional>

const std::string TT_INT = "INT";
const std::string TT_FLOAT = "FLOAT";
const std::string TT_PLUS = "PLUS";
const std::string TT_MINUS = "MINUS";
const std::string TT_MUL = "MUL";
const std::string TT_DIV = "DIV";
const std::string TT_LPAREN = "LPAREN";
const std::string TT_RPAREN = "RPAREN";

/********************* 
    TOKEN
*********************/
class Token{
    public:
        std::string type;
        std::string value;

        Token(std::string type, std::string value){
            this->type = type;
            this->value = value;
        }

        std::string repr(const Token& tk){
            if(!tk.value.empty()){
                return tk.type + ": " + tk.value;
            }
            return tk.type;
        }
};

/********************* 
    LEXER
*********************/

class Lexer{
    public:
        std::string text;
        int pos;
        char currentChar;

        Lexer(std::string text){
            this->text = text;
            this->pos = -1;
            this->currentChar = NULL;
            this->advance();
        }

        void advance(){
            this->pos++;
            
            if(this->pos < this->text.size()){
                this->currentChar = this->text[pos];
            }
            else{
                this->currentChar = NULL;
            }
        }

        std::vector<Token> make_tokens(){
            std::vector<Token> tokens;
            std::string whitespace = " \t";
            
            while(this->currentChar != NULL){
                if(whitespace.find(this->currentChar) != std::string::npos){
                    this->advance();
                }
                else if(this->currentChar == '+'){
                    tokens.push_back(Token(TT_PLUS, ""));
                    this->advance();
                }
            }

            return tokens;
        }

};