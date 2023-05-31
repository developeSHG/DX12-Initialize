#pragma once

// 인력 사무소인 클래스
// 예전 DX9 때는 Device라는 클래스에서 거의 모든 기능을 담당했는데, 조금씩 버전이 올라가면서 기능이 쪼개져있다.
class Device
{
public:
	void Init();

public:
	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
	

private:
	// DirectX 자체는 GPU를 제어하고, 프로그래밍 하는데 쓰이는 저수준 그래픽 API
	
	// COM(Component Object Model)
	// - DX의 프로그래밍 언어 독립성과 하위 호환성을 가능하게 하는 기술
	// - COM 객체(COM 인터페이스)를 사용. 세부사항은 우리한테 숨겨짐
	// - ComPtr 일종의 스마트 포인터
	ComPtr<ID3D12Debug>			_debugController;
	ComPtr<IDXGIFactory>		_dxgi; // 화면 관련 기능들
	ComPtr<ID3D12Device>		_device; // 각종 객체 생성
};

