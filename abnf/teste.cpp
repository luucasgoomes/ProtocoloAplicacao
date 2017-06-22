#include <iostream>
#include "parser_teste.h"
 
int main() {
  Parser_teste parser;
 
  ABNFRule * r = (ABNFRule*)parser.match("E-mail: Dona Bilica <bilica@oioio.com.br>\r\n");
  cout << "Nome da regra ativada: " << r->get_name() << endl;
  cout << "Texto que ativou a regra: " << r->get_match() << endl;
 
  Token * email = r->get_token("email");
  Token * nome = r->get_token("nome");
  cout << "Nome: " << nome->get_match() << endl;
  cout << "E-mail: " << email->get_match() << endl;
}
