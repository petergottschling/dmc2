#include <iostream>
#include <cmath>


template <size_t N>
auto deriv2 = [] (auto f, auto x, auto h) {
    if constexpr (N == 0) {
	return f(x);
    } else {
	auto prev = [&] (auto x2) { return deriv2<N-1>(f, x2, h); };
	return (prev(x+h) - prev(x)) / h;
    }
};

int main()
{
	auto f = [] (double x) { return 2.0 * std::cos(x) + x*x; };

	std::cout << deriv2<1>(f, 1.0, 1e-3) << std::endl;

	return 0;
}
 
