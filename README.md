# ThreadTest
Benchmark tool to test performance of std::async vs threadpool based on std::thread and different type of thread pool implementations.
### Resulsts
|  | MSVC 2015 | GCC 5.4 |
|--|--|--|
| Empty (calls per second) | 37635123 | 21725218
| do_nothing (calls per second) | 38112312 | 21965254
| New thread (calls per second) | 1659 | 23394
| std::async (calls per second) | 214311 | 3700371
| thread_pool (calls per second) | 446931 | 27878
| ctpl (calls per second) | 357280 | 22470
| DefaultThreadPool C++14 (calls per second) | 777329 | 63571

Test results are not from same cpu.
