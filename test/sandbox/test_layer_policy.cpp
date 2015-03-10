#include "gtest/gtest.h"

typedef float Tensor;

class LayerInterface {
 public:
    virtual ~LayerInterface() {};
    virtual void propagate(const LayerInterface & previous) = 0;
    virtual const Tensor & out_tensor(void) const = 0;
};

template<typename Policy_>
class LayerTemplate : public LayerInterface {
 public:
    ~LayerTemplate()
    {
    }
    void propagate(const LayerInterface & previous)
    {
        const Tensor & in_tensor = previous.out_tensor();
        Policy_::propagate(in_tensor, out_tensor_);
    }
    const Tensor & out_tensor(void) const { return out_tensor_; }
 private:
    Tensor out_tensor_;
};

class LinearPolicy {
 public:
    ~LinearPolicy() {}
    static void propagate(const Tensor & in_tensor, Tensor & out_tensor)
    {
    }
};

using LinearLayer = LayerTemplate<LinearPolicy>;

TEST(SANDBOX, LAYER_POLICY)
{
    LinearLayer l;
    LinearLayer l2;
    Tensor t = 1;
    l.propagate(l2);
}

