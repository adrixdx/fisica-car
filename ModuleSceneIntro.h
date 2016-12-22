#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "p2List.h"
#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;


struct Object {

	Cube cube;
	Sphere sphere;
	PhysBody3D* pb_cube;

};

	

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	void CreateCube(float x_scale, float y_scale, float z_scale, vec3 axis, float degrees, vec3 pos, Color color, float mass);
	void createBridge();
	void createFlag();
	void createTunnel();
	void createCircuit();
	void ModuleSceneIntro::createcylinder(const float radius, const float height, vec3 axis, float angle, vec3 pos, Color colorcylinder);

public:
	int laps_count = 0;
	bool is_allowed = false;
	float secondsPassed = TIMER;
	float bestTime = 0;
	float secondsLap = 0;
	bool win_condition = false;

	PhysBody3D* sensor_lap;
	PhysBody3D* interruptor;

	PhysBody3D* pb_lilCube;
	Cube lilCube;
	p2List<Object> circuit;

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	p2List<Cube*>cubelist;
	p2List<Cylinder*>cylinderlist;
};
