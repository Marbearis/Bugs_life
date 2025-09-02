class CfgPatches
{
	class Marbys_Bugs_Life
	{
		units[] = {"MAR_ANT_Basic","MAR_ANT_Ice","MAR_ANT_Spitter","MAR_antHill","MAR_Spider_Burrower","MAR_TrapDoor","MAR_Ant_Egg","MAR_Ant_Egg_Clutch",
        "MAR_Ant_Part_Head","MAR_Ant_Part_Thorax","MAR_Ant_Part_Abdomen","MAR_Ant_Part_Leg","MAR_Ant_Part_Mandible","MAR_Ant_Part_Antenne","MAR_ANT_QUEEN","MAR_Ant_Webs","MAR_Ant_Webs_2","MAR_Spider_Webs",
        "MAR_Spider_Webs_2","MAR_AntIce","MAR_ANT_Guppy"
        };
		weapons[] = {};
		magazines[]={};
		ammo[]={};
		requiredAddons[] = {"A3_Characters_F","a3_anims_f"};
		requiredVersion = 0.1;
		author = "Marbearis";
	};
};
#include "Projectiles\Ammo.hpp"
#include "data\CfgCloudlets.hpp"
/// editor/curator category creation!

class CfgEditorCategories
{
	class MAR_Bugs
	{
		displayName="Bug stuff";
	};
};

class CfgEditorSubcategories 
{
	
	class MAR_Bugs_Ants
	{
		displayName="Ants";
	};
    class MAR_Bugs_Spiders
	{
		displayName="Spiders";
	};
};

class cfgFactionClasses
{
	class MAR_Bug_Faction
		{
            displayName = "Bugs"; 
            icon = ""; 
            priority = 1; 
            side = 0; 
		};
};

///---


class Eventhandlers;

class CfgVehicles
{ 
	class House_F; // External class reference
	class Items_base_F; // External class reference
	class Land_Basketball_01_F; // External class reference
    class B_Soldier_base_F;	// External class reference
    class Marby_C_ExportClass : B_Soldier_base_F {
        identityTypes[] = {"empty_Face"};
    };

    class MAR_Critter_BASE : Marby_C_ExportClass 
    {
        scope = 0;			
        scopeCurator = 0;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Green";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Green";
        editorPreview="";
        faction = "MAR_Bug_Faction";
        editorSubcategory = "MAR_Bugs_Ants";
        displayName = "ANT_BASE";
        model = "\Bugs_life\Ants\BasicAnt.p3d";
        hiddenSelections[] = {"camo","eyes"};
        hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\Basic\ANT_CO.paa","\Bugs_life\Ants\textures\Basic\ANT_CO.paa"};
        uniformClass = "ANT_Uniform";
        nakedUniform = "ANT_Uniform";
        _generalMacro = "MAR_ANT_1";
        gestures = "CfgGestures_MAR_ANT";
        moves = "CfgMoves_MAR_ANT";
        items[] = {};
        linkedItems[] = {};
        RespawnlinkedItems[]={};
    
        vehicleclass = "Men";
    
        
        
        
        armor = 7;
    
        class Eventhandlers
        {
            init = "_this#0 allowFleeing 0;_this#0 setSpeaker 'NoVoice';_this#0 disableConversation true;";//[_this#0] execVM 'Bugs_life\Ants\AI\BasicAnt.sqf'
        };

    
        canCarryBackPack = 0;
        canDeactivateMines = 0;
        engineer = 0;
        attendant = 1;
            class SoundEnvironExt {		
                generic[] = {
                    {"run", {"\Bugs_life\data\AntSounds\antRun.ogg", 1, 1, 40}},
                    {"idle", {"\Bugs_life\data\AntSounds\idleChitter.ogg", 1, 1, 25}},                    
                    {"walk", {"\Bugs_life\data\AntSounds\AntWalk.ogg", 1, 1, 25}},  
                    {"meleeAttack", {"\Bugs_life\data\AntSounds\antBite.ogg", 1, 1, 25}}, 
                    {"rangedAttack", {"\Bugs_life\data\AntSounds\antSpit.ogg", 1, 1, 100}}          
                };
            };
            class SoundEquipment {	
                soldier[] = {
                    {"run", {"\Bugs_life\data\AntSounds\antRun.ogg", 1, 1, 40}},
                    {"idle", {"\Bugs_life\data\AntSounds\idleChitter.ogg", 1, 1, 25}},                    
                    {"walk", {"\Bugs_life\data\AntSounds\AntWalk.ogg", 1, 1, 25}},  
                    {"meleeAttack", {"\Bugs_life\data\AntSounds\antBite.ogg", 1, 1, 25}}, 
                    {"rangedAttack", {"\Bugs_life\data\AntSounds\antSpit.ogg", 1, 1, 100}} 
                };
            };
                class SoundBreath
                {
                    breath[] = {};
                    breath1[] = {};
                    breath2[] = {};
                    breath3[] = {};
                    breath4[] = {};
                    breath5[] = {};
                    breath6[] = {};
                    breath7[] = {};
                    breath8[] = {};
                    breath9[] = {};
                    breath10[] = {};
                    breath11[] = {};
                    breath12[] = {};
                    breath13[] = {};
                    breath14[] = {};
                    breath15[] = {};
                    breath16[] = {};
                    breath17[] = {};
                    breath18[] = {};
                };
                class SoundBreathAiming
                {
                    breath[] = {};
                    breath1[] = {};
                    breath2[] = {};
                    breath3[] = {};
                    breath4[] = {};
                    breath5[] = {};
                    breath6[] = {};
                    breath7[] = {};
                    breath8[] = {};
                    breath9[] = {};
                    breath10[] = {};
                    breath11[] = {};
                    breath12[] = {};
                    breath13[] = {};
                    breath14[] = {};
                    breath15[] = {};
                    breath16[] = {};
                    breath17[] = {};
                    breath18[] = {};
                };
                class SoundDrown
                {
                    breath[] = {};
                    breath1[] = {};
                    breath2[] = {};
                    breath3[] = {};
                    breath4[] = {};
                    breath5[] = {};
                    breath6[] = {};
                    breath7[] = {};
                    breath8[] = {};
                    breath9[] = {};
                    breath10[] = {};
                    breath11[] = {};
                    breath12[] = {};
                    breath13[] = {};
                    breath14[] = {};
                    breath15[] = {};
                    breath16[] = {};
                    breath17[] = {};
                    breath18[] = {};
                };
                class SoundInjured
                {
                    person_moan1[] = {};
                    person_moan2[] = {};
                    person_moan3[] = {};
                    person_moan4[] = {};
                    person_moan5[] = {};
                    person_moan6[] = {};
                    person_moan7[] = {};
                    person_moan8[] = {};
                    person_moan9[] = {};
                    person_moan10[] = {};
                    person_moan11[] = {};
                    person_moan12[] = {};
                    person_moan13[] = {};
                    person_moan14[] = {};
                    person_moan15[] = {};
                    person_moan16[] = {};
                    person_moan17[] = {};
                    person_moan18[] = {};
                };
                class SoundBleeding
                {
                    breath[] = {};
                };
                class SoundChoke
                {
                    breath[] = {};
                    breath1[] = {};
                    breath2[] = {};
                    breath3[] = {};
                    breath4[] = {};
                    breath5[] = {};
                    breath6[] = {};
                    breath7[] = {};
                    breath8[] = {};
                    breath9[] = {};
                    breath10[] = {};
                    breath11[] = {};
                    breath12[] = {};
                    breath13[] = {};
                    breath14[] = {};
                    breath15[] = {};
                    breath16[] = {};
                    breath17[] = {};
                    breath18[] = {};
                };
                class SoundRecovered
                {
                    Person1[] = {};
                    Person2[] = {};
                    Person3[] = {};
                    Person4[] = {};
                    Person5[] = {};
                    Person6[] = {};
                    Person7[] = {};
                    Person8[] = {};
                    Person9[] = {};
                    Person10[] = {};
                    Person11[] = {};
                    Person12[] = {};
                    Person13[] = {};
                    Person14[] = {};
                    Person15[] = {};
                    Person16[] = {};
                    Person17[] = {};
                    Person18[] = {};
                };
                class SoundBreathAutomatic
                {
                    breath[] = {};
                    breath0[] = {};
                };
                
                class SoundBreathInjured
                {
                    Person1[] = {};
                    Person2[] = {};
                    Person3[] = {};
                    Person4[] = {};
                    Person5[] = {};
                    Person6[] = {};
                    Person7[] = {};
                    Person8[] = {};
                    Person9[] = {};
                    Person10[] = {};
                    Person11[] = {};
                    Person12[] = {};
                    Person13[] = {};
                    Person14[] = {};
                    Person15[] = {};
                    Person16[] = {};
                    Person17[] = {};
                    Person18[] = {};
                };
                class SoundBurning
                {
                    Person1[] = {};
                    Person2[] = {};
                    Person3[] = {};
                    Person4[] = {};
                    Person5[] = {};
                    Person6[] = {};
                    Person7[] = {};
                    Person8[] = {};
                    Person9[] = {};
                    Person10[] = {};
                    Person11[] = {};
                    Person12[] = {};
                    Person13[] = {};
                    Person14[] = {};
                    Person15[] = {};
                    Person16[] = {};
                    Person17[] = {};
                    Person18[] = {};
                };
                class SoundBreathSwimming
                {
                    breathSwimming1[] = {};
                };
                class SoundHitScream
                {
                    Person1[] = {};
                    Person2[] = {};
                    Person3[] = {};
                    Person4[] = {};
                    Person5[] = {};
                    Person6[] = {};
                    Person7[] = {};
                    Person8[] = {};
                    Person9[] = {};
                    Person10[] = {};
                    Person11[] = {};
                    Person12[] = {};
                    Person13[] = {};
                    Person14[] = {};
                    Person15[] = {};
                    Person16[] = {};
                    Person17[] = {};
                    Person18[] = {};
                };
                class Character {
                    radius = 200;
                    detectionRadius = 500;
                    chaseDistance = 51;
                    coverRadius = 50;
                    escapeRadius = 200;
                    damage = 0.4;
                    damageHitPoints[] = {{"HitLeftLeg", 0.4}, {"HitRightLeg", 0.4}, {"HitBody", 0.7}};
                    armor = 45;
                    attackDistances[] = {2, 3};
                    allowWalk = 1;
                    aggressive = 1;
                    secrecy = 0.4;
                    curious = 1;
                    cowardice = 0;
                    societal = 0;
                    tactful = 1;
                    courage = 1;
                    friendly[] = {};
                    
