/**
 * Threads that waste CPU cycles
 */
#include <thread>
#include <chrono>
#include <unistd.h>

// a simple function that wastes CPU cycles "forever"
void CpuWaster() {
    printf("CPU Waster Process ID: %d\n", getpid());
    printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
    while(true) continue;
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %d\n", std::this_thread::get_id());
    std::thread thread1(CpuWaster);
    std::thread thread2(CpuWaster);

    while(true) { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}