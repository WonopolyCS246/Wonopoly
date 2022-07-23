#include <iostream>
#include <vector>
#include <string>

class Property
{
};

class Ownable : public Property
{
};

std::vector<int> V;
int main()
{
    V.push_back(1);
    V.push_back(2);

    V.erase(V.begin() + 0);

    for (int i = 0; i < V.size(); i++)
    {
        std::cout << V[i] << std::endl;
    }
    // V.emplace_back(new int{5});
    // this is to create a vector of pointers to ints
    return 0;
}