                    class Sounds {
                        idle[] = {};
                        attack[] = {};
                        hit[] = {};
                        other[] = {};
                    };
                    
                    class Animations {
                        attack_1[] = {};
                        attack_2[] = {};
                        attack_3[] = {};
                        agry[] = {};
                        eat[] = {};
                    };
                    
                    class HitPoints {
                        class HitFace {
                            armor = 1;
                            material = -1;
                            name = "bip01_head";
                            passThrough = 0.1;
                            radius = 0.08;
                            explosionShielding = 0.1;
                            minimalHit = 0.01;
                        };
                        
                        class HitNeck : HitFace {
                            armor = 1;
                            material = -1;
                            name = "bip01_neck";
                            passThrough = 0.1;
                            radius = 0.1;
                            explosionShielding = 0.5;
                            minimalHit = 0.01;
                        };
                        
                        class HitHead : HitNeck {
                            armor = 1;
                            material = -1;
                            name = "bip01_head";
                            passThrough = 0.1;
                            radius = 0.2;
                            explosionShielding = 0.5;
                            minimalHit = 0.01;
                            depends = "HitFace max HitNeck";
                        };
                        
                        class HitPelvis {
                            armor = 1;
                            material = -1;
                            name = "bip01_pelvis";
                            passThrough = 0.1;
                            radius = 0.2;
                            explosionShielding = 1;
                            visual = "injury_body";
                            minimalHit = 0.01;
                        };
                        
                        class HitAbdomen : HitPelvis {
                            armor = 1;
                            material = -1;
                            name = "bip01_spine1";
                            passThrough = 0.1;
                            radius = 0.15;
                            explosionShielding = 1;
                            visual = "injury_body";
                            minimalHit = 0.01;
                        };
                        
                        class HitDiaphragm : HitAbdomen {
                            armor = 1;
                            material = -1;
                            name = "bip01_spine2";
                            passThrough = 0.1;
                            radius = 0.15;
                            explosionShielding = 6;
                            visual = "injury_body";
                            minimalHit = 0.01;
                        };
                        
                        class HitChest : HitDiaphragm {
                            armor = 1;
                            material = -1;
                            name = "bip01_spine3";
                            passThrough = 0.1;
                            radius = 0.15;
                            explosionShielding = 6;
                            visual = "injury_body";
                            minimalHit = 0.01;
                        };
                        
                        class HitBody : HitChest {
                            armor = 6500;
                            material = -1;
                            name = "Body";
                            passThrough = 0.1;
                            radius = 0.16;
                            explosionShielding = 6;
                            visual = "injury_body";
                            minimalHit = 0.01;
                            depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
                        };
                        
                        class HitArms {
                            armor = 1;
                            material = -1;
                            name = "arms";
                            passThrough = 1;
                            radius = 0.1;
                            explosionShielding = 1;
                            visual = "injury_hands";
                            minimalHit = 0.01;
                        };
                        
                        class HitHands : HitArms {
                            armor = 1;
                            material = -1;
                            name = "hands";
                            passThrough = 1;
                            radius = 0.1;
                            explosionShielding = 1;
                            visual = "injury_hands";
                            minimalHit = 0.01;
                            depends = "HitArms";
                        };
                        
                        class HitLegs {
                            armor = 1;
                            material = -1;
                            name = "legs";
                            passThrough = 1;
                            radius = 0.12;
                            explosionShielding = 1;
                            visual = "injury_legs";
                            minimalHit = 0.01;
                        };
                    };
                    armorStructural = 0.4;
                    explosionShielding = 0.04;
                    minTotalDamageThreshold = 0.001;
                    impactDamageMultiplier = 0.5;
                };
                weapons[]=
                {
                    "Throw",
                    "Put"
                };
                magazines[]=
                {
                };
                respawnweapons[]=
                {
                    "Throw",
                    "Put"
                };
            respawnMagazines[]=
            {
            };
    };

    class MAR_acidCrater: House_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\data\bloodpools\acidPool.p3d";
        displayName = "acid crater";
        hiddenSelections[]={"camo"};
        hiddenSelectionsTextures[]={"\Bugs_life\data\bloodpools\DefaultMaterial_CA.paa"};
        hiddenSelectionsMaterials[]={"\Bugs_life\data\bloodpools\bloodPoolGreen.rvmat"};
    };    
    class MAR_AntIce:MAR_acidCrater
    {
        scope = 2;			
		scopeCurator = 2;
        model = "\Bugs_life\Ants\antIce.p3d";
        displayName = "ice spike";
    };

    #include "Spiders.hpp"
    #include "ANTS.hpp"
};

class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class ItemInfo;
class cfgWeapons 
{
	class Pistol_Base_F; //External class reference
	class ItemCore;	// External class reference
	class UniformItem;	// External class reference
	class Uniform_Base;	// External class reference
	class HeadgearItem;	// External class reference
	class Vest_Camo_Base;	// External class reference
	class VestItem;	// External class reference
	class V_PlateCarrierSpec_blk;
	class ANT_Queen_Uniform: Uniform_Base
		{
            scope = 1;
			displayName = "Ant Queen";
            model = "\Bugs_life\Ants\antQueen.p3d";
            hiddenSelections[] = {"camo","eyes","camo1"};
            hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\queen\body_CO.paa","\Bugs_life\Ants\textures\queen\body_CO.paa","\Bugs_life\Ants\textures\queen\eggAbdomen_CO.paa"};
            hiddenSelectionsMaterials[] = {"\Bugs_life\Ants\textures\queen\body.rvmat","\Bugs_life\Ants\textures\queen\body.rvmat","\Bugs_life\Ants\textures\queen\eggAbdomen.rvmat"};
			class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Queen_Uniform";
				uniformmodel="-";
			};
		};
    class ANT_Uniform: Uniform_Base
		{
			displayname="ANT_Basic";
			model = "\Bugs_life\Ants\BasicAnt.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\Basic\ANT_CO.paa","\Bugs_life\Ants\textures\Basic\ANT_CO.paa"};
			class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Uniform";
				uniformmodel="-";
			};
		};
 
    class Spider_Uniform: Uniform_Base
		{
			displayname="ANT_Basic";
			model = "\Bugs_life\Spiders\shpida.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Spiders\textures\spider_1\DefaultMaterial_CO.paa","\Bugs_life\Spiders\textures\spider_1\DefaultMaterial_CO.paa"};
			class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="Spider_Uniform";
				uniformmodel="-";
			};
		};
    class ANT_Uniform_spitter: Uniform_Base
		{
			displayname="ANT_ACID";
			model = "\Bugs_life\Ants\ACID_Ant.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[]={"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
			hiddenSelectionsMaterials[]={"\Bugs_life\Ants\textures\SpitterAnt\ANT.rvmat","\Bugs_life\Ants\textures\SpitterAnt\ANT.rvmat"};
            class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Uniform_spitter";
				uniformmodel="-";
			};
		};
    class ANT_Uniform_ICE: Uniform_Base
		{
			displayname="ANT_ICE";
			model = "\Bugs_life\Ants\ICE_Ant.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\IceAnt\ANT_CA.paa","\Bugs_life\Ants\textures\IceAnt\ANT_CA.paa"};
			hiddenSelectionsMaterials[]={"\Bugs_life\Ants\textures\IceAnt\ANT.rvmat","\Bugs_life\Ants\textures\IceAnt\ANT.rvmat"};
            class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Uniform_ICE";
				uniformmodel="-";
			};
		};
    class ANT_Uniform_Guppy:Uniform_Base 
    {
        	displayname="ANT_Guppy";
			model = "Bugs_life\Ants\antguppy.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\antguppy\anggup_CO.paa","\Bugs_life\Ants\textures\antguppy\anggup_CO.paa"};
			hiddenSelectionsMaterials[]={"\Bugs_life\Ants\textures\antguppy\anggup.rvmat","\Bugs_life\Ants\textures\antguppy\anggup.rvmat"};
            class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Uniform_Guppy";
				uniformmodel="-";
			};
    };
};



class CfgMovesBasic
{
	class Default;
	class StandBase;
	class BlendAnims;
	class Actions
	{
		class Default;
		class NoActions;
		
