#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> weapons(n);
    int luckyCount = 0;
    int unluckyCount = 0;
    for (int i = 0; i < n; ++i) {
        
        std::cin >> weapons[i];
        if (weapons[i] % 2 == 0) {
            luckyCount++;
        } else {
            unluckyCount++;
            
        }
    }
    if (luckyCount > unluckyCount) {
        
        std::cout << "READY FOR BATTLE" << std::endl;
    } else {
        std::cout << "NOT READY" << std::endl;
    }
    return 0;
}