#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

class Spell {
public:
    int powerSpell;
    int manaSpell;
    Spell(int power, int mana) : powerSpell(power), manaSpell(mana) {};
};

bool operator < (const Spell& left, const Spell& right) {
    return left.manaSpell < right.manaSpell;
}
struct spellComp {
    bool operator()(const Spell& left, const Spell& right) {
        if (left.powerSpell == right.powerSpell) {
            return left.manaSpell > right.manaSpell;
        }
        else return left.powerSpell < right.powerSpell;
    }
};

int main()
{
    std::vector<Spell> it;
    srand(time(0));
    it.push_back(Spell(rand() % 100 + 1, rand() % 100 + 1));
    it.push_back(Spell(rand() % 100 + 1, rand() % 100 + 1));
    it.push_back(Spell(rand() % 100 + 1, rand() % 100 + 1));

    sort(it.begin(), it.end());
    std::cout << "Sorted by mana : " << "\n\n";
    for (const auto& spell : it) {
        std::cout << "Power: " << spell.powerSpell << " ; Mana: " << spell.manaSpell << std::endl;
    }
    std::cout << "\n";
    sort(it.begin(), it.end(), spellComp());
    std::cout << "Sorted by power : " << "\n\n";
    for (const auto& spell : it) {
        std::cout << "Power: " << spell.powerSpell << " ; Mana: " << spell.manaSpell << std::endl;
    }
    return 0;
}