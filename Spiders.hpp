//OPFOR Spiders 
    class MAR_Spider_Base:MAR_Critter_BASE
    {
        side = 0;
        scope = 0;			
        scopeCurator = 0;
        uniformClass = "Spider_Uniform";
        nakedUniform = "Spider_Uniform";
        _generalMacro = "MAR_Spider_1";
        gestures = "CfgGestures_MAR_Spider";
        moves = "CfgMoves_MAR_Spider";
        faction = "MAR_Bug_Faction";
        editorSubcategory = "MAR_Bugs_Spiders";
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
    class MAR_Spider_Burrower:MAR_Spider_Base
    {
        side = 0;
        scope = 2;			
        scopeCurator = 2;
        impactEffectsBlood = "MAR_ImpactEffectsBugGuts_Green";
        impactEffectsNoBlood = "MAR_ImpactEffectsBugGuts_Green";
        editorPreview="";       
        displayName = "Trapdoor Spider";
        model = "\Bugs_life\Spiders\shpida.p3d";
        hiddenSelections[] = {"camo","eyes"};
        hiddenSelectionsTextures[] = {"\Bugs_life\Spiders\textures\spider_1\DefaultMaterial_CO.paa","\Bugs_life\Spiders\textures\spider_1\DefaultMaterial_CO.paa"};


    };
//OPFOR END

//Props
    class MAR_TrapDoor: House_F
    {
        scope = 2;			
		scopeCurator = 2;
        editorSubcategory = "MAR_Bugs_Spiders";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Spiders\Spider_hole.p3d";
        displayName = "MAR_TrapDoor";
        hiddenSelections[] = {"earth"};
		hiddenSelectionsTextures[] = {"\Bugs_life\Ants\textures\anthill\anthill_CO.paa"};
        hiddenSelectionsMaterials[] = {"\Bugs_life\data\genericGround\DefaultMaterial.rvmat"};
        class AnimationSources
        {
            class Spider_Open_Source
            {
                source="user";
                animPeriod=3;
                initPhase=0;
                sound="";
                soundPosition="";
            };
        };

    };

    class MAR_Spider_Webs:House_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Spiders";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Spiders\SpiderWebs.p3d";
        displayName = "Spider webs";
        
    };
    
    class MAR_Spider_Webs_2:House_F
    {
        scope = 2;			
		scopeCurator = 2;
        armor = 1;
        editorSubcategory = "MAR_Bugs_Spiders";
        editorCategory = "MAR_Bugs";
        model = "\Bugs_life\Spiders\SpiderWebs_1.p3d";
        displayName = "Spider webs tall";
      
    };
