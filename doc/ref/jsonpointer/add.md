### jsoncons::jsonpointer::add

Adds a `json` value.

#### Header
```c++
#include <jsoncons_ext/jsonpointer/jsonpointer.hpp>

template<class Json>
Json add(const Json& root, typename Json::string_view_type path, const Json& value)
```

### Examples

#### Add a member to an object

```c++
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpointer/jsonpointer.hpp>

using namespace jsoncons;

int main()
{
    json target = json::parse(R"(
    { "foo": "bar"}
    )");

    try
    {
        jsonpointer::add(target, "/baz", json("qux"));
        std::cout << target << std::endl;
    }
    catch (const parse_exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
```
Output:
```json
{"baz":"qux","foo":"bar"}
```

#### Add an element to an array

```c++
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpointer/jsonpointer.hpp>

using namespace jsoncons;

int main()
{
    json target = json::parse(R"(
    { "foo": [ "bar", "baz" ] }
    )");

    try
    {
        jsonpointer::add(target, "/foo/1", json("qux"));
        std::cout << target << std::endl;
    }
    catch (const parse_exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
```
Output:
```json
{"foo":["bar","qux","baz"]}
```

