#include <stdio.h>
#include "singleton.h"

namespace mz {
namespace patterns {

Singleton& Singleton::get_instance() noexcept
{
    static Singleton instance;
    return instance;
}

void Singleton::print_msg(char const* msg) const noexcept
{
    printf("%s", msg);
}

}  // namespace patterns
}  // namespace mz