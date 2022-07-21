#include "Trie.h"

int main()
{
    Trie trie({{"looked"}, {"just"}, {"like"}, {"her"}, {"brother"}});
    std::string res = trie.insertSpaces("jesslookedjustliketimherbrother");
    std::cout << "RES = " << res << '\n';
    return 0;
}
