# ThreadTest
Benchmark tool to test performance of std::async vs threadpool based on std::thread
### Resulsts
|  | MSVC 2015 | GCC 5.4 |
|--|--|--|
| Empty (calls per second) | 37126616 | 21725218
| do_nothing (calls per second) | 37690612 | 21965254
| New thread (calls per second) | 1651 | 22635
| std::async (calls per second) | 206341 | 3642368
| thread_pool (calls per second) | 554437 | 148270

Test results are not from same cpu.
