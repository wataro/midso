namespace midso {

class TensorType
{
public:

    TensorType(
        const SizeType & d0 = 1,
        const SizeType & d1 = 1,
        const SizeType & d2 = 1,
        const SizeType & d3 = 1,
        const SizeType & d4 = 1,
        const SizeType & d5 = 1,
        const SizeType & d6 = 1,
        const SizeType & d7 = 1,
    );

    const SizeType n_dimensions(void) const
    {
        return this->dimensions_.size();
    }

    const SizeVectorType & dimensions(void) const
    {
        return this->dimensions_;
    }
    
private:

    SizeVectorType dimensions_; 
    FloatVectorType values_
    CudaMemoryType * cuda_values_;

};

} // namespace

