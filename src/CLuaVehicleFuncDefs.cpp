#include "Main.h"

const char* haha = nullptr;

void CVehicleFuncDefs::init(lua_State *L)
{
	CVehicleFuncDefs::initVariables(L);
	CVehicleFuncDefs::initFunctions(L);
}

void CVehicleFuncDefs::initClass(lua_State *L)
{
	lua_newclass(L, "Vehicle");

	lua_registerfunction(L, "createVehicle", CVehicleFuncDefs::createVehicle);
	lua_registerfunction(L, "setVehiclePosition", CVehicleFuncDefs::setVehiclePosition);
	lua_registerfunction(L, "getVehiclePosition", CVehicleFuncDefs::getVehiclePosition);

	lua_registeroop(L, "new", "createVehicle");
	lua_registeroop(L, "setPosition", "setVehiclePosition");
	lua_registeroop(L, "getPosition", "getVehiclePosition");

	lua_registervariable(L, "position", "setVehiclePosition", "getVehiclePosition");

	lua_registerclass(L);
}

void CVehicleFuncDefs::initFunctions(lua_State *L)
{

}

void CVehicleFuncDefs::initVariables(lua_State *L)
{
	lua_newtable(L);
	
	lua_pushinteger(L, 400);
	lua_setfield(L, -2, "Landstalker");

	lua_pushinteger(L, 401);
	lua_setfield(L, -2, "Bravura");

	lua_pushinteger(L, 402);
	lua_setfield(L, -2, "Buffalo");

	lua_pushinteger(L, 403);
	lua_setfield(L, -2, "Linerunner");

	lua_pushinteger(L, 404);
	lua_setfield(L, -2, "Perennial");

	lua_pushinteger(L, 405);
	lua_setfield(L, -2, "Sentinel");

	lua_pushinteger(L, 406);
	lua_setfield(L, -2, "Dumper");

	lua_pushinteger(L, 407);
	lua_setfield(L, -2, "Firetruck");

	lua_pushinteger(L, 408);
	lua_setfield(L, -2, "Trashmaster");

	lua_pushinteger(L, 409);
	lua_setfield(L, -2, "Stretch");

	lua_pushinteger(L, 410);
	lua_setfield(L, -2, "Manana");

	lua_pushinteger(L, 411);
	lua_setfield(L, -2, "Infernus");

	lua_pushinteger(L, 412);
	lua_setfield(L, -2, "Voodoo");

	lua_pushinteger(L, 413);
	lua_setfield(L, -2, "Pony");

	lua_pushinteger(L, 414);
	lua_setfield(L, -2, "Mule");

	lua_pushinteger(L, 415);
	lua_setfield(L, -2, "Cheetah");

	lua_pushinteger(L, 416);
	lua_setfield(L, -2, "Ambulance");

	lua_pushinteger(L, 417);
	lua_setfield(L, -2, "Leviathan");

	lua_pushinteger(L, 418);
	lua_setfield(L, -2, "Moonbeam");

	lua_pushinteger(L, 419);
	lua_setfield(L, -2, "Esperanto");

	lua_pushinteger(L, 420);
	lua_setfield(L, -2, "Taxi");

	lua_pushinteger(L, 421);
	lua_setfield(L, -2, "Washington");

	lua_pushinteger(L, 422);
	lua_setfield(L, -2, "Bobcat");

	lua_pushinteger(L, 423);
	lua_setfield(L, -2, "MrWhoopee");

	lua_pushinteger(L, 424);
	lua_setfield(L, -2, "BFInjection");

	lua_pushinteger(L, 425);
	lua_setfield(L, -2, "Hunter");

	lua_pushinteger(L, 426);
	lua_setfield(L, -2, "Premier");

	lua_pushinteger(L, 427);
	lua_setfield(L, -2, "Enforcer");

	lua_pushinteger(L, 428);
	lua_setfield(L, -2, "Securicar");

	lua_pushinteger(L, 429);
	lua_setfield(L, -2, "Banshee");

	lua_pushinteger(L, 430);
	lua_setfield(L, -2, "Predator");

	lua_pushinteger(L, 431);
	lua_setfield(L, -2, "Bus");

	lua_pushinteger(L, 432);
	lua_setfield(L, -2, "Rhino");

	lua_pushinteger(L, 433);
	lua_setfield(L, -2, "Barracks");

	lua_pushinteger(L, 434);
	lua_setfield(L, -2, "Hotknife");

	lua_pushinteger(L, 435);
	lua_setfield(L, -2, "ArticleTrailer");

	lua_pushinteger(L, 436);
	lua_setfield(L, -2, "Previon");

	lua_pushinteger(L, 437);
	lua_setfield(L, -2, "Coach");

	lua_pushinteger(L, 438);
	lua_setfield(L, -2, "Cabbie");

	lua_pushinteger(L, 439);
	lua_setfield(L, -2, "Stallion");

	lua_pushinteger(L, 440);
	lua_setfield(L, -2, "Rumpo");

	lua_pushinteger(L, 441);
	lua_setfield(L, -2, "RCBandit");

	lua_pushinteger(L, 442);
	lua_setfield(L, -2, "Romero");

	lua_pushinteger(L, 443);
	lua_setfield(L, -2, "Packer");

	lua_pushinteger(L, 444);
	lua_setfield(L, -2, "Monster");

	lua_pushinteger(L, 445);
	lua_setfield(L, -2, "Admiral");

	lua_pushinteger(L, 446);
	lua_setfield(L, -2, "Squallo");

	lua_pushinteger(L, 447);
	lua_setfield(L, -2, "Seasparrow");

	lua_pushinteger(L, 448);
	lua_setfield(L, -2, "Pizzaboy");

	lua_pushinteger(L, 449);
	lua_setfield(L, -2, "Tram");

	lua_pushinteger(L, 450);
	lua_setfield(L, -2, "ArticleTrailer2");

	lua_pushinteger(L, 451);
	lua_setfield(L, -2, "Turismo");

	lua_pushinteger(L, 452);
	lua_setfield(L, -2, "Speeder");

	lua_pushinteger(L, 453);
	lua_setfield(L, -2, "Reefer");

	lua_pushinteger(L, 454);
	lua_setfield(L, -2, "Tropic");

	lua_pushinteger(L, 455);
	lua_setfield(L, -2, "Flatbed");

	lua_pushinteger(L, 456);
	lua_setfield(L, -2, "Yankee");

	lua_pushinteger(L, 457);
	lua_setfield(L, -2, "Caddy");

	lua_pushinteger(L, 458);
	lua_setfield(L, -2, "Solair");

	lua_pushinteger(L, 459);
	lua_setfield(L, -2, "TopfunVanBerkleyRC");

	lua_pushinteger(L, 460);
	lua_setfield(L, -2, "Skimmer");

	lua_pushinteger(L, 461);
	lua_setfield(L, -2, "PCJ600");

	lua_pushinteger(L, 462);
	lua_setfield(L, -2, "Faggio");

	lua_pushinteger(L, 463);
	lua_setfield(L, -2, "Freeway");

	lua_pushinteger(L, 464);
	lua_setfield(L, -2, "RCBaron");

	lua_pushinteger(L, 465);
	lua_setfield(L, -2, "RCRaider");

	lua_pushinteger(L, 466);
	lua_setfield(L, -2, "Glendale");

	lua_pushinteger(L, 467);
	lua_setfield(L, -2, "Oceanic");

	lua_pushinteger(L, 468);
	lua_setfield(L, -2, "Sanchez");

	lua_pushinteger(L, 469);
	lua_setfield(L, -2, "Sparrow");

	lua_pushinteger(L, 470);
	lua_setfield(L, -2, "Patriot");

	lua_pushinteger(L, 471);
	lua_setfield(L, -2, "Quad");

	lua_pushinteger(L, 472);
	lua_setfield(L, -2, "Coastguard");

	lua_pushinteger(L, 473);
	lua_setfield(L, -2, "Dinghy");

	lua_pushinteger(L, 474);
	lua_setfield(L, -2, "Hermes");

	lua_pushinteger(L, 475);
	lua_setfield(L, -2, "Sabre");

	lua_pushinteger(L, 476);
	lua_setfield(L, -2, "Rustler");

	lua_pushinteger(L, 477);
	lua_setfield(L, -2, "ZR350");

	lua_pushinteger(L, 478);
	lua_setfield(L, -2, "Walton");

	lua_pushinteger(L, 479);
	lua_setfield(L, -2, "Regina");

	lua_pushinteger(L, 480);
	lua_setfield(L, -2, "Comet");

	lua_pushinteger(L, 481);
	lua_setfield(L, -2, "BMX");

	lua_pushinteger(L, 482);
	lua_setfield(L, -2, "Burrito");

	lua_pushinteger(L, 483);
	lua_setfield(L, -2, "Camper");

	lua_pushinteger(L, 484);
	lua_setfield(L, -2, "Marquis");

	lua_pushinteger(L, 485);
	lua_setfield(L, -2, "Baggage");

	lua_pushinteger(L, 486);
	lua_setfield(L, -2, "Dozer");

	lua_pushinteger(L, 487);
	lua_setfield(L, -2, "Maverick");

	lua_pushinteger(L, 488);
	lua_setfield(L, -2, "SANNewsMaverick");

	lua_pushinteger(L, 489);
	lua_setfield(L, -2, "Rancher");

	lua_pushinteger(L, 490);
	lua_setfield(L, -2, "FBIRancher");

	lua_pushinteger(L, 491);
	lua_setfield(L, -2, "Virgo");

	lua_pushinteger(L, 492);
	lua_setfield(L, -2, "Greenwood");

	lua_pushinteger(L, 493);
	lua_setfield(L, -2, "Jetmax");

	lua_pushinteger(L, 494);
	lua_setfield(L, -2, "HotringRacer");

	lua_pushinteger(L, 495);
	lua_setfield(L, -2, "Sandking");

	lua_pushinteger(L, 496);
	lua_setfield(L, -2, "BlistaCompact");

	lua_pushinteger(L, 497);
	lua_setfield(L, -2, "PoliceMaverick");

	lua_pushinteger(L, 498);
	lua_setfield(L, -2, "Boxville");

	lua_pushinteger(L, 499);
	lua_setfield(L, -2, "Benson");

	lua_pushinteger(L, 500);
	lua_setfield(L, -2, "Mesa");

	lua_pushinteger(L, 501);
	lua_setfield(L, -2, "RCGoblin");

	lua_pushinteger(L, 502);
	lua_setfield(L, -2, "HotringRacerA");

	lua_pushinteger(L, 503);
	lua_setfield(L, -2, "HotringRacerB");

	lua_pushinteger(L, 504);
	lua_setfield(L, -2, "BloodringBanger");

	lua_pushinteger(L, 505);
	lua_setfield(L, -2, "RancherLure");

	lua_pushinteger(L, 506);
	lua_setfield(L, -2, "SuperGT");

	lua_pushinteger(L, 507);
	lua_setfield(L, -2, "Elegant");

	lua_pushinteger(L, 508);
	lua_setfield(L, -2, "Journey");

	lua_pushinteger(L, 509);
	lua_setfield(L, -2, "Bike");

	lua_pushinteger(L, 510);
	lua_setfield(L, -2, "MountainBike");

	lua_pushinteger(L, 511);
	lua_setfield(L, -2, "Beagle");

	lua_pushinteger(L, 512);
	lua_setfield(L, -2, "Cropduster");

	lua_pushinteger(L, 513);
	lua_setfield(L, -2, "Stuntplane");

	lua_pushinteger(L, 514);
	lua_setfield(L, -2, "Tanker");

	lua_pushinteger(L, 515);
	lua_setfield(L, -2, "Roadtrain");

	lua_pushinteger(L, 516);
	lua_setfield(L, -2, "Nebula");

	lua_pushinteger(L, 517);
	lua_setfield(L, -2, "Majestic");

	lua_pushinteger(L, 518);
	lua_setfield(L, -2, "Buccaneer");

	lua_pushinteger(L, 519);
	lua_setfield(L, -2, "Shamal");

	lua_pushinteger(L, 520);
	lua_setfield(L, -2, "Hydra");

	lua_pushinteger(L, 521);
	lua_setfield(L, -2, "FCR900");

	lua_pushinteger(L, 522);
	lua_setfield(L, -2, "NRG500");

	lua_pushinteger(L, 523);
	lua_setfield(L, -2, "HPV1000");

	lua_pushinteger(L, 524);
	lua_setfield(L, -2, "CementTruck");

	lua_pushinteger(L, 525);
	lua_setfield(L, -2, "Towtruck");

	lua_pushinteger(L, 526);
	lua_setfield(L, -2, "Fortune");

	lua_pushinteger(L, 527);
	lua_setfield(L, -2, "Cadrona");

	lua_pushinteger(L, 528);
	lua_setfield(L, -2, "FBITruck");

	lua_pushinteger(L, 529);
	lua_setfield(L, -2, "Willard");

	lua_pushinteger(L, 530);
	lua_setfield(L, -2, "Forklift");

	lua_pushinteger(L, 531);
	lua_setfield(L, -2, "Tractor");

	lua_pushinteger(L, 532);
	lua_setfield(L, -2, "CombineHarvester");

	lua_pushinteger(L, 533);
	lua_setfield(L, -2, "Feltzer");

	lua_pushinteger(L, 534);
	lua_setfield(L, -2, "Remington");

	lua_pushinteger(L, 535);
	lua_setfield(L, -2, "Slamvan");

	lua_pushinteger(L, 536);
	lua_setfield(L, -2, "Blade");

	lua_pushinteger(L, 537);
	lua_setfield(L, -2, "FreightTrain");

	lua_pushinteger(L, 538);
	lua_setfield(L, -2, "BrownstreakTrain");

	lua_pushinteger(L, 539);
	lua_setfield(L, -2, "Vortex");

	lua_pushinteger(L, 540);
	lua_setfield(L, -2, "Vincent");

	lua_pushinteger(L, 541);
	lua_setfield(L, -2, "Bullet");

	lua_pushinteger(L, 542);
	lua_setfield(L, -2, "Clover");

	lua_pushinteger(L, 543);
	lua_setfield(L, -2, "Sadler");

	lua_pushinteger(L, 544);
	lua_setfield(L, -2, "FiretruckLA");

	lua_pushinteger(L, 545);
	lua_setfield(L, -2, "Hustler");

	lua_pushinteger(L, 546);
	lua_setfield(L, -2, "Intruder");

	lua_pushinteger(L, 547);
	lua_setfield(L, -2, "Primo");

	lua_pushinteger(L, 548);
	lua_setfield(L, -2, "Cargobob");

	lua_pushinteger(L, 549);
	lua_setfield(L, -2, "Tampa");

	lua_pushinteger(L, 550);
	lua_setfield(L, -2, "Sunrise");

	lua_pushinteger(L, 551);
	lua_setfield(L, -2, "Merit");

	lua_pushinteger(L, 552);
	lua_setfield(L, -2, "UtilityVan");

	lua_pushinteger(L, 553);
	lua_setfield(L, -2, "Nevada");

	lua_pushinteger(L, 554);
	lua_setfield(L, -2, "Yosemite");

	lua_pushinteger(L, 555);
	lua_setfield(L, -2, "Windsor");

	lua_pushinteger(L, 556);
	lua_setfield(L, -2, "MonsterA");

	lua_pushinteger(L, 557);
	lua_setfield(L, -2, "MonsterB");

	lua_pushinteger(L, 558);
	lua_setfield(L, -2, "Uranus");

	lua_pushinteger(L, 559);
	lua_setfield(L, -2, "Jester");

	lua_pushinteger(L, 560);
	lua_setfield(L, -2, "Sultan");

	lua_pushinteger(L, 561);
	lua_setfield(L, -2, "Stratum");

	lua_pushinteger(L, 562);
	lua_setfield(L, -2, "Elegy");

	lua_pushinteger(L, 563);
	lua_setfield(L, -2, "Raindance");

	lua_pushinteger(L, 564);
	lua_setfield(L, -2, "RCTiger");

	lua_pushinteger(L, 565);
	lua_setfield(L, -2, "Flash");

	lua_pushinteger(L, 566);
	lua_setfield(L, -2, "Tahoma");

	lua_pushinteger(L, 567);
	lua_setfield(L, -2, "Savanna");

	lua_pushinteger(L, 568);
	lua_setfield(L, -2, "Bandito");

	lua_pushinteger(L, 569);
	lua_setfield(L, -2, "FreightFlatTrailerTrain");

	lua_pushinteger(L, 570);
	lua_setfield(L, -2, "StreakTrailerTrain");

	lua_pushinteger(L, 571);
	lua_setfield(L, -2, "Kart");

	lua_pushinteger(L, 572);
	lua_setfield(L, -2, "Mower");

	lua_pushinteger(L, 573);
	lua_setfield(L, -2, "Dune");

	lua_pushinteger(L, 574);
	lua_setfield(L, -2, "Sweeper");

	lua_pushinteger(L, 575);
	lua_setfield(L, -2, "Broadway");

	lua_pushinteger(L, 576);
	lua_setfield(L, -2, "Tornado");

	lua_pushinteger(L, 577);
	lua_setfield(L, -2, "AT400");

	lua_pushinteger(L, 578);
	lua_setfield(L, -2, "DFT30");

	lua_pushinteger(L, 579);
	lua_setfield(L, -2, "Huntley");

	lua_pushinteger(L, 580);
	lua_setfield(L, -2, "Stafford");

	lua_pushinteger(L, 581);
	lua_setfield(L, -2, "BF400");

	lua_pushinteger(L, 582);
	lua_setfield(L, -2, "Newsvan");

	lua_pushinteger(L, 583);
	lua_setfield(L, -2, "Tug");

	lua_pushinteger(L, 584);
	lua_setfield(L, -2, "PetrolTrailer");

	lua_pushinteger(L, 585);
	lua_setfield(L, -2, "Emperor");

	lua_pushinteger(L, 586);
	lua_setfield(L, -2, "Wayfarer");

	lua_pushinteger(L, 587);
	lua_setfield(L, -2, "Euros");

	lua_pushinteger(L, 588);
	lua_setfield(L, -2, "Hotdog");

	lua_pushinteger(L, 589);
	lua_setfield(L, -2, "Club");

	lua_pushinteger(L, 590);
	lua_setfield(L, -2, "FreightBoxTrailerTrain");

	lua_pushinteger(L, 591);
	lua_setfield(L, -2, "ArticleTrailer3");

	lua_pushinteger(L, 592);
	lua_setfield(L, -2, "Andromada");

	lua_pushinteger(L, 593);
	lua_setfield(L, -2, "Dodo");

	lua_pushinteger(L, 594);
	lua_setfield(L, -2, "RCCam");

	lua_pushinteger(L, 595);
	lua_setfield(L, -2, "Launch");

	lua_pushinteger(L, 596);
	lua_setfield(L, -2, "PoliceCarLSPD");

	lua_pushinteger(L, 597);
	lua_setfield(L, -2, "PoliceCarSFPD");

	lua_pushinteger(L, 598);
	lua_setfield(L, -2, "PoliceCarLVPD");

	lua_pushinteger(L, 599);
	lua_setfield(L, -2, "PoliceRanger");

	lua_pushinteger(L, 600);
	lua_setfield(L, -2, "Picador");

	lua_pushinteger(L, 601);
	lua_setfield(L, -2, "SWAT");

	lua_pushinteger(L, 602);
	lua_setfield(L, -2, "Alpha");

	lua_pushinteger(L, 603);
	lua_setfield(L, -2, "Phoenix");

	lua_pushinteger(L, 604);
	lua_setfield(L, -2, "GlendaleShit");

	lua_pushinteger(L, 605);
	lua_setfield(L, -2, "SadlerShit");

	lua_pushinteger(L, 606);
	lua_setfield(L, -2, "BaggageTrailerA");

	lua_pushinteger(L, 607);
	lua_setfield(L, -2, "BaggageTrailerB");

	lua_pushinteger(L, 608);
	lua_setfield(L, -2, "TugStairsTrailer");

	lua_pushinteger(L, 609);
	lua_setfield(L, -2, "Boxville");

	lua_pushinteger(L, 610);
	lua_setfield(L, -2, "FarmTrailer");

	lua_pushinteger(L, 611);
	lua_setfield(L, -2, "UtilityTrailer");

	lua_setglobal(L, "VehicleModel");
	lua_stacktrace(L, "Vehicle table");

}

