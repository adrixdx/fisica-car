#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Color.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(10.0f,10.0f, 10.0f));
	App->camera->LookAt(vec3(0, 1, 0));
	

	

	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 5, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 5.8, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 5.8, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 4.2, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 4.2, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(2, 5, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-2, 5, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 5.8, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 5.8, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 4.2, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 4.2, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(4, 5, 2), Black);//Flag
	createcube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-4, 5, 2), Black);//Flag
	createcube(10.0f, 2.4f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 5, 2), White);//Flag
	createcylinder(0.2f, 12.8f, vec3(0, 0, 1), 90, vec3(-4.5, 0, 2), Black);//FlagCylinder
	createcylinder(0.2f, 12.8f, vec3(0, 0, 1), 90, vec3(4.5, 0, 1), Black);//FlagCylinder

	createcube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 20), White);//Tunnel
	createcube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 20), White);//Tunnel
	createcube(10.0f, 1.0f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 6, 44.5), White);//Tunnel
	createcube(10.0f, 0.25f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 6.6, 44.5), Pink);//Tunnel
	createcube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 69), White);//Tunnel
	createcube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 69), White);//Tunnel
	createcube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(4.5, 1.5, 44.5), White);//Tunnel
	createcube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(-4.5, 1.5, 44.5), White);//Tunnel
	createcube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(4.5, 5, 44.5), White);//Tunnel
	createcube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(-4.5, 5, 44.5), White);//Tunnel

	createcube(1.0f, 0.25f, 105.0f, vec3(0, 0, 1), 0, vec3(4.5, 1, 35), Pink);//Bordes
	createcube(1.0f, 0.25f, 95.0f, vec3(0, 0, 1), 0, vec3(-4.5, 1, 35), Pink);//Bordes
	createcube(1.0f, 1.0f, 105.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 35),White);//Bordes
	createcube(1.0f, 1.0f, 95.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 35), White);//Bordes

	createcube(1.0f, 0.25f, 20.0f, vec3(0, 1, 0), -30, vec3(-0.5, 1, 95.5), Pink);//Bordes
	createcube(1.0f, 1.0f, 20.0f, vec3(0, 1, 0), -30, vec3(-0.5, 0.5, 95.5), White);//Bordes
	createcube(1.0f, 0.25f, 15.0f, vec3(0, 1, 0), -30, vec3(-8.25, 1, 88.5), Pink);//Bordes
	createcube(1.0f, 1.0f, 15.0f, vec3(0, 1, 0), -30, vec3(-8.25, 0.5, 88.5), White);//Bordes

	createcube(10.0f, 0.25f, 1.0f, vec3(0, 1, 0), 0, vec3(-17, 1, 95), Pink);//Bordes
	createcube(10.0f, 1.0f, 1.0f, vec3(0, 1, 0), 0, vec3(-17, 0.5, 95), White);//Bordes
	createcube(22.0f, 0.25f, 1.0f, vec3(0, 1, 0), 0, vec3(-16, 1, 104.5), Pink);//Bordes
	createcube(22.0f, 1.0f, 1.0f, vec3(0, 1, 0), 0, vec3(-16, 0.5, 104.5), White);//Bordes

	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), -45, vec3(0, 0.5, -15), Yellow);//Rampa
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	for (int i = 0; i < cubelist.count(); i++) {
		delete cubelist[i];
	}
	for (int i = 0; i < cylinderlist.count(); i++) {
		delete cylinderlist[i];
	}
	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0, Black);
	p.axis = true;
	p.Render();


	
	p2List_item<Cylinder*>*iteratorcylinder;
	iteratorcylinder = cylinderlist.getFirst();
	while (iteratorcylinder != NULL) {

		iteratorcylinder->data->Render();
		iteratorcylinder = iteratorcylinder->next;
	}
	p2List_item<Cube*>*iteratorcube;
	iteratorcube = cubelist.getFirst();
	while (iteratorcube != NULL) {

		iteratorcube->data->Render();
		iteratorcube = iteratorcube->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::createcube(const float x, const float y, const float z, vec3 axis, float angle, vec3 pos, Color colorcube) {
	Cube* cube=new Cube(x,y,z);
	cube->SetPos(pos.x, pos.y, pos.z);
	cube->SetRotation(angle, axis);
	cube->color = colorcube;


	cubelist.add(cube);

}

void ModuleSceneIntro::createcylinder(const float radius, const float height, vec3 axis, float angle, vec3 pos, Color colorcylinder) {
	Cylinder* cylinder = new Cylinder(radius, height);
	cylinder->SetPos(pos.x, pos.y, pos.z);
	cylinder->SetRotation(angle, axis);
	cylinder->color = colorcylinder;

	cylinderlist.add(cylinder);

}

