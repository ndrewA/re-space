#include "Trie.h"

Trie::Trie(const std::unordered_set<std::string>& dictionary)
{
    root = std::make_shared<Node>();

    for(const std::string& word : dictionary)
    {
        std::shared_ptr<Node> curNode = root;

        for(const char& letter : word)
        {
            if(curNode->nextLetters.find(letter) == curNode->nextLetters.end())
            {
                std::shared_ptr<Node> newNode = std::make_shared<Node>();
                newNode->nodeLetter = letter;

                curNode->nextLetters.insert({letter, newNode});
            }

            curNode = curNode->nextLetters[letter];
        }

        curNode->isEnd = true;
    }
}

std::shared_ptr<Node> Trie::getNext(const std::shared_ptr<Node>& curNode, const char& target)
{
    if(curNode->nextLetters.find(target) == curNode->nextLetters.end()) return nullptr;

    else return curNode->nextLetters[target];
}

std::string Trie::insertSpaces(const std::string& text)
{
    std::string curText = "";

    for(size_t i = 0; i < text.size(); )
    {
        std::string lastWord = "";

        size_t j = i;

        std::string curWord = "";

        std::shared_ptr<Node> curNode = root;

        while(curNode && j < text.size())
        {
            curWord += text[j];

            curNode = getNext(curNode, text[j]);

            if(curNode && curNode->isEnd)
                lastWord = curWord;

            ++j;
        }

        if(!lastWord.empty())
        {
            if(curText.back() != ' ') curText += ' ';

            curText += (lastWord + " ");

            i += lastWord.size();

        } else {

            curText += curWord[0];

            ++i;
        }
    }

    if(curText.back() == ' ') curText.pop_back();

    return curText;
}
