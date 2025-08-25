	
	class CfgAmmo
	{
		class SmokeShell;		
		class B_408_Ball;
		class G_20mm_HE;
		class B_56x15_dual;
		class GrenadeHand;
		class Default;
		class BulletCore;
	    
    
        
        class B_BugsLife_Acid_Spit: SmokeShell
        {
            explosionSoundEffect = "DefaultExplosion";
            timeToLive = 900;
            grenadeFireSound[] = {};
            grenadeBurningSound[] = {};
            model = "\A3\Weapons_F_EPB\Ammo\B_IRstrobe_F.p3d";
            simulation = "shotGrenade";
			effectFly="BugsLife_AcidSpit";	
            hit = 9;
            indirectHit = 0;
            indirectHitRange = 0;
            deflecting = 0;
            airFriction = -0.001;
            whistleDist = 16;
            typicalSpeed = 26;
            explosionTime = 0;
            fuseDistance = 1;
            directionalExplosion = 0;
            deflectionSlowDown = 0;
            simulationStep = 0.05;
            SoundSetExplosion[] = {"Explosion_Debris_SoundSet"};		  
        };
   
	
		
		
		class B_BugsLife_Acid_Spit_Sub:SmokeShell
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

