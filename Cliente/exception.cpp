
#include "exception.h"

error::error(int motivo){
    this->motivo=motivo;
}

const char *error::what(void) const throw(){
    switch (motivo)
    {
    case 1:
        return "Error en la llamada a los servicios del servidor";
    case 2:
        return "El comando ingresado no es correcto";
    case 3:
        return "Error, llamando al comando";
    default:
        return "";
    }
}