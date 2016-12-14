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
	createcylinder(0.2f, 12.8f, vec3(0, 0, 1), 90, vec3(4.5, 0, 2), Black);//FlagCylinder

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

	createcube(12.0f, 0.25f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 3, 94.5), Pink);//Bordes
	createcube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 2.5, 94.5), White);//Bordes
	createcube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 1.5, 94.5), White);//Bordes
	createcube(10.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-18, 1, 94.5), White);//Bordes
	createcube(10.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 0.5, 94.5), White);//Bordes
	createcube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 0, 94.5), White);//Bordes
	createcube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, -1, 94.5), White);//Bordes
	createcube(22.0f, 0.25f, 1.0f, vec3(0, 0, 1), -11, vec3(-15.5, 3, 104.5), Pink);//Bordes
	createcube(22.0f, 5.0f, 1.0f, vec3(0, 0, 1), -11, vec3(-16, 0.5, 104.5), White);//Bordes

	createcube(20.0f, 0.25f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 5, 97.5), Pink);//Bordes
	createcube(20.0f, 5.0f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 2.5, 97.5), White);//Bordes
	createcube(15.0f, 0.25f, 1.0f, vec3(0, 1, 0), -45, vec3(-27.5, 5, 89.5), Pink);//Bordes
	createcube(15.0f, 5.0f, 1.0f, vec3(0, 1, 0), -45, vec3(-27.5, 2.5, 89.5), White);//Bordes

	createcube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 5, -32), Pink);//Bordes
	createcube(1.0f, 5.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, -32), White);//Bordes

	createcube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 5, -59), Pink);//Bordes
	createcube(1.0f, 5.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, -59), White);//Bordes

	createcube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 5, -87), Pink);//Bordes
	createcube(1.0f, 5.0f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 2.5, -87), White);//Bordes

	createcube(18.5f, 0.25f, 1.0f, vec3(0, 0, 1), 30, vec3(-25.5, 9, -90.5), Pink);//Bordes
	createcube(20.0f, 5.0f, 1.0f, vec3(0, 0, 1), 30, vec3(-25, 6.5, -90.5), White);//Bordes

	createcube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 13.5, -90.5), Pink);//Bordes
	createcube(35.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 11, -90.5), White);//Bordes

	createcube(18.5f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(25.5, 9, -90.5), Pink);//Bordes
	createcube(20.0f, 5.0f, 1.0f, vec3(0, 0, 1), -30, vec3 (25, 6.5, -90.5), White);//Bordes

	createcube(17.0f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(24, 9.5, -80.5), Pink);//Bordes
	createcube(17.0f, 5.0f, 1.0f, vec3(0, 0, 1), -30, vec3(23, 7.25, -80.5), White);//Bordes

	createcube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 13.5, -80.5), Pink);//Bordes
	createcube(35.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 11, -80.5), White);//Bordes

	createcube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), 45, vec3(36.5, 5, -87), Pink);//Bordes
	createcube(1.0f, 5.0f, 10.0f, vec3(0, 1, 0), 45, vec3(36.5, 2.5, -87), White);//Bordes

	createcube(1.0f, 0.25f, 50.0f, vec3(1, 0, 0), 5, vec3(40, 3, -59), Pink);//Bordes
	createcube(1.0f, 5.0f, 50.0f, vec3(1, 0, 0), 5, vec3(40, 0.5, -59), White);//Bordes

	createcube(1.0f, 0.25f, 45.0f, vec3(1, 0, 0), 5, vec3(31, 3.5, -59), Pink);//Bordes
	createcube(1.0f, 6.0f, 45.0f, vec3(1, 0, 0), 5, vec3(31, 0.5, -59), White);//Bordes

	createcube(2.0f, 4.0f, 1.0f, vec3(1, 0, 0), 0, vec3(30, 1.5, -80.5), White);//Bordes

	createcube(1.0f, 0.25f, 20.0f, vec3(0, 1, 0), -60, vec3(-24.5, 5, -10), Pink);//Bordes
	createcube(1.0f, 5.0f, 20.0f, vec3(0, 1, 0), -60, vec3(-24.5, 2.5, -10), White);//Bordes

	createcube(1.0f, 0.25f, 20.0f, vec3(1, 0, 0), -12, vec3(-16, 3, -24), Pink);//Bordes
	createcube(1.0f, 5.0f, 20.0f, vec3(1, 0, 0), -12, vec3(-16, 0.5, -23.5), White);//Bordes

	createcube(1.0f, 1.0f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 0.5, -83), White);//Bordes
	createcube(1.0f, 0.25f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 1, -83), Pink);//Bordes

	createcube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), -45, vec3(-14.25, 0.5, -136.5), White);//Bordes
	createcube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), -45, vec3(-14.25, 1, -136.5), Pink);//Bordes

	createcube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), 45, vec3(-6.25, 0.5, -136.5), White);//Bordes
	createcube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), 45, vec3(-6.25, 1, -136.5), Pink);//Bordes

	createcube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), 90, vec3(-10.25, 0.5, -138.25), White);//Bordes
	createcube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), 90, vec3(-10.25, 1, -138.25), Pink);//Bordes

	createcube(1.0f, 0.25f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 5, 41), Pink);//Bordes
	createcube(1.0f, 5.0f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, 41), White);//Bordes
	createcube(1.0f, 0.25f, 90.0f, vec3(0, 1, 0), 0, vec3(-33, 5, 39.5), Pink);//Bordes
	createcube(1.0f, 5.0f, 90.0f, vec3(0, 1, 0), 0, vec3(-33, 2.5, 39.5), White);//Bordes

	createcube(1.0f, 0.25f, 130.0f, vec3(0, 1, 0), 0, vec3(-4.5, 1, -70), Pink);//Bordes
	createcube(1.0f, 1.0f, 130.0f, vec3(0, 1, 0), 0, vec3(-4.5, 0.5, -70), White);//Bordes
	createcube(1.0f, 0.25f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 1, -85), Pink);//Bordes
	createcube(1.0f, 1.0f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 0.5, -85), White);//Bordes



	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 15), Yellow);//Rampa
	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 30), Yellow);//Rampa
	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 45), Yellow);//Rampa
	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 60), Yellow);//Rampa
	createcube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 75), Yellow);//Rampa
	
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