		// ANT moveset
			class MAR_ANT_Moves: NoActions
			{
				Disable_Gesture[]=
				{
					"Disable_Gesture",
					"Gesture"
				};
				stance="ManStanceUndefined";
				useFastMove = 1;
				turnSpeed = 1;
				LimpF="ANT_Walk";
				LimpLF="ANT_Walk";
				LimpRF="ANT_Walk";
				LimpL="ANT_Walk_L";
				LimpR="ANT_Walk_R";
				LimpB="ANT_Walk_B";
				LimpLB="ANT_Walk_B";
				LimpRB="ANT_Walk_B";
				stop="ANT_Idle";
				default="ANT_Idle";
				stopRelaxed="ANT_Idle";
				TurnL="ANT_Turn_L";
				TurnR="ANT_Turn_R";
				TurnLRelaxed="ANT_Turn_L";
				TurnRRelaxed="ANT_Turn_R";
				WalkF="ANT_Walk";
				PlayerWalkF="ANT_Walk";
				WalkLF="ANT_Walk";
				PlayerWalkLF="ANT_Walk";
				WalkRF="ANT_Walk";
				PlayerWalkRF="ANT_Walk";
				WalkL="ANT_Walk_L";
				PlayerWalkL="ANT_Walk_L";
				WalkR="ANT_Walk_R";
				PlayerWalkR="ANT_Walk_R";
				WalkB="ANT_Walk_B";
				PlayerWalkB="ANT_Walk_B";
				WalkLB="ANT_Walk_B";
				PlayerWalkLB="ANT_Walk_B";
				WalkRB="ANT_Walk_B";
				PlayerWalkRB="ANT_Walk_B";
				SlowF="ANT_Walk";
				PlayerSlowF="ANT_Walk";
				SlowB="ANT_Walk_B";
				PlayerSlowB="ANT_Walk_B";
				PlayerFastF="ANT_Walk";
				combat="ANT_Idle";
				up="ANT_Walk";
				down="ANT_Walk";
				gear="ANT_Idle";
				upDegree="ManPosNoWeapon";
				PlayerSlowLF="ANT_Walk";
				PlayerSlowRF="ANT_Walk";
				PlayerSlowL="ANT_Walk_L";
				PlayerSlowR="ANT_Walk_R";
				PlayerSlowLB="ANT_Walk_B";
				PlayerSlowRB="ANT_Walk_B";
				FastF="ANT_Run";
				FastLF="ANT_Run";
				FastRF="ANT_Run";
				FastL="ANT_Walk_L";
				FastR="ANT_Walk_R";
				FastLB="ANT_Walk";
				FastRB="ANT_Walk";
				TactF="ANT_Walk";
				TactLF="ANT_Walk";
				TactRF="ANT_Walk";
				TactL="ANT_Walk_L";
				TactR="ANT_Walk_R";
				TactLB="ANT_Walk_B";
				TactRB="ANT_Walk_B";
				TactB="ANT_Walk_B";
				PlayerTactF="ANT_Walk";
				PlayerTactLF="ANT_Walk";
				PlayerTactRF="ANT_Walk";
				PlayerTactL="ANT_Walk_L";
				PlayerTactR="ANT_Walk_R";
				PlayerTactLB="ANT_Walk_B";
				PlayerTactRB="ANT_Walk_B";
				PlayerTactB="ANT_Walk_B";
				Die="ANT_Death_Static";
				StartFreefall="ANT_inAir";
				Unconscious = "ANT_Death";
			};
        //movement
                class MAR_ANT_Walk: MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Walk";
                    Up="ANT_Walk";
                    Crouch="ANT_Walk";
                    AdjustB="";
                    Stand="ANT_Idle";
                };

