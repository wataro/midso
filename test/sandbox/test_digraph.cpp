#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

template<typename T_>
using Vector = std::vector<T_>;

template<typename T1_, typename T2_>
using Pair = std::pair<T1_, T2_>;

template<typename T_>
class Layer
{
    public:
    typedef T_ Value;
    Layer(const T_ & value): value_(value) {}
    const T_ & output(void) const { return this->value_; }

    void set_input(const T_ & value)
    {
        this->input_values_.push_back(value);
    }
    void propagate(void)
    {
        for(auto v: this->input_values_) {
            std::cout << this->value_ << " <- " << v << std::endl;
        }
        this->input_values_.clear();
    }
    private:
    Vector<Value> input_values_;
    Value value_;
};

template<typename T_>
class Digraph
{
    public:
    typedef T_* Item;
    typedef Pair<Item, Item> Arc;
    typedef Pair<Item, Vector<Item>> Vertex;
    struct VertexFind {
        VertexFind(const Item key): key_(key){}
        Item key_;
        bool operator()(const Vertex & v)
        {
            return this->key_ == v.first;
        }
    };
    Digraph(Vector<Arc> & arcs) : arcs_(arcs)
    {
        this->build_dependencies();
    }

    void propagate()
    {
        for(auto vertex: this->vertices_) {
            for(auto depend: vertex.second) {
                vertex.first->set_input(depend->output());
            }
            vertex.first->propagate();
        }
    }
    private:
    void build_dependencies()
    {
        if (this->arcs_.empty()) {
            return;
        }
        Item & root = this->arcs_.front().first;
        this->vertices_.push_back(Vertex(root, Vector<Item>(1, root)));
        for(auto arc: this->arcs_) {
            auto key = arc.second;
            auto value = arc.first;
            auto it = std::find_if(this->vertices_.begin(), this->vertices_.end(), VertexFind(key));
            if (this->vertices_.end() == it) {
                this->vertices_.push_back(Vertex(key, Vector<Item>(1, value)));
            }
            else
            {
                it->second.push_back(value);
            }
        }
    }
    Vector<Arc> arcs_;
    Vector<Vertex> vertices_;
};

TEST(SANDBOX, DIGRAPH)
{
    /*
     * [0] -- [1] --+-- [2] -- [4] --+-- [5]
     *              |                |
     *              +-- [3] ---------+
     * */
    Layer<char> layers[] = {'0', '1', '2', '3', '4', '5'};
    Digraph<Layer<char>>::Arc arc_array[] = {
        std::make_pair(layers + 0, layers + 1),
        std::make_pair(layers + 1, layers + 2),
        std::make_pair(layers + 1, layers + 3),
        std::make_pair(layers + 2, layers + 4),
        std::make_pair(layers + 3, layers + 5),
        std::make_pair(layers + 4, layers + 5),
    };
    Vector<typename Digraph<Layer<char>>::Arc> arcs;
    arcs.push_back(arc_array[0]);
    arcs.push_back(arc_array[1]);
    arcs.push_back(arc_array[2]);
    arcs.push_back(arc_array[3]);
    arcs.push_back(arc_array[4]);
    arcs.push_back(arc_array[5]);
    Digraph<Layer<char>> digraph(arcs);
    digraph.propagate();
}

