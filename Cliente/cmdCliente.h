#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string.h>


using namespace std;

#include "XmlRpc.h"
using namespace XmlRpc;

using namespace std;

class cmd{

    public:
        cmd(XmlRpcClient c,XmlRpcValue Args);
        void help(XmlRpcClient c,bool aux_e,XmlRpcValue Args2);
        void serviciosservidor(void);
        XmlRpcValue pintar(void);
        XmlRpcValue irposicion(void);
        XmlRpcValue modoautomatico(void);
        XmlRpcValue setcolor(void);
        void enviarcomandos(XmlRpcClient c,char *e_token1,XmlRpcValue Args);
        bool buscarcomando(char *c);

    private:

        XmlRpcValue  result;
        vector <string> comandos; 
        stringstream ss;
        char entradac[20];
};