                class MAR_ANT_Walk_B: MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Walk_B";
                    Up="ANT_Walk_B";
                    Crouch="ANT_Walk_B";
                    AdjustB="";
                    Stand="ANT_Idle";
                };

                class MAR_ANT_Walk_R: MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Walk_R";
                    Up="ANT_Walk_R";
                    Crouch="ANT_Walk_R";
                    AdjustB="";
                    Stand="ANT_Idle";
                };
                class MAR_ANT_Walk_L: MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Walk_L";
                    Up="ANT_Walk_L";
                    Crouch="ANT_Walk_L";
                    AdjustB="";
                    Stand="ANT_Idle";
                };

                class MAR_ANT_Run: MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Run";
                    Up="ANT_Run";
                    Crouch="ANT_Run";
                    AdjustB="";
                    Stand="ANT_Idle";
                };
                class MAR_ANT_inAir:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_inAir";
                    Up="ANT_inAir";
                    Crouch="ANT_inAir";
                    AdjustB="";
                    Stand="ANT_inAir";
                };
                class MAR_ANT_Landing:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Landing";
                    Up="ANT_Landing";
                    Crouch="ANT_Landing";
                    AdjustB="";
                    Stand="ANT_Landing";
                };
                class MAR_ANT_Turn_R:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Turn_R";
                    Up="ANT_Turn_R";
                    Crouch="ANT_Turn_R";
                    AdjustB="";
                    Stand="ANT_Idle";
                };

                class  MAR_ANT_Turn_L:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Turn_L";
                    Up="ANT_Turn_L";
                    Crouch="ANT_Turn_L";
                    AdjustB="";
                    Stand="ANT_Idle";
                    
                };
                class  MAR_ANT_Death_1:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Death";
                    Up="ANT_Death";
                    Crouch="ANT_Death";
                    AdjustB="";
                    Stand="ANT_Death";
                };
                class  MAR_ANT_Death_2:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Death_2";
                    Up="ANT_Death_2";
                    Crouch="ANT_Death_2";
                    AdjustB="";
                    Stand="ANT_Death_2";
                };
                class  MAR_ANT_Death_3:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Death_3";
                    Up="ANT_Death_3";
                    Crouch="ANT_Death_3";
                    AdjustB="";
                    Stand="ANT_Death_3";
                };
                class  MAR_ANT_Death_Static:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Death_Static";
                    Up="ANT_Death_Static";
                    Crouch="ANT_Death_Static";
                    AdjustB="";
                    Stand="ANT_Death_Static";
                };
        
                //hit reactions
                class MAR_ANT_Hit_F:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Hit_F";
                    Up="ANT_Hit_F";
                    Crouch="ANT_Hit_F";
                    AdjustB="";
                    Stand="ANT_Hit_F";
                };

                class MAR_ANT_Hit_B:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Hit_B";
                    Up="ANT_Hit_B";
                    Crouch="ANT_Hit_B";
                    AdjustB="";
                    Stand="ANT_Hit_B";
                };
                
                //Combat actions
                class  MAR_ANT_Attack_1:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Attack_1";
                    Up="ANT_Attack_1";
                    Crouch="ANT_Attack_1";
                    AdjustB="";
                    Stand="ANT_Attack_1";
                };

                class MAR_ANT_Attack_Ranged:MAR_ANT_Moves
                {
                    turnSpeed=4.5;
                    PlayerCrouch="ANT_Attack_Ranged";
                    Up="ANT_Attack_Ranged";
                    Crouch="ANT_Attack_Ranged";
                    AdjustB="";
                    Stand="ANT_Attack_Ranged";
                };

                

                class MAR_ANT_Climb_Out:MAR_ANT_Moves
                {
                    turnSpeed=0;
                    PlayerCrouch="ANT_Climb_Out";
                    Up="ANT_Climb_Out";
                    Crouch="ANT_Climb_Out";
                    AdjustB="";
                    Stand="ANT_Climb_Out";
                };
        
        
		//ANT moveset end
        //spider moveSet
            class MAR_SPIDER_Moves: NoActions
			{
				Disable_Gesture[]=
				{
					"Disable_Gesture",
					"Gesture"
				};
				stance="ManStanceUndefined";
				useFastMove = 1;
				turnSpeed = 1;
				LimpF="SPIDER_Walk";
				LimpLF="SPIDER_Walk";
				LimpRF="SPIDER_Walk";
				LimpL="SPIDER_Walk_L";
				LimpR="SPIDER_Walk_R";
				LimpB="SPIDER_Walk_B";
				LimpLB="SPIDER_Walk_B";
				LimpRB="SPIDER_Walk_B";
				stop="SPIDER_Idle";
				default="SPIDER_Idle";
				stopRelaxed="SPIDER_Idle";
				TurnL="SPIDER_Turn_L";
				TurnR="SPIDER_Turn_R";
				TurnLRelaxed="SPIDER_Turn_L";
				TurnRRelaxed="SPIDER_Turn_R";
				WalkF="SPIDER_Walk";
				PlayerWalkF="SPIDER_Walk";
				WalkLF="SPIDER_Walk";
				PlayerWalkLF="SPIDER_Walk";
				WalkRF="SPIDER_Walk";
				PlayerWalkRF="SPIDER_Walk";
				WalkL="SPIDER_Walk_L";
				PlayerWalkL="SPIDER_Walk_L";
				WalkR="SPIDER_Walk_R";
				PlayerWalkR="SPIDER_Walk_R";
				WalkB="SPIDER_Walk_B";
				PlayerWalkB="SPIDER_Walk_B";
				WalkLB="SPIDER_Walk_B";
				PlayerWalkLB="SPIDER_Walk_B";
				WalkRB="SPIDER_Walk_B";
				PlayerWalkRB="SPIDER_Walk_B";
				SlowF="SPIDER_Walk";
				PlayerSlowF="SPIDER_Walk";
				SlowB="SPIDER_Walk_B";
				PlayerSlowB="SPIDER_Walk_B";
				PlayerFastF="SPIDER_Walk";
				combat="SPIDER_Idle";
				up="SPIDER_Walk";
				down="SPIDER_Walk";
				gear="SPIDER_Idle";
				upDegree="ManPosNoWeapon";
				PlayerSlowLF="SPIDER_Walk";
				PlayerSlowRF="SPIDER_Walk";
				PlayerSlowL="SPIDER_Walk_L";
				PlayerSlowR="SPIDER_Walk_R";
				PlayerSlowLB="SPIDER_Walk_B";
				PlayerSlowRB="SPIDER_Walk_B";
				FastF="SPIDER_Run";
				FastLF="SPIDER_Run";
				FastRF="SPIDER_Run";
				FastL="SPIDER_Walk_L";
				FastR="SPIDER_Walk_R";
				FastLB="SPIDER_Walk";
				FastRB="SPIDER_Walk";
				TactF="SPIDER_Walk";
				TactLF="SPIDER_Walk";
				TactRF="SPIDER_Walk";
				TactL="SPIDER_Walk_L";
				TactR="SPIDER_Walk_R";
				TactLB="SPIDER_Walk_B";
				TactRB="SPIDER_Walk_B";
				TactB="SPIDER_Walk_B";
				PlayerTactF="SPIDER_Walk";
				PlayerTactLF="SPIDER_Walk";
				PlayerTactRF="SPIDER_Walk";
				PlayerTactL="SPIDER_Walk_L";
				PlayerTactR="SPIDER_Walk_R";
				PlayerTactLB="SPIDER_Walk_B";
				PlayerTactRB="SPIDER_Walk_B";
				PlayerTactB="SPIDER_Walk_B";
				Die="SPIDER_Death_Static";
				StartFreefall="SPIDER_inAir";
				Unconscious = "SPIDER_Death";
			};

            class MAR_SPIDER_Burrowed_Moves:MAR_SPIDER_Moves
            {
                Disable_Gesture[]=
                {
                    "Disable_Gesture",
                    "Gesture"
                };
                stance="ManStanceUndefined";
                useFastMove = 1;
                turnSpeed = 1;
                LimpF="SPIDER_Burrowed_Idle";
                LimpLF="SPIDER_Burrowed_Idle";
                LimpRF="SPIDER_Burrowed_Idle";
                LimpL="SPIDER_Burrowed_Idle";
                LimpR="SPIDER_Burrowed_Idle";
                LimpB="SPIDER_Burrowed_Idle";
                LimpLB="SPIDER_Burrowed_Idle";
                LimpRB="SPIDER_Burrowed_Idle";
                stop="SPIDER_Burrowed_Idle";
                default="SPIDER_Burrowed_Idle";
                stopRelaxed="SPIDER_Burrowed_Idle";
                TurnL="SPIDER_Burrowed_Idle";
                TurnR="SPIDER_Burrowed_Idle";
                TurnLRelaxed="SPIDER_Burrowed_Idle";
                TurnRRelaxed="SPIDER_Burrowed_Idle";
                WalkF="SPIDER_Burrowed_Idle";
                PlayerWalkF="SPIDER_Burrowed_Idle";
                WalkLF="SPIDER_Burrowed_Idle";
                PlayerWalkLF="SPIDER_Burrowed_Idle";
                WalkRF="SPIDER_Burrowed_Idle";
                PlayerWalkRF="SPIDER_Burrowed_Idle";
                WalkL="SPIDER_Burrowed_Idle";
                PlayerWalkL="SPIDER_Burrowed_Idle";
                WalkR="SPIDER_Burrowed_Idle";
                PlayerWalkR="SPIDER_Burrowed_Idle";
                WalkB="SPIDER_Burrowed_Idle";
                PlayerWalkB="SPIDER_Burrowed_Idle";
                WalkLB="SPIDER_Burrowed_Idle";
                PlayerWalkLB="SPIDER_Burrowed_Idle";
                WalkRB="SPIDER_Burrowed_Idle";
                PlayerWalkRB="SPIDER_Burrowed_Idle";
                SlowF="SPIDER_Burrowed_Idle";
                PlayerSlowF="SPIDER_Burrowed_Idle";
                SlowB="SPIDER_Burrowed_Idle";
                PlayerSlowB="SPIDER_Burrowed_Idle";
                PlayerFastF="SPIDER_Burrowed_Idle";
                combat="SPIDER_Burrowed_Idle";
                up="SPIDER_Burrowed_Idle";
                down="SPIDER_Burrowed_Idle";
                gear="SPIDER_Burrowed_Idle";
                upDegree="ManPosNoWeapon";
                PlayerSlowLF="SPIDER_Burrowed_Idle";
                PlayerSlowRF="SPIDER_Burrowed_Idle";
                PlayerSlowL="SPIDER_Burrowed_Idle";
                PlayerSlowR="SPIDER_Burrowed_Idle";
                PlayerSlowLB="SPIDER_Burrowed_Idle";
                PlayerSlowRB="SPIDER_Burrowed_Idle";
                FastF="SPIDER_Burrowed_Idle";
                FastLF="SPIDER_Burrowed_Idle";
                FastRF="SPIDER_Burrowed_Idle";
                FastL="SPIDER_Burrowed_Idle";
                FastR="SPIDER_Burrowed_Idle";
                FastLB="SPIDER_Burrowed_Idle";
                FastRB="SPIDER_Burrowed_Idle";
                TactF="SPIDER_Burrowed_Idle";
                TactLF="SPIDER_Burrowed_Idle";
                TactRF="SPIDER_Burrowed_Idle";
                TactL="SPIDER_Burrowed_Idle";
                TactR="SPIDER_Burrowed_Idle";
                TactLB="SPIDER_Burrowed_Idle";
                TactRB="SPIDER_Burrowed_Idle";
                TactB="SPIDER_Burrowed_Idle";
                PlayerTactF="SPIDER_Burrowed_Idle";
                PlayerTactLF="SPIDER_Burrowed_Idle";
                PlayerTactRF="SPIDER_Burrowed_Idle";
                PlayerTactL="SPIDER_Burrowed_Idle";
                PlayerTactR="SPIDER_Burrowed_Idle";
                PlayerTactLB="SPIDER_Burrowed_Idle";
                PlayerTactRB="SPIDER_Burrowed_Idle";
                PlayerTactB="SPIDER_Burrowed_Idle";
                Die="SPIDER_Burrowed_Idle";
                StartFreefall="SPIDER_Burrowed_Idle";
                Unconscious = "SPIDER_Burrowed_Idle";
            };

            class MAR_SPIDER_Burrowed_Attack:MAR_SPIDER_Burrowed_Moves
            {
                turnSpeed=0;
                PlayerCrouch="Spider_Burrowed_Attack";
                Up="Spider_Burrowed_Attack";
                Crouch="Spider_Burrowed_Attack";
                AdjustB="";
                Stand="Spider_Burrowed_Attack";
            };  
            

        //spider moveset end
        //antQueen
       
           
            class MAR_ANTQueen_Moves:MAR_SPIDER_Moves
            {
                Disable_Gesture[]=
                {
                    "Disable_Gesture",
                    "Gesture"
                };
                stance="ManStanceUndefined";
                useFastMove = 1;
                turnSpeed = 1;
                LimpF="ANT_Queen_Idle";
                LimpLF="ANT_Queen_Idle";
                LimpRF="ANT_Queen_Idle";
                LimpL="ANT_Queen_Idle";
                LimpR="ANT_Queen_Idle";
                LimpB="ANT_Queen_Idle";
                LimpLB="ANT_Queen_Idle";
                LimpRB="ANT_Queen_Idle";
                stop="ANT_Queen_Idle";
                default="ANT_Queen_Idle";
                stopRelaxed="ANT_Queen_Idle";
                TurnL="ANT_Queen_Idle";
                TurnR="ANT_Queen_Idle";
                TurnLRelaxed="ANT_Queen_Idle";
                TurnRRelaxed="ANT_Queen_Idle";
                WalkF="ANT_Queen_Idle";
                PlayerWalkF="ANT_Queen_Idle";
                WalkLF="ANT_Queen_Idle";
                PlayerWalkLF="ANT_Queen_Idle";
                WalkRF="ANT_Queen_Idle";
                PlayerWalkRF="ANT_Queen_Idle";
                WalkL="ANT_Queen_Idle";
                PlayerWalkL="ANT_Queen_Idle";
                WalkR="ANT_Queen_Idle";
                PlayerWalkR="ANT_Queen_Idle";
                WalkB="ANT_Queen_Idle";
                PlayerWalkB="ANT_Queen_Idle";
                WalkLB="ANT_Queen_Idle";
                PlayerWalkLB="ANT_Queen_Idle";
                WalkRB="ANT_Queen_Idle";
                PlayerWalkRB="ANT_Queen_Idle";
                SlowF="ANT_Queen_Idle";
                PlayerSlowF="ANT_Queen_Idle";
                SlowB="ANT_Queen_Idle";
                PlayerSlowB="ANT_Queen_Idle";
                PlayerFastF="ANT_Queen_Idle";
                combat="ANT_Queen_Idle";
                up="ANT_Queen_Idle";
                down="ANT_Queen_Idle";
                gear="ANT_Queen_Idle";
                upDegree="ManPosNoWeapon";
                PlayerSlowLF="ANT_Queen_Idle";
                PlayerSlowRF="ANT_Queen_Idle";
                PlayerSlowL="ANT_Queen_Idle";
                PlayerSlowR="ANT_Queen_Idle";
                PlayerSlowLB="ANT_Queen_Idle";
                PlayerSlowRB="ANT_Queen_Idle";
                FastF="ANT_Queen_Idle";
                FastLF="ANT_Queen_Idle";
                FastRF="ANT_Queen_Idle";
                FastL="ANT_Queen_Idle";
                FastR="ANT_Queen_Idle";
                FastLB="ANT_Queen_Idle";
                FastRB="ANT_Queen_Idle";
                TactF="ANT_Queen_Idle";
                TactLF="ANT_Queen_Idle";
                TactRF="ANT_Queen_Idle";
                TactL="ANT_Queen_Idle";
                TactR="ANT_Queen_Idle";
                TactLB="ANT_Queen_Idle";
                TactRB="ANT_Queen_Idle";
                TactB="ANT_Queen_Idle";
                PlayerTactF="ANT_Queen_Idle";
                PlayerTactLF="ANT_Queen_Idle";
                PlayerTactRF="ANT_Queen_Idle";
                PlayerTactL="ANT_Queen_Idle";
                PlayerTactR="ANT_Queen_Idle";
                PlayerTactLB="ANT_Queen_Idle";
                PlayerTactRB="ANT_Queen_Idle";
                PlayerTactB="ANT_Queen_Idle";
                Die="ANT_Queen_Idle";
                StartFreefall="ANT_Queen_Idle";
                Unconscious = "ANT_Queen_Idle";
            };
            class MAR_ANTQueen_Walk:MAR_ANTQueen_Moves
            {

            };
            class MAR_ANTQueen_Roar:MAR_ANTQueen_Moves
            {
                turnSpeed=4.5;
                PlayerCrouch="MAR_ANTQueen_Roar";
                Up="MAR_ANTQueen_Roar";
                Crouch="MAR_ANTQueen_Roar";
                AdjustB="";
                Stand="MAR_ANTQueen_Roar";
            };
            class MAR_ANTQueen_ClimbIn:MAR_ANTQueen_Moves
            {
                turnSpeed=4.5;
                PlayerCrouch="ANT_Climb_IN";
                Up="ANT_Climb_IN";
                Crouch="ANT_Climb_IN";
                AdjustB="";
                Stand="ANT_Climb_IN";  
            };
            class MAR_ANTQueen_ClimbOutAssUp:MAR_ANTQueen_Moves
            {
                turnSpeed=4.5;
                PlayerCrouch="ANT_Climb_outAssUp";
                Up="ANT_Climb_outAssUp";
                Crouch="ANT_Climb_outAssUp";
                AdjustB="";
                Stand="ANT_AssOutIdle";
                StartFreefall="ANT_AssOutIdle";  
            };
            class MAR_ANTQueen_ClimbOut:MAR_ANTQueen_Moves
            {
                turnSpeed=4.5;
                PlayerCrouch="ANT_ClimbOut";
                Up="ANT_ClimbOut";
                Crouch="ANT_ClimbOut";
                AdjustB="";
                Stand="ANT_Queen_Idle";  
            };
            class MAR_ANTQueen_AssOutIdle:MAR_ANTQueen_ClimbOutAssUp
            {
                PlayerCrouch="ANT_AssOutIdle";
                Up="ANT_AssOutIdle";
                Crouch="ANT_AssOutIdle";
                AdjustB="";
                Stand="ANT_AssOutIdle";  
                StartFreefall="ANT_AssOutIdle";   
            };
        //antQueen end  
        //antGuppy moveset
          class MAR_ANTGuppy_Moves:NoActions
            {
                Disable_Gesture[]=
                {
                    "Disable_Gesture",
                    "Gesture"
                };
                stance="ManStanceUndefined";
                useFastMove = 1;
                turnSpeed = 1;
                LimpF="Guppy_Inch";
                LimpLF="Guppy_Inch";
                LimpRF="Guppy_Inch";
                LimpL="Guppy_Inch";
                LimpR="Guppy_Inch";
                LimpB="Guppy_Inch";
                LimpLB="Guppy_Inch";
                LimpRB="Guppy_Inch";
                stop="Guppy_Idle";
                default="Guppy_Idle";
                stopRelaxed="Guppy_Idle";
                TurnL="Guppy_Inch";
                TurnR="Guppy_Inch";
                TurnLRelaxed="Guppy_Inch";
                TurnRRelaxed="Guppy_Inch";
                WalkF="Guppy_Inch";
                PlayerWalkF="Guppy_Inch";
                WalkLF="Guppy_Inch";
                PlayerWalkLF="Guppy_Inch";
                WalkRF="Guppy_Inch";
                PlayerWalkRF="Guppy_Inch";
                WalkL="Guppy_Inch";
                PlayerWalkL="Guppy_Inch";
                WalkR="Guppy_Inch";
                PlayerWalkR="Guppy_Inch";
                WalkB="Guppy_Inch";
                PlayerWalkB="Guppy_Inch";
                WalkLB="Guppy_Inch";
                PlayerWalkLB="Guppy_Inch";
                WalkRB="Guppy_Inch";
                PlayerWalkRB="Guppy_Inch";
                SlowF="Guppy_Inch";
                PlayerSlowF="Guppy_Inch";
                SlowB="Guppy_Inch";
                PlayerSlowB="Guppy_Inch";
                PlayerFastF="Guppy_Inch";
                combat="Guppy_Idle";
                up="Guppy_Idle";
                down="Guppy_Idle";
                gear="Guppy_Idle";
                upDegree="ManPosNoWeapon";
                PlayerSlowLF="Guppy_Inch";
                PlayerSlowRF="Guppy_Inch";
                PlayerSlowL="Guppy_Inch";
                PlayerSlowR="Guppy_Inch";
                PlayerSlowLB="Guppy_Inch";
                PlayerSlowRB="Guppy_Inch";
                FastF="Guppy_Inch";
                FastLF="Guppy_Inch";
                FastRF="Guppy_Inch";
                FastL="Guppy_Inch";
                FastR="Guppy_Inch";
                FastLB="Guppy_Inch";
                FastRB="Guppy_Inch";
                TactF="Guppy_Inch";
                TactLF="Guppy_Inch";
                TactRF="Guppy_Inch";
                TactL="Guppy_Inch";
                TactR="Guppy_Inch";
                TactLB="Guppy_Inch";
                TactRB="Guppy_Inch";
                TactB="Guppy_Inch";
                PlayerTactF="Guppy_Inch";
                PlayerTactLF="Guppy_Inch";
                PlayerTactRF="Guppy_Inch";
                PlayerTactL="Guppy_Inch";
                PlayerTactR="Guppy_Inch";
                PlayerTactLB="Guppy_Inch";
                PlayerTactRB="Guppy_Inch";
                PlayerTactB="Guppy_Inch";
                Die="ANT_Death";
                StartFreefall="Guppy_Idle";
                Unconscious = "Guppy_Idle";
            };
            class MAR_Guppy_Inch:MAR_ANTGuppy_Moves
            {
                turnSpeed=0;
                PlayerCrouch="Guppy_Inch";
                Up="Guppy_Inch";
                Crouch="Guppy_Inch";
                AdjustB="";
                Stand="Guppy_Idle";
            };
            class MAR_Guppy_Attack:MAR_ANTGuppy_Moves
            {
                turnSpeed=0;
                PlayerCrouch="ANT_Attack_1";
                Up="ANT_Attack_1";
                Crouch="ANT_Attack_1";
                AdjustB="";
                Stand="ANT_Attack_1";
            };
        //antguppy moveset end
    };      
	
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
    class States{
		class AinvPknlMstpSlayWrflDnon_medicOther;
		class Armaman_getEaten:AinvPknlMstpSlayWrflDnon_medicOther
		{
            forceAim=1;
            canBlendStep=0;
            file = "\Bugs_life\Spiders\animations\Human_Dragged_under.rtm";
            speed = -1.2;
            soundOverride = "hit";
            terminal = 1;
		};
	};
};

