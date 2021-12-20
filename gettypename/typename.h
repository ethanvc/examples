#pragma once

#include <string_view>

template <typename T>
constexpr std::string_view GetTypeName(){
#ifdef _MSC_VER
	return msvc::GetTypeName<T>();
#else
	static_assert(false, "unsupport platform");
#endif
}

constexpr std::string_view kUnknownTypeName("UnknownTypeName");

namespace msvc {
	template <typename T>
	constexpr std::string_view GetTypeName() {
		std::string_view raw = __FUNCSIG__;
		std::string_view n = raw;
		auto pos = n.rfind(">(void)");
		if (n.npos == pos) return kUnknownTypeName;
		n = n.substr(0, pos);

		pos = n.find_last_of(":<");
		if (n.npos == pos) return kUnknownTypeName;
		++pos;
		n = n.substr(pos);
		return n;
	}
}
