#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "xchainer/array.h"
#include "xchainer/cuda/cuda_backend.h"
#include "xchainer/device.h"
#include "xchainer/scalar.h"

namespace xchainer {
namespace cuda {

class CudaDevice : public Device {
public:
    CudaDevice(CudaBackend& backend, int index) : Device(backend, index) {}

    std::shared_ptr<void> Allocate(size_t bytesize) override;

    void MemoryCopyFrom(void* dst, const void* src, size_t bytesize, Device& src_device) override;

    void MemoryCopyTo(void* dst, const void* src, size_t bytesize, Device& dst_device) override;

    std::shared_ptr<void> TransferDataFrom(
            Device& src_device, const std::shared_ptr<void>& src_ptr, size_t offset, size_t bytesize) override;

    std::shared_ptr<void> TransferDataTo(Device& dst_device, const std::shared_ptr<void>& src_ptr, size_t offset, size_t bytesize) override;

    std::shared_ptr<void> FromHostMemory(const std::shared_ptr<void>& src_ptr, size_t bytesize) override;

    void Fill(const Array& out, Scalar value) override;

    void ArgMax(const Array& src, const std::vector<int8_t>& axis, const Array& out) override;

    void Sum(const Array& src, const std::vector<int8_t>& axis, const Array& out) override;

    void Copy(const Array& src, const Array& out) override;

    void Equal(const Array& lhs, const Array& rhs, const Array& out) override;

    void Exp(const Array& src, const Array& out) override;

    void Add(const Array& lhs, const Array& rhs, const Array& out) override;
    void Subtract(const Array& lhs, const Array& rhs, const Array& out) override;
    void Mul(const Array& lhs, Scalar rhs, const Array& out) override;
    void Mul(const Array& lhs, const Array& rhs, const Array& out) override;

    void IfLessElse(const Array& lhs, Scalar rhs, Scalar pos, const Array& neg, const Array& out) override;

    void Dot(const Array& lhs, const Array& rhs, const Array& out) override;

    void Log(const Array& x, const Array& out) override;

    void Synchronize() override;
};

}  // namespace cuda
}  // namespace xchainer