class CfgGesturesMale;
class CfgGestures_MAR_ANT: CfgGesturesMale
{
	skeletonName = "ant_Armature";
	class ManActions
	{
	};
	class Actions;
	class Default;
	class BlendAnims {
		ANT_FullBody[]=
		{
		};
	};
	class States
	{
		class Disable_Gesture: Default
		{
			speed=1;
			file = "\Bugs_life\Ants\animations\idle_1.rtm";
			disableWeapons=0;
			interpolationRestart=2;
			enableOptics=1;
			weaponIK=1;
			looped=0;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
		};
	};
};

class CfgGestures_MAR_ANT_Guppy:CfgGestures_MAR_ANT
{
    skeletonName = "antGup_Armature";
	class ManActions
	{
	};
	class Actions;
	class Default;
	class BlendAnims {
		ANT_FullBody[]=
		{
		};
	};
	class States
	{
		class Disable_Gesture: Default
		{
			speed=1;
			file = "\Bugs_life\Ants\animations\antGuppyIdle.rtm";
			disableWeapons=0;
			interpolationRestart=2;
			enableOptics=1;
			weaponIK=1;
			looped=0;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
		};
	};
};
class CfgGestures_MAR_ANT_Queen: CfgGesturesMale
{
	skeletonName = "ant_Queen_S";
	class ManActions
	{
	};
	class Actions;
	class Default;
	class BlendAnims {
		ANT_FullBody[]=
		{
		};
	};
	class States
	{
		class Disable_Gesture: Default
		{
			speed=1;
			file = "\Bugs_life\Ants\animations\idle_1.rtm";
			disableWeapons=0;
			interpolationRestart=2;
			enableOptics=1;
			weaponIK=1;
			looped=0;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
		};
	};
};

