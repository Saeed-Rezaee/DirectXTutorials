#include "Mesh.h"
#include "Vertex.h"

using namespace DirectX;

Mesh::Mesh(ID3D11Device* pDevice, Vertex* pVerts, UINT numVerts, UINT* pIndices, UINT numIndices)
{
	// Create the VERTEX BUFFER description -----------------------------------
	// - The description is created on the stack because we only need
	//    it to create the buffer.  The description is then useless.
	D3D11_BUFFER_DESC vbd;
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * numVerts;       // numVerts = number of vertices in the buffer
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER; // Tells DirectX this is a vertex buffer
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;

	// Create the proper struct to hold the initial vertex data
	// - This is how we put the initial data into the buffer
	D3D11_SUBRESOURCE_DATA initialVertexData;
	initialVertexData.pSysMem = pVerts;

	// Actually create the buffer with the initial data
	// - Once we do this, we'll NEVER CHANGE THE BUFFER AGAIN
	pDevice->CreateBuffer(&vbd, &initialVertexData, &VertexBuffer);

	IndexCount = numIndices;

	// Create the INDEX BUFFER description ------------------------------------
	// - The description is created on the stack because we only need
	//    it to create the buffer.  The description is then useless.
	D3D11_BUFFER_DESC ibd;
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(int) * IndexCount;         // numIndices = number of indices in the buffer
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER; // Tells DirectX this is an index buffer
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;

	// Create the proper struct to hold the initial index data
	// - This is how we put the initial data into the buffer
	D3D11_SUBRESOURCE_DATA initialIndexData;
	initialIndexData.pSysMem = pIndices;

	// Actually create the buffer with the initial data
	// - Once we do this, we'll NEVER CHANGE THE BUFFER AGAIN
	pDevice->CreateBuffer(&ibd, &initialIndexData, &IndexBuffer);
}

Mesh::~Mesh()
{
	if (VertexBuffer)
	{
		VertexBuffer->Release();
	}

	if (IndexBuffer)
	{
		IndexBuffer->Release();
	}
}

ID3D11Buffer* const Mesh::GetVertexBuffer() const
{
	return VertexBuffer;
}

ID3D11Buffer* const Mesh::GetIndexBuffer() const
{
	return IndexBuffer;
}

const UINT Mesh::GetIndexCount() const
{
	return IndexCount;
}
