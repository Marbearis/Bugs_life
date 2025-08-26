







[ 
    "MAR_BL_BUGEXPLODECHANCE", 
    "SLIDER", 
    ["bug explode chance"],
    ["Marbearis' Bugs & critters","General Settings"],
    [0, 100, 5, 0],
    1,
    {   
        params ["_value"];  
        
		MAR_BL_BUGEXPLODECHANCE = _value;
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_BUGPRT_DSPAWN", 
    "SLIDER", 
    ["Bug part despawn timer"],
    ["Marbearis' Bugs & critters","General Settings"],
    [0, 100, 15, 0],
    1,
    {   
        params ["_value"];  
        
		MAR_BL_BUGPRT_DSPAWN = _value;
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_CANBUGSEXPLODE", 
    "CHECKBOX", 
    ["can bugs explode"],
    ["Marbearis' Bugs & critters","General Settings"],
    true,
    1,
    {   
        params ["_value"];  
		MAR_BL_CANBUGSEXPLODE = _value;
		
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_CANSPAWNGIBLETS", 
    "CHECKBOX", 
    ["spawn bug parts on explode?"],
    ["Marbearis' Bugs & critters","General Settings"],
    true,
    1,
    {   
        params ["_value"];  
		MAR_BL_CANSPAWNGIBLETS = _value;
		
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_CANEGGSSPAWNUNITS", 
    "CHECKBOX", 
    ["can eggs spawn units"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    true,
    1,
    {   
        params ["_value"];  
		MAR_BL_CANEGGSSPAWNUNITS = _value;
		
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_ANTWORKERHLTTH", 
    "EDITBOX", 
    ["Worker Health"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    "100",
    1,
    {   
        params ["_value"];  
        _number = parseNumber _value;
		MAR_BL_ANTWORKERHLTTH = _number;
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_ANTSPITTERHLTTH", 
    "EDITBOX", 
    ["Spitter Health"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    "75",
    1,
    {   
        params ["_value"];  
        _number = parseNumber _value;
		MAR_BL_ANTSPITTERHLTTH = _number;
    }
] call CBA_fnc_addSetting;

[ 
    "MAR_BL_ANTICEHLTTH", 
    "EDITBOX", 
    ["Ice ant Health"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    "60",
    1,
    {   
        params ["_value"];  
        _number = parseNumber _value;
		MAR_BL_ANTICEHLTTH = _number;
    }
] call CBA_fnc_addSetting;




Bugzlife_SpawnAntHill = {

    params ["_position",["_dropside",[east]],["_linger", false],"_AntHillHP","_spawnAmount","_antType"];

    _position= (ASLtoATL _position);
                    
    [_position, _dropside, _linger,_AntHillHP,_spawnAmount,_antType] spawn {
        params ["_position", "_dropside", "_linger","_AntHillHP","_spawnAmount","_antType"];
        
        _positionATL=_position;
        [_position,{ 

            if (isDedicated) exitWith {}; 

                _dustEffect = "#particlesource" createVehicleLocal _this; 
                _dustEffect setParticleClass "HDustVTOL1"; 

                _rocks1 = "#particlesource" createVehicleLocal _this; 
                _rocks1 setposasl _this; 
                _rocks1 setParticleParams[["\A3\data_f\ParticleEffects\Universal\Mud.p3d", 1, 0, 1], "", "SpaceObject", 1, 12.5, [0, 0, 0], [0, 0, 5], 5, 100, 7.9, 1, [.15, .15], [ 
                    [0.1, 0.1, 0.1, 1], 
                    [0.25, 0.25, 0.25, 0.5], 
                    [0.5, 0.5, 0.5, 0] 
                ], [0.08], 1, 0, "", "", _this, 0, false, 0.3]; 
                _rocks1 setParticleRandom[0, [0, 0, 0], [2, 2, 0.2], 1, 0.25, [0, 0, 0, 0.1], 0, 0]; 
                _rocks1 setDropInterval 0.01; 
                _rocks1 setParticleCircle[0, [0, 0, 0]]; 

                _dust = "#particlesource" createVehicleLocal _this;       
                _dust setParticleClass "DeminingExplosiveDirt";

                _dust2 = "#particlesource" createVehicleLocal _this;        
                _dust2 setParticleClass "DeminingExplosiveCircleDust";  

                

                uisleep 0.4;  
                deleteVehicle _rocks1; 
               
                deleteVehicle _dustEffect; 
                
                deleteVehicle _dust;  
              
                deleteVehicle _dust2;     

        }] remoteExec["spawn", 0, false];


        _craterpos = _positionATL;
        _craterpos set [2, 0.3];
        _DroidPodCrater = createvehicle ["MAR_antHill", _craterpos, [], 0, "CAN_COLLIDE"]; 
		_groundTexture = surfaceTexture getPosATL _DroidPodCrater;
		_DroidPodCrater setObjectTextureGlobal [0,_groundTexture];
		_soundArray = ["A3\sounds_f\sfx\explosion1.wss","A3\sounds_f\sfx\explosion2.wss","A3\sounds_f\sfx\explosion3.wss"];
		_soundArray_wonk = ["\Bugs_life\data\AntSounds\ANT_Erupt_1.ogg","\Bugs_life\data\AntSounds\ANT_Erupt_2.ogg","\Bugs_life\data\AntSounds\ANT_Erupt_3.ogg"];	
		playSound3D [selectRandom _soundArray, _DroidPodCrater];
		playSound3D [selectRandom _soundArray_wonk, _DroidPodCrater];
		
        _projectile = _DroidPodCrater;

        {
            [_x, [[_projectile], true]] remoteExec ["addcuratorEditableObjects", 0];
        } forEach allCurators;


        _projectile setVectorUp surfaceNormal position _projectile;
        _DroidPodCrater setVectorUp surfaceNormal position _DroidPodCrater;
		_DroidPodCrater animateSource ['Anthill_Raised',0,5];
        
    
        _projectile setVariable ['CraterOBJ', _DroidPodCrater, true];

        _position = _CraterPos;

       
		switch (_antType) do {
			case 0:{Antlist =  ["MAR_ANT_Basic","MAR_ANT_Ice","MAR_ANT_Spitter"];};
			case 1:{Antlist =  ["MAR_ANT_Basic"];};
			case 2:{Antlist =  ["MAR_ANT_Spitter"];};
			case 3:{Antlist =  ["MAR_ANT_Ice"];};
			default {Antlist =  ["MAR_ANT_Basic","MAR_ANT_Ice","MAR_ANT_Spitter"];};
		};
        private _list = AntList;
        systemChat str _antType;
       
        
        [_position, _dropside#0, _list, _DroidPodCrater, _projectile,_spawnAmount,_linger] spawn {
            params ["_spawn", "_side", "_list", "_DroidPodCrater", "_projectile","_spawnAmount","_linger"];
			_FloodGroup = createGroup _side;
            sleep 0.5;
			
			[_FloodGroup, getPos _DroidPodCrater, 100] call BIS_fnc_taskPatrol;
            _spawn = (_DroidPodCrater modelToWorldVisual (_DroidPodCrater selectionPosition ["Body","Memory"]));
			
			for "_i" from 1 to _spawnAmount do {
				if ((count units _FloodGroup)>= _spawnAmount) exitWith {};
				if (!(alive _DroidPodCrater)||(isNil "_DroidPodCrater")) exitWith {};
				_unit = _FloodGroup createUnit [(selectRandom _list), _spawn, [], 0, "CAN_COLLIDE"];
				_unit attachTo [_DroidPodCrater,[0,0,0],"Body"];
				_unit setPosATL [_spawn#0,_spawn#1,(_spawn#2)+3];
				
				[_unit] joinSilent _FloodGroup;
				_unit setDir (random 360);

				[_unit,["ANT_Climb_Out", 0, 0.2, false]] remoteExec ["switchMove",0];
				sleep 2;
				detach _unit;
				_unit setVelocityModelSpace [0,7,3];
				sleep 3;
			};

			if (_linger) then {
				sleep 1;
				_projectile allowdamage true;
				while {alive _projectile} do {

					_time = time;

					waitUntil {
						(time - _time) > (random [15,30,60]) or !(alive _projectile)
					};
					if (alive _projectile) then {
						for "_i" from 1 to _spawnAmount do {
							if ((count units _FloodGroup)>= _spawnAmount) exitWith {};
							if (!(alive _DroidPodCrater)||(isNil "_DroidPodCrater")) exitWith {};
							_unit = _FloodGroup createUnit [(selectRandom _list), _spawn, [], 0, "CAN_COLLIDE"];
							_unit setPosATL [_spawn#0,_spawn#1,(_spawn#2)+5];

							_unit setDir (random 360);
							
							[_unit,["ANT_Climb_Out", 0, 0.2, false]] remoteExec ["switchMove",0];
							sleep 2;
							_unit setVelocityModelSpace [0,7,7];

							sleep 3;
						};
					};
				};
       		};
            _FloodGroup deleteGroupWhenEmpty true;
        };


        [[_projectile,_AntHillHP],{ 

			params ["_projectile","_AntHillHP"];

			_projectile allowDamage false;
			_projectile setVariable ["gooberHealth",_AntHillHP,true];
			_projectile removeAllEventHandlers "HitPart";
			_projectile addEventHandler ["HitPart", {
			
			(_this select 0) params ["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"]; 

			if ( ((str (side _shooter) == "CIV") and (((currentWeapon _shooter) == ""))) or (captive _shooter)) exitWith {};
			if ( ( !([(side _shooter), (side _target)] call BIS_fnc_sideIsEnemy) and (str (side _target) != "CIV")) or (captive _target)) exitWith {};
			systemChat (_selection#0);
			if ((_selection#0) != "anthole") exitWith {systemChat "bingo"};
			private _currentHealth = _target getVariable ["gooberHealth", _AntHillHP]; 

			private _ProjHit = _ammo#0;
			systemChat str (_ammo#4);
			if (_ammo#4 isKindOf "GrenadeHand") then {systemChat str _ammo#4};
			private _newHealth = [_currentHealth - _ProjHit, 0, 500] call BIS_fnc_clamp;

			_target setVariable ["gooberHealth", _newHealth, true];

			if (_currentHealth == 0) then {
				[_target, [1, false, _shooter]] remoteExec ["setDamage",_target];_target setDamage 1;

				_target animateSource ['Anthill_Raised',1,1];

				[_target,{ 

						

						uisleep 4;  
					  
						deleteVehicle _this;
				}] remoteExec["spawn", 0, false];
			};

			}];

        }] remoteExec ['spawn', ([0, -2] select isDedicated)];

        

    };
};

Bugzlife_TrapDoor = {
    params ["_position","_side","_canDie"];
	_position= (ASLtoATL _position);
	
	_trapDoor = createvehicle ["MAR_TrapDoor", [_position#0,_position#1,((_position#2)-0.3)], [], 0, "CAN_COLLIDE"];
	_groundTexture = surfaceTexture getPosATL _trapDoor;
	_trapDoor setObjectTextureGlobal [0,_groundTexture];
	_trapDoor setVectorUp surfaceNormal position _trapDoor;
	_group = createGroup _side;
	
	_spawn = (_trapDoor modelToWorldVisual (_trapDoor selectionPosition ["spider","Memory"]));
	_unit = _group createUnit ["MAR_Spider_Burrower", _spawn, [], 0, "CAN_COLLIDE"];
	[_unit] joinSilent _group;
	_unit setVariable ["IMS_IsUnitInvicibleScripted",true,true];
	[_unit,["Spider_Burrowed_Idle", 0, 0.2, false]] remoteExec ["switchMove",0];
	_unit setVariable ["trapDoorCanDie",_canDie,true];
	_unit hideObjectGlobal true;
	_unit hideObject true;
	_group deleteGroupWhenEmpty true;
	_unit setVariable ["trapDoor",_trapDoor,true];	
};

Bugslife_TrapDoorAttack = {

	params ["_spider","_poorChuddie"];
	if !(isNil {_spider getVariable "s_Food"}) exitWith {};
	_home = (_spider getVariable "trapDoor");
	_dir = [_spider,_poorChuddie]call BIS_fnc_dirTo;
	_spider setDir _dir;
	_home setDir ((getDir _spider));
	[_home,((getDir _spider))] remoteExec ["setDir",_home];
	_soundArray = ["A3\sounds_f\sfx\explosion1.wss","A3\sounds_f\sfx\explosion2.wss","A3\sounds_f\sfx\explosion3.wss"];
	playSound3D [selectRandom _soundArray, _home];

	_home animateSource ["Spider_Open_Source",1,10];
	_spider hideObjectGlobal false;
	_spider hideObject false;
	_home spawn {sleep 0.5; _this animatesource ["Spider_Open_Source",0,20];};
	[_spider,["Spider_Burrowed_Attack", 0, 0.2, false]] remoteExec ["switchMove",0];
	[(getPosASL _home),{ 
			
            if (isDedicated) exitWith {}; 

                _dustEffect = "#particlesource" createVehicleLocal _this; 
                _dustEffect setParticleClass "HDustVTOL1"; 

                _rocks1 = "#particlesource" createVehicleLocal _this; 
                _rocks1 setposasl _this; 
                _rocks1 setParticleParams[["\A3\data_f\ParticleEffects\Universal\Mud.p3d", 1, 0, 1], "", "SpaceObject", 1, 12.5, [0, 0, 0], [0, 0, 5], 5, 100, 7.9, 1, [.15, .15], [ 
                    [0.1, 0.1, 0.1, 1], 
                    [0.25, 0.25, 0.25, 0.5], 
                    [0.5, 0.5, 0.5, 0] 
                ], [0.08], 1, 0, "", "", _this, 0, false, 0.3]; 
                _rocks1 setParticleRandom[0, [0, 0, 0], [2, 2, 0.2], 1, 0.25, [0, 0, 0, 0.1], 0, 0]; 
                _rocks1 setDropInterval 0.01; 
                _rocks1 setParticleCircle[0, [0, 0, 0]]; 

                _dust = "#particlesource" createVehicleLocal _this;       
                _dust setParticleClass "DeminingExplosiveDirt";

                _dust2 = "#particlesource" createVehicleLocal _this;        
                _dust2 setParticleClass "DeminingExplosiveCircleDust";  

                

                uisleep 0.4;  
                deleteVehicle _rocks1; 
               
                deleteVehicle _dustEffect; 
                
                deleteVehicle _dust;  
              
                deleteVehicle _dust2;     

    }] remoteExec["spawn", 0, false];

	uiSleep 0.1;
	//grab grenade
	if (!(_poorChuddie isKindOf "MAN")&&(_poorChuddie isKindOf "GrenadeHand"))then {
		if (isNil {_spider getVariable "s_Food"}) then {
								
			_dir = getDir _spider;
			_spider setDir (_dir);
			_poorChuddie attachTo [_home,[0,0,0],"true"];
			_spider setVariable ["s_Food",_poorChuddie,true];
			
			sleep 0.8;
			_poorChuddie setPosATL getPosATL _spider;
			[_poorChuddie, [1, false, _spider]] remoteExec ["setDamage",2];
			_poorChuddie hideObjectGlobal true;
			_poorChuddie hideObject true;
			if (_poorChuddie isKindof "SmokeShell")then {
				_poorChuddie spawn {
					uiSleep 4;
					deleteVehicle _this;
				};				
			};
			_spider hideObjectGlobal true;
			_spider hideObject true;
			_spider spawn {sleep 8; _this setVariable ["s_Food",nil,true];};

			if ((_spider getVariable ["trapDoorCanDie",true])&& !(_poorChuddie isKindOf "SmokeShell")) then {
				waitUntil {isNull _poorChuddie};
				_home animateSource ["Spider_Open_Source",1,15];
				[_spider, [1, false, _poorChuddie]] remoteExec ["setDamage",2]; 
				
			};																		
		};
	};
	//grab chuddie
	{	
			
		if (
			(_x != _spider) and  						
			(alive _x) and 
			!(animationState _x == "IMS_ButtStock_Evade_F") and 
			!(animationState _x == "IMS_ButtStock_Evade_R") and 
			!(animationState _x == "IMS_ButtStock_Evade_L") and 
			!(animationState _x == "IMS_ButtStock_Evade_B") and 
			!(animationState _x == "starWars_landRoll_b") and 
			!(animationState _x == "starWars_landRoll") and 
			!(animationState _x == "STAR_WARS_FIGHT_DODGE_RIGHT") and 
			!(animationState _x == "STAR_WARS_FIGHT_DODGE_LEFT") and 
			(isNil {_x getVariable "IMS_IsUnitInvicibleScripted"})
			) 
		then {
				if (isNil {_spider getVariable "s_Food"}) then {					
					_dir = getDir _spider;
					_x setDir (_dir);
					_soundArray_wonk = ["\Bugs_life\data\humanSounds\human_scream_1.ogg","\Bugs_life\data\humanSounds\human_scream_2.ogg","\Bugs_life\data\humanSounds\human_scream_3.ogg"];
					playSound3D [selectRandom _soundArray_wonk, _x];	
					[_x,_dir] remoteExec ["setDir",_x];
					[_x,["Armaman_getEaten", 0, 0.2, false]] remoteExec ["switchMove",0];
					_spider setVariable ["s_Food",_x,true];					
					sleep 0.8;
					[_x, [1, false, _spider]] remoteExec ["setDamage",2];
					_x hideObjectGlobal true;
					_x hideObject true;
					_spider hideObjectGlobal true;
					_spider hideObject true;
					_spider spawn {sleep 8; _this setVariable ["s_Food",nil,true];};																		
				};
			};
		
	}forEach nearestObjects [_spider modelToWorldVisual(_spider selectionPosition ["bitezone","Memory"]),["MAN"],6.3];
};

Bugzlife_BugDeathContainer = {
	params ["_bug","_killer"]; 
	switch true do  {
		case ((_bug isKindOf "MAR_ANT_Spitter")||(_bug isKindOf "MAR_ANT_Ice")):{
			
				_bug spawn BugzLife_fnc_explodeBug;
		
		};
		case ((_bug isKindOf "MAR_Spider_Burrower")):{
			
				_bug spawn BugzLife_fnc_explodeBug;
		
		};
		case ((_bug isKindOf "MAR_Ant_Egg")||(_bug isKindOf "MAR_Ant_Egg_Clutch")): {
				_bug spawn BugzLife_fnc_explodeBug;
				_bug call BugsLife_HandleMelee;

		};

		case (_bug isKindOf "MAR_ANT_BASE"): {
					

			if ((MAR_BL_BUGEXPLODECHANCE >= floor (random 100))||MAR_BL_BUGEXPLODECHANCE == 100) then {_bug spawn BugzLife_fnc_explodeBug;}else {
				_meleeSounds = [
					"\Bugs_life\data\AntSounds\antDeath.ogg"
				];
			
				playSound3D [selectRandom _meleeSounds, _bug];
				[_bug,[(selectRandom ["ANT_Death_3","ANT_Death_2"]), 0, 0.2, false]] remoteExec ["switchMove",0];
				uiSleep 1.1;
				[_bug,["ANT_Death", 0, 0.2, false]] remoteExec ["switchMove",0];
			};

		};
		default {};
	};
};
//	[[_this,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
BugzLife_fnc_explodeBug = {

	if (isDedicated) exitWith {};			
	if (!(MAR_BL_CANBUGSEXPLODE)and!((_this isKindOf "MAR_Ant_Egg")||(_this isKindOf "MAR_Ant_Egg_Clutch")||(_this isKindOf "MAR_ANT_Spitter")||(_this isKindOf "MAR_Spider_Burrower")||(_this isKindOf "MAR_ANT_Ice"))) exitWith {
		[_this,[(selectRandom ["ANT_Death_3","ANT_Death_2"]), 0, 0.2, false]] remoteExec ["switchMove",0];
		uiSleep 1.1;
		[_this,["ANT_Death", 0, 0.2, false]] remoteExec ["switchMove",0];
	};
	if (_this isKindOf "MAR_ANT_BASE") then {
		[_this,[(selectRandom ["ANT_Death_3","ANT_Death_2"]), 0, 0.2, false]] remoteExec ["switchMove",0];
	};
	

	
	if (_this isKindOf "MAR_Spider_Base") then {GlobalBugSoundPitch = 0.5}else {GlobalBugSoundPitch = 1};
	_meleeSounds = [
		"\Bugs_life\data\AntSounds\antDeath.ogg"
	];
	playSound3D [selectRandom _meleeSounds, _this,false,_this,5,GlobalBugSoundPitch];
	if !((_this isKindOf "MAR_Ant_Egg")||(_this isKindOf "MAR_Ant_Egg_Clutch")||(_this isKindOf "MAR_Spider_Burrower"))then {uiSleep 1.1;};
	

	_this hideObjectGlobal true;
	_this hideObject true;
	
	_textures = getObjectTextures _this;	
	_materials = getObjectMaterials _this;
	_boomSounds = [
		"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_01.wss",
		"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_02.wss", 
		"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_03.wss", 
		"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_04.wss"  
	];

	
	

	_meleeSounds = [
		"\Bugs_life\data\AntSounds\ant_explode.ogg",
		"\Bugs_life\data\AntSounds\ant_explode_1.ogg",
		"\Bugs_life\data\AntSounds\ant_explode_2.ogg"
	];

	playSound3D [selectRandom _meleeSounds, _this,false,_this,5,GlobalBugSoundPitch];
	private _lamd = createVehicle ["MAR_acidCrater",position _this, [], 0, "CAN_COLLIDE"];
	if (_this isKindOf "MAR_ANT_Ice") then {
		_IceSpike = createVehicle ["MAR_AntIce",position _this, [], 0, "CAN_COLLIDE"];
		[_IceSpike] spawn {sleep 120; deleteVehicle _this;};
	};
	_lamd setDir (random 360);
	_lamd setObjectScale (selectRandom [0.8,0.9,0.6,0.7,0.5]);
	
	_case = ((configFile >> "CfgVehicles" >> typeOf _this >> "impactEffectsBlood") call BIS_fnc_getCfgData);
	if (isNil "_case") then {_case = "MAR_ImpactEffectsBugGuts_Orange"};
	switch _case do {
			case ("MAR_ImpactEffectsBugGuts_Orange"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolOrange_CA.paa","\Bugs_life\data\bloodpools\bloodPoolOrange.rvmat",[1,0.5,0,0.12]]};
			case ("MAR_ImpactEffectsBugGuts_Green"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolGreen_CA.paa","\Bugs_life\data\bloodpools\bloodPoolGreen.rvmat",[0,1,0,0.12]]};
			case ("MAR_ImpactEffectsBugGuts_Blue"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolBlue_CA.paa","\Bugs_life\data\bloodpools\bloodPoolBlue.rvmat",[0,0.4,1,0.12]]};
			default {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolOrange_CA.paa","\Bugs_life\data\bloodpools\bloodPoolOrange.rvmat",[1,0.5,0,0.12]] };
	};

	[[_lamd,_this],{
		params ["_lamd","_unit","_IceSpike"];
			if (isDedicated) exitWith {};

			if ((player distance _lamd) <= 12) then {
				enableCamShake true; 
				addCamShake [1, 0.7, 1];
			};

			if (((_unit isKindOf "MAR_Ant_Egg")||(_unit isKindOf "MAR_Ant_Egg_Clutch")) and (MAR_BL_CANEGGSSPAWNUNITS)) then {
				_FloodGroup = createGroup east;
				_spawn = getPosATL _unit;
				deleteVehicle _unit;
				_list =  ["MAR_ANT_Basic"];
				if ((random 100) < 50) then {
					_bug = _FloodGroup createUnit [(selectRandom _list), _spawn, [], 0, "CAN_COLLIDE"];
				};
				_FloodGroup deleteGroupWhenEmpty true;
			};

			_fulgi  = "#particlesource" createVehiclelocal getposaTL _lamd; 
			_fulgi setParticleRandom [0, [1, 1, 0], [8, 8, 5], 3, 0.25, [0, 0, 0, 0.1], 0, 0];
			_fulgi setDropInterval 0.001;
			_fulgi setParticleCircle [0, [0, 0, 0]];
			_fulgi setParticleParams [["\A3\data_f\cl_exp", 1, 0, 1],"","Billboard",1,15,[0,0,0],[0,0,0],0,1.7,1,0,[0.15],[bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2],[1],0,0,"","",_lamd, 0, false, 0.4, [bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2]]; 
			_gravi1 = "#particlesource" createVehicleLocal getpos _lamd;  
			_gravi1 setParticleCircle [0.1, [1, 1, 0]];
			_gravi1 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract.p3d",1,0,1,0],"","Billboard",1,2,[0,0,0],[0,0,0.6],0,0.05,0.04,0.05,[1,2,5,8,12,17],[bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2],[1.5,0.5,0,0],0.4,0.09,"","","",0,false,0,[bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2]];
			_gravi1 setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0.25, [0.01, 0.01, 0.01, 0.1], 0, 0];
			_gravi1 setDropInterval 0.0004;
			_smoke2 = "#particlesource" createVehicleLocal getPos _lamd;
			_smoke2 setposasl getPosASL _lamd;
			_smoke2 setParticleCircle [0.5, [7,7,-4]];
			_smoke2 setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0.05, [0.01, 0.01, 0.01, 0.1], 0, 0];
			_smoke2 setParticleParams [["\A3\data_f\cl_fireD", 1, 0, 1], "", "Billboard", 1, 1, [0, 0, 0.6], [0.2,0.5,0.2], 90, 10, 7.85, 0.375, [1, 2, 3],[bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2], [10], 1, 0, "", "", _lamd];
			_smoke2 setDropInterval 0.0004;
			if ((_unit isKindOf "MAR_ANT_Spitter")||(_unit isKindOf "MAR_ANT_Ice")) then {
				_fog1 = "#particlesource" createVehicleLocal getposaTL _lamd; 
				_fog1 setParticleParams [   
					["\A3\data_f\cl_exp", 1, 0, 1], "", "Billboard", 3, 7,   
					[0, 0, 0], [0, 0, 0], 1, 1.27, 1, 0,   
					[0,0.5,0],[bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2 ], [1000], 1, 0, "", "", _lamd, 0, false, -1, [bloodpoolTexture#2, bloodpoolTexture#2, bloodpoolTexture#2]  
				];   
				_fog1 setParticleRandom [3, [1, 1, 0.3], [0, 0, -0.1], 2, 0.15, [0, 0, 0, 0.1], 0, 0];   
				_fog1 setParticleCircle [1, [0, 0, -0.12]];   
				_fog1 setDropInterval 1;
				if (_unit isKindOf "MAR_ANT_Spitter") then {
					_fog1 setParticleFire [2,2,0.1];
				};   
				if (_unit isKindOf "MAR_ANT_Ice")then{_unit call BugsLife_HandleMelee;};
				_fog1 spawn {uiSleep 32; deleteVehicle _this};
			};
			uisleep 0.1;
			deleteVehicle _smoke2;
			uisleep 0.1;
			{
				deleteVehicle _x;
			} forEach [_gravi1,_fulgi];
			uisleep 0.2;
		}] remoteExec ["spawn",0];

	_lamd setObjectTextureGlobal [0,bloodpoolTexture#0];
	_lamd setObjectMaterialGlobal [0,bloodpoolTexture#1];
	[_lamd] spawn {sleep 120; deleteVehicle _this;};


	if (isDedicated) exitWith {};

	if ((_this isKindOf "MAR_Ant_Egg")||(_this isKindOf "MAR_Ant_Egg_Clutch")||!(MAR_BL_CANSPAWNGIBLETS)) exitWith {};
	switch true do {
		case (_this isKindOf "MAR_ANT_BASE"):{
			_Part_1 = "MAR_Ant_Part_Thorax" createVehicle (_this modelToWorldVisual [0,0,0]);
			{
				_Part_1 setObjectTextureGlobal [_x,_textures#0];
				_Part_1 setObjectMaterialGlobal [_x,_materials#0];
			}forEach (_Part_1 selectionNames 1);
			_Part_1 setPosATL (_this modelToWorldVisual [0,0,0]);
			_Part_1 setDir 180;
			_Part_1 setVelocityModelSpace [0,-6,4];
			_Part_2 = "MAR_Ant_Part_Head" createVehicle (_this modelToWorldVisual [0,0.5,0]);
			{
				_Part_2 setObjectTextureGlobal [_x,_textures#0];
				_Part_2 setObjectMaterialGlobal [_x,_materials#0];
			}forEach (_Part_2 selectionNames 1);
			_Part_2 setPosATL (_this modelToWorldVisual [0,0.5,0]);
			_Part_2 setDir 180;
			_Part_2 setVelocityModelSpace [0,-6,4];
			_PArt_3 = "MAR_Ant_Part_Abdomen" createVehicle (_this modelToWorldVisual [0,-0.5,0]);
			{
				_Part_3 setObjectTextureGlobal [_x,_textures#0];
				_Part_3 setObjectMaterialGlobal [_x,_materials#0];
			}forEach (_Part_3 selectionNames 1);
			_PArt_3 setPosATL (_this modelToWorldVisual [0,-0.5,0]);
			_PArt_3 setDir 180;
			_PArt_3 setVelocityModelSpace [0,6,4];
			
			for "_i" from 1 to 6 do {
				legSide = 0.2;
				legVelocity = 7;
				if (_i > 3) then {legSide = -0.2; legVelocity = -7;}; 
				_Part_4 = "MAR_Ant_Part_Leg" createVehicle (_this modelToWorldVisual [1,selectRandom [-0.5,0.5,0,0.3,-0.3],0.05]);
				{
					_Part_4 setObjectTextureGlobal [_x,_textures#0];
					_Part_4 setObjectMaterialGlobal [_x,_materials#0];
				}forEach (_Part_4 selectionNames 1);
				_Part_4 setPosATL (_this modelToWorldVisual [0,selectRandom [legSide,1,0.5],0.05]);
				
				_Part_4 setVelocityModelSpace [selectRandom [legVelocity,legVelocity],0,6];
				_Part_4 spawn {sleep MAR_BL_BUGPRT_DSPAWN; [_this,true,1] call BIS_fnc_VREffectKilled;};
			};
			
			
			_Part_5 = "MAR_Ant_Part_Mandible" createVehicle (_this modelToWorldVisual [-1,-0.1,0.05]);
			{
				_Part_5 setObjectTextureGlobal [_x,_textures#0];
				_Part_5 setObjectMaterialGlobal [_x,_materials#0];
			}forEach (_Part_5 selectionNames 1);
			_Part_5 setPosATL (_this modelToWorldVisual [-1,0,0.05]);
			_Part_5 setDir ((getDir _this) - 180);
			_Part_5 setVelocityModelSpace [7,0,0];
			_Part_6 = "MAR_Ant_Part_Mandible" createVehicle (_this modelToWorldVisual [-1,-0.1,0.05]);
			{
				_Part_6 setObjectTextureGlobal [_x,_textures#0];
				_Part_6 setObjectMaterialGlobal [_x,_materials#0];
			}forEach (_Part_6 selectionNames 1);
			_Part_6 setPosATL (_this modelToWorldVisual [1,0,0.05]);
			_Part_6 setDir ((getDir _this) - 180);
			_Part_6 setVelocityModelSpace [-7,0,0];
			deleteVehicle _this;
			{
				_x spawn {sleep MAR_BL_BUGPRT_DSPAWN; [_this,true,1] call BIS_fnc_VREffectKilled;};
			}forEach [_Part_1,_Part_2,_Part_3,_Part_5,_Part_6];
		};

		default {};
	};
	
};

MAR_Bugslife_FindTarget = {
	_targets = _this targets [true, 500];
	if (count _targets == 0) exitWith {
		objNull
	};
	_tarArr = _this findNearestEnemy _this;
	{
		_ins = [_x, "FIRE", _this] checkVisibility [eyePos _this, eyePos _x];
		if (_ins >= 0.4) exitWith {
			_tarArr = _x;
		};
	} forEach _targets;
	_tarArr
};

Bugslife_ANTMelee = {
	params ["_zombie","_en"];
	
	if (_zombie getVariable ["CanMelee",true]) then {
		_zombie setVariable ["CanMelee",false];
		_zombie spawn {uiSleep 1; _this setVariable ["CanMelee",true];};
		if (animationState _zombie in ["ant_attack_1"])exitWith {};
	
		[_zombie,["ANT_Attack_1", 0, 0.2, false]] remoteExec ["switchMove",0];
			
		_meleeSounds = [
			"\Bugs_life\data\AntSounds\antBite.ogg"
		];
		

		
		playSound3D [selectRandom _meleeSounds, _zombie];
		uiSleep 0.1;
		if !(animationState _zombie in ["ant_attack_1"])exitWith {};
		
		
		uisleep 0.2;
		
		if !(animationState _zombie in ["ant_attack_1"])exitWith {};
		if (_zombie isKindOf "MAR_ANT_Ice") exitWith {
			[_zombie, [1, false, _zombie]] remoteExec ["setDamage",2];
		};
		_zombie call BugsLife_HandleMelee;
	};
};

ANTZ_MoveAi = {
	_unit = _this select 0;
	if !(isNil {_unit getVariable "WBK_IsOnTheMove"}) exitWith {};
	_anim = _this select 1;
	_pos = _this select 2;
	_unit playMoveNow _anim;
	_unit setVariable ["WBK_IsOnTheMove",1];
	uisleep 0.8;
	_unit setVariable ["WBK_IsOnTheMove",nil];
	_group = group _unit;
	units _group doFollow leader _group;
};

BugsLife_AntEgginit = {
	params ["_egg"];
	if (isDedicated) exitWith {};
	_egg allowDamage false;
	_egg addEventHandler ["HitPart", {
			
			(_this select 0) params ["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"]; 
	
			if ( ((str (side _shooter) == "CIV") and (((currentWeapon _shooter) == ""))) or (captive _shooter)) exitWith {};
			if ( ( !([(side _shooter), (side _target)] call BIS_fnc_sideIsEnemy) and (str (side _target) != "CIV")) or (captive _target)) exitWith {};
																								 
			private _currentHealth = _target getVariable ["gooberHealth", if ((_target isKindOf "MAR_Ant_Egg_Clutch")) then {200}else{50}]; 

			private _ProjHit = _ammo#0;
			private _newHealth = [_currentHealth - _ProjHit, 0, 500] call BIS_fnc_clamp;

			_target setVariable ["gooberHealth", _newHealth, true];

			if (_currentHealth == 0) then {_target allowDamage true; [_target, [1, false, _shooter]] remoteExec ["setDamage",2];};

	}];
	
	if (_egg isKindOf "MAR_Ant_Egg_Clutch") then {
		_egg setVectorUp surfaceNormal position _egg;
		_webs ="MAR_Ant_Webs" createvehicle getPosATL _egg;
		_webs attachTo [_egg,[0,0,-0.5]];
		
		_webs setVectorUp surfaceNormal position _webs;
	};
	
	_egg addEventHandler ["Killed", {
		(_this select 0) spawn {
			uisleep 0.1;
			_this remoteExec ["Bugzlife_BugDeathContainer",_this];

			{
				deleteVehicle _x;
			}forEach attachedObjects _this;			
		};
	}];

	_egg addEventHandler ["Deleted", {
		params ["_eggs"];
		{
			deleteVehicle _x;
		}forEach attachedObjects _egg;	

	}];

};

BugsLife_HandleMelee = 
{
	params ["_zombie"];
	MBradius = 1.4;
	if (_zombie isKindOf "MAR_ANT_Ice") then {
		MBradius = 8;							
	};
	{	
		
		_meleeSounds = [
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_01.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_02.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_03.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_04.ogg"
			];

		if ((side _x == side _zombie)) exitWith {};
									

		playSound3D [selectRandom _meleeSounds, _x];
		

		
		
		if (
			(_x != _zombie) and  	
			(side _x != side _zombie) and 					
			(alive _x) and 
			(animationState _x != "IMS_ButtStock_Evade_F") and 
			(animationState _x != "IMS_ButtStock_Evade_R") and 
			(animationState _x != "IMS_ButtStock_Evade_L") and 
			(animationState _x != "IMS_ButtStock_Evade_B") and 
			(animationState _x != "starWars_landRoll_b") and 
			(animationState _x != "starWars_landRoll") and 
			(animationState _x != "STAR_WARS_FIGHT_DODGE_RIGHT") and 
			(animationState _x != "STAR_WARS_FIGHT_DODGE_LEFT") and 
			(isNil {_x getVariable "IMS_IsUnitInvicibleScripted"})
			) 
		then {

			if (((_x != _zombie) and (alive _x)) and (_x isKindOf "MAR_ANT_BASE")) exitWith {
									
				private _chimp = _x getVariable ["WBK_SynthHP",1];
				private _newHealth = _chimp - 25 ;
				_x setVariable ["WBK_SynthHP", _newHealth,true];

				if (_newHealth <= 0) exitWith {
					[_x, [1, false, _zombie]] remoteExec ["setDamage",2];			
				};			
				if (((_x worldToModel (_zombie modelToWorld [0, 0, 0])) select 1) < 0) then {
					[_x,["ANT_Hit_B", 0, 0.7, false]] remoteExec ["switchMove",0];
				}else 						
				{
					[_x,["ANT_Hit_F", 0, 0.7, false]] remoteExec ["switchMove",0];
				};															
			};
				[_x,_zombie] spawn {
					params ["_victim","_zombie"];
					if (_zombie isKindOf "MAR_ANT_Ice") then {
						
						_victim enableSimulation false;
						uiSleep 5;
						if (_victim != player) exitWith {[_victim, [1, false, _zombie]] remoteExec ["setDamage",2];};
						_victim enableSimulation true;
												
					};
									
				};
				
				switch true do {
					case (!(isNil "ace_medical_fnc_addDamageToUnit")):{ 
						[[_x,_zombie],{
							params ["_target","_zombie"];
							
							if (!(isNil {_target getVariable "optre_suit_energy"})) then {
								if ((_target getVariable ["optre_suit_energy",0]) <= 0) exitWith {
									[_target, 0.5, "body", "stab"] remoteExec ["ace_medical_fnc_addDamageToUnit", _target];
								};
								_shieldEnergy = _target getVariable ["optre_suit_energy",0];
								_newShieldEnergy = _shieldEnergy - 25;
								_target setVariable ["optre_suit_energy", _newShieldEnergy, true];
							}else {
								[_target, 0.5, "body", "stab"] remoteExec ["ace_medical_fnc_addDamageToUnit", _target];
							};
						}]remoteExec ["spawn",_x];
						
					};

					case ((local _x) && {!(isDamageAllowed _x)}):{
						switch true do {
							

							case (WBK_Armor_System_OnlyHP):{
								_currentHealth = _x getVariable "WBK_AS_HP";
								_newDamage = _currentHealth -0.20;
								_x setVariable ["WBK_AS_HP",_newDamage,true];
							}; 

							case !(WBK_Armor_System_OnlyHP):{
									_currentArmor = _x getVariable "WBK_AdvancedHealth";
									if (_currentArmor <= 0) then {
										_currentHealth = _x getVariable "WBK_AS_HP";
										_newDamage = _currentHealth -0.20;
										_x setVariable ["WBK_AS_HP",_newDamage,true];
									 }else {
									_newDamage = _currentArmor - (15*WBK_Armor_System_DMG_Modifier);
									_x setVariable ["WBK_AdvancedHealth",_newDamage,true];
								};
							}; 
						};
					};			
					
					default {
						if (!(isNil {_x getVariable "optre_suit_energy"})) then {
								[[_x,_zombie],{
									params ["_target","_zombie"];
									
										if ((_target getVariable ["optre_suit_energy",0]) <= 0) exitWith {
											private _poop = damage _target;						
											[_target, [(0.20 + _poop), false, _zombie]] remoteExec ["setDamage",_poop]; 
										};
										_shieldEnergy = _target getVariable ["optre_suit_energy",0];
										_newShieldEnergy = _shieldEnergy - 25;
										_target setVariable ["optre_suit_energy", _newShieldEnergy, true];
								
										
									
								}]remoteExec ["spawn",_x];
							}else{		
									private _poop = damage _x;						
									[_x, [(0.20 + _poop), false, _zombie]] remoteExec ["setDamage",_poop];
						}; 
					};
												
					
				};																								

			};
		
	} forEach nearestObjects [_zombie modelToWorldVisual(_zombie selectionPosition ["a_spitPoint","Memory"]),["MAN"],MBradius];
};

BugsLife_RangedAttack_FNC= {

	params ["_mantis","_en"];
	_mantis setVariable ["IsCanFire",1]; 
	_mantis spawn {uisleep selectRandom [1,2,3,4]; _this setVariable ["IsCanFire",nil];};	
	[_mantis,["ANT_Attack_Ranged", 0, 0.2, false]] remoteExec ["switchMove",0];
	_meleeSounds = [
		"\Bugs_life\data\AntSounds\antSpit.ogg"
	];
	playSound3D [(selectRandom _meleeSounds), _mantis];
	if !(animationState _mantis in ["ant_attack_ranged"]) exitWith {};

	uiSleep 0.3;
	if !(animationState _mantis in ["ant_attack_ranged"]) exitWith {};
	if (((_mantis worldToModel (_en modelToWorld [0, 0, 0])) select 0) < 7) exitWith {					
		switch true do {
	
			case (_mantis isKindOf "MAR_ANT_Spitter"): {
				
				_mantis setVariable ["WBK_OPTRE_AfterContact",1];
																							
				uiSleep 0.3;				
				[_mantis,_mantis modelToWorldVisual [0,5,1],"B_BugsLife_Acid_Spit", _en, selectRandom [[(aimPos _en select 0) - 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) - 2,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 2,aimPos _en select 1,aimPos _en select 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 1]], (selectRandom [40,50,55]), false, [0,0,0]] spawn Bugzz_fnc_ProjectileCreate;						
			};

			case (_mantis isKindOf "MAR_ANT_Ice"): {
				
				_mantis spawn {uisleep selectRandom [1,2,3,4]; _this setVariable ["IsCanFire",nil];};
				[_mantis,_mantis modelToWorldVisual [0,1.2,1],"G_40mm_HE", _en, selectRandom [[(aimPos _en select 0) - 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) - 2,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 2,aimPos _en select 1,aimPos _en select 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 1]], (selectRandom [120,150,160]), false, [0,0,0]] spawn Bugzz_fnc_ProjectileCreate;						
			};
		
			
			default {
							
			};
		};
	};
};

Bugzz_fnc_ProjectileCreate = {
	params   
	[   
		["_shooter", objNull, [objNull]],   
		["_startPos", [0.0 , 0.0, 0.0], [[]]],   
		["_class", "M_Titan_AT", ["", objNull]],   
		["_target", objNull, [objNull]],   
		["_tgtPos", [0.0 , 0.0, 0.0], [[]]],   
		["_speed", 100.0, [0.0]],   
		["_destroyTarget", true, [true]],   
		["_localOffset", [0.0, 0.0, 0.0], [[]]],   
		["_minDistanceToTarget", 8.0, [0.0]],   
		["_function", "", [""]],   
		["_isGlobalFunction", false, [true]]   
	];
	   
	if ((isNil "_shooter") ||(!alive _shooter)) exitWith {};
	if (count _startPos != 3 || {{typeName _x != typeName 0} count _startPos > 0}) exitWith {"fn_guidedProjectile invalid position, not a 3D vector" call BIS_fnc_error};   
	if (_startPos isEqualTo [0,0,0]) exitWith {"fn_guidedProjectile invalid position, at 0,0,0" call BIS_fnc_error};   
	if (typeName _class == typeName "" && {_class == ""}) exitWith {"fn_guidedProjectile invalid class provided" call BIS_fnc_error};   
	if (typeName _class == typeName objNull && {isNull _class}) exitWith {"fn_guidedProjectile invalid object provided" call BIS_fnc_error};   
	if (isNull _target) exitWith {"fn_guidedProjectile invalid target provided" call BIS_fnc_error};   
	private _rocket = createVehicle [_class,_startPos, [], 0, "NONE"];
	_rocket setDir (getDir _shooter);
	_rocket setShotParents [vehicle _shooter, _shooter];  
	private _currentPos = getPosASLVisual _rocket;   
	private _targetPos = _tgtPos;   
	if (_rocket isKindOf "B_BugsLife_Acid_Spit") then {
		[_rocket, {
			if (isDedicated) exitWith {};
			_fulgi  = "#particlesource" createVehiclelocal getposaTL _this; 
			_fulgi setParticleRandom [0, [1, 1, 0], [0, 0, 3], 3, 0.25, [0, 0, 0, 0.1], 0, 0];
			_fulgi setDropInterval 0.05;
			_fulgi setParticleCircle [0, [0, 0, 0]];
			_fulgi setParticleParams [["\A3\data_f\cl_exp", 1, 0, 1],"","Billboard",1,15,[0,0,0],[0,0,0],0,1.7,1,0,[0.05, 0.20],[[0.01,1,0.1,1]],[1],0,0,"","",_this, 0, false, -1, [[0.01,100,0.005,1],[0.01,100,0.005,1],[0.01,100,0.005,1]]]; 
			_fulgi attachTo [_this,[0,0,0]];
			_fog1 = "#particlesource" createVehicleLocal getposaTL _this;
			_fog1 setParticleParams [ 
				["\A3\data_f\cl_exp", 1, 0, 1], "", "Billboard", 1, 1, 
				[0, 0, 0], [0, 0, 0], 1, 1.25, 1, 0, 
				[0.3,0.6],[[0.01,1,0.1,1]], [1000], 1, 0, "", "", _this, 0, false, -1, [[0.01,100,0.005,1],[0.01,100,0.005,1],[0.01,100,0.005,1]]
			]; 
			_fog1 setParticleRandom [3, [0.1, 0.1, 0.1], [0, 0, -0.1], 2, 0.15, [0, 0, 0, 0.1], 0, 0]; 
			_fog1 setParticleCircle [0.1, [0, 0, -0.12]]; 
			_fog1 setDropInterval 0.005; 
			_fog1 attachTo [_this,[0,0,0]];	
			_fog1 setParticleFire [2,1,0.1];
			
			waitUntil {sleep 0.1; !(alive _this)};
			deleteVehicle _fulgi;
			
			deleteVehicle _fog1;
		}] remoteExec ["spawn", 0];

		_rocket spawn {
			_grenade = _this;
			_actualHitClass = "#particlesource" createVehicle position _grenade; 
			_actualHitClass attachTo [_grenade,[0,0,0]];
			
			
			waitUntil {sleep 0.1; !(alive _grenade)};
			if (isDedicated) exitWith {};
			_boomSounds = [
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_01.wss",
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_02.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_03.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_04.wss"  

			];
			
			_meleeSounds = [
				"\a3\sounds_f\vehicles\crashes\watersplash_2.wss",
				"\a3\sounds_f\vehicles\crashes\watersplash_1.wss"
			];

			
			playSound3D [(selectRandom _boomSounds), _actualHitClass];
			playSound3D [(selectRandom _meleeSounds), _actualHitClass];
			_actualHitClass call BugsLife_HandleMelee;
			private _lamd = createVehicle ["MAR_acidCrater",position _actualHitClass, [], 0, "CAN_COLLIDE"]; 
			_lamd spawn {sleep 30; deleteVehicle _this;};
			
			[_actualHitClass, {

				if (isDedicated) exitWith {};
					
					_fulgi  = "#particlesource" createVehiclelocal getposaTL _this;  
					_fulgi setParticleRandom [0, [1, 1, 0], [5, 3, 1], 3, 0.25, [0, 0, 0, 0.1], 0, 0];   
					_fulgi setDropInterval 0.1;   
					_fulgi setParticleCircle [1, [0, 0, 0]];   
					_fulgi setParticleParams [["\A3\data_f\cl_exp", 1, 0, 1],"","Billboard",1,15,[0,0,0],[0,0,0],0,1.7,1,0,[0.15],[[0.01,0.5,0.1,1]],[1],0,0,"","", _this, 0, false, 0.4, [[0.01,3,0.005,1],[0.01,5,0.005,1],[0.01,7,0.005,1]]]; 

					_fog1 = "#particlesource" createVehicleLocal getposaTL _this; 
					_fog1 setParticleParams [   
						["\A3\data_f\cl_exp", 1, 0, 1], "", "Billboard", 3, 7,   
						[0, 0, 0], [0, 0, 0], 1, 1.27, 1, 0,   
						[0,0.5,0],[[0.01,1,0.1,1]], [1000], 1, 0, "", "", _this, 0, false, -1, [[0.01,25,0.005,1],[0.01,25,0.005,1],[0.01,25,0.005,1]]  
					];   
					_fog1 setParticleRandom [3, [1, 1, 0.3], [0, 0, -0.1], 2, 0.15, [0, 0, 0, 0.1], 0, 0];   
					_fog1 setParticleCircle [1, [0, 0, -0.12]];   
					_fog1 setDropInterval 1;   
					_fog1 setParticleFire [2,2,0.1];

					

					
					
					uisleep 1;
					deleteVehicle _fulgi;
					
					uisleep 10;
					deleteVehicle _fog1;
					
			}] remoteExec ["spawn", 0];

			uisleep 15;
			deleteVehicle _actualHitClass;
		};
	};

	
	private _forwardVector = vectorNormalized (_targetPos vectorDiff _currentPos);   
	private _rightVector = (_forwardVector vectorCrossProduct [0,0,1]) vectorMultiply -1;   
	private _upVector = _forwardVector vectorCrossProduct _rightVector;   
	private _targetVelocity = _forwardVector vectorMultiply _speed;   
	[_rocket,[_forwardVector, _upVector]] remoteExecCall ["setVectorDirAndUp",0];   
	[_rocket,_targetVelocity] remoteExecCall ["setVelocity",0];
	uisleep 20;   
	deleteVehicle _rocket;
};

