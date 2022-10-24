/**
 * Two philosophers, thinking and eating sushi
 * scoped mutex usage is to lock more than one mutex in one line
 * it will be automatically unlocked after the scope is done
 * while loop or any {} block is considered a scope, once it's done, the mutex is unlocked
 * two philosophers share a unique plate of sushi but only one pair of sticks
 * make sure both sticks (mutex) are locked before one takes turn to eat
 */
#include <thread>
#include <mutex>

int sushi_count = 500;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        std::scoped_lock lock(first_chopstick, second_chopstick);
        if (sushi_count) {
            sushi_count--;
        }
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}