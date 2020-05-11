/*
    Use PIMPL idiom to reduce dependencies of given class compilation
    and its clients and therefore reduce the compilation times in large
    projects.
*/

#ifndef MZ_PATTERNS_PIMPL_H_
#define MZ_PATTERNS_PIMPL_H_

#include <memory>

namespace mz {
namespace patterns {


class PimplUser
{
public:
    PimplUser();
    ~PimplUser();

    PimplUser(PimplUser&&);
    PimplUser& operator=(PimplUser&&);

    PimplUser(PimplUser const& other);
    PimplUser& operator=(PimplUser const& other);
private:
    class mz_pimpl;
    std::unique_ptr<mz_pimpl> pimpl_;
};
    
} // namespace patterns    
} // namespace mz 


#endif  // !MZ_PATTERNS_PIMPL_H_
