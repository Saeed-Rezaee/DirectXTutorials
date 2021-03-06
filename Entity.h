#pragma once
#include <DirectXMath.h>

// Forward Declaration of Mesh Class.
class Mesh;
class Material;

class Entity
{
public:
	// Entity's Constructor - Construct Entity with Mesh.
	explicit Entity(Mesh* t_mesh, Material* t_material);

	// Copy Constructor for Entity
	Entity(const Entity& t_rhs);

	//Move Entity relative to the direction it is facing
	void MoveRelative(const float& t_X, const float& t_Y, const float& t_Z);
	
	// Absolute Movement of Entity in the direction it is facing.
	void MoveAbsolute(const float& t_X, const float& t_Y, const float& t_Z);
	
	// Get this Entity's Mesh
	Mesh* GetEntityMesh() const;

	// Get this Entity's Material
	const Material* GetEntityMaterial() const;
	
	// Get this Entity's current position
	const DirectX::XMFLOAT3& GetPosition() const;
	
	// Set position for this Entity using float values.
	void SetPosition(const float& t_X, const float& t_Y, const float& t_Z);
	
	// Set position using DirectX Vector3.
	void SetPosition(const DirectX::XMFLOAT3& t_position);
	
	// Get this Entity's Scale.
	const DirectX::XMFLOAT3& GetScale() const;

	// Set Scale of this Entity.
	void SetScale(const float& t_X, const float& t_Y, const float& t_Z);
	
	// Get this Entity's Current Rotation.
	const DirectX::XMFLOAT4& GetRotation() const;
	
	// Set this Entity's current Rotation.
	void SetRotation(const DirectX::XMFLOAT4& t_rotation);

	// Get World matrix for this Entity;
	DirectX::XMFLOAT4X4 GetWorldMatrix();

	// Prepare Materials and Shaders for upcoming draw() call.
	void prepareMaterial(const DirectX::XMFLOAT4X4& t_view_matrix, const DirectX::XMFLOAT4X4& t_projection_matrix);
	
	// Destructor for Entity (Virtual)
	virtual ~Entity();

private:
	// Pointer to Entity's Mesh Object.
	Mesh* entity_mesh = nullptr;

	// Pointer to Entity's material Object.
	Material* entity_material = nullptr;

	// Current Position of this Entity.
	DirectX::XMFLOAT3 position;

	// Current Scale of this Entity.
	DirectX::XMFLOAT3 scale;

	// Current Rotation of this Entity.
	DirectX::XMFLOAT4 rotation;
};