#include "../Time/GameTime.h"
#include "Entity.h"

#include "EntityTransform.h"


using namespace glm;

EntityTransform::EntityTransform(Entity* entity)
: m_Owner( entity )
, m_Dirty( true )
, m_LocalPosition( glm::vec3() )
, m_LocalRotation( glm::vec3() )
, m_LocalScale( glm::vec3() )
, m_IdentityMatrix( glm::mat4() )
, m_TranslationMatrix( glm::mat4() )
, m_RotationMatrix( glm::mat4() )
, m_ScaleMatrix( glm::mat4() )
, m_WorldMatrix( glm::mat4() )
{

}

EntityTransform::~EntityTransform()
{

}


//-- Matrix
mat4 EntityTransform::getWorldMatrix()
{
	if( m_Dirty )
	{
		updateWorldMatrix();
		m_Dirty = false;
	}

	if( m_Owner != NULL )
	{
		if( m_Owner->GetParent() != NULL )
		{
			mat4 combinedW = m_Owner->GetParent()->getTransform()->getWorldMatrix();
			return combinedW * m_WorldMatrix;
		}
		else
		{
			return m_WorldMatrix;
		}
	}
		
}

void EntityTransform::updateTranslationMatrix()
{
	//-- set position values direction
	m_TranslationMatrix[3][0] = m_LocalPosition.x;
	m_TranslationMatrix[3][1] = m_LocalPosition.y;
	m_TranslationMatrix[3][2] = m_LocalPosition.z;

	//-- flag for update
	m_Dirty = true;
}

void EntityTransform::updateRotationMatrix()
{
	//there must be a better way to do this in glm

	//-- set to identity
	m_RotationMatrix = glm::mat4();
	//-- rotate the individual axis
	glm::rotate( m_RotationMatrix, m_LocalRotation.x, vec3(1.0f, 0, 0) );
	glm::rotate( m_RotationMatrix, m_LocalRotation.y, vec3(0, 1.0f, 0) );
	glm::rotate( m_RotationMatrix, m_LocalRotation.z, vec3(0, 0, 1.0f) );

	//-- flag for update
	m_Dirty = true;
}

void EntityTransform::updateScaleMatrix()
{
	//-- set identity
	m_ScaleMatrix = glm::mat4();
	//-- scale the matrix
	glm::scale( m_ScaleMatrix, m_LocalScale );

	//-- flag for update
	m_Dirty = true;
}

void EntityTransform::updateWorldMatrix()
{
	m_WorldMatrix = m_TranslationMatrix * m_RotationMatrix * m_ScaleMatrix * m_IdentityMatrix;
}


//-- Rotation
vec3 EntityTransform::getWorldRotationDegrees()
{
	//-- get owners parent transform if it exists
	if( m_Owner != NULL )
	{
		if( m_Owner->GetParent() != NULL )
		{
			return m_LocalRotation + m_Owner->GetParent()->getTransform()->getWorldRotationDegrees();
		}
	}

	//-- return local rotation if there is no parent entity
	return m_LocalRotation;
}

vec3 EntityTransform::getLocalRotationDegrees()
{
	return m_LocalRotation;
}

vec3 EntityTransform::getLocalRotationRadians()
{
	vec3 rotationRadians( glm::radians( m_LocalRotation.x ), glm::radians( m_LocalRotation.y ), glm::radians( m_LocalRotation.z ) );

	return rotationRadians;
}

void EntityTransform::setRotation(vec3 rotation)
{
	m_LocalRotation = rotation;
	updateRotationMatrix();
}

void EntityTransform::rotate(vec3 rotation)
{
	m_LocalRotation += rotation;
	updateRotationMatrix();
}

void EntityTransform::rotateX(float x)
{
	m_LocalRotation.x += x;
	updateRotationMatrix();
}

void EntityTransform::rotateY(float y)
{
	m_LocalRotation.y += y;
	updateRotationMatrix();
}

void EntityTransform::rotateZ(float z)
{
	m_LocalRotation.z += z;
	updateRotationMatrix();
}


//-- translation	
void EntityTransform::setPosition(vec3 position)
{
	m_LocalPosition = position;
	updateTranslationMatrix();
}

void EntityTransform::setPositionX(float x)
{
	m_LocalPosition.x = x;
	updateTranslationMatrix();
}

void EntityTransform::setPositionY(float y)
{
	m_LocalPosition.y = y;
	updateTranslationMatrix();
}

void EntityTransform::setPositionZ(float z)
{
	m_LocalPosition.z = z;
	updateTranslationMatrix();
}

vec3 EntityTransform::getLocalPosition()
{
	return m_LocalPosition;
}

void EntityTransform::translate(vec3 translation)
{
	m_LocalPosition += translation;
	updateTranslationMatrix();
}


//-- scale
void EntityTransform::setScale(vec3 scale)
{
	m_LocalScale = scale;
	updateScaleMatrix();
}

vec3 EntityTransform::getLocalScale()
{
	return m_LocalScale;
}