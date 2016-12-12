#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	createcube(1.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 1, 0));
	createcylinder(1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(1, 2, 1));
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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	p2List_item<Cube*>*iteratorcube;
	iteratorcube = cubelist.getFirst();
	while (iteratorcube != NULL) {

		iteratorcube->data->Render();
		iteratorcube = iteratorcube->next;
	}

	p2List_item<Cylinder*>*iteratorcylinder;
	iteratorcylinder = cylinderlist.getFirst();
	while (iteratorcylinder != NULL) {

		iteratorcylinder->data->Render();
		iteratorcylinder = iteratorcylinder->next;
	}


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::createcube(const float x, const float y, const float z, vec3 axis, float angle, vec3 pos) {
	Cube* cube=new Cube(x,y,z);
	cube->SetPos(pos.x, pos.y, pos.z);
	cube->SetRotation(angle, axis);
	Color Red;

	cubelist.add(cube);

}

void ModuleSceneIntro::createcylinder(const float radius, const float height, vec3 axis, float angle, vec3 pos) {
	Cylinder* cylinder = new Cylinder(radius, height);
	cylinder->SetPos(pos.x, pos.y, pos.z);
	cylinder->SetRotation(angle, axis);
	Color Pink;

	cylinderlist.add(cylinder);

}

