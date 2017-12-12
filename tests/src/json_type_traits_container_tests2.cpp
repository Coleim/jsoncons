// Copyright 2013 Daniel Parker
// Distributed under Boost license

#include <boost/test/unit_test.hpp>
#include <jsoncons/json.hpp>
#include <jsoncons/json_serializer.hpp>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <deque>
#include <forward_list>
#include <list>
#include <array>
#include <valarray>

namespace jsoncons {
    template <>
    struct json_type_traits<json,std::vector<std::pair<std::string,int>>>
    {
        static std::vector<std::pair<std::string,int>> as(const json& j)
        {
            std::vector<std::pair<std::string,int>> v;
            for (auto nv : j.object_range())
            {
                v.emplace_back(std::string(nv.key()),nv.value().as<int>());
            }

            return v;
        }
    };
}

using namespace jsoncons;

BOOST_AUTO_TEST_SUITE(json_type_traits_specialized)

BOOST_AUTO_TEST_CASE(test1)
{
    json j = json::object{ {"a",1},{"b",2} };
    auto v = j.as<std::vector<std::pair<std::string,int>>>();
    for (auto pr : v)
    {
        std::cout << pr.first << ", " << pr.second << std::endl;
    }
}

BOOST_AUTO_TEST_SUITE_END()


