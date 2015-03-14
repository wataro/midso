#include "gtest/gtest.h"
#include <vector>
#include <map>

template<typename T_>
using Vector = std::vector<T_>;

template<typename T1_, typename T2_>
using Pair = std::pair<T1_, T2_>;

template<typename Key_, typename Value_>
using Map = std::multimap<Key_, Value_>;

template<typename T_>
class Digraph
{
    public:
    typedef T_* Item;
    typedef Pair<T_*, T_*> Arc;
    typedef Pair<T_*, Vector<Arc>> Vertex;
    Digraph(Vector<Arc> & arcs) : arcs_(arcs)
    {
        this->build_dependencies();
    }

    void propagate()
    {
        for(auto depend: this->dependencies_) {
            std::cout << depend.first[0] << " <- " << depend.second[0] << std::endl;
        }
    }
    private:
    void build_dependencies()
    {
        if (this->arcs_.empty()) {
            return;
        }
        Item & root = this->arcs_.front().first;
        this->dependencies_.insert(std::make_pair(root, root));
        for(auto arc: this->arcs_) {
            this->dependencies_.insert(std::make_pair(arc.second, arc.first));
        }
    }
    Vector<Arc> arcs_;
    Map<Item, Item> dependencies_;
};

TEST(SANDBOX, DIGRAPH)
{
    /*
     * [0] -- [1] --+-- [2] -- [4] --+-- [5]
     *              |                |
     *              +-- [3] ---------+
     * */
    char vertices[] = {'0', '1', '2', '3', '4', '5'};
    Digraph<char>::Arc arc_array[] = {
        std::make_pair(vertices + 0, vertices + 1),
        std::make_pair(vertices + 1, vertices + 2),
        std::make_pair(vertices + 1, vertices + 3),
        std::make_pair(vertices + 2, vertices + 4),
        std::make_pair(vertices + 3, vertices + 5),
        std::make_pair(vertices + 4, vertices + 5),
    };
    Vector<typename Digraph<char>::Arc> arcs;
    arcs.push_back(arc_array[0]);
    arcs.push_back(arc_array[1]);
    arcs.push_back(arc_array[2]);
    arcs.push_back(arc_array[3]);
    arcs.push_back(arc_array[4]);
    arcs.push_back(arc_array[5]);
    Digraph<char> digraph(arcs);
    digraph.propagate();
}

