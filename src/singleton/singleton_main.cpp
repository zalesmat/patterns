#include "singleton.h"

using namespace mz::patterns;

int main()
{
    Singleton::get_instance().print_msg("Hello from singleton!\n");

    return 0;    
}