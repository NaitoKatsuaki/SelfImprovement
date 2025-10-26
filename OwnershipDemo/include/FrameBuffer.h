#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

/*****************************
* FrameBuffer.h
* メモリバッファを学ぶ。
* 画像用のバッファ
*
******************************/

class FrameBuffer
{
public:
	//-------------------------------
	// コンストラクタ
	explicit FrameBuffer(size_t size);
	~FrameBuffer();

	// コピー禁止
	FrameBuffer(const FrameBuffer&) = delete;
	FrameBuffer& operator=(const FrameBuffer&) = delete;

	// ムーブは許可
	FrameBuffer(FrameBuffer&& other) noexcept;
	FrameBuffer& operator=(FrameBuffer&& other) noexcept;

	// データvalueで埋める
	void fill(uint8_t value);

	// データの表示
	void print() const;
private:
	size_t _bufferSize;
	std::unique_ptr<uint8_t[]> _data;

};