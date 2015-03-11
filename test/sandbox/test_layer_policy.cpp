#include "gtest/gtest.h"

typedef float Tensor;
typedef float Float;
typedef int Yaml;

class LayerInterface {
 public:
    virtual ~LayerInterface() {};
    virtual void propagate(const LayerInterface & previous) = 0;
    virtual const Tensor & out_tensor(void) const = 0;
};

class LinearLayer : public LayerInterface
{
 public: 
    /*
     * Layer:
     *   type: LinearLayer
     *   args:
     *     mul: 0.5
     *     add: 0.2
     */
    static LinearLayer * load(const Yaml & config)
    {
        return new LinearLayer();
    }
    LinearLayer(const Float & mul = 1.0, const Float & add = 0.0)
    : mul_(mul), add_(add)
    {

    } 
    ~LinearLayer()
    {
    }
    void propagate(const LayerInterface & previous)
    {
        const Tensor & in_tensor = previous.out_tensor();
        out_tensor_ = in_tensor * this->mul_ + this->add_;
    }
    const Tensor & out_tensor(void) const { return out_tensor_; }
 private:
    const Float mul_;
    const Float add_;
    Tensor out_tensor_;
};


TEST(SANDBOX, LAYER_POLICY)
{
    LinearLayer l;
    LinearLayer l2;
    Tensor t = 1;
    l.propagate(l2);
}

