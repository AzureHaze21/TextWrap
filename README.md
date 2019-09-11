# TextWrap

```cpp
int main()
{
	constexpr char txt[] = R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi sit amet nunc eleifend, dapibus urna eget, faucibus tellus. Sed a hendrerit velit. Aenean vel molestie libero. Vestibulum maximus purus quis ullamcorper viverra. Vestibulum ullamcorper viverra dolor at iaculis. Ut fermentum velit non arcu cursus dignissim. Etiam eleifend quam sed purus posuere ultrices.)";
	constexpr auto lines = textwrap::wrap<16>(txt);

	for (auto& line : lines)
	{
    //
  }

	return 0;
}
```
