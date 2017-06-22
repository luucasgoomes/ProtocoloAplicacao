#include <string>
#include <list>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "API_serv.h"
#include <parser_Mensagem.h>


using namespace std;

int cria_servidor(){
  TCPServerSocket server("191.36.11.106",8000);  
  while(true){
         try {
            // aguarda uma nova conexão ou dados em 
            //uma conexão existente
            Connection & sock = server.wait(0);

            string addr;
            unsigned short port;

            // obtém o IP e port do socket da outra ponta da 
            // conexão
            sock.get_peer(addr, port);  
            
             string data = sock.recv(1024);

            // conseguiu ler algo desse socket ...
            if (data.size()) decodificador(data);
         
         } catch (TCPServerSocket::DisconnectedException e) {
            // esta exceção informa que uma conexão foi encerrada
            // o socket correspondente foi invalidado automaticamente
            cout << e.what() << ": " << e.get_addr() << ':';
            cout << e.get_port()<< endl;
        }
            
            
  }
}
int codificador(){}
int decoficador(string data){

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
		  cout<<"inicio"<<endl;
		  TAcessar acesso =tipo.get_acess();
		  
		  cout<<"usuario: "<< acesso.get_acess()<<endl;
		}else if(tipo.get_choice() ==msg_PR_word){
		  cout<<"Dados"<<endl;  
		} 
	}   
}  
int finaliza_conexao(){}
int envia(){}

main(){
  cria_servidor();


}
