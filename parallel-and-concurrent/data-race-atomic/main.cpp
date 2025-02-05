/**
 * Two shoppers adding items to a shared notepad
 * Data Race condition C++ demo
 * solved using atomic lock
 */
#include <cstdio>
#include <thread>
#include <atomic>

std::atomic<unsigned int> garlic_count = 0;

void shopper() {
    for (int i=0; i<10000000; i++) {
        garlic_count++;
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count.load());
}