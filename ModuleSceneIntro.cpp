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

	App->camera->Move(vec3(0,0, 0));
	App->camera->LookAt(vec3(0, 1, 0));
	
	Cube sensor_cube;
	sensor_cube.size = { 15, 0.5, 10 };
	sensor_cube.SetPos(0, 0.5, -12.5);

	sensor_lap = App->physics->AddBody(sensor_cube, 0);
	sensor_lap->SetAsSensor(true);

	sensor_lap->collision_listeners.add(this);

	Cube sensor_cube2;
	sensor_cube2.size = { 20, 0.5, 20 };
	sensor_cube2.SetPos(-5, 0.5, 90);

	interruptor = App->physics->AddBody(sensor_cube2, 0);
	interruptor->SetAsSensor(true);

	interruptor->collision_listeners.add(this);

	// STAGE 1

	createCircuit();
	createFlag();
	createTunnel();
	createBridge();

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	circuit.clear();
	cubelist.clear();
	cylinderlist.clear();
	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.color = Black;
	p.axis = true;
	p.Render();


	
	p2List_item<Object>* item = circuit.getFirst();

	while (item != NULL) {

		item->data.pb_cube->GetTransform(item->data.cube.transform.M);
		item->data.cube.Render();
		item = item->next;

	}
	
	
	
	

	if(secondsPassed > 0.0f && win_condition == false)
	{
		secondsPassed -= 0.024f;
		secondsLap += 0.024f;

		char title[80];
		sprintf_s(title, "LAPS: %d/%d   %.2f     BEST TIME: %.2f", laps_count, LAPS, secondsPassed, bestTime);
		App->window->SetTitle(title);

		if (laps_count == LAPS)
		{	
			App->window->SetTitle("              YOU WON!!!!!!!              (press ESC -> to EXIT)");
			win_condition = true;
			
		}
	}
	

	if (secondsPassed < 0.0f && win_condition == false)
	{
		App->window->SetTitle("              YOU LOOSE!!!!!!!              (press ESC -> to EXIT)");
	}
	
	
	
	


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if(body1 == sensor_lap && body2 == (PhysBody3D*)App->player->vehicle)
	{
		if (is_allowed == true)
		{
			laps_count++;
			is_allowed = false;

			if (secondsLap < bestTime || bestTime == 0.00f){

				bestTime = secondsLap;
			}
			
			secondsLap = 0;
		}
	}

	if (body1 == interruptor && body2 == (PhysBody3D*)App->player->vehicle)
	{
		if (is_allowed == false)
			is_allowed = true;
	}
}

void ModuleSceneIntro::CreateCube(float x_scale, float y_scale, float z_scale, vec3 axis, float degrees, vec3 pos, Color color, float mass)
{
	Object wall;
	wall.cube.size = { x_scale, y_scale, z_scale };
	if( degrees != NULL){
		wall.cube.SetRotation(degrees, axis);
	}
	wall.cube.color = color;

	wall.pb_cube = App->physics->AddBody(wall.cube, mass);
	wall.pb_cube->SetPos(pos.x, pos.y, pos.z);
	circuit.add(wall);
}

void ModuleSceneIntro::createcylinder(const float radius, const float height, vec3 axis, float angle, vec3 pos, Color colorcylinder) {
	Cylinder* cylinder = new Cylinder(radius, height);
	cylinder->SetPos(pos.x, pos.y, pos.z);
	cylinder->SetRotation(angle, axis);
	cylinder->color = colorcylinder;

	cylinderlist.add(cylinder);

}

void ModuleSceneIntro::createBridge(){

	CreateCube(34.0f, 1.0f, 10.0f, vec3(0, 0, 1), 0, vec3(0, 8, -85.5), Black, 0);//Puente
	CreateCube(17.0f, 1.0f, 10.0f, vec3(0, 0, 1), -30, vec3(23.5, 4, -85.5), Black, 0);//Puente
	CreateCube(17.0f, 1.0f, 10.0f, vec3(0, 0, 1), 30, vec3(-23.5, 4, -85.5), Black, 0);//Puente

}

