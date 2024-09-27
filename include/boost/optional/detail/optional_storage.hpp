#ifndef BOOST_OPTIONAL_OPTIONAL_DETAIL_OPTIONAL_STORAGE_HPP
#define BOOST_OPTIONAL_OPTIONAL_DETAIL_OPTIONAL_STORAGE_HPP

#include <boost/optional/detail/optional_utility.hpp>

namespace boost {
namespace optional_detail {

constexpr struct trivial_init_t{} trivial_init{};

template <class T>
union storage_t
{
    unsigned char dummy_;
    T value_;

    storage_t( trivial_init_t ) noexcept : dummy_() {};

    template <class... Args>
    storage_t( Args&&... args ) : value_(constexpr_forward<Args>(args)...) {}

    ~storage_t(){}
};

template <class T>
union constexpr_storage_t
{
    unsigned char dummy_;
    T value_;

    constexpr constexpr_storage_t( trivial_init_t ) noexcept : dummy_() {};

    template <class... Args>
    constexpr constexpr_storage_t( Args&&... args ) : value_(constexpr_forward<Args>(args)...) {}
};

} // namespace optional_detail
} // namespace boost

#endif
