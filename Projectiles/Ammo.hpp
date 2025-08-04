	class Eventhandlers;
	class CfgAmmo
	{
		
	class B_408_Ball;
	class G_20mm_HE;
	class B_56x15_dual;
	class GrenadeHand;
	class Default;
	class BulletCore;
	
	
		class B_BugsLife_Acid_Spit:GrenadeHand
			{
				hit = 7;
				indirectHit = 4;
				timeToLive = 15;
				explosive=0;
				effectFly="BugsLife_AcidSpit";				
				cartridge = "";
				model = "Bugs_Life\Projectiles\spiker_round.p3d";
				fuseDistance = 0.1;
				thrustTime = 200;
				triggerDistance=0.1;
				triggerSpeedCoef[]={0.5,1};
				submunitionConeAngle=15;
				submunitionConeType[]=
				{
					"randomcenter",
					3
				};
				submunitionAmmo[]=
				{
					"B_BugsLife_Acid_Spit_Sub",
					0.93000001				
				};
				multiSoundHit[]={};
				CraterEffects="ClusterCraterWaterEffects";
				CraterWaterEffects="ClusterCraterWaterEffects";
				ExplosionEffects="MAR_ImpactEffects_Acid";
				class HitEffects
				{
					Hit_Foliage_green="MAR_ImpactEffects_Acid";
					Hit_Foliage_Dead="MAR_ImpactEffects_Acid";
					Hit_Foliage_Green_big="MAR_ImpactEffects_Acid";
					Hit_Foliage_Palm="MAR_ImpactEffects_Acid";
					Hit_Foliage_Pine="MAR_ImpactEffects_Acid";
					hitFoliage="MAR_ImpactEffects_Acid";
					hitGlass="MAR_ImpactEffects_Acid";
					hitGlassArmored="MAR_ImpactEffects_Acid";
					hitWood="MAR_ImpactEffects_Acid";
					hitHay="MAR_ImpactEffects_Acid";
					hitMetal="MAR_ImpactEffects_Acid";
					hitMetalPlate="MAR_ImpactEffects_Acid";
					hitBuilding="MAR_ImpactEffects_Acid";
					hitPlastic="MAR_ImpactEffects_Acid";
					hitRubber="MAR_ImpactEffects_Acid";
					hitConcrete="MAR_ImpactEffects_Acid";
					hitMan="MAR_ImpactEffects_Acid";
					hitGroundSoft="MAR_ImpactEffects_Acid";
					hitGroundHard="MAR_ImpactEffects_Acid";
					hitWater="MAR_ImpactEffects_Acid";
					hitVirtual="MAR_ImpactEffects_Acid";
				};
			};
		
		class B_BugsLife_Acid_Spit_Sub:GrenadeHand
		{
			hit = 7;
			indirectHit = 4;
			timeToLive = 15;
			explosive=0;
			CraterEffects="ClusterCraterWaterEffects";
			CraterWaterEffects="ClusterCraterWaterEffects";
			ExplosionEffects="MAR_ImpactEffects_Acid";
			effectsMissile = "BugsLife_AcidSpit";
			effectFly="BugsLife_AcidSpit";	
			cartridge = "";
			model = "Bugs_Life\Projectiles\spiker_round.p3d";
			fuseDistance = 0.1;
			thrustTime = 200;
			multiSoundHit[]={};
			class HitEffects
			{
				Hit_Foliage_green="MAR_ImpactEffects_Acid";
				Hit_Foliage_Dead="MAR_ImpactEffects_Acid";
				Hit_Foliage_Green_big="MAR_ImpactEffects_Acid";
				Hit_Foliage_Palm="MAR_ImpactEffects_Acid";
				Hit_Foliage_Pine="MAR_ImpactEffects_Acid";
				hitFoliage="MAR_ImpactEffects_Acid";
				hitGlass="MAR_ImpactEffects_Acid";
				hitGlassArmored="MAR_ImpactEffects_Acid";
				hitWood="MAR_ImpactEffects_Acid";
				hitHay="MAR_ImpactEffects_Acid";
				hitMetal="MAR_ImpactEffects_Acid";
				hitMetalPlate="MAR_ImpactEffects_Acid";
				hitBuilding="MAR_ImpactEffects_Acid";
				hitPlastic="MAR_ImpactEffects_Acid";
				hitRubber="MAR_ImpactEffects_Acid";
				hitConcrete="MAR_ImpactEffects_Acid";
				hitMan="MAR_ImpactEffects_Acid";
				hitGroundSoft="MAR_ImpactEffects_Acid";
				hitGroundHard="MAR_ImpactEffects_Acid";
				hitWater="MAR_ImpactEffects_Acid";
				hitVirtual="MAR_ImpactEffects_Acid";
			};
		};




	};

class cfgMagazines
{
	
	class OPTRE_FC_Battery_Base;
	class MAR_Spiker_Mag: OPTRE_FC_Battery_Base
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName="spiker rounds";
		displaynameshort = "Spikes";
		ammo="B_spiker_Round";
		descriptionshort="Ammo for the brute spiker";
		count=32;
		initspeed=450;
		mass=1;
		tracersEvery = 1;
		lastRoundsTracer=32;
	};
	class 6Rnd_45ACP_Cylinder;
	class MAR_Mangler_Mag: 6Rnd_45ACP_Cylinder
	{

		displayName="Mangler Rounds";
		displaynameshort = "Mangler spikes";
		ammo="B_Mangler_Round";
		count=8;
		tracersEvery = 1;
		initspeed=400;
	
	};

	class MAR_test_Mag: MAR_Mangler_Mag
	{
		displayName="Titanus [HPIR rounds]";
		displaynameshort = "HPIR";
		initSpeed=1430;
		count=5;
		tracersEvery = 1;
		ammo="B_TestRound";
	};

	class MAR_Mangler_Mag_DHE: 6Rnd_45ACP_Cylinder
	{

		displayName="Mangler Rounds [DHE]";
		displaynameshort = "DHE Mangler Rounds";
		ammo="B_ManglerRND_Spec";
		count=8;
		tracersEvery = 1;
		initspeed=400;
	
	};

	class MAR_Disruptor_Mag: OPTRE_FC_Battery_Base
	{
		displayName="Disrupter bolts";
		displaynameshort = "Bolts";
		ammo="B_Disrupter_Round";
		descriptionshort="Ammo for the Disruptor";
		count=10;
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		tracersEvery = 1;
		initspeed=700;
	};

	
};