class CfgGestures_MAR_Spider: CfgGestures_MAR_ANT
{
   
	skeletonName = "shpida_s";
    	class ManActions
	{
	};
	class Actions;
	class Default;
	class BlendAnims {
		ANT_FullBody[]=
		{
		};
	};
	class States
	{
		class Disable_Gesture: Default
		{
			speed=1;
			file = "\Bugs_life\Spiders\animations\idle.rtm"
			disableWeapons=0;
			interpolationRestart=2;
			enableOptics=1;
			weaponIK=1;
			looped=0;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
		};
	};
};

class CfgMoves_MAR_ANT: CfgMovesMaleSdr
{
	gestures="CfgGestures_MAR_ANT";
	skeletonName = "ant_Armature";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a"};
	collisionGeomCompPattern[] = {1};
	class Default: Default
    {
        actions = "MAR_ANT_Moves";
		file = "\Bugs_life\Ants\animations\idle_1.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class StandBase: StandBase
    {
        actions = "MAR_ANT_Moves";
        //ragdoll=0;
		file = "\Bugs_life\Ants\animations\idle_1.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
        file = "\Bugs_life\Ants\animations\death_static.rtm";
		disableWeapons=1;
        //ragdoll=1;
		interpolationRestart=1;
		soundOverride="fallbody";
		soundEdge[]={0.44999999};
		soundEnabled=0;
	};
	class States
	{
		class ANT_Idle: StandBase
		{
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		    collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";			
			file = "\Bugs_life\Ants\animations\idle_1.rtm";
            actions = "MAR_ANT_Moves";
			duty = 0.1;
			boundingSphere = 4;
			interpolationSpeed = 1.5;
			variantAfter[]={6,6,6};
            variantsAI[] = {};
            variantsPlayer[] = {};			
            speed = -3;
            relSpeedMin = 1;
            relSpeedMax = 1;
            canPullTrigger = 1;
            canReload = 1;
            limitGunMovement = 0.5;
            headBobStrength=0;
            headBobMode=0;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableMissile = 1;
            enableOptics = 1;
			leaning="empty";
            soundOverride="idle";
			aiming="HeadDefault_MAR_ANT";
		    aimingBody="HeadDefault_MAR_ANT";
			head = "HeadDefault_MAR_ANT";
			legs="legsDefault_MAR_ANT";
			InterpolateTo[]=
			{
				"ANT_Idle",
				0.01,							
				"ANT_Walk",
				0.01,
                "ANT_Walk_B",
				0.01,
                "ANT_Walk_R",
				0.01,
                "ANT_Walk_L",
				0.01,
				"ANT_Run",
				0.01,	
                "ANT_Death",
                0.01,
                "ANT_Death_2",
                0.01,
                "ANT_Death_3",
                0.01,
                "ANT_Turn_R",
                0.01,
                "ANT_Turn_L",
                0.01,
                "ANT_Attack_1",
                0.01,
                "ANT_Attack_Ranged",
                0.01,
                "ANT_inAir",
                0.01,
                "ANT_Landing",
                0.01				
			};
            interpolateFrom[]={
       	
            };
			
			preload = 1;
		};
	
		
		//locomotion
		class ANT_Walk:ANT_Idle
		{
			file = "\Bugs_life\Ants\animations\walk_f.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk";
            soundOverride="walk";
		};

        class ANT_Walk_B:ANT_Walk
		{
			file = "\Bugs_life\Ants\animations\walk_B.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk_B";
		};
        
        class ANT_inAir:ANT_Idle
        {
            speed = -2;
            file = "\Bugs_life\Ants\animations\inair.rtm";
            actions = "MAR_ANT_inAir";
        };

        class ANT_Landing:ANT_Idle
        {
            looped = false;
            speed = -1.2;
            file = "\Bugs_life\Ants\animations\Landing.rtm";
            actions = "MAR_ANT_Landing";
            soundOverride="fallbody";
        };

        class ANT_Walk_R:ANT_Walk
		{
			file = "\Bugs_life\Ants\animations\walk_R.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk_R";
		};

        class ANT_Walk_L:ANT_Walk
		{
			file = "\Bugs_life\Ants\animations\walk_L.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk_L";
		};

		class ANT_Run:ANT_Walk
		{
			speed = -1;
            file = "\Bugs_life\Ants\animations\run_F.rtm";
            actions = "MAR_ANT_Run";
            soundOverride="run";
		};

        class ANT_Turn_R:ANT_Idle
		{
			speed = -1.2;
            looped = false;
            file = "\Bugs_life\Ants\animations\turnr.rtm";
            actions = "MAR_ANT_Turn_R";
		};

        class ANT_Turn_L:ANT_Idle
		{
			speed = -1.2;
            looped = false;
            file = "\Bugs_life\Ants\animations\turnl.rtm";
            actions = "MAR_ANT_Turn_L";
		};

        class ANT_Death:ANT_Idle
        {
            interpolationSpeed = 10;
            terminal = 1;
            speed = -1.2;
            looped = false;
            soundOverride="death";
            file = "\Bugs_life\Ants\animations\death_1.rtm";
            actions = "MAR_ANT_Death_1";
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
        };

        class ANT_Death_2:ANT_Death
        {
            terminal = 1;
            speed = -1.2;
            looped = false;
          //  ragdoll=1;
            file = "\Bugs_life\Ants\animations\death_2.rtm";
            actions = "MAR_ANT_Death_2";
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
        };

        class ANT_Death_3:ANT_Death
        {
            terminal = 1;
            speed = -1.2;
            looped = false;
          //  ragdoll=1;
            file = "\Bugs_life\Ants\animations\death_3.rtm";
            actions = "MAR_ANT_Death_3";
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
        };

        class ANT_DEATH_Static:ANT_Death
        {
            terminal = 1;
            //ragdoll=1;
            file = "\Bugs_life\Ants\animations\death_static.rtm";
            actions = "MAR_ANT_Death_Static";
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
        };

		class ANT_Attack_1:ANT_Idle
        {
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";		
            looped = false;
            speed = -1;
            file = "\Bugs_life\Ants\animations\attack_1.rtm";
            actions = "MAR_ANT_Attack_1";
            soundOverride="meleeAttack";
        };
        class ANT_Attack_Ranged:ANT_Idle
        {
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
            looped = false;
            speed = -1;
            file = "\Bugs_life\Ants\animations\attackRanged.rtm";
            actions = "MAR_ANT_Attack_Ranged";
            soundOverride="rangedAttack";
        };
         
        class ANT_Climb_Out:ANT_Idle
        {
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
            looped = false;
            speed = -1.2;
            file = "\Bugs_life\Ants\animations\climb_Out.rtm";
            actions = "MAR_ANT_Climb_Out";
            soundOverride="rangedAttack";
        };

        class ANT_Hit_F:ANT_Idle
        {
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
            looped = false;
            speed = -1;
            file = "\Bugs_life\Ants\animations\Hit_F.rtm";
            actions = "MAR_ANT_Hit_F";
           // soundOverride="rangedAttack";
        };
        class ANT_Hit_B:ANT_Idle
        {
            leaning="empty";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
            looped = false;
            speed = -1;
            file = "\Bugs_life\Ants\animations\Hit_B.rtm";
            actions = "MAR_ANT_Hit_B";
           // soundOverride="rangedAttack";
        };
       

	

		// attacks
		
	};
	