int CVehicleFuncDefs::createVehicle(lua_State *L)
{
	int modelid;
	float x, y, z;
	float rotation;
	int color1, color2;

	CArgReader argReader(L);
	argReader.ReadNumber(modelid);
	argReader.ReadNumber(x);
	argReader.ReadNumber(y);
	argReader.ReadNumber(z);
	argReader.ReadNumber(rotation);
	argReader.ReadNumber(color1);
	argReader.ReadNumber(color2);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	CVehicle *vehicle = new CVehicle(modelid, x, y, z, rotation, color1, color2, -1);
	lua_userdata(L, vehicle->getEntityTypeName(), vehicle);
	//CVehicle **vehicle = reinterpret_cast<CVehicle **>(lua_newuserdata(L, sizeof(CVehicle*)));

	//CVehicle *vehicle = new CVehicle(modelid, x, y, z, rotation, color1, color2);
	sampgdk::logprintf("vehicle data: %d | %f %f %f | %f | %d %d", modelid, x, y, z, rotation, color1, color2);

	return 1;
}

int CVehicleFuncDefs::setVehiclePosition(lua_State *L)
{
	CVehicle *vehicle;
	float x, y, z;

	CArgReader argReader(L);
	argReader.ReadUserData(vehicle);
	argReader.ReadNumber(x);
	argReader.ReadNumber(y);
	argReader.ReadNumber(z);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	lua_pushboolean(L, 1);

	//vehicle->setPos(x, y, z);

	lua_stacktrace(L, "setVehiclePosition");
	return 1;
}

