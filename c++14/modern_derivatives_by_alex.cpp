#include <iostream>
#include <cmath>


template <size_t N>
auto deriv2 = [] (auto f, auto x, auto h) {
	auto prev = [&] (auto x2) {
		return deriv2<N-1>(f, x2, h);
	};
	return (prev(x+h) - prev(x)) / h;
};

template <>
auto deriv2<0> = [] (auto f, auto x, auto h) {
	return f(x);
};

int main()
{
    auto f = [] (double x) { return 2.0 * std::cos(x) + x*x; };

    std::cout << "f''(1) = " << deriv2<2>(f, 1.0, 1e-3) << std::endl;
    std::cout << "f(5)(1) = " << deriv2<5>(f, 1.0, 1e-3) << std::endl;

    return 0;
}
