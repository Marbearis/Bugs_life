class CfgCloudlets {
    class BloodMist;
    class Blood;
    class LaptopSparks;
    class SmokeTrailEffect1;
    class ImpactEffectsWater1Med;
    class MAR_BugGut_Mist_Green:BloodMist {
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
        size[] = {
			2, 2
		};
        emissiveColor[] = {{ 0.25, 0.9, 0.25, 1 }};
    };

    class MAR_BugGuts_Green:Blood{
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
        emissiveColor[] = {{ 0.25, 0.9, 0.25, 1 }};
    };

    class MAR_BugAcid_Mist_Green: SmokeTrailEffect1 {
        size[] = {
			4, 4
		};
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
        emissiveColor[] = {{ 0.25, 0.9, 0.25, 1 }};
       
    };

    class MAR_BugAcid_Mist_Impact_Green:ImpactEffectsWater1Med
    {
        color[]=
        {
            {0.3,1,0,0.12},
            {0.3,1,0,0.050000001}
        };
        emissiveColor[] = {{ 0.25, 0.9, 0.25, 1 }};
    };
    
    class MAR_BugGut_Mist_Orange:MAR_BugGut_Mist_Green {
        color[]=
        {
            {1,0.6,0,0.12},
            {1,0.6,0,0.050000001}
        };
        emissiveColor[] = {{ 1, 0.5, 0.25, 1 }};
    };

    class MAR_BugGuts_Orange:MAR_BugGuts_Green{
        color[]=
        {
            {1,0.6,0,0.12},
            {1,0.6,0,0.050000001}
        };
        emissiveColor[] = {{ 1, 0.5, 0.25, 1 }};
    };

    class MAR_BugGut_Mist_Blue:MAR_BugGut_Mist_Green {
        color[]=
        {
            {,0.6,1,0.12},
            {,0.6,1,0.050000001}
        };
        emissiveColor[] = {{ 0, 0.5, 1, 1 }};
    };

    class MAR_BugGuts_Blue:MAR_BugGuts_Green{
        color[]=
        {
            {,0.6,1,0.12},
            {,0.6,1,0.050000001}
        };
        emissiveColor[] = {{ 0, 0.5, 1, 1 }};
    };

  

    
};

class MAR_ImpactEffects_Acid 
{
    class MAR_BugAcid_Mist01
	{
		simulation="particles";
		type="MAR_BugAcid_Mist";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.1;
		qualityLevel=2;
	};
	class MAR_BugAcid_Mist_Impact01
	{
		simulation="particles";
		type="MAR_BugAcid_Mist_Impact";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.1;
		qualityLevel=1;
	};
};

class MAR_ImpactEffectsBugGuts_Green
{
	class BloodMist
	{
		simulation="particles";
		type="MAR_BugGut_Mist_Green";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
		MoveVelocityVar[]={0,0,0};
	};
	class Blood
	{
		simulation="particles";
		type="MAR_BugGuts_Green";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	
};

class MAR_ImpactEffectsBugGuts_Orange
{
	class BloodMist
	{
		simulation="particles";
		type="MAR_BugGut_Mist_Orange";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
		MoveVelocityVar[]={0,0,0};
	};
	class Blood
	{
		simulation="particles";
		type="MAR_BugGuts_Orange";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	
};

class MAR_ImpactEffectsBugGuts_Blue
{
	class BloodMist
	{
		simulation="particles";
		type="MAR_BugGut_Mist_Blue";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
		MoveVelocityVar[]={0,0,0};
	};
	class Blood
	{
		simulation="particles";
		type="MAR_BugGuts_Blue";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=0.2;
	};
	
};

class BugsLife_AcidSpit
{
    class BloodMist
	{
		simulation="particles";
		type="MAR_BugAcid_Mist_Green";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
		MoveVelocityVar[]={0,0,0};
	};
	class Blood
	{
		simulation="particles";
		type="MAR_BugGuts_Green";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=1;
	};
};