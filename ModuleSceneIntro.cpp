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
	

	// STAGE 1

	//CreateCube(8, 0.1, 8, Cian, 100000, 0, 1.5, 0, 0, { 0, 0, 0 }); // A  


	/*CreateCube(3, 3, 100, Cian, 100000, -10, 1.5, 0, 0, { 0, 0, 0 }); // A  
	CreateCube(3, 3, 100, Black, 100000, 10, 1.5, 0, 0, { 0, 0, 0 });

	CreateCube(3, 3, 100, Black, 100000, -40, 1.5, 0, 0, { 0, 0, 0 }); // B  
	CreateCube(3, 3, 100, Cian, 100000, -60, 1.5, 0, 0, { 0, 0, 0 });

	CreateCube(3, 3, 14, Cian, 100000, -15, 1.5, 55, -45, { 0, 1, 0 }); // C1
	CreateCube(2, 3, 9, Black, 100000, -25, 1.5, 60, 90, { 0, 1, 0 }); // C2
	CreateCube(3, 3, 14, Cian, 100000, -35, 1.5, 55,  45, { 0, 1, 0 }); // C3

	CreateCube(3, 3, 22, Cian, 100000, 5, 1.5, 60, -26.56, { 0, 1, 0 }); // D1
	CreateCube(2, 3, 14, Black, 100000, -5, 1.5, 75, -45, { 0, 1, 0 }); // D2
	CreateCube(3, 3, 30, Cian, 100000, -25, 1.5, 80, 90, { 0, 1, 0 }); // D3
	CreateCube(2, 3, 14, Black, 100000, -45, 1.5, 75, 45, { 0, 1, 0 }); // D4
	CreateCube(3, 3, 22, Cian, 100000, -55, 1.5, 60, 26.56, { 0, 1, 0 }); // D1

	CreateCube(3, 3, 14, Cian, 100000, -15, 1.5, -55, 45, { 0, 1, 0 }); // E1
	CreateCube(2, 3, 9, Black, 100000, -25, 1.5, -60, 90, { 0, 1, 0 }); // E2
	CreateCube(3, 3, 14, Cian, 100000, -35, 1.5, -55, -45, { 0, 1, 0 }); // E3

	CreateCube(3, 3, 22, Cian, 100000, 5, 1.5, -60, 26.56, { 0, 1, 0 }); // F1
	CreateCube(2, 3, 14, Black, 100000, -5, 1.5, -75, 45, { 0, 1, 0 }); // F2
	CreateCube(3, 3, 30, Cian, 100000, -25, 1.5, -80, 90, { 0, 1, 0 }); // F3
	CreateCube(2, 3, 14, Black, 100000, -45, 1.5, -75, -45, { 0, 1, 0 }); // F4
	CreateCube(3, 3, 22, Cian, 100000, -55, 1.5, -60, -26.56, { 0, 1, 0 }); // F1
	*/








	
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 5, 2), Black,0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 5.8, 2), Black,0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 5.8, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(1, 4.2, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-1, 4.2, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(2, 5, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-2, 5, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 5.8, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 5.8, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(3, 4.2, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-3, 4.2, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(4, 5, 2), Black, 0);//Flag
	CreateCube(1.0f, 0.8f, 0.1f, vec3(0, 0, 1), 0, vec3(-4, 5, 2), Black, 0);//Flag
	CreateCube(10.0f, 2.4f, 0.1f, vec3(0, 0, 1), 0, vec3(0, 5, 2), White, 0);//Flag
	createcylinder(0.2f, 12.8f, vec3(0, 0, 1), 90, vec3(-4.5, 0, 2), Black);//FlagCylinder
	createcylinder(0.2f, 12.8f, vec3(0, 0, 1), 90, vec3(4.5, 0, 2), Black);//FlagCylinder

	CreateCube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 20), White, 0);//Tunnel
	CreateCube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 20), White, 0);//Tunnel
	CreateCube(10.0f, 1.0f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 6, 44.5), White, 0);//Tunnel
	CreateCube(10.0f, 0.25f, 50.0f, vec3(0, 0, 1), 0, vec3(0, 6.6, 44.5), Pink, 0);//Tunnel
	CreateCube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 69), White, 0);//Tunnel
	CreateCube(1.0f, 10.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 69), White, 0);//Tunnel
	CreateCube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(4.5, 1.5, 44.5), White, 0);//Tunnel
	CreateCube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(-4.5, 1.5, 44.5), White, 0);//Tunnel
	CreateCube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(4.5, 5, 44.5), White, 0);//Tunnel
	CreateCube(1.0f, 1.5f, 50.0f, vec3(0, 0, 1), 0, vec3(-4.5, 5, 44.5), White, 0);//Tunnel

	CreateCube(1.0f, 0.25f, 105.0f, vec3(0, 0, 1), 0, vec3(4.5, 1, 35), Pink, 0);//Bordes
	CreateCube(1.0f, 0.25f, 95.0f, vec3(0, 0, 1), 0, vec3(-4.5, 1, 35), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 105.0f, vec3(0, 0, 1), 0, vec3(4.5, 0.5, 35),White, 0);//Bordes
	CreateCube(1.0f, 1.0f, 95.0f, vec3(0, 0, 1), 0, vec3(-4.5, 0.5, 35), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 20.0f, vec3(0, 1, 0), -30, vec3(-0.5, 1, 95.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 20.0f, vec3(0, 1, 0), -30, vec3(-0.5, 0.5, 95.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 15.0f, vec3(0, 1, 0), -30, vec3(-8.25, 1, 88.5), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 15.0f, vec3(0, 1, 0), -30, vec3(-8.25, 0.5, 88.5), White, 0);//Bordes

	CreateCube(12.0f, 0.25f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 3, 94.5), Pink, 0);//Bordes
	CreateCube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 2.5, 94.5), White, 0);//Bordes
	CreateCube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 1.5, 94.5), White, 0);//Bordes
	CreateCube(10.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-18, 1, 94.5), White, 0);//Bordes
	CreateCube(10.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 0.5, 94.5), White, 0);//Bordes
	CreateCube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, 0, 94.5), White, 0);//Bordes
	CreateCube(12.0f, 1.0f, 1.0f, vec3(0, 0, 1), -21, vec3(-17, -1, 94.5), White, 0);//Bordes
	CreateCube(22.0f, 0.25f, 1.0f, vec3(0, 0, 1), -11, vec3(-15.5, 3, 104.5), Pink, 0);//Bordes
	CreateCube(22.0f, 5.0f, 1.0f, vec3(0, 0, 1), -11, vec3(-16, 0.5, 104.5), White, 0);//Bordes

	CreateCube(20.0f, 0.25f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 5, 97.5), Pink, 0);//Bordes
	CreateCube(20.0f, 5.0f, 1.0f, vec3(0, 1, 0), -45, vec3(-33, 2.5, 97.5), White, 0);//Bordes
	CreateCube(15.0f, 0.25f, 1.0f, vec3(0, 1, 0), -45, vec3(-27.5, 5, 89.5), Pink, 0);//Bordes
	CreateCube(15.0f, 5.0f, 1.0f, vec3(0, 1, 0), -45, vec3(-27.5, 2.5, 89.5), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 5, -32), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, -32), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 60.0f, vec3(0, 1, 0), 0, vec3(-33, 5, -51), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 60.0f, vec3(0, 1, 0), 0, vec3(-33, 2.5, -51), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 5, -59), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 50.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, -59), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 5, -87), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 10.0f, vec3(0, 1, 0), -45, vec3(-36.5, 2.5, -87), White, 0);//Bordes

	CreateCube(18.5f, 0.25f, 1.0f, vec3(0, 0, 1), 30, vec3(-25.5, 9, -90.5), Pink, 0);//Bordes
	CreateCube(20.0f, 5.0f, 1.0f, vec3(0, 0, 1), 30, vec3(-25, 6.5, -90.5), White, 0);//Bordes

	CreateCube(18.5f, 0.25f, 1.0f, vec3(0, 0, 1), 30, vec3(-25.5, 9, -80.5), Pink, 0);//Bordes
	CreateCube(18.0f, 5.0f, 1.0f, vec3(0, 0, 1), 30, vec3(-24, 7, -80.5), White, 0);//Bordes

	CreateCube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 13.5, -90.5), Pink, 0);//Bordes
	CreateCube(35.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 11, -90.5), White, 0);//Bordes

	CreateCube(18.5f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(25.5, 9, -90.5), Pink, 0);//Bordes
	CreateCube(20.0f, 5.0f, 1.0f, vec3(0, 0, 1), -30, vec3 (25, 6.5, -90.5), White, 0);//Bordes

	CreateCube(17.0f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(24, 9.5, -80.5), Pink, 0);//Bordes
	CreateCube(17.0f, 5.0f, 1.0f, vec3(0, 0, 1), -30, vec3(23, 7.25, -80.5), White, 0);//Bordes

	CreateCube(35.0f, 0.25f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 13.5, -80.5), Pink, 0);//Bordes
	CreateCube(35.0f, 5.0f, 1.0f, vec3(0, 0, 1), 0, vec3(0, 11, -80.5), White, 0);//Bordes

	CreateCube(34.0f, 1.0f, 10.0f, vec3(0, 0, 1), 0, vec3(0, 8, -85.5), Black, 0);//Puente
	CreateCube(17.0f, 1.0f, 10.0f, vec3(0, 0, 1), -30, vec3(23.5, 4, -85.5), Black, 0);//Puente
	CreateCube(17.0f, 1.0f, 10.0f, vec3(0, 0, 1), 30, vec3(-23.5, 4, -85.5), Black, 0);//Puente

	CreateCube(1.0f, 0.25f, 10.0f, vec3(0, 1, 0), 45, vec3(36.5, 5, -87), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 10.0f, vec3(0, 1, 0), 45, vec3(36.5, 2.5, -87), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 50.0f, vec3(1, 0, 0), 5, vec3(40, 3, -59), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 50.0f, vec3(1, 0, 0), 5, vec3(40, 0.5, -59), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 40.0f, vec3(1, 0, 0), 7.5, vec3(31, 3.5, -61), Pink, 0);//Bordes
	CreateCube(1.0f, 6.0f, 40.0f, vec3(1, 0, 0), 7.5, vec3(31, 0.5, -61), White, 0);//Bordes

	CreateCube(2.0f, 4.0f, 1.0f, vec3(1, 0, 0), 0, vec3(30, 1.5, -80.5), White, 0);//Arreglo bajada
	CreateCube(3.0f, 4.0f, 1.0f, vec3(1, 0, 0), 0, vec3(-31.5, 1.5, -80.5), White, 0);//Arreglo bajada

	CreateCube(40.0f, 0.25f, 1.0f, vec3(0, 1, 0), 25, vec3(22.5, 1, -25.5), Pink, 0);//Bordes
	CreateCube(40.0f, 1.0f, 1.0f, vec3(0, 1, 0), 25, vec3(22.5, 0.5, -25.5), White, 0);//Bordes

	CreateCube(29.0f, 0.25f, 1.0f, vec3(0, 1, 0), 22, vec3(17.75, 1, -35.5), Pink, 0);//Bordes
	CreateCube(29.0f, 1.0f, 1.0f, vec3(0, 1, 0), 22, vec3(17.75, 0.5, -35.5), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 20.0f, vec3(0, 1, 0), -60, vec3(-24.5, 5, -10), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 20.0f, vec3(0, 1, 0), -60, vec3(-24.5, 2.5, -10), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 20.0f, vec3(1, 0, 0), -12, vec3(-16, 3, -24), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 20.0f, vec3(1, 0, 0), -12, vec3(-16, 0.5, -23.5), White, 0);//Bordes

	CreateCube(1.0f, 1.0f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 0.5, -83), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 104.0f, vec3(1, 0, 0), 0, vec3(-16, 1, -83), Pink, 0);//Bordes

	CreateCube(1.0f, 1.0f, 119.0f, vec3(1, 0, 0), 0, vec3(-26, 0.5, -80.5), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 119.0f, vec3(1, 0, 0), 0, vec3(-26, 1, -80.5), Pink, 0);//Bordes

	CreateCube(8.0f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(-29.5, 2.5, -21.5), White, 0);//Bordes
	CreateCube(7.0f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(-30, 2, -21.5), White, 0);//Bordes
	CreateCube(6.5f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(-30, 1.5, -21.5), White, 0);//Bordes
	CreateCube(6.0f, 1.0f, 1.0f, vec3(0, 0, 1), -30, vec3(-30, 1, -21.5), White, 0);//Bordes
	CreateCube(8.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-29.5, 0.5, -21.5), White, 0);//Bordes
	CreateCube(4.0f, 1.0f, 1.0f, vec3(0, 0, 1), 0, vec3(-30.5, 1.5, -21.5), White, 0);//Bordes
	CreateCube(8.0f, 0.25f, 1.0f, vec3(0, 0, 1), -30, vec3(-29.5, 3, -21.5), Pink, 0);//Bordes

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

	CreateCube(1.0f, 0.25f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 5, 41), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 100.0f, vec3(0, 1, 0), 0, vec3(-40, 2.5, 41), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 90.0f, vec3(0, 1, 0), 0, vec3(-33, 5, 39.5), Pink, 0);//Bordes
	CreateCube(1.0f, 5.0f, 90.0f, vec3(0, 1, 0), 0, vec3(-33, 2.5, 39.5), White, 0);//Bordes

	CreateCube(1.0f, 0.25f, 130.0f, vec3(0, 1, 0), 0, vec3(-4.5, 1, -70), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 130.0f, vec3(0, 1, 0), 0, vec3(-4.5, 0.5, -70), White, 0);//Bordes
	CreateCube(1.0f, 0.25f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 1, -85), Pink, 0);//Bordes
	CreateCube(1.0f, 1.0f, 110.0f, vec3(0, 1, 0), 0, vec3(4.5, 0.5, -85), White, 0);//Bordes



	CreateCube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 15), Yellow, 0);//Rampa
	CreateCube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 30), Yellow, 0);//Rampa
	CreateCube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 45), Yellow, 0);//Rampa
	CreateCube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 60), Yellow, 0);//Rampa
	CreateCube(8.0f, 1.0f, 3.0f, vec3(1, 0, 0), 45, vec3(-36.5, 0.5, 75), Yellow, 0);//Rampa
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	circuit.clear();
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


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
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

