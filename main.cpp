#include "System/Game/Game.h"
#include "filesystem"


int main() {
    namespace fs = std::filesystem;
    std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    Game();

    return 0;
}
