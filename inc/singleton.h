/*
    Use SINGLETON when project requires globally available object
    which shall be instantiated only once.
*/

#ifndef MZ_PATTERNS_SINGLETON_H_
#define MZ_PATTERNS_SINGLETON_H_

namespace mz {
namespace patterns {

class Singleton
{
public:
    static Singleton& get_instance() noexcept;

    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

    void print_msg(char const*) const noexcept;
private:
    Singleton() = default;
};

}  // namespace patterns
}  // namespace mz

#endif  // !MZ_PATTERNS_SINGLETON_H_