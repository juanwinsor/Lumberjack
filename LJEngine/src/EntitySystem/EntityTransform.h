#ifndef ENTITY_TRANSFORM_H__
#define ENTITY_TRANSFORM_H__


class Entity;

using namespace glm;

class EntityTransform
{
public:
	EntityTransform(Entity* entity);
	~EntityTransform();

	//-- matrix	
	mat4 getWorldMatrix();

	//-- rotation
	vec3 getWorldRotationDegrees();
	vec3 getLocalRotationDegrees();
	vec3 getLocalRotationRadians();
	void setRotation(vec3 rotation);
	void rotate(vec3 rotation);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);

	//-- translation	
	void setPosition(vec3 position);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);
	vec3 getLocalPosition();
	void translate(vec3 translation);

	//-- scale
	void setScale(vec3 scale);
	vec3 getLocalScale();


private:

	Entity* m_Owner;

	void updateTranslationMatrix();
	void updateRotationMatrix();
	void updateWorldMatrix();
	void updateScaleMatrix();

	vec3 m_LocalScale;
	vec3 m_LocalPosition;
	vec3 m_LocalRotation;

	mat4 m_IdentityMatrix;
	mat4 m_ScaleMatrix;
	mat4 m_TranslationMatrix;
	mat4 m_RotationMatrix;

	mat4 m_WorldMatrix;
		
	bool m_Dirty;
};


#endif