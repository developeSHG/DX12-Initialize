#pragma once

// [기안서]
// 외주를 맡길 때 이런 저런 정보들을 같이 넘겨줘야 하는데,
// 아무 형태로나 요청하면 못 알아먹는다
// - 각종 리소스를 어떤 용도로 사용하는지 꼼꼼하게 적어서 넘겨주는 용도 (표준규격양식)
// DX11까지는 View 라는 용어로 활용했다.
// 12로 넘어오면서 DescriptorHeap 이라 불림.
class DescriptorHeap // View
{
	// GPU한테 요청할 때, 리소스 자체를 팍 넘겨주는 게 아니라
	// 리소스를 한 번 더 매핑해서 리소스가 무엇인지 적은 기안서를 건네준다고 보면 된다.
public:
	void Init(ComPtr<ID3D12Device> device, shared_ptr<class SwapChain> swapChain);

	D3D12_CPU_DESCRIPTOR_HANDLE		GetRTV(int32 idx) { return _rtvHandle[idx]; }
	D3D12_CPU_DESCRIPTOR_HANDLE		GetBackBufferView();

private:
	ComPtr<ID3D12DescriptorHeap>	_rtvHeap;
	uint32							_rtvHeapSize = 0;
	D3D12_CPU_DESCRIPTOR_HANDLE		_rtvHandle[SWAP_CHAIN_BUFFER_COUNT];

	shared_ptr<class SwapChain>		_swapChain;
};