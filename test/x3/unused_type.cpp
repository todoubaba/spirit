/*=============================================================================
    Copyright (c) 2019 Nikita Kniazev

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/

#include <boost/spirit/home/x3/support/unused.hpp>
#include <type_traits>

int main()
{
    using boost::spirit::x3::unused;
    using boost::spirit::x3::unused_type;

    unused_type unused_mut;
    static_assert(std::is_same<decltype((unused)), unused_type const&>::value, "");
    static_assert(std::is_same<decltype((unused_mut)), unused_type&>::value, "");
    static_assert(std::is_same<decltype(unused = 123), unused_type const&>::value, "");
    static_assert(std::is_same<decltype(unused = unused), unused_type const&>::value, "");
    static_assert(std::is_same<decltype(unused = unused_mut), unused_type const&>::value, "");
    static_assert(std::is_same<decltype(unused_mut = 123), unused_type&>::value, "");
    static_assert(std::is_same<decltype(unused_mut = unused), unused_type&>::value, "");
    static_assert(std::is_same<decltype(unused_mut = unused_mut), unused_type&>::value, "");
}
