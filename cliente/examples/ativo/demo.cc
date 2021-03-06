#include <parser_Ativo.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  TAtivo pkt;

  // definindo os valores de varios campos 
  TAtivo::Choice_id & id = pkt.get_id();
  id.set_nome("PETR3");
 
  //pkt.set_codigo(111);
  pkt.set_valor(1298);
  //pkt.set_nome( "PETR3");
  pkt.set_data("30092015");
  pkt.set_horario("135812");

  // verifica se os valores contidos na estrutura de dados respeitam
  // a especificação
  pkt.check_constraints();

  // mostra a estrutura de dados na tela
  cout << "Estrutura de dados em memória (antes de codificação XER):" << endl;
  pkt.show();

  // cria o codificador
  ofstream out("pkt.data");
  TAtivo::DerSerializer encoder(out);

  // codifica a estrutura de dados
  encoder.serialize(pkt);
  out.close();

  // cria o decodificador
  ifstream arq("pkt.data");
  TAtivo::DerDeserializer decoder(arq);

  // tenta decodificar uma estrutura de dados
  TAtivo * other = decoder.deserialize();
  arq.close();

  cout << endl;

  if (other) {
    cout << "Estrutura de dados obtida da decodificação XER:" << endl;
    other->show();
  } else cerr << "Erro: não consegui decodificar a estrutura de dados ..." << endl;

  // devem-se destruir explicitamente as estruturas de dados obtidas 
  // do decodificador 
  delete other; 
}
