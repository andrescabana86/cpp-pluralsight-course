/**
 * Two shoppers adding items to a shared notepad
 * Data Race condition C++ demo
 * solved using mutex
 */
#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
std::mutex pencil;

void shopper() {
    for (int i=0; i<10000000; i++) {
        pencil.lock();
        garlic_count++;
        pencil.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
}