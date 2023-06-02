#pragma once

// [계약서 / 결재]

// CPU [        ]    GPU [        ]
// 한국 [        ]   베트남 [       ]
// 외주를 보낸다고 하면 단순 "일만 하라" 라고 보낼 순 없다.
// 방식, 출처 등등 정보를 알려줘야 하는데 그런 계약서의 역할이 RootSignature 클래스.

class RootSignature
{
public:
	void Init();

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	void CreateSamplerDesc();
	void CreateRootSignature();

private:
	ComPtr<ID3D12RootSignature>	_signature;
	D3D12_STATIC_SAMPLER_DESC _samplerDesc;
};

