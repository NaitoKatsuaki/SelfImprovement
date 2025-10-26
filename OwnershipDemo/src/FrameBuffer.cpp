#include "FrameBuffer.h"

//-----------------------------------------------------
FrameBuffer::FrameBuffer(size_t size)
	: _data(new uint8_t[size]),
	_bufferSize(size)
{
	std::cout << "allocated buffer size of " << _bufferSize << " bytes\n";
}

//-----------------------------------------------------
FrameBuffer::~FrameBuffer()
{
	std::cout << "destroyed buffer by using share_ptr\n";
}

//-----------------------------------------------------
FrameBuffer::FrameBuffer(FrameBuffer&& other) noexcept
	: _data(std::move(other._data)), _bufferSize(other._bufferSize)
{
	other._bufferSize = 0;
	std::cout << "FrameBuffer moved(constructor)\n";
}

//-----------------------------------------------------
FrameBuffer& FrameBuffer::operator=(FrameBuffer && other) noexcept
{
	// thisポインタが引数のオブジェクトのアドレスと一致してない場合は別オブジェクト
	if (this != &other)
	{
		_data = std::move(other._data);
		_bufferSize = other._bufferSize;
		other._bufferSize = 0;
		std::cout << "FrameBuffer moved (assignment)\n";
	}

	return *this;
}

//-----------------------------------------------------
void FrameBuffer::fill(uint8_t value)
{
	std::fill_n(_data.get(), _bufferSize, value);
}

//-----------------------------------------------------
void FrameBuffer::print() const
{
	std::cout << "Buffer size: " << _bufferSize << "first 5 values: ";
	for (size_t i = 0; i < std::min<size_t>(_bufferSize, 5); ++i)
	{
		std::cout << static_cast<int>(_data[i]) << " ";
	}
	std::cout << "\n";
}
