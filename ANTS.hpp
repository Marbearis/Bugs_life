//OPFOR ANTS
    class MAR_ANT_BASE:MAR_Critter_BASE
    {
        side = 0;
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
        class Eventhandlers
        {
            init = "_this#0 allowFleeing 0;_this#0 setSpeaker 'NoVoice';_this#0 disableConversation true;";//[_this#0] execVM 'Bugs_life\Ants\AI\BasicAnt.sqf'
        };
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
    class MAR_ANT_QUEEN:MAR_ANT_BASE
    {
        side = 0;
        scope = 2;			
        scopeCurator = 2;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Orange";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Orange";
        editorPreview="";
        faction = "MAR_Bug_Faction";
        editorSubcategory = "MAR_Bugs_Ants";
        displayName = "Ant Queen";
        model = "\Bugs_life\Ants\antQueen.p3d";
        hiddenSelections[] = {"camo","eyes","camo1"};
        hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\queen\body_CO.paa","\Bugs_life\Ants\textures\queen\body_CO.paa","\Bugs_life\Ants\textures\queen\eggAbdomen_CO.paa"};
        hiddenSelectionsMaterials[] = {"\Bugs_life\Ants\textures\queen\body.rvmat","\Bugs_life\Ants\textures\queen\body.rvmat","\Bugs_life\Ants\textures\queen\eggAbdomen.rvmat"};
        uniformClass = "ANT_Queen_Uniform";
        nakedUniform = "ANT_Queen_Uniform";
        _generalMacro = "MAR_ANT_Queen";
        gestures = "CfgGestures_MAR_ANT_Queen";
        moves = "CfgMoves_MAR_ANT_Queen";
        class Eventhandlers
        {
            init = "_this#0 allowFleeing 0;_this#0 setSpeaker 'NoVoice';_this#0 disableConversation true;";//[_this#0] execVM 'Bugs_life\Ants\AI\BasicAnt.sqf'
        };
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
    };
//OPFOR END

//GREENFOR
    class MAR_ANT_Basic_G:MAR_ANT_Basic
    {
        side = 2;
    };
    class MAR_ANT_Spitter_G: MAR_ANT_Spitter
    {
        side = 2;
    };
    class MAR_ANT_Ice_G:MAR_ANT_Ice
    {
        side = 2;
    };
    class MAR_ANT_QUEEN_G:MAR_ANT_QUEEN
    {
        side = 2;
    };
//GREENFOR END

//ANT PROPS

    class MAR_antHill: House_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\Anthill.p3d";
        displayName = "Ant hill";
        hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\anthill\anthill_CO.paa"};
        hiddenSelectionsMaterials[]={"\Bugs_life\Ants\textures\anthill\anthill.rvmat"};
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
        armor = 1;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\parts\Head.p3d";
        displayName = "Ant head";
        hiddenSelections[] = {"camo","eyes"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa","\Bugs_life\Ants\textures\SpitterAnt\ANT_CO.paa"};
        class Eventhandlers
        {
            init = "_this#0 call BugsLife_AntEgginit";
        };
       
    };

    class MAR_Ant_Egg:Land_Basketball_01_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\egg.p3d";
        displayName = "Ant Egg (physx)";
        hiddenSelections[] = {"egg"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\egg\DefaultMaterial_CO.paa"};
        hiddenSelectionsMaterials[] = {"\Bugs_life\Ants\textures\egg\DefaultMaterial.rvmat"};

        class Eventhandlers
        {
            init = "_this#0 call BugsLife_AntEgginit";
        };
   
    };

    class MAR_Ant_Egg_Clutch:House_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\eggclutch.p3d";
        displayName = "Ant Egg Clutch";
        hiddenSelections[] = {"egg"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\egg\DefaultMaterial_CO.paa"};
        hiddenSelectionsMaterials[] = {"\Bugs_life\Ants\textures\egg\DefaultMaterial.rvmat"};
        class Eventhandlers
        {
            init = "_this#0 call BugsLife_AntEgginit";
        };
    };

    class MAR_Ant_Webs:House_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\antWebs.p3d";
        displayName = "Ant webbing";
    };

    class MAR_Ant_Webs_2:House_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Ants";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Ants\antWebs_1.p3d";
        displayName = "Ant webbing tall";
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

