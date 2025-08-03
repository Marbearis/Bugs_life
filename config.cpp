class CfgPatches
{
	class Marbys_Bugs_Life
	{
		units[] = {"MAR_ANT_Basic","MAR_antHill"};
		weapons[] = {};
		magazines[]={};
		ammo[]={};
		requiredAddons[] = {"A3_Characters_F","a3_anims_f"};
		requiredVersion = 0.1;
		author = "Marbearis";
	};
};

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
	class House_F;//
	class Items_base_F;
	class Land_Basketball_01_F;
    class MAR_antHill: House_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\Anthill.p3d";
        displayName = "Ant hill";

    };
	//units
	class B_Soldier_base_F;	// External class reference
	class WBK_C_ExportClass : B_Soldier_base_F {
		identityTypes[] = {"empty_Face"};
	};

	class MAR_ANT_BASE : WBK_C_ExportClass 
    {
        side = 0;
        scope = 0;			
        scopeCurator = 0;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts";
        faction = "MAR_Bug_Faction";
		editorSubcategory = "MAR_Bugs_Ants";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\Basic\ANT_CO.paa","\Bugs_life\Ants\textures\Basic\ANT_CO.paa"};
        _generalMacro = "MAR_ANT_1";
        gestures = "CfgGestures_MAR_ANT";
        moves = "CfgMoves_MAR_ANT";
        items[] = {};
        linkedItems[] = {};
        RespawnlinkedItems[]={};
        uniformClass = "ANT_Uniform";
        nakedUniform = "ANT_Uniform";
        vehicleclass = "Men";
        displayName = "ANT_BASE";
        
        
        model = "\Bugs_life\Ants\BasicAnt.p3d";
        armor = 7;
        editorPreview="";
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
                {"run", {"\Mars_Addons\Units\ANT\Sounds\Golem_StompSlam_Impact.ogg", 1, 1, 60}},
                            
                {"walk", {"\Mars_Addons\Units\ANT\Sounds\Golem_StompSlam_Impact.ogg", 1, 1, 25}}
            
                };
            };
            class SoundEquipment {	
                soldier[] = {
                {"run", {"\Mars_Addons\Units\ANT\Sounds\Golem_StompSlam_Impact.ogg", 1, 1, 60}},
                            
                {"walk", {"\Mars_Addons\Units\ANT\Sounds\Golem_StompSlam_Impact.ogg", 1, 1, 25}}
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

    class MAR_ANT_Basic:MAR_ANT_BASE
    {
        side = 0;
		scope = 2;			
		scopeCurator = 2;
        displayName = "Worker Ant";
    };
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
				Die="ANT_DEATH";
				StartFreefall="ANT_InAir";
				Unconscious = "ANT_DEATH";
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
                turnSpeed=4.5;
				PlayerCrouch="ANT_Death";
				Up="ANT_Death";
				Crouch="ANT_Death";
				AdjustB="";
				Stand="ANT_Death";
            };
            class  MAR_ANT_Death_Static:MAR_ANT_Moves
            {
                turnSpeed=4.5;
				PlayerCrouch="ANT_Death_Static";
				Up="ANT_Death_Static";
				Crouch="ANT_Death_Static";
				AdjustB="";
				Stand="ANT_Death_Static";
            };

            
		
	
			//hit reactions
	
			
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
		//ANT moveset end
	};
	
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
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
		file = "\Bugs_life\Ants\animations\idle_1.rtm";
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
    };
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
		disableWeapons=1;
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
			aiming="empty";
		    aimingBody="empty";
			head = "empty";
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
                "ANT_Turn_R",
                0.01,
                "ANT_Turn_L",
                0.01,
                "ANT_DEATH",
                0.01,
                "ANT_Attack_1",
                0.01
				
			};
			
			preload = 1;
		};
	
		
		//locomotion
		class ANT_Walk:ANT_Idle
		{
			file = "\Bugs_life\Ants\animations\walk_f.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk";
		};

        class ANT_Walk_B:ANT_Walk
		{
			file = "\Bugs_life\Ants\animations\walk_B.rtm";
			speed = -1.2;
            actions = "MAR_ANT_Walk_B";
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
		};

        class ANT_Turn_R:ANT_Walk
		{
			speed = -1.2;
            file = "\Bugs_life\Ants\animations\turnr.rtm";
            actions = "MAR_ANT_Turn_R";
		};

        class ANT_Turn_L:ANT_Walk
		{
			speed = -1.2;
            file = "\Bugs_life\Ants\animations\turnl.rtm";
            actions = "MAR_ANT_Turn_L";
		};

        class ANT_DEATH:ANT_Idle
        {
            terminal = 1;
            speed = -1.2;
            looped = flase;
            file = "\Bugs_life\Ants\animations\death_1.rtm";
            actions = "MAR_ANT_Death_1";
        };

        class ANT_DEATH_Static:ANT_DEATH
        {
            terminal = 1;
            file = "\Bugs_life\Ants\animations\death_static.rtm";
            actions = "MAR_ANT_Death_Static";
        };

		class ANT_Attack_1:ANT_Walk
        {
            looped = flase;
            file = "\Bugs_life\Ants\animations\attack_1.rtm";
            actions = "MAR_ANT_Attack_1";
        };

	

		// attacks
		
	};
	
	class BlendAnims: BlendAnims
	{
		legsDefault_MAR_ANT[]=
		{
            "a_foreleg.r",
            0.6800000,
			"a_foreleg.r.001",
            0.6800000,
            "a_foreleg.r.002",
            0.6800000,
            "a_foreleg.r.003",
            0.6800000,
            "a_midleg.r",
            0.6800000,
            "a_midleg.r.001",
            0.6800000,
            "a_midleg.r.002",
            0.6800000,
            "a_midleg.r.003",
            0.6800000,
            "a_rearleg.r",
            0.6800000,
            "a_rearleg.r.001",
            0.6800000,
            "a_rearleg.r.002",
            0.6800000,
            "a_rearleg.r.003",
            0.6800000,
            "a_foreleg.l",
            0.6800000,
            "a_foreleg.l.001",
            0.6800000,
            "a_foreleg.l.002",
            0.6800000,
            "a_foreleg.l.003",
            0.6800000,
            "a_midleg.l",
            0.6800000,
            "a_midleg.l.001",
            0.6800000,
            "a_midleg.l.002",
            0.6800000,
            "a_midleg.l.003",
            0.6800000,
            "a_rearleg.l",
            0.6800000,
            "a_rearleg.l.001",
            0.6800000,
            "a_rearleg.l.002",
            0.6800000,
            "a_rearleg.l.003",
            0.6800000
					
		};
		
	};
};



class CfgCloudlets {
    class BloodMist;
    class Blood;
    class MAR_BugGut_Mist:BloodMist {
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
    };
    class MAR_BugGuts:Blood{
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
    };
};


class MAR_ImpactEffectsBugGuts
{
	class BloodMist
	{
		simulation="particles";
		type="MAR_BugGut_Mist";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
		MoveVelocityVar[]={0,0,0};
	};
	class Blood
	{
		simulation="particles";
		type="MAR_BugGuts";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	
};





class Extended_PreInit_EventHandlers
{	
    class MAR_Addons_PreInit
    {
        init="call compile preprocessFileLineNumbers 'Bugs_life\XEH_preInit.sqf'";
    };
};


class Extended_PostInit_EventHandlers 
{
    class MAR_Addons_PostInit 
	{
     //   init="call compile preprocessFileLineNumbers 'Mars_Addons\XEH_postInit.sqf'";
    };
};

class Extended_InitPost_EventHandlers 
{
    class MAR_ANT_Basic 
    {
        class MAR_ANT_Basic_AI_INIT 
        {
            init = "_unit = _this select 0; if (local _unit) then {[_unit] execVM '\Bugs_life\Ants\AI\MAR_AI_basicAnt.sqf';};";
        };						
    };
};