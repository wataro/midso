#include "gtest/gtest.h"
#include <algorithm>
#include <memory>
#include <vector>

template<typename T_>
using Vector = std::vector<T_>;

template<typename T1_, typename T2_>
using Pair = std::pair<T1_, T2_>;

template<typename T_>
using Pointer = std::shared_ptr<T_>;

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
struct Vertex_
{
    typedef T_ Item;
    typedef Vertex_<Item> Vertex;
    Vertex_(Item key, Item value): key_(key), depends_(1, value){}
    Item key_;
    Vector<Item> depends_;
};

template<typename T_>
class Digraph
{
    public:
    typedef T_* Item;
    typedef Pair<Item, Item> Arc;
    typedef Vertex_<Item> Vertex;
    Digraph(Vector<Arc> & arcs) : arcs_(arcs)
    {
        this->build_dependencies();
    }

    Vector<Vertex> & vertices() {
        return this->vertices_;
    }
    static Vector<Arc> reversed_arcs(Vector<Arc> & arcs)
    {
        Vector<Arc> arcs_rev(arcs.rbegin(), arcs.rend());
        for(auto & arc: arcs_rev) {
            std::swap(arc.first, arc.second);
        }
        return arcs_rev;
    }
    private:
    void build_dependencies()
    {
        if (this->arcs_.empty()) {
            return;
        }
        for(auto arc: this->arcs_) {
            auto key = arc.second;
            auto it = std::find_if(this->vertices_.begin(), this->vertices_.end(),
                                   [key](const Vertex & v) { return v.key_ == key; });
            if (this->vertices_.end() == it) {
                auto value = arc.first;
                this->vertices_.push_back(Vertex(key, value));
            }
            else
            {
                auto value = arc.first;
                it->depends_.push_back(value);
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
    for(auto vertex: digraph.vertices()) {
        for(auto depend: vertex.depends_) {
            vertex.key_->set_input(depend->output());
        }
        vertex.key_->propagate();
    }
    arcs = Digraph<Layer<char>>::reversed_arcs(arcs);
    Digraph<Layer<char>> digraph_rev(arcs);
    for(auto vertex: digraph_rev.vertices()) {
        for(auto depend: vertex.depends_) {
            vertex.key_->set_input(depend->output());
        }
        vertex.key_->propagate();
    }
}

