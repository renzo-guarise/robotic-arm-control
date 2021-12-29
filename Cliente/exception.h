
#include <iostream>

using namespace std;
class error{

    public:

        error(int motivo);
        const char *what(void) const throw();

    private:

        int motivo;
};