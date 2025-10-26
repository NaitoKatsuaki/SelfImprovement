#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

/*****************************
* FrameBuffer.h
* �������o�b�t�@���w�ԁB
* �摜�p�̃o�b�t�@
*
******************************/

class FrameBuffer
{
public:
	//-------------------------------
	// �R���X�g���N�^
	explicit FrameBuffer(size_t size);
	~FrameBuffer();

	// �R�s�[�֎~
	FrameBuffer(const FrameBuffer&) = delete;
	FrameBuffer& operator=(const FrameBuffer&) = delete;

	// ���[�u�͋���
	FrameBuffer(FrameBuffer&& other) noexcept;
	FrameBuffer& operator=(FrameBuffer&& other) noexcept;

	// �f�[�^value�Ŗ��߂�
	void fill(uint8_t value);

	// �f�[�^�̕\��
	void print() const;
private:
	size_t _bufferSize;
	std::unique_ptr<uint8_t[]> _data;

};