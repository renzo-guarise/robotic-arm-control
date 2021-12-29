#include "cmdCliente.h"
#include "exception.h"

cmd::cmd(XmlRpcClient c,XmlRpcValue Args){


    if (c.execute("system.listMethods", Args, result)){

      ss << result ;
      string aux=ss.str();
      aux.erase(0,1);
      aux.erase(aux.size()-1,1);
      stringstream check1(aux); 
      string intermediate; 

      while(getline(check1,intermediate,',')){ 
          comandos.push_back(intermediate); 
      } 
      comandos.push_back("exit");
      comandos.push_back("help");
    }else{
        //Si no se encuentra conectado el servidor sale del programa
        throw error(1);
    }

}
void cmd::serviciosservidor(void){
    std::cout << "----------------------------------------------------------------------------------\n--------------------------------- CMD CLIENTE ------------------------------------\n----------------------------------------------------------------------------------\n";
    std::cout << "\n\n Los servicios del servidor son:" << "\n\n";
    for(size_t i = 0; i < comandos.size()-5; i++) {
        std::cout << ": "<< comandos[i] << '\n';
    }
    std::cout << ": exit" <<"\n";
    std::cout << ": help" <<"\n\n";
    std::cout << "Ante la duda consulte el metodo help"<<"\n\n";
    std::cout << "Ingrese el servicio deseado..." << "\n\n";
}


XmlRpcValue cmd::pintar(){

    XmlRpcValue Args;
    char args[20],args2[20],args3[20];
    std::cout<<"\nIngrese la posicion inicial 'x,y,z'\n? ";
    std::cin.getline(args,40);
    std::cout<<"\nIngrese la posicion final 'x,y,z'\n? ";
    std::cin.getline(args2,40);
    std::cout<<"\nIndique si desea pintar en el trayecto [s/n]\n? ";
    std::cin.getline(args3,40);
    Args[0]=args;
    Args[1]=args2;
    Args[2]=args3;
    return Args;

}
XmlRpcValue cmd::irposicion(void){

    XmlRpcValue Args;
    char args[20];
    std::cout<<"\nIngrese la posicion a la que desea ir\n? ";
    std::cin.getline(args,40);
    Args[0]=args;
    return Args;

}

XmlRpcValue cmd::modoautomatico(void){

    XmlRpcValue Args;
    char args[20];
    std::cout<<"\nIngrese la posicion a la que desea ir\n? ";
    std::cin.getline(args,40);
    Args[0]=args;
    return Args;

}
XmlRpcValue cmd::setcolor(void){

    XmlRpcValue Args;
    char args[20];
    std::cout<<"\nIngrese el color\n? ";
    std::cin.getline(args,40);
    Args[0]=args;
    return Args;

}

void cmd::help(XmlRpcClient c,bool aux_e,XmlRpcValue Args2){

    XmlRpcValue Args;
    char args[20];

    if(aux_e){
        for(size_t i = 0; i < comandos.size()-5; i++) {
            std::cout << ": "<< comandos[i] << '\n';
        }
        std::cout<<"\nIngrese el nombre del comando\n? ";
        std::cin.getline(args,40);
        Args[0]=args;
    }
    else{

        Args[0]=Args2[0];
    }
    aux_e=true;
    auto it = ss.str().find(string(Args[0]));

    if (it == std::string::npos) {
        throw error(2);
    }

    if (c.execute("system.methodHelp", Args, result))
        std::cout << "\nAyuda : " << result << "\n\n";
        else
            std::cout << "Error en la llamada a 'Help'\n\n";

}

bool cmd::buscarcomando(char *c){
    auto it = ss.str().find(c);
    if (it == std::string::npos) {
        throw error(2);
    }
    return true;
}
void cmd::enviarcomandos(XmlRpcClient c,char *e_token1,XmlRpcValue Args){
    if(c.execute(e_token1, Args, result)){
          std::cout << "\nComando enviado exitosamente" << endl;
          std::cout << result<< endl;
    }
    else{
          throw error(3);
        }
}