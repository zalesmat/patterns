#include "pimpl.h"

namespace mz {
namespace patterns {

class PimplUser::mz_pimpl
{
};

PimplUser::~PimplUser() = default;
PimplUser::PimplUser(PimplUser&&) = default;
PimplUser& PimplUser::operator=(PimplUser&&) = default;

PimplUser::PimplUser() : pimpl_(std::make_unique<mz_pimpl>())
{
}

PimplUser::PimplUser(PimplUser const& other) : pimpl_(std::make_unique<mz_pimpl>(*other.pimpl_))
{
}

PimplUser& PimplUser::operator=(PimplUser const& other)
{
    *pimpl_ = *other.pimpl_;
    return *this;
}

}  // namespace patterns
}  // namespace mz