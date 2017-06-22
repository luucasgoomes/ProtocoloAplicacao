#include <string>
#include <list>
#include <sstream>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
//#include "API_serv.h"
#include <parser_Mensagem.h>
#include "TCPBaseSocket.h"
#include <iostream>
#include <cstdlib>

using namespace std;
TCPServerSocket server("191.36.11.37",8000);  
enum estado{aguarda_conexao,preparando_jogo,aguarda_letra,finaliza_jogo};

list<Connection*> client_list;
estado _Estado;

int decodificador(string data){

  // cria o decodificador
	istringstream inp(data);
	TMensagem::XerDeserializer decoder(inp);
	
	// tenta decodificar uma estrutura de dados
	TMensagem * other;
		
	while (other = decoder.deserialize()){
		cout << "Estrutura de dados obtida da decodificação XER:" << endl;
		//other->show();
		TMensagem::Choice_msg & tipo=other->get_msg();
		if(tipo.get_choice() == msg_PR_acess){
		  cout<<"Acesso"<<endl;
		  TAcessar acesso =tipo.get_acess();
		  
		  cout<<"usuario: "<< acesso.get_acess()<<endl;
		}else if(tipo.get_choice() ==msg_PR_palavra){
		  cout<<"Dados"<<endl;  
		} 
	}
	
	   
} 

int cria_servidor(){
  TMensagem pkt;
  
  
  while(true){
         try {
            // aguarda uma nova conexão ou dados em 
            //uma conexão existenteonnection
            Connection & sock = server.wait(0);
            string addr;
            unsigned short port;

            if (sock.isNew()) client_list.push_back(&sock);
            
            // obtém o IP e port do socket da outra ponta da 
            // conexão
            sock.get_peer(addr, port);  
            TMensagem::Choice_msg & msg = pkt.get_msg();
            pkt.set_id(8);
            TAcessar acess = msg.get_acess();
            acess.set_acess(1);
            
            pkt.check_constraints();
            pkt.show();
            
         	  ostringstream out;
            TMensagem::XerSerializer encoder(out);
            encoder.serialize(pkt);	
            sock.send(out.str());
            return 1;

                  
            
         
         } catch (TCPServerSocket::DisconnectedException e) {
            // esta exceção informa que uma conexão foi encerrada
            // o socket correspondente foi invalidado automaticamente
            cout << e.what() << ": " << e.get_addr() << ':';
            cout << e.get_port()<< endl;
        }
            
            
  }
}
void inicial(){

TMensagem pkt,pkt1;
TMensagem::Choice_msg & msg = pkt.get_msg();
      pkt.set_id(8);
      TInformacao info = msg.get_info();
      info.set_info("Novo jogo iniciando, aguarde...");
      
      pkt.check_constraints();
      pkt.show();
      
   	  ostringstream out;
      TMensagem::XerSerializer encoder(out);
      encoder.serialize(pkt);
      Connection *jogador1 = *client_list.begin();
      jogador1->send(out.str());
     
      Connection *jogador2  = *client_list.rbegin();
      jogador2->send(out.str());


}
void inicial2(){
TMensagem pkt,pkt1;
string palavra_atualizada ="bolacha";

Connection *jogador1 = *client_list.begin();
Connection *jogador2  = *client_list.rbegin();
      int tamanho = palavra_atualizada.size();
      cout<<tamanho<<endl;
      int t=tamanho+tamanho -1;
      string nova="-------";

      TMensagem::Choice_msg & msg1 = pkt1.get_msg();  
      pkt1.set_id(9);
      TPalavra palavra = msg1.get_palavra();
      palavra.set_palavra(nova);
      pkt1.check_constraints();
      pkt1.show();
      ostringstream out1;
      TMensagem::XerSerializer encoder1(out1);
      encoder1.serialize(pkt1);
      cout<<"aqui2"<<endl;
      
     
      jogador1->send(out1.str());
      jogador2->send(out1.str());



}

void envia_permissao(int jogador, int pontos, int perm){
  TMensagem pkt,pkt1;
  Connection *jogador1 = *client_list.begin();
  Connection *jogador2  = *client_list.rbegin();

  TMensagem::Choice_msg & msg1 = pkt1.get_msg();  
  pkt1.set_id(9);
  TPermissao permission = msg1.get_permission();
  permission.set_permissao(perm);
  permission.set_pontuacao(pontos);
  
  pkt1.check_constraints();
  pkt1.show();
  ostringstream out1;
  TMensagem::XerSerializer encoder1(out1);
  encoder1.serialize(pkt1);
  cout<<"aqui2"<<endl;
  
  if(jogador==1) jogador1->send(out1.str());
  if(jogador==2) jogador2->send(out1.str());


}

int maquina(estado tipo){
  switch(tipo){
  case aguarda_conexao:
  
    cria_servidor();
    if(server.get_num_connections()>=2){
        inicial();
        inicial2();
      
      _Estado=preparando_jogo;
    }else _Estado=aguarda_conexao;
    
  
  break;
 
  
  
  case preparando_jogo:{
  
  envia_permissao(1,10,0);
  envia_permissao(2,10,1);
    
 
  
 
    
    
   
    
    
    
  break;
  }
  case aguarda_letra :
  
  break;
  case finaliza_jogo:
  
  break;
  default:

  break;
  }
}

int codificador(){}

int finaliza_conexao(){}
int envia(){}

int main(){
  _Estado=aguarda_conexao;
  while(1) maquina(_Estado);

  return 1;
}
