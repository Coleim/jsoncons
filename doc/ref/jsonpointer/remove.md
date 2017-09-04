### jsoncons::jsonpointer::remove

Removes a `json` element.

#### Header
```c++
#include <jsoncons_ext/jsonpointer/jsonpointer.hpp>

template<class Json>
Json remove(const Json& root, typename Json::string_view_type path)
```

### Examples

#### Remove an array element

```c++
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpointer/jsonpointer.hpp>

using namespace jsoncons;

int main()
{
    json target = json::parse(R"(
        { "foo": [ "bar", "qux", "baz" ] }
    )");

    try
    {
        jsonpointer::remove(target, "/foo/1");
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
{"foo":["bar","baz"]}
```

