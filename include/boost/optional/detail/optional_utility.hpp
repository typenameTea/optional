#ifndef BOOST_OPTIONAL_OPTIONAL_DETAIL_OPTIONAL_UTILITY_HPP
#define BOOST_OPTIONAL_OPTIONAL_DETAIL_OPTIONAL_UTILITY_HPP

namespace boost {
namespace optional_detail {

// Workaround: forward and move aren't constexpr in C++11
template <class T> inline constexpr T&& constexpr_forward(typename boost::remove_reference<T>::type& t) noexcept
{
  return static_cast<T&&>(t);
}

template <class T> inline constexpr T&& constexpr_forward(typename boost::remove_reference<T>::type&& t) noexcept
{
  static_assert(!boost::is_lvalue_reference<T>::value, "!!");
  return static_cast<T&&>(t);
}

template <class T> inline constexpr typename boost::remove_reference<T>::type&& constexpr_move(T&& t) noexcept
{
  return static_cast<typename boost::remove_reference<T>::type&&>(t);
}

} // namespace optional_detail
} // namespace boost

#endif
