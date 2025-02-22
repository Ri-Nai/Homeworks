#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "d3dApp.h"
#include "Model.h"

class GameApp : public D3DApp
{
public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();


private:
	bool InitEffect();
	bool InitResource();



private:
	// 定义了方阵的大小
	static constexpr int size = 16;
	// 定义了游戏至此的角度
	float angle = 0;
	// 定义了模型和对应的世界矩阵组
	std::vector<std::unique_ptr<Model>> models;
	std::vector<std::vector<XMMATRIX>> worlds;

	ComPtr<ID3D11InputLayout> m_pVertexLayout;	    // 顶点输入布局
	ComPtr<ID3D11Buffer> m_pVertexBuffer;			// 顶点缓冲区
	ComPtr<ID3D11Buffer> m_pIndexBuffer;			// 索引缓冲区
	ComPtr<ID3D11Buffer> m_pConstantBuffer;		    // 常量缓冲区

	ComPtr<ID3D11VertexShader> m_pVertexShader;	    // 顶点着色器
	ComPtr<ID3D11PixelShader> m_pPixelShader;		// 像素着色器
	ConstantBuffer m_CBuffer;	                    // 用于修改GPU常量缓冲区的变量
};


#endif
