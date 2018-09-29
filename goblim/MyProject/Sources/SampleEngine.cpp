/*
EngineGL overloaded for custom rendering
*/
#include "SampleEngine.h"
#include "Engine/OpenGL/v4/GLProgram.h"
#include "Engine/OpenGL/SceneLoaderGL.h"
#include "Engine/Base/NodeCollectors/MeshNodeCollector.h"
#include "Engine/Base/NodeCollectors/FCCollector.h"
#include "Engine/OpenGL/Lighting/LightingModelGL.h"

#include "Materials/TPMaterial/TPMaterial.h"
#include "Materials/MoonMaterial/MoonMaterial.h"
#include "Materials/EnvMaterial/EnvMaterial.h"
#include "Materials/SmokeMaterial/SmokeMaterial.h"
#include "Materials/SunMaterial/SunMaterial.h"
#include "Materials/GrassGroundMaterial/GrassGroundMaterial.h"
#include "Materials/DirtGroundMaterial/DirtGroundMaterial.h"
#include "Materials/TreeMaterial/TreeMaterial.h"
#include "Materials/TrunkMaterial/TrunkMaterial.h"
#include "Materials/RockMaterial/RockMaterial.h"
#include "Materials/ThunderBoltMaterial/ThunderBoltMaterial.h"
#include "Materials/SpaceShipMaterial/SpaceShipMaterial.h"
#include "Materials/GlassMaterial/GlassMaterial.h"
#include "Materials/ReactorFireMaterial/ReactorFireMaterial.h"
#include "Materials/ReactorMaterial/ReactorMaterial.h"
#include "Materials/BaseFireMaterial/BaseFireMaterial.h"
#include "Materials/CampFireMaterial/CampFireMaterial.h"
#include "Materials/TreeShadowMaterial/TreeShadowMaterial.h"
#include "Materials/SmokeFireMaterial/SmokeFireMaterial.h"
#include "Materials/SunLightMaterial/SunLightMaterial.h"
#include "Materials/FireLightMaterial/FireLightMaterial.h"

#include "GPUResources/GPUInfo.h"


SampleEngine::SampleEngine(int width, int height) :
EngineGL (width, height)
{
	LOG_INFO << "# - " << __FUNCTION__ << std::endl;
	
	
}

SampleEngine::~SampleEngine()
{


}


