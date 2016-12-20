#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	VehicleInfo car;

	Cube wing;

	Cylinder wheel;

	wing.color=White;

	wheel.color = Blue;
	


	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);

	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);

	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();

	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);

	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.color = Pink;
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();



	Cube tunning(1.5,0.2,1);

	vehicle->getChassisWorldTransform().getOpenGLMatrix(&tunning.transform);

	btVector3 tunningoffset(info.tunning_offset.x, info.tunning_offset.y, info.tunning_offset.z);

	tunningoffset = tunningoffset.rotate(q.getAxis(), q.getAngle());

	tunning.color = White;
	tunning.transform.M[12] += tunningoffset.getX();
	tunning.transform.M[13] += tunningoffset.getY();
	tunning.transform.M[14] += tunningoffset.getZ();

	Cube tunning2(1.5, 0.2, 1);

	vehicle->getChassisWorldTransform().getOpenGLMatrix(&tunning2.transform);

	btVector3 tunning2offset(info.tunning2_offset.x, info.tunning2_offset.y, info.tunning2_offset.z);

	tunning2offset = tunning2offset.rotate(q.getAxis(), q.getAngle());

	tunning2.color = White;
	tunning2.transform.M[12] += tunning2offset.getX();
	tunning2.transform.M[13] += tunning2offset.getY();
	tunning2.transform.M[14] += tunning2offset.getZ();


	chassis.Render();
	tunning.Render();
	tunning2.Render();
	wing.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}