int CVehicleFuncDefs::getVehiclePosition(lua_State *L)
{

	CVehicle *vehicle;

	CArgReader argReader(L);
	argReader.ReadUserData(vehicle);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	Vector4 vehiclePosition = vehicle->getPos();
	//sampgdk::InvokeNativeArray()
	int vehicleid = vehicle->getVehicleID();
	float x, y, z;
	void *haha[4];
	haha[0] = &vehicleid;
	haha[1] = &x;
	haha[2] = &y;
	haha[3] = &z;
	void *somepointer = &haha;
	AMX_NATIVE someNativeFunction = sampgdk::FindNative("getVehiclePos");
	sampgdk::logprintf("someNativeFunction: %d", someNativeFunction);
	sampgdk::InvokeNativeArray(someNativeFunction, "dRRR", haha);

	sampgdk::logprintf("Haha: %f %f %f", x, y, z);

	lua_pushinteger(L, static_cast<lua_Number>(vehiclePosition.x));
	lua_pushinteger(L, static_cast<lua_Number>(vehiclePosition.y));
	lua_pushinteger(L, static_cast<lua_Number>(vehiclePosition.z));
	lua_pushinteger(L, static_cast<lua_Number>(vehiclePosition.w));

	lua_stacktrace(L, "getVehiclePosition");
	return 4;
}