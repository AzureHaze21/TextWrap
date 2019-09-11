#include <array>

namespace textwrap
{
	template<std::size_t Row, std::size_t StrLen, typename Data, std::size_t... Cols >
	constexpr int wrap_store(Data& data, const char* str, std::size_t& pos, std::index_sequence<Cols...>)
	{
		([&]() { data[Row][Cols] = str[(Cols + (sizeof...(Cols) * Row)) > StrLen ? StrLen : (Cols + (sizeof...(Cols) * Row))]; return 0; }() + ...);
		return 0;
	}

	template<std::size_t Width, std::size_t StrLen, std::size_t... Rows, typename Data>
	constexpr int wrap_impl(Data& data, const char* str, std::index_sequence<Rows...>)
	{
		std::size_t pos{ 0 };
		int l[] = { (wrap_store<Rows, StrLen>(data, str, pos, std::make_index_sequence<Width>{}))... };
		return 0;
	}

	template<std::size_t Width = 70U, typename T, std::size_t N>
	constexpr decltype(auto) wrap(const T(&str)[N])
	{
		static_assert(Width > 0);

		constexpr auto Length = Width > (N - 1) ? (N - 1) : Width;
		constexpr auto Height = (Length == (N - 1)) ? 1 : ((N - 1) / Length) + ((N - 1) - ((N - 1) / Length) > 0 ? 1 : 0);

		using Line = std::array<char, Length + 1>; // '\0'
		using List = std::array<Line, Height>;

		List data{};
		wrap_impl<Length, N - 1>(data, str, std::make_index_sequence<Height>{});

		return data;
	}
}