void ModuleSceneIntro::createFlag() {
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 6.5, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 7.3, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 7.3, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 5.7, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 5.7, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(2, 6.5, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-2, 6.5, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 7.3, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 7.3, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 5.7, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 5.7, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(4, 6.5, -5), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-4, 6.5, -5), Black, 0);//Flag
	CreateCube(10.0f, 2.4f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 6.5, -5), White, 0);//Flag

}

void ModuleSceneIntro::createTunnel() {

	CreateCube(1.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 20), White, 0);//Tunnel
	CreateCube(1.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 20), White, 0);//Tunnel
	CreateCube(20.0f, 1.0f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 3, 44.5), White, 0);//Tunnel
	CreateCube(20.0f, 0.25f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 3.6, 44.5), Pink, 0);//Tunnel
	CreateCube(1.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 69), White, 0);//Tunnel
	CreateCube(1.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 69), White, 0);//Tunnel
	CreateCube(1.0f, 1.f, 50.0f, vec3(0, 1, 0), -5, vec3(7.5, 4.3, 44.5), White, 0);//Tunnel
	CreateCube(1.0f, 1.f, 50.0f, vec3(0, 1, 0), 5, vec3(-7.5, 4.3, 44.5), White, 0);//Tunnel
	


}

void ModuleSceneIntro::createCircuit() {
	CreateCube(15.0f, 0.1f, 7.0f, vec3(1, 0, 0), -17, vec3(0, 0.5, -7), Cian, 0);
	//CreateCube(15.0f, 1.5f, 2.0f, vec3(1, 0, 0), 0, vec3(0, 0, -6), Cian, 900000);
	
	
	CreateCube(1.0f, 5.25f, 105.0f, vec3(0, 0, 1), 0, vec3(8.5, 1, 35), Pink, 0);//Bordes
	CreateCube(1.0f, 5.25f, 95.0f, vec3(0, 0, 1), 0, vec3(-8.5, 1, 35), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 105.0f, vec3(0, 0, 1), 0, vec3(8.5, 0.5, 35), White, 0);//Bordes
	CreateCube(1.0f, 5.0f, 95.0f, vec3(0, 0, 1), 0, vec3(-8.5, 0.5, 35), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 20.0f, vec3(0, 1, 0), -30, vec3(3.5, 1, 95.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 20.0f, vec3(0, 1, 0), -30, vec3(3.5, 0.5, 95.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), -45, vec3(-10.05, 1, 84), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), -45, vec3(-10.05, 0.5, 84), White, 0);//Bordes
	CreateCube(10.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(-17, 1, 85.5), Pink, 0);//Bordes
	CreateCube(10.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-17, 0.5, 85), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), 45, vec3(-23.05, 1, 84), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), 45, vec3(-23.05, 0.5, 84), White, 0);//Bordes
	CreateCube(22.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(-12.5, 1, 104.5), Pink, 0);//Bordes
	CreateCube(22.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-13, 0.5, 104.5), White, 0);//Bordes
	CreateCube(20.0f, 0.25f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 1, 97.5), Pink, 0);//Bordes
	CreateCube(20.0f, 1.0f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 0.5, 97.5), White, 0);//Bordes
	
	
	CreateCube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 1, -32), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 0.5, -32), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 60.0f, vec3(0, 1, 0), 0, vec3(-33, 1, -51), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 60.0f, vec3(0, 1, 0), 0, vec3(-33, 0.5, -51), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 1, -59), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 0.5, -59), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 1, -87), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 0.5, -87), White, 0);//Bordes
	CreateCube(18.0f, 0.25f, 1.0f, vec3(0, 0, 1), 30, vec3(-25, 5, -90.5), Pink, 0);//Bordes **
	CreateCube(18.0f, 1.0f, 1.0f, vec3(0, 0, 1), 30, vec3(-25, 4.5, -90.5), White, 0);//Bordes**
	CreateCube(18.0f, 0.25f, 1.0f, vec3(0, 0, 1), 30, vec3(-25.5, 5, -80.5), Pink, 0);//Bordes**
	CreateCube(18.0f, 1.0f, 1.0f, vec3(0, 0, 1), 30, vec3(-25, 4.5, -80.5), White, 0);//Bordes**
	CreateCube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 9.75, -90.5), Pink, 0);//Bordes
	CreateCube(35.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 9.25, -90.5), White, 0);//Bordes
	CreateCube(18.0f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(25, 5, -90.5), Pink, 0);//Bordes
	CreateCube(18.0f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(25, 4.5, -90.5), White, 0);//Bordes
	CreateCube(18.0f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(25, 5, -80.5), Pink, 0);//Bordes
	CreateCube(18.0f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(25, 4.5, -80.5), White, 0);//Bordes*/
	CreateCube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 9.75, -80.5), Pink, 0);//Bordes
	CreateCube(35.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 9.25, -80.5), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), 45, vec3(40.5, 1, -87), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 10.0f, vec3(0, 1, 0), 45, vec3(40.5, 0.5, -87), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 50.0f, vec3(1, 0, 0), 0, vec3(44, 1, -59), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 50.0f, vec3(1, 0, 0), 0, vec3(44, 0.5, -59), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 40.0f, vec3(1, 0, 0), 0, vec3(31, 1, -61), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 40.0f, vec3(1, 0, 0), 0, vec3(31, 0.5, -61), White, 0);//Bordes
	CreateCube(40.0f, 0.25f, 1.0f, vec3(0, 1, 0), 25, vec3(26.5, 1, -25.5), Pink, 0);//Bordes
	CreateCube(40.0f, 1.0f, 1.0f, vec3(0, 1, 0), 25, vec3(26.5, 0.5, -25.5), White, 0);//Bordes
	
	CreateCube(29.0f, 0.25f, 1.0f, vec3(0, 1, 0), 22, vec3(17.75, 1, -35.5), Pink, 0);//Bordes
	CreateCube(29.0f, 1.0f, 1.0f, vec3(0, 1, 0), 22, vec3(17.75, 0.5, -35.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 15.0f, vec3(0, 1, 0), -42, vec3(-20, 1, -9), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 15.0f, vec3(0, 1, 0), -42, vec3(-20, 0.5, -9), White, 0);//Bordes
	
	CreateCube(1.0f, 0.25f, 20.0f, vec3(1, 0, 0), 0, vec3(-16, 1, -24), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 20.0f, vec3(1, 0, 0), 0, vec3(-16, 0.5, -23.5), White, 0);//Bordes
	CreateCube(1.0f, 1.0f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 0.5, -83), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 1, -83), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 119.0f, vec3(1, 0, 0), 0, vec3(-26, 0.5, -80.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 119.0f, vec3(1, 0, 0), 0, vec3(-26, 1, -80.5), Pink, 0);//Bordes
	CreateCube(8.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-29.5, 0.5, -21.5), White, 0);//Bordes
	CreateCube(8.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(-29.5, 1, -21.5), Pink, 0);//Bordes

	CreateCube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), -45, vec3(-14.25, 0.5, -136.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), -45, vec3(-14.25, 1, -136.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 15.0f, vec3(0, 1, 0), -45, vec3(-20.75, 0.5, -145), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 15.0f, vec3(0, 1, 0), -45, vec3(-20.75, 1, -145), Pink, 0);//Bordes

	CreateCube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), 45, vec3(-6.25, 0.5, -136.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), 45, vec3(-6.25, 1, -136.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 15.0f, vec3(0, 1, 0), 45, vec3(-0.75, 0.5, -145), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 15.0f, vec3(0, 1, 0), 45, vec3(-0.75, 1, -145), Pink, 0);//Bordes

	CreateCube(1.0f, 1.0f, 5.0f, vec3(0, 1, 0), 90, vec3(-10.25, 0.5, -138.25), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 5.0f, vec3(0, 1, 0), 90, vec3(-10.25, 1, -138.25), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 10.0f, vec3(0, 1, 0), 90, vec3(-10.5, 0.5, -150), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), 90, vec3(-10.5, 1, -150), Pink, 0);//Bordes
	
	CreateCube(1.0f, 0.25f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 1, 41), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 0.5, 41), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 86.0f, vec3(0, 1, 0), 0, vec3(-25, 1, 39.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 86.0f, vec3(0, 1, 0), 0, vec3(-25, 0.5, 39.5), White, 0);//Bordes
	
	CreateCube(1.0f, 0.25f, 130.0f, vec3(0, 1, 0), -2, vec3(-6, 1, -70), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 130.0f, vec3(0, 1, 0), -2, vec3(-6, 0.5, -70), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 1, -85), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 0.5, -85), White, 0);//Bordes
}

