#include <parser_Mensagem.h>

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "TCPBaseSocket.h"
 
using namespace std;
TCPClientSocket client;

void envia_letra(string letra){
	 
	 TMensagem pkt;
	 TMensagem::Choice_msg & msg = pkt.get_msg();
	 pkt.set_id(1);
	 TLetra letter = msg.get_letter();
	 letter.set_letra(letra);
	 pkt.check_constraints();
	 ostringstream out;
	 TMensagem::XerSerializer encoder(out);
	 encoder.serialize(pkt);
	 client.send(out.str());
}

int decodificador(string data){

  // cria o decodificador
	istringstream inp(data);
	TMensagem::XerDeserializer decoder(inp);
	
	// tenta decodificar uma estrutura de dados
	TMensagem * other;
		
	while (other = decoder.deserialize()){
		//other->show();
		TMensagem::Choice_msg & tipo=other->get_msg();
		if(tipo.get_choice() == msg_PR_acess){
		  cout<<endl<<"Esperando adversário"<<endl;
		 // TAcessar acesso =tipo.get_acess();
		   // cout<<"usuario: "<< acesso.get_acess()<<endl;
		}else if(tipo.get_choice() ==msg_PR_info){
		  TInformacao info =tipo.get_info();
		  cout<<endl<<"=================================="<<endl
		  <<info.get_info()<<endl<<"=================================="<<endl;
		}else if(tipo.get_choice() ==msg_PR_palavra){
		  TPalavra palavra =tipo.get_palavra();
		  cout<<endl<<"=================================="<<endl<< "Descubra a palavra: "
		  <<palavra.get_palavra()<<endl;
		}else if(tipo.get_choice() == msg_PR_permission){
		  TPermissao permission = tipo.get_permission();
		  int check_vez = permission.get_permissao();
		  cout << check_vez << endl;
		  if (check_vez == 1){
		      cout << "Qual letra você escolhe?"<< endl;
          string letra;
   		    cin >> letra;
		      envia_letra(letra);	
		  }else cout << "Aguarde o adversário jogar ..." << endl;
		} 
	
	}   
	//delete other;
}   


int main() {

  TMensagem pkt;  
  
  client.connect("191.36.10.242",8000);
  cout <<"=================================="<<endl<<"Bem vindo ao Jogo"<<endl<<"=================================="<< endl;
  
  TMensagem::Choice_msg & msg = pkt.get_msg();

 
	while(1){
	char * buffer;
	string recebido = client.recv(1024);
	if (recebido.size()) {
	}
		decodificador(recebido);
		//cout << buffer<< endl;

  	}

}