	class BlendAnims: BlendAnims
	{
		legsDefault_MAR_ANT[]=
		{
            "a_head",
            0.8,
            "a_mandible.l",
            0.7,
            "a_mandible.r",
            0.7,
            "a_antenne_r",
            0.7,
            "a_antenne_r.001",	
            0.5,
            "a_antenne_l",
            0.7,
            "a_antenne_l.001",	
            0.5,   
            "a_thorax",
            0.9,
            "a_mid",
            0.8,  
            "a_foreleg.r",
            0.9,
			"a_foreleg.r.001",
            0.8,
            "a_foreleg.r.002",
            0.6800000,
            "a_foreleg.r.003",
            0.6800000,
            "a_midleg.r",
            0.9,
            "a_midleg.r.001",
            0.8,
            "a_midleg.r.002",
            0.6800000,
            "a_midleg.r.003",
            0.6800000,
            "a_rearleg.r",
            0.9,
            "a_rearleg.r.001",
            0.8,
            "a_rearleg.r.002",
            0.6800000,
            "a_rearleg.r.003",
            0.6800000,
            "a_foreleg.l",
            0.9,
            "a_foreleg.l.001",
            0.8,
            "a_foreleg.l.002",
            0.6800000,
            "a_foreleg.l.003",
            0.6800000,
            "a_midleg.l",
            0.9,
            "a_midleg.l.001",
            0.8,
            "a_midleg.l.002",
            0.6800000,
            "a_midleg.l.003",
            0.6800000,
            "a_rearleg.l",
            0.9,
            "a_rearleg.l.001",
            0.8,
            "a_rearleg.l.002",
            0.6800000,
            "a_rearleg.l.003",
            0.6800000
					
		};
        HeadDefault_MAR_ANT[]={
            "a_head",
            0.6,
            "a_mandible.l",
            0.5,
            "a_mandible.r",
            0.5,
            "a_antenne_r",
            0.5,
            "a_antenne_r.001",	
            0.5,
            "a_antenne_l",
            0.5,
            "a_antenne_l.001",	
            0.5,
            "a_thorax",
            0.2,
            "a_mid",
            0.1,
            "a_foreleg.r",
            0.2,
            "a_midleg.r",
            0.2,
            "a_rearleg.r",
            0.2,
            "a_foreleg.l",
            0.2,
            "a_midleg.l",
            0.2,
            "a_rearleg.l",
            0.2
        };
		
	};
};

class CfgMoves_MAR_ANT_Guppy: CfgMovesMaleSdr
{
	gestures="CfgGestures_MAR_ANT_Guppy";
	skeletonName = "antGup_Armature";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a"};
	collisionGeomCompPattern[] = {1};
	class Default: Default
    {
        actions = "MAR_ANTGuppy_Moves";
		file = "\Bugs_life\Ants\animations\antGuppyIdle.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class StandBase: StandBase
    {
        actions = "MAR_ANTGuppy_Moves";
        //ragdoll=0;
		file = "\Bugs_life\Ants\animations\antGuppyIdle.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
        file = "\Bugs_life\Ants\animations\antGuppyIdle.rtm";
		disableWeapons=1;
        //ragdoll=1;
		interpolationRestart=1;
		soundOverride="fallbody";
		soundEdge[]={0.44999999};
		soundEnabled=0;
	};
	class States
	{
		class Guppy_Idle: StandBase
		{
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		    collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";			
			file = "\Bugs_life\Ants\animations\antGuppyIdle.rtm";
            actions = "MAR_ANTGuppy_Moves";
			duty = 0.1;
			boundingSphere = 4;
			interpolationSpeed = 1.5;
			variantAfter[]={6,6,6};
            variantsAI[] = {};
            variantsPlayer[] = {};			
            speed = -3;
            relSpeedMin = 1;
            relSpeedMax = 1;
            canPullTrigger = 1;
            canReload = 1;
            limitGunMovement = 0.5;
            headBobStrength=0;
            headBobMode=0;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableMissile = 1;
            enableOptics = 1;
			leaning="HeadDefault_MAR_Guppy";
            soundOverride="idle";
			aiming="HeadDefault_MAR_Guppy";
		    aimingBody="HeadDefault_MAR_Guppy";
			head = "HeadDefault_MAR_Guppy";
			legs="legsDefault_MAR_Guppy";
			InterpolateTo[]=
			{
				"Guppy_Idle",
				0.01,
                "Guppy_Inch",
                0.01,
                "ANT_Attack_1",
                0.1							
				
			};
            interpolateFrom[]={
       	
            };
			
			preload = 1;
		};

		class Guppy_Inch:Guppy_Idle
        {
            file ="\Bugs_life\Ants\animations\antGuppyinch.rtm";
            actions = "MAR_Guppy_Inch";
            interpolationSpeed = 10;
            speed = -0.7;           
            soundOverride="Run";
            leaning="none";
            soundOverride="idle";
			aiming="none";
		    aimingBody="none";
			head = "none";
			legs="none";
        };
	
        class ANT_Attack_1:Guppy_Inch
        {
            actions = "MAR_Guppy_Attack";
            file ="\Bugs_life\Ants\animations\antGuppyattack.rtm";
            speed = -1; 
            looped = false;
        };

        class ANT_Death: Guppy_Inch
        {
            looped = false;
            terminal = 1;
            speed = -3; 
            file ="\Bugs_life\Ants\animations\antGuppydeath.rtm";
            soundOverride = "death";
        };

	
		
	};
	
	class BlendAnims: BlendAnims
	{
		legsDefault_MAR_Guppy[]=
		{
            "a_head",
            0.4,
            "a_bod",
            0.3,
            "a_butt",
            0.1
					
		};
        HeadDefault_MAR_Guppy[]={
            "a_head",
            0.5,
            "a_bod",
            0.4,
            "a_butt",
            0.1
        };
		
	};
};

class CfgMoves_MAR_ANT_Queen: CfgMovesMaleSdr
{
	gestures="CfgGestures_MAR_ANT_Queen";
	skeletonName = "ant_Queen_S";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a"};
	collisionGeomCompPattern[] = {1};
	class Default: Default
    {
        actions = "MAR_ANTQueen_Moves";
		file = "\Bugs_life\Ants\animations\antQueen_idle.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class StandBase: StandBase
    {
        actions = "MAR_ANTQueen_Moves";
        //ragdoll=0;
		file = "\Bugs_life\Ants\animations\antQueen_idle.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
        file = "\Bugs_life\Ants\animations\death_static.rtm";
		disableWeapons=1;
        //ragdoll=1;
		interpolationRestart=1;
		soundOverride="fallbody";
		soundEdge[]={0.44999999};
		soundEnabled=0;
	};
	class States
	{
 
		class ANT_Queen_Idle: Default
		{
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		    collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";			
			file = "\Bugs_life\Ants\animations\antQueen_idle.rtm";
            actions = "MAR_ANTQueen_Moves";
			duty = 0.1;
			boundingSphere = 4;
			interpolationSpeed = 1.5;
			variantAfter[]={6,6,6};
            variantsAI[] = {};
            variantsPlayer[] = {};			
            speed = -3;
            relSpeedMin = 1;
            relSpeedMax = 1;
            canPullTrigger = 1;
            canReload = 1;
            limitGunMovement = 0.5;
            headBobStrength=0;
            headBobMode=0;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableMissile = 1;
            enableOptics = 1;
            forceAim=1;
			leaning="empty";
            soundOverride="idle";
			aiming="HeadDefault_MAR_ANTQueen";
		    aimingBody="HeadDefault_MAR_ANTQueen";
			head = "HeadDefault_MAR_ANTQueen";
			legs="legsDefault_MAR_ANTQueen";
         
			InterpolateTo[]=
			{
				"ANT_Queen_Idle",
				0.01,							
				"ANT_Queen_Walk",
				0.01,
                "ANT_Queen_Walk_B",
				0.01,
                "ANT_Queen_Walk_R",
				0.01,
                "ANT_Queen_Walk_L",
				0.01,
				"ANT_Queen_Run",
				0.01,	
                "ANT_Queen_Death",
                0.01,
                "ANT_Queen_Death_2",
                0.01,
                "ANT_Queen_Death_3",
                0.01,
                "ANT_Queen_Turn_R",
                0.01,
                "ANT_Queen_Turn_L",
                0.01,
                "ANT_Queen_Attack_1",
                0.01,
                "ANT_Queen_Attack_Ranged",
                0.01,
                "ANT_Queen_inAir",
                0.01,
                "ANT_Queen_Landing",
                0.01				
			};
            interpolateFrom[]=
            {                
            };
		
		
			preload = 1;
		};
	
		
		//locomotion
            class ANT_Queen_Walk:ANT_Queen_Idle
            {
                file = "\Bugs_life\Ants\animations\walk_f.rtm";
                speed = -1.2;
                actions = "MAR_ANTQueen_Walk";
                soundOverride="walk";
            };
        //locomotion
            class ANT_Climb_IN: ANT_Queen_Idle
            {   
                file = "\Bugs_life\Ants\animations\antQueen_climbin.rtm";
                leaning="empty";
                aiming="empty";
                aimingBody="empty";
                head = "empty";	
                actions = "MAR_ANTQueen_ClimbIn";	
                looped = false;
                speed = -4;
                InterpolateTo[]=
                {
                    "ANT_Climb_outAssUp",
                    0.01,							                                
                };
            };
            class ANT_Climb_outAssUp: ANT_Queen_Idle
            {   
                file = "\Bugs_life\Ants\animations\antQueen_ClimbOutAssUp.rtm";
                leaning="empty";
                aiming="empty";
                aimingBody="empty";
                head = "empty";	
                actions = "MAR_ANTQueen_ClimbOutAssUp";	
                looped = false;
                speed = -3;
                InterpolateTo[]=
                {
                    "ANT_Climb_IN",
                    0.01,							                                
                };
            };
            class ANT_AssOutIdle: ANT_Queen_Idle
            {   
                file = "\Bugs_life\Ants\animations\antQueen_IdleAssUp.rtm";
                leaning="empty";
                aiming="empty";
                aimingBody="empty";
                head = "empty";	
                actions = "MAR_ANTQueen_AssOutIdle";	
                looped = true;
                speed = -6;
                InterpolateTo[]=
                {
                    "ANT_AssOutIdle",
                    0.01,							                                
                };
            };
            class ANT_Roar: ANT_Queen_Idle
            {   
                file = "\Bugs_life\Ants\animations\antQueen_Roar.rtm";
                leaning="empty";
                aiming="empty";
                aimingBody="empty";
                head = "empty";
                actions = "MAR_ANTQueen_Roar";		
                looped = false;
                speed = -3;
            };
            class ANT_ClimbOut: ANT_Queen_Idle
            {   
                file = "\Bugs_life\Ants\animations\antQueen_ClimbOut.rtm";
                leaning="empty";
                aiming="empty";
                aimingBody="empty";
                head = "empty";
                actions = "MAR_ANTQueen_ClimbOut";		
                looped = false;
                speed = -4;
                  InterpolateTo[]=
                {
                    "ANT_Queen_Idle",
                    0.01,							                                
                };
            };

		// attacks
		
	};
	
