/**
* @file thread_test.cpp
* @date 2017
* @brief Performance comparing tool for std::async and thread pool based on std::thread
*
*/

#include "thread_pool.h"

#include <chrono>
#include <thread>
#include <future>
#include <iostream>
#include <stdexcept>

extern void do_nothing();


template <typename T>
long long unsigned int calls_per_second(const T &thecall, unsigned int interval)
{
	auto now = []() -> auto {
		return ::std::chrono::high_resolution_clock::now();
	};
	typedef ::std::chrono::duration<long double> timediff_t;
	unsigned long long count = 0;
	const auto start = now();

	long double curtime_as_ldbl = (timediff_t(now() - start)).count();
	while (curtime_as_ldbl < interval) {
		thecall();
		++count;
		curtime_as_ldbl = (timediff_t(now() - start)).count();
	}
	return count / interval;
}

int main()
{
	ThreadPool thread_pool(0);

	std::cout << "Do nothing calls per second: " << calls_per_second([]() {}, 5) << std::endl;
	std::cout << "Empty calls per second: " << calls_per_second([]() { do_nothing(); }, 5) << std::endl;

	std::cout << "New thread calls per second: "
		<< calls_per_second([]() { std::thread t{ do_nothing }; t.join(); }, 5)
		<< std::endl;
	
	std::cout << "std::async launch calls per second: " 
		<< calls_per_second([]() { auto future = std::async(std::launch::async | std::launch::deferred, do_nothing);
							    future.wait(); }, 5 ) 
		<< std::endl;

	std::cout << "thread_pool launch calls per second: " 
		<< calls_per_second([&thread_pool]() { auto result = thread_pool.enqueue(&do_nothing);
											   result.wait(); }, 5) 
		<< std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(10));
	return 0;
}
