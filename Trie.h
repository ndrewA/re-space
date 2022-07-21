#ifndef TRIE_H
#define TRIE_H

#include <iostream>

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>

struct Node
{
    char nodeLetter;
    std::unordered_map<char, std::shared_ptr<Node>> nextLetters;
    bool isEnd;
    Node() : isEnd(false) {}
};

class Trie
{
    private:
        std::shared_ptr<Node> root;

    public:
        Trie(const std::unordered_set<std::string>& dictionary);
        ~Trie() {}
        std::string insertSpaces(const std::string& text);

    private:
        std::shared_ptr<Node> getNext(const std::shared_ptr<Node>& curNode, const char& target);
};

#endif // TRIE_H
