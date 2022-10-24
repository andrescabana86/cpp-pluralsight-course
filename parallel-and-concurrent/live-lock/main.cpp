/**
 * Two philosophers, thinking and eating sushi
 * live lock could happen when threads are actively working for unlocking mutex
 * if all of them are doing it, no one will take both mutex
 * eventually you will be blocked in live execution
 */
#include <thread>
#include <mutex>

int sushi_count = 500;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        // create a manual unlock mechanism
        if (!second_chopstick.try_lock()) {
            // if other thread lock second, unlock first and let other thread take it
            first_chopstick.unlock();
            std::this_thread::yield(); // reschedule execution
        } else {
            if (sushi_count) {
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread steve(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread nikki(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    steve.join();
    nikki.join();
    printf("The philosophers are done eating.\n");
}