bool SampleEngine::init(std::string filename)
{
	// Sphere englobante espace - étoile - nébuleuse
	EnvMaterial* envMaterial = new EnvMaterial("EnvMaterial");
	Node* env = scene->getNode("env");
	env->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	env->frame()->scale(glm::vec3(2.0));
	env->frame()->translate(glm::vec3(0, 0, 0));
	env->setMaterial(envMaterial);
	scene->getSceneNode()->adopt(env);

	// Le soleil
	SunMaterial* sunMaterial = new SunMaterial("SunMaterial");
	Node* sun = scene->getNode("sun");
	sun->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	sun->frame()->scale(glm::vec3(0.03));
	sun->frame()->translate(glm::vec3(0, 10, -500));
	sun->setMaterial(sunMaterial);
	scene->getSceneNode()->adopt(sun);

	// La lune
	MoonMaterial* moonMaterial = new MoonMaterial("MoonMaterial");
	Node* moon = scene->getNode("moon");
	moon->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	moon->frame()->scale(glm::vec3(0.008));
	moon->frame()->translate(glm::vec3(700, 200, -350));
	moon->frame()->rotate(glm::vec3(0, 10, 0), 35);
	moon->setMaterial(moonMaterial);
	scene->getSceneNode()->adopt(moon);

	// Eclaire
	/*
	ThunderBoltMaterial* thunderBoltMaterial = new ThunderBoltMaterial("ThunderBoltMaterial");
	Node* thunderBolt = scene->getNode("thunderBolt");
	thunderBolt->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "ThunderBolt.obj"));
	thunderBolt->frame()->scale(glm::vec3(2));
	thunderBolt->frame()->translate(glm::vec3(0.2, 1.6, 0));
	thunderBolt->setMaterial(thunderBoltMaterial);
	scene->getSceneNode()->adopt(thunderBolt);
	*/

	// Sol herbe
	GrassGroundMaterial* grassGroundMaterial = new GrassGroundMaterial("GrassGroundMaterial");
	Node* grassGround = scene->getNode("grassGround");
	grassGround->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "GrassGround.obj"));
	grassGround->frame()->scale(glm::vec3(7));
	grassGround->frame()->translate(glm::vec3(0, -0.2, 0));
	grassGround->setMaterial(grassGroundMaterial);
	scene->getSceneNode()->adopt(grassGround);

	// Sol terre
	DirtGroundMaterial* dirtGroundMaterial = new DirtGroundMaterial("DirtGroundMaterial");
	Node* dirtGround = scene->getNode("dirtGround");
	dirtGround->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "DirtGround.obj"));
	dirtGround->frame()->scale(glm::vec3(7));
	dirtGround->frame()->translate(glm::vec3(0, -0.2, 0));
	dirtGround->setMaterial(dirtGroundMaterial);
	scene->getSceneNode()->adopt(dirtGround);

	//Rock
	RockMaterial* rockMaterial = new RockMaterial("RockMaterial");
	Node* rock = scene->getNode("rock");
	rock->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Rock1.obj"));
	rock->frame()->scale(glm::vec3(1));
	rock->frame()->translate(glm::vec3(0.03, -0.3, -0.7));
	rock->setMaterial(rockMaterial);
	scene->getSceneNode()->adopt(rock);

	//Rock 2
	RockMaterial* rockMaterial2 = new RockMaterial("RockMaterial");
	Node* rock2 = scene->getNode("rock2");
	rock2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Rock2.obj"));
	rock2->frame()->scale(glm::vec3(1));
	rock2->frame()->translate(glm::vec3(0.03, -0.3, -0.7));
	rock2->setMaterial(rockMaterial2);
	scene->getSceneNode()->adopt(rock2);

	//Rock 3
	RockMaterial* rockMaterial3 = new RockMaterial("RockMaterial");
	Node* rock3 = scene->getNode("rock3");
	rock3->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Rock3.obj"));
	rock3->frame()->scale(glm::vec3(1));
	rock3->frame()->translate(glm::vec3(0.03, -0.3, -0.7));
	rock3->setMaterial(rockMaterial3);
	scene->getSceneNode()->adopt(rock3);

	//Rock 4
	RockMaterial* rockMaterial4 = new RockMaterial("RockMaterial");
	Node* rock4 = scene->getNode("rock4");
	rock4->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Rock4.obj"));
	rock4->frame()->scale(glm::vec3(1));
	rock4->frame()->translate(glm::vec3(0.03, -0.3, -0.7));
	rock4->setMaterial(rockMaterial4);
	scene->getSceneNode()->adopt(rock4);

	//Arbre 1
	// Tronc 
	TrunkMaterial* trunkMaterial = new TrunkMaterial("TrunkMaterial");
	Node* trunk = scene->getNode("trunk");
	trunk->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Trunk.obj"));
	trunk->frame()->scale(glm::vec3(10));
	trunk->frame()->translate(glm::vec3(0.25, 0.0, 0));
	trunk->setMaterial(trunkMaterial);
	scene->getSceneNode()->adopt(trunk);

	// Feuillage 
	TreeMaterial* treeMaterial = new TreeMaterial("TreeMaterial");
	Node* tree = scene->getNode("tree");
	tree->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Tree.obj"));
	tree->frame()->scale(glm::vec3(10));
	tree->frame()->translate(glm::vec3(0.25, 0.03, 0));
	tree->setMaterial(treeMaterial);
	scene->getSceneNode()->adopt(tree);

	// Ombre 
	TreeShadowMaterial* treeShadowMaterial = new TreeShadowMaterial("TreeShadowMaterial");
	Node* treeShadow = scene->getNode("treeShadow");
	treeShadow->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "TreeShadow.obj"));
	treeShadow->frame()->scale(glm::vec3(8));
	treeShadow->frame()->translate(glm::vec3(0.315, 0.0048, 0));
	treeShadow->setMaterial(treeShadowMaterial);
	scene->getSceneNode()->adopt(treeShadow);

	//Arbre 2
	// Tronc
	TrunkMaterial* trunkMaterial2 = new TrunkMaterial("TrunkMaterial");
	Node* trunk2 = scene->getNode("trunk2");
	trunk2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Trunk.obj"));
	trunk2->frame()->scale(glm::vec3(10));
	trunk2->frame()->translate(glm::vec3(-0.1, 0.0, -0.15));
	trunk2->setMaterial(trunkMaterial2);
	scene->getSceneNode()->adopt(trunk2);

	// Feuillage 
	TreeMaterial* treeMaterial2 = new TreeMaterial("TreeMaterial");
	Node* tree2 = scene->getNode("tree2");
	tree2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Tree.obj"));
	tree2->frame()->scale(glm::vec3(10));
	tree2->frame()->translate(glm::vec3(-0.1, 0.03, -0.15));
	tree2->setMaterial(treeMaterial);
	scene->getSceneNode()->adopt(tree2);

	// Ombre 
	TreeShadowMaterial* treeShadowMaterial2 = new TreeShadowMaterial("TreeShadowMaterial");
	Node* treeShadow2 = scene->getNode("treeShadow2");
	treeShadow2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "TreeShadow.obj"));
	treeShadow2->frame()->scale(glm::vec3(8));
	treeShadow2->frame()->translate(glm::vec3(-0.12238, 0.0048, -0.19));
	treeShadow2->setMaterial(treeShadowMaterial2);
	scene->getSceneNode()->adopt(treeShadow2);

	//Arbre 3
	// Tronc
	TrunkMaterial* trunkMaterial3 = new TrunkMaterial("TrunkMaterial");
	Node* trunk3 = scene->getNode("trunk3");
	trunk3->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Trunk.obj"));
	trunk3->frame()->scale(glm::vec3(10));
	trunk3->frame()->translate(glm::vec3(-0.05, 0.0, 0.09));
	trunk3->setMaterial(trunkMaterial3);
	scene->getSceneNode()->adopt(trunk3);

	// Feuillage 
	TreeMaterial* treeMaterial3 = new TreeMaterial("TreeMaterial");
	Node* tree3 = scene->getNode("tree3");
	tree3->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Tree.obj"));
	tree3->frame()->scale(glm::vec3(10));
	tree3->frame()->translate(glm::vec3(-0.05, 0.03, 0.09));
	tree3->setMaterial(treeMaterial3);
	scene->getSceneNode()->adopt(tree3);

	// Ombre 
	TreeShadowMaterial* treeShadowMaterial3 = new TreeShadowMaterial("TreeShadowMaterial");
	Node* treeShadow3 = scene->getNode("treeShadow3");
	treeShadow3->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "TreeShadow.obj"));
	treeShadow3->frame()->scale(glm::vec3(8));
	treeShadow3->frame()->translate(glm::vec3(-0.060, 0.0048, 0.11));
	treeShadow3->setMaterial(treeShadowMaterial3);
	scene->getSceneNode()->adopt(treeShadow3);

	//blur = scene->getEffect<Blur>("Blur");
	//fboTest = scene->getResource<GPUFBO>("Test");
	//fboTest->createTexture2DAttachments(1024, 1024);


	// Vaisseau Spatial
	SpaceShipMaterial* spaceShipMaterial = new SpaceShipMaterial("SpaceShipMaterial");
	Node* spaceShip = scene->getNode("spaceShip");
	spaceShip->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "SpaceShip.obj"));
	spaceShip->frame()->scale(glm::vec3(0.15));
	spaceShip->frame()->translate(glm::vec3(-14, 7, 0));
	spaceShip->setMaterial(spaceShipMaterial);
	scene->getSceneNode()->adopt(spaceShip);

	// Vaisseau Spatial cockpit
	GlassMaterial* glassMaterial = new GlassMaterial("GlassMaterial");
	Node* glass = scene->getNode("glass");
	glass->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Capsule.obj"));
	glass->frame()->scale(glm::vec3(0.15));
	glass->frame()->translate(glm::vec3(-14, 7, 0));
	glass->setMaterial(glassMaterial);
	scene->getSceneNode()->adopt(glass);

	// Vaisseau Spatial reacteur
	ReactorMaterial* reactorMaterial = new ReactorMaterial("ReactorMaterial");
	Node* reactor = scene->getNode("reactor");
	reactor->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "SpaceShipReactor3.obj"));
	reactor->frame()->scale(glm::vec3(0.15));
	reactor->frame()->translate(glm::vec3(-14, 7, 0));
	reactor->setMaterial(reactorMaterial);
	scene->getSceneNode()->adopt(reactor);

	// Vaisseau Spatial reacteur feu
	ReactorFireMaterial* reactorFireMaterial = new ReactorFireMaterial("ReactorFireMaterial");
	Node* reactorFire = scene->getNode("reactorFire");
	reactorFire->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "SpaceShipReactor.obj"));
	reactorFire->frame()->scale(glm::vec3(0.15));
	reactorFire->frame()->translate(glm::vec3(-14, 7, 0));
	reactorFire->setMaterial(reactorFireMaterial);
	scene->getSceneNode()->adopt(reactorFire);

	// Feu de camp base
	BaseFireMaterial* baseFireMaterial = new BaseFireMaterial("BaseFireMaterial");
	Node* baseFire = scene->getNode("baseFire");
	baseFire->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "CampFireBase.obj"));
	baseFire->frame()->scale(glm::vec3(0.3));
	baseFire->frame()->translate(glm::vec3(2.3, 0.07, -1.5));
	baseFire->setMaterial(baseFireMaterial);
	scene->getSceneNode()->adopt(baseFire);
	
	// Feu de camp
	CampFireMaterial* campFireMaterial = new CampFireMaterial("CampFireMaterial");
	Node* campFire = scene->getNode("campFire");
	campFire->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "CampFire.obj"));
	campFire->frame()->scale(glm::vec3(0.3));
	campFire->frame()->translate(glm::vec3(2.3, 0.08, -1.5));
	campFire->setMaterial(campFireMaterial);
	scene->getSceneNode()->adopt(campFire);

	// Lumiére feu de camp
	FireLightMaterial* fireLightMaterial = new FireLightMaterial("FireLightMaterial");
	Node* fireLight = scene->getNode("fireLight");
	fireLight->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	fireLight->frame()->translate(glm::vec3(0.7, 0.032, -0.4));
	fireLight->frame()->scale(glm::vec3(0.01, 0.0, 0.01));
	fireLight->setMaterial(fireLightMaterial);
	scene->getSceneNode()->adopt(fireLight);

	// Fumée feu de camp
	SmokeFireMaterial* smokeFireMaterial = new SmokeFireMaterial("SmokeFireMaterial");
	Node* smokeFire = scene->getNode("smokeFire");
	smokeFire->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	smokeFire->frame()->translate(glm::vec3(0.67, 0.45, -0.44));
	smokeFire->frame()->scale(glm::vec3(0.0015));
	smokeFire->setMaterial(smokeFireMaterial);
	scene->getSceneNode()->adopt(smokeFire);
	
	SmokeFireMaterial* smokeFireMaterial2 = new SmokeFireMaterial("SmokeFireMaterial");
	Node* smokeFire2 = scene->getNode("smokeFire2");
	smokeFire2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	smokeFire2->frame()->translate(glm::vec3(0.67, 0.72, -0.44));
	smokeFire2->frame()->scale(glm::vec3(0.0025));
	smokeFire2->setMaterial(smokeFireMaterial2);
	scene->getSceneNode()->adopt(smokeFire2);

	SmokeFireMaterial* smokeFireMaterial3 = new SmokeFireMaterial("SmokeFireMaterial");
	Node* smokeFire3 = scene->getNode("smokeFire3");
	smokeFire3->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	smokeFire3->frame()->translate(glm::vec3(0.67, 1.19, -0.44));
	smokeFire3->frame()->scale(glm::vec3(0.005));
	smokeFire3->setMaterial(smokeFireMaterial3);
	scene->getSceneNode()->adopt(smokeFire3);

	// Nuage
	/*
	SmokeMaterial* smokeMaterial = new SmokeMaterial("SmokeMaterial");
	Node* smoke = scene->getNode("smoke");
	smoke->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	smoke->frame()->scale(glm::vec3(0.052));
	smoke->frame()->translate(glm::vec3(0, 110, 0));
	smoke->setMaterial(smokeMaterial);
	scene->getSceneNode()->adopt(smoke);
	*/

	// Eclairage soleil
	SunLightMaterial* sunLightMaterial = new SunLightMaterial("SunLightMaterial");
	Node* sunLight = scene->getNode("sunLight");
	sunLight->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	sunLight->frame()->scale(glm::vec3(0.52));
	sunLight->frame()->translate(glm::vec3(0.67, 0.45, -0.44));
	sunLight->setMaterial(sunLightMaterial);
	scene->getSceneNode()->adopt(sunLight);

	// Eclairage feu
	/*
	SmokeMaterial* smokeMaterial2 = new SmokeMaterial("SmokeMaterial");
	Node* smoke2 = scene->getNode("smoke2");
	smoke2->setModel(scene->m_Models.get<ModelGL>(ressourceCoreObjPath + "Sphere.obj"));
	smoke2->frame()->translate(glm::vec3(0.7, -0.005, -0.4));
	smoke2->frame()->scale(glm::vec3(0.007));
	smoke2->setMaterial(smokeMaterial2);
	scene->getSceneNode()->adopt(smoke2);
	*/

	setUpEngine();
	LOG_INFO << "initialisation complete" << std::endl;
	return(true);
}

void SampleEngine::render ()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//fboTest->enable();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (unsigned int i = 0; i < renderedNodes->nodes.size(); i++) {
		renderedNodes->nodes[i]->render();
	}
	//fboTest->disable();
	//blur->apply(fboTest);
	//fboTest->display();

	drawBBAndLight();
}


void SampleEngine::animate(const int elapsedTime)
{
	// Animate each node
	for (unsigned int i = 0; i < allNodes->nodes.size(); i++)
		allNodes->nodes[i]->animate(elapsedTime);
	// force update of lighting model
	lightingModel->update(true);
	Scene::getInstance()->camera()->updateBuffer();
}