	class BlendAnims: BlendAnims
	{
		legsDefault_MAR_ANTQueen[]=
		{
            "a_head",
            0.8,
            "a_mandible.l",
            0.7,
            "a_mandible.r",
            0.7,
            "a_antenne_r",
            0.7,
            "a_antenne_r.001",	
            0.5,
            "a_antenne_r.002",	
            0.3,
            "a_antenne_l",
            0.7,
            "a_antenne_l.001",	
            0.5,   
            "a_antenne_l.002",	
            0.3,  
            "a_thorax",
            0.9,
            "a_mid",
            0.8,  
            "a_foreleg.r",
            0.9,
			"a_foreleg.r.001",
            0.8,
            "a_foreleg.r.002",
            0.6800000,
            "a_foreleg.r.003",
            0.6800000,
            "a_midleg.r",
            0.9,
            "a_midleg.r.001",
            0.8,
            "a_midleg.r.002",
            0.6800000,
            "a_midleg.r.003",
            0.6800000,
            "a_rearleg.r",
            0.9,
            "a_rearleg.r.001",
            0.8,
            "a_rearleg.r.002",
            0.6800000,
            "a_rearleg.r.003",
            0.6800000,
            "a_foreleg.l",
            0.9,
            "a_foreleg.l.001",
            0.8,
            "a_foreleg.l.002",
            0.6800000,
            "a_foreleg.l.003",
            0.6800000,
            "a_midleg.l",
            0.9,
            "a_midleg.l.001",
            0.8,
            "a_midleg.l.002",
            0.6800000,
            "a_midleg.l.003",
            0.6800000,
            "a_rearleg.l",
            0.9,
            "a_rearleg.l.001",
            0.8,
            "a_rearleg.l.002",
            0.6800000,
            "a_rearleg.l.003",
            0.6800000
					
		};
        HeadDefault_MAR_ANTQueen[]={
            "a_head",
            0.6,
            "a_mandible.l",
            0.5,
            "a_mandible.r",
            0.5,
            "a_antenne_r",
            0.5,
            "a_antenne_r.001",	
            0.5,
            "a_antenne_r.002",	
            0.3,
            "a_antenne_l",
            0.5,
            "a_antenne_l.001",	
            0.5,
            "a_antenne_l.002",	
            0.3,
            "a_thorax",
            0.2,
            "a_mid",
            0.1,
            "a_abdomen",
            0.5,
            "a_abdomen.001",
            0.4,
            "a_abdomen.002",
            0.3,
            "a_foreleg.r",
            0.2,
            "a_midleg.r",
            0.2,
            "a_rearleg.r",
            0.2,
            "a_foreleg.l",
            0.2,
            "a_midleg.l",
            0.2,
            "a_rearleg.l",
            0.2
        };
		
	};
};

class CfgMoves_MAR_Spider: CfgMovesMaleSdr
{
	gestures="CfgGestures_MAR_Spider";
	skeletonName = "shpida_s";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a"};
	collisionGeomCompPattern[] = {1};
	class Default: Default
    {
        actions = "MAR_SPIDER_Moves";
		file = "\Bugs_life\Spiders\animations\idle.rtm"
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class StandBase: StandBase
    {
        actions = "MAR_SPIDER_Moves";
        //ragdoll=0;
		file = "\Bugs_life\Spiders\animations\idle.rtm"
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
        file = "\Bugs_life\Spiders\animations\idle.rtm"
		disableWeapons=1;
        //ragdoll=1;
		interpolationRestart=1;
		soundOverride="fallbody";
		soundEdge[]={0.44999999};
		soundEnabled=0;
	};
	class States
	{
		class Spider_Idle: StandBase
		{
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		    collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";			
			file = "\Bugs_life\Spiders\animations\idle.rtm"
            actions = "MAR_SPIDER_Moves";
			duty = 0.1;
			boundingSphere = 4;
			interpolationSpeed = 1.5;
			variantAfter[]={6,6,6};
            variantsAI[] = {};
            variantsPlayer[] = {};			
            speed = -3;
            relSpeedMin = 1;
            relSpeedMax = 1;
            canPullTrigger = 1;
            canReload = 1;
            limitGunMovement = 0.5;
            headBobStrength=0;
            headBobMode=0;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableMissile = 1;
            enableOptics = 1;
			leaning="empty";
            soundOverride="idle";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
			legs="empty";
			InterpolateTo[]=
			{
				"Spider_Idle",
				0.01							
				
			};
            interpolateFrom[]={
       	
            };
			
			preload = 1;
		};
        class Spider_Burrowed_Idle: StandBase
		{
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		    collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";			
			file = "\Bugs_life\Spiders\animations\Burrowed_idle.rtm";
            actions = "MAR_SPIDER_Burrowed_Moves";
			duty = 0.1;
			boundingSphere = 4;
			interpolationSpeed = 1.5;
			variantAfter[]={6,6,6};
            variantsAI[] = {};
            variantsPlayer[] = {};			
            speed = -3;
            relSpeedMin = 1;
            relSpeedMax = 1;
            canPullTrigger = 1;
            canReload = 1;
            limitGunMovement = 0.5;
            headBobStrength=0;
            headBobMode=0;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableMissile = 1;
            enableOptics = 1;
			leaning="empty";
            soundOverride="idle";
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
			legs="empty";
			InterpolateTo[]=
			{
				"Spider_Burrowed_Idle",
				0.01,
                "Spider_Burrowed_Attack",
                0.01							
					
			};
            interpolateFrom[]={
       	
            };
			
			preload = 1;
		};
		class Spider_Burrowed_Attack:Spider_Burrowed_Idle
        {
            file = "\Bugs_life\Spiders\animations\Burrowed_attack.rtm";
            actions = "MAR_SPIDER_Burrowed_Attack";
            interpolationSpeed = 10;
            speed = -1.2;
            looped = false;
            soundOverride="attack";
        };
	
       

	

		// attacks
		
	};
	
	class BlendAnims: BlendAnims
	{
		legsDefault_MAR_Spider[]=
		{
          
					
		};
        HeadDefault_MAR_Spider[]={
      
        };
		
	};
};







class Extended_PreInit_EventHandlers
{	
    class MAR_BugsLife_PreInit
    {
        init="call compile preprocessFileLineNumbers 'Bugs_life\XEH_preInit.sqf'";
    };
};


class Extended_PostInit_EventHandlers 
{
    class MAR_BugsLife_PostInit 
	{
        init="call compile preprocessFileLineNumbers 'Bugs_life\XEH_postInit.sqf'";
    };
};

class Extended_InitPost_EventHandlers 
{
    class MAR_ANT_BASE 
    {
        class MAR_ANT_Basic_AI_INIT 
        {
           init = "_unit = _this select 0; if (local _unit) then {[_unit] execVM '\Bugs_life\Ants\AI\MAR_AI_basicAnt.sqf';};";
        };						
    };
    class MAR_Spider_Base 
    {
        class MAR_Spider_Basic_AI_INIT 
        {
           init = "_unit = _this select 0; if (local _unit) then {[_unit] execVM '\Bugs_life\Spiders\AI\MAR_AI_basicSpider.sqf';};";
        };						
    };
};

class CfgGroups
{
	class East
	{
		class Mar_ANTs_OPF
		{
			name = "ants";
			class Ant_groups_OPF
			{
				name = "Ant Groups";
				class Worker_Patrol_OP
				{
					name = "Patrol";
					side = 0;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class Spitter_Patrol_OP
				{
					name = "Spitter Patrol";
					side = 0;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class ICE_Patrol_OP
				{
					name = "Ice ant Patrol";
					side = 0;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class WorkerSpitter_Patrol_OP
				{
					name = "Scout section";
					side = 0;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 5,5,0 };
					};
					class Unit5
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,10,0 };
					};
					class Unit6
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,15,0 };
					};
                    class Unit7
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 18,18,0 };
					};
				};

                class WorkerICESpitter_Patrol_OP
				{
					name = "Hill defense section";
					side = 0;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 5,5,0 };
					};
					class Unit5
					{
						side = 0;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,10,0 };
					};
					class Unit6
					{
						side = 0;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,15,0 };
					};
                    class Unit7
					{
						side = 0;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 18,18,0 };
					};
				};

			};
            
		};
	};

    class Indep
	{
		class Mar_ANTs_INDI
		{
			name = "ants";
			class Ant_groups_INDI
			{
				name = "Ant Groups";
				class Worker_Patrol_IND
				{
					name = "Patrol";
					side = 2;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class Spitter_Patrol_IND
				{
					name = "Spitter Patrol";
					side = 2;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class ICE_Patrol_IND
				{
					name = "Ice ant Patrol";
					side = 2;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit5
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
				};

                class WorkerSpitter_Patrol_IND
				{
					name = "Scout section";
					side = 2;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 5,5,0 };
					};
					class Unit5
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,10,0 };
					};
					class Unit6
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 15,15,0 };
					};
                    class Unit7
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 18,18,0 };
					};
				};

                class WorkerICESpitter_Patrol_IND
				{
					name = "Hill defense section";
					side = 2;					
					rarityGroup = 0.30000001;
					
					class Unit0
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 0,0,0 };
					};
					class Unit1
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 5,-5,0 };
					};
					class Unit2
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 10,-10,0 };
					};
                    class Unit3
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,-15,0 };
					};
                    class Unit4
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "CORPORAL";
						position[] = { 5,5,0 };
					};
					class Unit5
					{
						side = 2;
						vehicle = "MAR_ANT_Basic";
						rank = "PRIVATE";
						position[] = { 10,10,0 };
					};
					class Unit6
					{
						side = 2;
						vehicle = "MAR_ANT_Ice";
						rank = "PRIVATE";
						position[] = { 15,15,0 };
					};
                    class Unit7
					{
						side = 2;
						vehicle = "MAR_ANT_Spitter";
						rank = "PRIVATE";
						position[] = { 18,18,0 };
					};
				};

			};
            
		};
	};
};