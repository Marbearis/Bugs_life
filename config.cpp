class CfgPatches
{
	class Marbys_Bugs_Life
	{
		units[] = {"MAR_ANT_Basic","MAR_ANT_Ice","MAR_ANT_Spitter","MAR_antHill"};
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
        class AnimationSources
        {
            class Anthill_Raised
            {
                source="user";
                animPeriod=3;
                initPhase=1;
                sound="";
                soundPosition="";
            };
        };

    };
    
    class MAR_Ant_Part_Head:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Head.p3d";
        displayName = "Ant head";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
    };

    class MAR_Ant_Part_Thorax:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Thorax.p3d";
        displayName = "Ant Thorax";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
    };

    class MAR_Ant_Part_Abdomen:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Abdomen.p3d";
        displayName = "Ant Abdomen";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
    };

    class MAR_Ant_Part_Leg:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Leg.p3d";
        displayName = "Ant Leg";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
    };

    class MAR_Ant_Part_Antenne:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\antenne.p3d";
        displayName = "Ant antenne";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
    };

    class MAR_Ant_Part_Mandible:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Mandible.p3d";
        displayName = "Ant Mandible";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
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
	//units
	class B_Soldier_base_F;	// External class reference
	class Marby_C_ExportClass : B_Soldier_base_F {
		identityTypes[] = {"empty_Face"};
	};

	class MAR_ANT_BASE : Marby_C_ExportClass 
    {
        side = 0;
        scope = 0;			
        scopeCurator = 0;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Green";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Green";
        faction = "MAR_Bug_Faction";
		editorSubcategory = "MAR_Bugs_Ants";
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

    class MAR_ANT_Basic:MAR_ANT_BASE
    {
        side = 0;
		scope = 2;			
		scopeCurator = 2;
        displayName = "Worker Ant";
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Orange";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Orange";
    };
    class MAR_ANT_Spitter:MAR_ANT_BASE
    {
        side = 0;
		scope = 2;			
		scopeCurator = 2;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Green";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Green";
        displayName = "Spitter Ant";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
        uniformClass = "ANT_Uniform_spitter";
        nakedUniform = "ANT_Uniform_spitter";
    };
    class MAR_ANT_Ice:MAR_ANT_BASE
    {
        side = 0;
		scope = 2;			
		scopeCurator = 2;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Blue";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Blue";
        displayName = "Ice Ant";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\IceAnt\ANT_CO.paa","\Bugs_life\Ants\textures\IceAnt\ANT_CO.paa"};
        uniformClass = "ANT_Uniform_ICE";
        nakedUniform = "ANT_Uniform_ICE";
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
    class ANT_Uniform_spitter: Uniform_Base
		{
			displayname="ANT_Basic";
			model = "\Bugs_life\Ants\BasicAnt.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
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
			displayname="ANT_Basic";
			model = "\Bugs_life\Ants\BasicAnt.p3d";
			scope=1;
			picture="";
			hiddenSelections[] = {"camo","eyes"};
			hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\IceAnt\ANT_CO.paa","\Bugs_life\Ants\textures\IceAnt\ANT_CO.paa"};
			class ItemInfo: UniformItem
			{
				containerclass="Supply200";
				mass=30;
				uniformclass="ANT_Uniform_ICE";
				uniformmodel="-";
			};
		};
};

/*
    class CfgRagDollSkeletons
    {
            class BaseRagdoll;
            class AntRagdoll: BaseRagdoll
        {
            networkBonePrimary="a_thorax";
            networkBoneSecondary="a_mid";
            
            
            class BaseRagdollBone
            {
                childrenUseIdleAnim=0;
                material="Ragdoll";
                childrenUseStartTrans=1;
            };

            class Bones
            {
                class Pelvis: BaseRagdollBone
                {
                    radius=0.12;
                    networkType="root";
                    name="pelvis";
                    type="box";
                    size[]={0.11,0.12,0.20999999};
                    startBone="a_mid";
                    endBone="a_thorax";
                    mass=36;
                };
                class Chest: BaseRagdollBone
                {
                    radius=0.16;
                    name="chest";
                    startBone="a_thorax";
                    endBone="a_head";
                    type="box";
                    size[]={0.11,0.14,0.19};
                    mass=20;
                };
                class Head: BaseRagdollBone
                {
                    name="head";
                    type="sphere";
                    startBone="a_head";
                    offset[]={0,-0.1,0};
                    mass=9.75;
                    radius=0.12;
                };
                //right
                    class r_foreleg: BaseRagdollBone
                    {
                        name="r_foreleg";
                        type="capsule";
                        startBone="a_foreleg.r";
                        endBone="a_foreleg.r.001";
                        mass=9.75;
                    };
                    class r_foreleg_1: BaseRagdollBone
                    {
                        name="r_foreleg_1";
                        type="capsule";
                        startBone="a_foreleg.r.001";
                        endBone="a_foreleg.r.002";
                        mass=12;
                    };
                    class r_foreleg_2: BaseRagdollBone
                    {
                        childrenUseIdleAnim=1;
                        networkType="rightHand";
                        name="r_foreleg_2";
                        type="sphere";
                        startBone="a_foreleg.r.002";
                        endBone =   "a_foreleg.r.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
                    class r_midLeg: r_foreleg
                    {
                        name="r_midLeg";
                        type="capsule";
                        startBone="a_midleg.r";
                        endBone="a_midleg.r.001";
                        mass=9.75;
                    };
                    class r_midLeg_1: r_foreleg_1
                    {
                        name="r_midLeg_1";
                        type="capsule";
                        startBone="a_midleg.r.001";
                        endBone="a_midleg.r.002";
                        mass=12;
                    };
                    class r_midLeg_2: r_foreleg_2
                    {
                        childrenUseIdleAnim=1;
                        networkType="rightHand";
                        name="r_midLeg_2";
                        type="sphere";
                        startBone="a_midleg.r.002";
                        endBone =   "a_midleg.r.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
                    class r_rearLeg: r_foreleg
                    {
                        name="r_rearLeg";
                        type="capsule";
                        startBone="a_rearleg.r";
                        endBone="a_rearleg.r.001";
                        mass=9.75;
                    };
                    class r_rearLeg_1: r_foreleg_1
                    {
                        name="r_rearLeg_1";
                        type="capsule";
                        startBone="a_rearleg.r.001";
                        endBone="a_rearleg.r.002";
                        mass=12;
                    };
                    class r_rearLeg_2: r_foreleg_2
                    {
                        childrenUseIdleAnim=1;
                        networkType="rightHand";
                        name="r_rearLeg_2";
                        type="sphere";
                        startBone="a_rearleg.r.002";
                        endBone =   "a_rearleg.r.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
                //left
                    class l_foreleg: BaseRagdollBone
                    {
                        name="l_foreleg";
                        type="capsule";
                        startBone="a_foreleg.l";
                        endBone="a_foreleg.l.001";
                        mass=9.75;
                    };
                    class l_foreleg_1: BaseRagdollBone
                    {
                        name="l_foreleg_1";
                        type="capsule";
                        startBone="a_foreleg.l.001";
                        endBone="a_foreleg.l.002";
                        mass=12;
                    };
                    class l_foreleg_2: BaseRagdollBone
                    {
                        childrenUseIdleAnim=1;
                        networkType="rightHand";
                        name="l_foreleg_2";
                        type="sphere";
                        startBone="a_foreleg.l.002";
                        endBone =   "a_foreleg.l.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
                    class l_midLeg: r_foreleg
                    {
                        name="l_midLeg";
                        type="capsule";
                        startBone="a_midleg.l";
                        endBone="a_midleg.l.001";
                        mass=9.75;
                    };
                    class l_midLeg_1: r_foreleg_1
                    {
                        name="l_midLeg_1";
                        type="capsule";
                        startBone="a_midleg.l.001";
                        endBone="a_midleg.l.002";
                        mass=12;
                    };
                    class l_midLeg_2: r_foreleg_2
                    {
                        childrenUseIdleAnim=1;
                        networkType="leftHand";
                        name="l_midLeg_2";
                        type="sphere";
                        startBone="a_midleg.l.002";
                        endBone =   "a_midleg.l.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
                    class l_rearLeg: r_foreleg
                    {
                        name="l_rearLeg";
                        type="capsule";
                        startBone="a_rearleg.l";
                        endBone="a_rearleg.l.001";
                        mass=9.75;
                    };
                    class l_rearLeg_1: r_foreleg_1
                    {
                        name="l_rearLeg_1";
                        type="capsule";
                        startBone="a_rearleg.l.001";
                        endBone="a_rearleg.l.002";
                        mass=12;
                    };
                    class l_rearLeg_2: r_foreleg_2
                    {
                        childrenUseIdleAnim=1;
                        networkType="leftHand";
                        name="l_rearLeg_2";
                        type="sphere";
                        startBone="a_rearleg.l.002";
                        endBone =   "a_rearleg.l.003";
                        mass=6;
                        radius=0.079999998;
                        childrenUseStartTrans=0;
                    };
            };
        

        };
        
    };

    class CfgSkeletonParameters
    {
        class ant_Armature
        {
            pivotsModel = "Bugs_life\Ants\BasicAnt_pivots.p3d";
            ragdoll = "AntRagdoll";
            weaponBone = "";
        };
    };
*/

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
};