#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string.h>
#include "exception.h"
#include "cmdCliente.h"

using namespace std;

#include "XmlRpc.h"
using namespace XmlRpc;

int main(int argc, char* argv[])
{

    if (argc != 3){
        std::cerr<<"Uso: clienteServer adrressHost Port";
        return -1;
    }

    bool baux=true,aux_e=true;
    int port = atoi(argv[2]);
    XmlRpcClient c(argv[1], port);
    XmlRpcValue Args;
    cmd *consola;

    try{
        consola=new cmd(c,Args);
    }
    catch(error &e){ cerr << e.what()<< endl;return -1;}

    consola->serviciosservidor();

    char entrada[20]="1";
    while (entrada !="0"){

        XmlRpcValue Args;
        std::cout << "----------------------------------------------------------------------------------\n--------------------------------- CMD CLIENTE ------------------------------------\n----------------------------------------------------------------------------------\nCMD >>> ";
        std::cin.getline(entrada,40);
        if (string(entrada)=="exit"){
            cout << "Consola finalizada";
        return -1;
        }

        char *entrada_token1 = strtok(entrada," ");
        char *entrada_token2 = strtok(NULL," ");

        if (entrada_token2 !=NULL){
            int i=0;
            while (entrada_token2 !=NULL){
            Args[i]=entrada_token2;
            entrada_token2 = strtok(NULL," ");
            i++;
            }
            aux_e=false;
        }

        if(string(entrada_token1)=="pintar"){

            if(aux_e){
                Args=consola->pintar();
            }
            aux_e=true;
        }

        if(string(entrada_token1)=="irPosicion"){
            if(aux_e){
                Args=consola->irposicion();
            }
            aux_e=true;
        }

        if(string(entrada_token1)=="modoautomatico"){
            if(aux_e){
                Args=consola->modoautomatico();
            }
            aux_e=true;
        }

        if(string(entrada_token1)=="setColor"){
            if(aux_e){
                Args=consola->setcolor();
            }
            aux_e=true;
        }

        try{ 

            if(string(entrada_token1)=="help"){
                baux=false;
                consola->help(c,aux_e,Args);
                aux_e=true;
            }
        }
        catch(error &e){ cerr << e.what()<< endl;}
        if (baux){
      
            try{ 

                consola->buscarcomando(entrada_token1);
                consola->enviarcomandos(c,entrada_token1,Args);

            }
            catch(error &e){ cerr << e.what()<< endl;}
        }
        baux=true;
    }

}
