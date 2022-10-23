/**
 * Two shoppers adding garlic and potatoes to a shared notepad
 * solved by using mutex and mutual exclusion
 */
#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
unsigned int potato_count = 0;
std::mutex pencil;

void add_garlic() {
    garlic_count++;
}

void add_potato() {
    potato_count++;
    add_garlic();
}

void shopper() {
    for (int i=0; i<10000000; i++) {
        // execute under lock
        pencil.lock();
        add_garlic();
        pencil.unlock();
        // execute under lock
        pencil.lock();
        add_potato();
        pencil.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}