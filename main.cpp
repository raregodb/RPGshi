#include "System/Game/Game.h"
#include "filesystem"


int main() {
    namespace fs = std::filesystem;
    std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Game();

    return 0;
}
