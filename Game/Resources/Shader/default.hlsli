

struct VS_IN
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

struct VS_OUT
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};

// 정점 변화에 대해 정보를 고치는 단계 
VS_OUT VS_Main(VS_IN input)
{
    VS_OUT output = (VS_OUT)0;

    output.pos = float4(input.pos, 1.f); // 마지막만 1로 채워넣음
    output.color = input.color;

    return output;
}

// 색상을 정해주는 단계
float4 PS_Main(VS_OUT input) : SV_Target
{
    return input.color;
}