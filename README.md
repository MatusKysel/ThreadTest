# ThreadTest
Benchmark tool to test performance of std::async vs threadpool based on std::thread
## Resulsts
### Windows
Do nothing calls per second: 37126616
Empty calls per second: 37690612
New thread calls per second: 1651
std::async launch calls per second: 206341
thread_pool launch calls per second: 554437
### Linux
