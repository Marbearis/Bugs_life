





[ 
    "MAR_BL_ANTWORKERHLTTH", 
    "EDITBOX", 
    ["Worker Health"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    "200",
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
    "100",
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
    ["Worker Health"],
    ["Marbearis' Bugs & critters","ANT Settings"],
    "200",
    1,
    {   
        params ["_value"];  
        _number = parseNumber _value;
		MAR_BL_ANTICEHLTTH = _number;
    }
] call CBA_fnc_addSetting;




Bugzlife_MARAntHill_SpawnHill = {

    params ["_position",["_dropside",[east]],["_linger", false]];

    _position= (ASLtoATL _position);
                    
    [_position, _dropside, _linger] spawn {
        params ["_position", "_dropside", "_linger"];
        
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
		_soundArray = ["A3\sounds_f\sfx\explosion1.wss","A3\sounds_f\sfx\explosion2.wss","A3\sounds_f\sfx\explosion3.wss"];
		_soundArray_wonk = ["\Bugs_life\data\AntSounds\ANT_Erupt_1.ogg","\Bugs_life\data\AntSounds\ANT_Erupt_2.ogg","\Bugs_life\data\AntSounds\ANT_Erupt_3.ogg"];
		[[_DroidPodCrater,_soundArray] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
		[[_DroidPodCrater,_soundArray_wonk] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
        _projectile = _DroidPodCrater;

        {
            [_x, [[_projectile], true]] remoteExec ["addcuratorEditableObjects", 0];
        } forEach allCurators;


        _projectile setVectorUp surfaceNormal position _projectile;
        _DroidPodCrater setVectorUp surfaceNormal position _DroidPodCrater;
		_DroidPodCrater animateSource ['Anthill_Raised',0,5];
        
    

        // _projectile setposATL ([getPosATL _projectile # 0, getPosATL _projectile # 1, 0]);
        // _projectile setVectorUp surfaceNormal position _projectile;

        _projectile setVariable ['CraterOBJ', _DroidPodCrater, true];

        _position = _CraterPos;

        _side = (_dropside select 0);

        _list =  ["MAR_ANT_Basic","MAR_ANT_Ice","MAR_ANT_Spitter"];
        
       
        
        [_position, _side, _list, _DroidPodCrater, _projectile] spawn {
            params ["_spawn", "_side", "_list", "_DroidPodCrater", "_projectile"];
			_spawnAmount = 6;
            sleep 0.5;
			_FloodGroup = createGroup east;
            _spawn = (_DroidPodCrater modelToWorldVisual (_DroidPodCrater selectionPosition ["Body","Memory"]));
			
			for "_i" from 1 to _spawnAmount do {
				if !(alive _DroidPodCrater) exitWith {};
				_unit = _FloodGroup createUnit [(selectRandom _list), _spawn, [], 0, "CAN_COLLIDE"];
				_unit setPosATL [_spawn#0,_spawn#1,(_spawn#2)+3];

				_unit setDir (random 360);

				[_unit,["ANT_Climb_Out", 0, 0.2, false]] remoteExec ["switchMove",0];

				sleep 6;
			};
			

            _FloodGroup deleteGroupWhenEmpty true;
        };


        [_projectile,{ 

			params ["_projectile"];

			_projectile allowDamage false;
			_projectile setVariable ["gooberHealth",500,true];
			_projectile removeAllEventHandlers "HitPart";
			_projectile addEventHandler ["HitPart", {
			
			(_this select 0) params ["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"]; 

			if ( ((str (side _shooter) == "CIV") and (((currentWeapon _shooter) == ""))) or (captive _shooter)) exitWith {};
			if ( ( !([(side _shooter), (side _target)] call BIS_fnc_sideIsEnemy) and (str (side _target) != "CIV")) or (captive _target)) exitWith {};

			private _currentHealth = _target getVariable ["gooberHealth", 500]; 
		
			private _ProjSpeed = _ammo#0;
			private _newHealth = [_currentHealth - _ProjSpeed, 0, 500] call BIS_fnc_clamp;

			_target setVariable ["gooberHealth", _newHealth, true];

			if (_currentHealth == 0) then {_target setDamage 1;};

			}];

        }] remoteExec ['spawn', ([0, -2] select isDedicated)];

        if (_linger) then {
            sleep 1;
            _projectile allowdamage true;
            while {alive _projectile} do {

                _time = time;

                waitUntil {
                    (time - _time) > (random [15,30,60]) or !(alive _projectile)
                };
                if (alive _projectile) then {
                    _spawn = getPosATL _projectile;
                    _DroidgroupLinger = [_spawn, _side, [selectRandom _listout]] call BIS_fnc_spawngroup;
                    _DroidgroupLinger deleteGroupWhenEmpty true;
                };
            };
        };

    };
};



Bugzlife_AntDeathContainer = {
	params ["_bug","_killer"]; 
	//if (animationState _bug != "ANT_Death") exitWith {};
	switch true do  {
		case (_bug isKindOf "MAR_ANT_Spitter"):{

			[_bug,["ANT_Death", 0, 0.2, false]] remoteExec ["switchMove",0];		
			_bug call BugzLife_fnc_explodeAnt;

		};

		case (_bug isKindOf "MAR_ANT_BASE"): {
			
			[_bug,["ANT_Death", 0, 0.2, false]] remoteExec ["switchMove",0];
			if ((random 100) > 70 ) then {_bug call BugzLife_fnc_explodeAnt;};

		};
		default {};
	};
};

BugzLife_fnc_explodeAnt = {
	_this hideObjectGlobal true;
	_this hideObject true;
	_textures = getObjectTextures _this;	
	
			_boomSounds = [
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_01.wss",
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_02.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_03.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_04.wss"  

			];
			[[_this,_boomSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
			_meleeSounds = [
				"\a3\sounds_f\vehicles\crashes\watersplash_2.wss",
				"\a3\sounds_f\vehicles\crashes\watersplash_1.wss"
			];
			[[_this,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
			
			private _lamd = createVehicle ["MAR_acidCrater",position _this, [], 0, "CAN_COLLIDE"];
			_lamd setDir (random 360);
			_lamd setObjectScale (selectRandom [0.8,0.9,0.6,0.7,0.5]);
			
			_case = ((configFile >> "CfgVehicles" >> typeOf _this >> "impactEffectsBlood") call BIS_fnc_getCfgData);
			switch _case do {
					case ("MAR_ImpactEffectsBugGuts_Orange"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolOrange_CA.paa","\Bugs_life\data\bloodpools\bloodPoolOrange.rvmat",[1,0.5,0,0.12]]};
					case ("MAR_ImpactEffectsBugGuts_Green"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolGreen_CA.paa","\Bugs_life\data\bloodpools\bloodPoolGreen.rvmat",[0,1,0,0.12]]};
					case ("MAR_ImpactEffectsBugGuts_Blue"): {bloodpoolTexture = ["\Bugs_life\data\bloodpools\bloodpoolBlue_CA.paa","\Bugs_life\data\bloodpools\bloodPoolBlue.rvmat",[0,0.4,1,0.12]]};
			};
			[[_lamd,_this],{
				params ["_lamd","_unit"];
					if (isDedicated) exitWith {};
					if ((player distance _lamd) <= 12) then {
						enableCamShake true; 
						addCamShake [1, 0.7, 1];
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
					if (_unit isKindOf "MAR_ANT_Spitter") then {
						_fog1 = "#particlesource" createVehicleLocal getposaTL _lamd; 
						_fog1 setParticleParams [   
							["\A3\data_f\cl_exp", 1, 0, 1], "", "Billboard", 3, 7,   
							[0, 0, 0], [0, 0, 0], 1, 1.27, 1, 0,   
							[0,0.5,0],[[0.01,1,0.1,1]], [1000], 1, 0, "", "", _lamd, 0, false, -1, [[0.01,25,0.005,1],[0.01,25,0.005,1],[0.01,25,0.005,1]]  
						];   
						_fog1 setParticleRandom [3, [1, 1, 0.3], [0, 0, -0.1], 2, 0.15, [0, 0, 0, 0.1], 0, 0];   
						_fog1 setParticleCircle [1, [0, 0, -0.12]];   
						_fog1 setDropInterval 1;   
						_fog1 setParticleFire [2,2,0.1];
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
			_lamd spawn {sleep 120; deleteVehicle _this;};
	


	
	_Part_1 = "MAR_Ant_Part_Thorax" createVehicle (_this modelToWorldVisual [0,0,0]);
	{
		_Part_1 setObjectTextureGlobal [_x,_textures#0];
	}forEach (_Part_1 selectionNames 1);
	_Part_1 setPosATL (_this modelToWorldVisual [0,0,0]);
	_Part_1 setDir 180;
	_Part_1 setVelocityModelSpace [0,-6,4];
	_Part_2 = "MAR_Ant_Part_Head" createVehicle (_this modelToWorldVisual [0,0.5,0]);
	{
		_Part_2 setObjectTextureGlobal [_x,_textures#0];
	}forEach (_Part_2 selectionNames 1);
	_Part_2 setPosATL (_this modelToWorldVisual [0,0.5,0]);
	_Part_2 setDir 180;
	_Part_2 setVelocityModelSpace [0,-6,4];
	_PArt_3 = "MAR_Ant_Part_Abdomen" createVehicle (_this modelToWorldVisual [0,-0.5,0]);
	{
		_Part_3 setObjectTextureGlobal [_x,_textures#0];
	}forEach (_Part_3 selectionNames 1);
	_PArt_3 setPosATL (_this modelToWorldVisual [0,-0.5,0]);
	_PArt_3 setDir 180;
	_PArt_3 setVelocityModelSpace [0,6,4];
	
	for "_i" from 1 to 6 do {
		legSide = 0.2;
		legVelocity = 7;
		if (_i > 3) then {legSide = -0.2; legVelocity = -7;}; 
		_Part_4 = "MAR_Ant_Part_Leg" createVehicle (_this modelToWorldVisual [1,-0.1,0.05]);
		{
			_Part_4 setObjectTextureGlobal [_x,_textures#0];
		}forEach (_Part_4 selectionNames 1);
		_Part_4 setPosATL (_this modelToWorldVisual [0,selectRandom [legSide,0.1,0.5],0.05]);
		
		_Part_4 setVelocityModelSpace [selectRandom [legVelocity,legVelocity],0,6];
		_Part_4 spawn {sleep 35; deleteVehicle _this;};
	};
	
	
	_Part_5 = "MAR_Ant_Part_Mandible" createVehicle (_this modelToWorldVisual [-1,-0.1,0.05]);
	{
		_Part_5 setObjectTextureGlobal [_x,_textures#0];
	}forEach (_Part_5 selectionNames 1);
	_Part_5 setPosATL (_this modelToWorldVisual [-1,0,0.05]);
	_Part_5 setDir ((getDir _this) - 180);
	_Part_5 setVelocityModelSpace [7,0,0];
	_Part_6 = "MAR_Ant_Part_Mandible" createVehicle (_this modelToWorldVisual [-1,-0.1,0.05]);
	{
		_Part_6 setObjectTextureGlobal [_x,_textures#0];
	}forEach (_Part_6 selectionNames 1);
	_Part_6 setPosATL (_this modelToWorldVisual [1,0,0.05]);
	_Part_6 setDir ((getDir _this) - 180);
	_Part_6 setVelocityModelSpace [-7,0,0];
	deleteVehicle _this;
	{
		_x spawn {sleep 35; deleteVehicle _this;};
	}forEach [_Part_1,_Part_2,_Part_3,_Part_5,_Part_6];
};

MAR_Bugslife_FindTarget = {
	_targets = _this targets [true, 500];
	if (count _targets == 0) exitWith {
		objNull
	};
	_tarArr = _this findNearestEnemy _this;
	{
		_ins = [_x, "FIRE", _this] checkVisibility [eyePos _this, eyePos _x];
		if (_ins >= 0.7) exitWith {
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
		[[_zombie,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
		uiSleep 0.1;
		if !(animationState _zombie in ["ant_attack_1"])exitWith {};
		
		
		uisleep 0.2;
		
		if !(animationState _zombie in ["ant_attack_1"])exitWith {};
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

BugsLife_HandleMelee = 
{
	params ["_zombie"];
	{	
		_meleeSounds = [
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_01.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_02.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_03.ogg",
			"\MAR_Banished_EXP\data\Sounds\grunt\punchkick_sgt_04.ogg"
			];

		if ((side _x == side _zombie)) exitWith {
			
		};

	//	[[_x,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
		
		if (((_x != _zombie) and (alive _x)) and (_x isKindOf "MAR_ANT_BASE")) exitWith {
									
			private _chimp = _x getVariable ["WBK_HaloCustomHp",1];
			private _newHealth = _chimp - 25 ;
			_x setVariable ["WBK_HaloCustomHp", _newHealth,true];
			if (_newHealth <= 0) exitWith {
				if ((((_x worldToModel (_zombie modelToWorld [0, 0, 0])) select 1) < 0)) then {
					[_x,["ANT_DEATH", 0, 0.9, false]] remoteExec ["switchMove",0];
				}else 						
				{
					[_x,["ANT_DEATH", 0, 0.7, false]] remoteExec ["switchMove",0];
				};
				_x setDamage 2;
			};			
			if (((_x worldToModel (_zombie modelToWorld [0, 0, 0])) select 1) < 0) then {
				[_x,["Grunt_Hit_Back", 0, 0.7, false]] remoteExec ["switchMove",0];
			}else 						
			{
				[_x,["Grunt_Hit_Front", 0, 0.7, false]] remoteExec ["switchMove",0];
			};											
		};

		
		if (
			!(_x == _zombie) and 
			(alive _zombie) and 						
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
				
				if ((typeOf _x isKindOf "OPTRE_FC_Elite_Undersuit") or (typeOf _x isKindOf "OPTRE_Spartan2_Soldier_Base")) then {
					[_x, _zombie] remoteExec ["WBK_CreateMeleeHitAnim",_x];
				}else{
						[_x, _zombie] spawn {
							_zombie = _this select 0;
							_hitter = _this select 1;	
										
							private _timesHit = _zombie getVariable ["I_timesHit", 1];
							
							if (_timesHit >= 3) then
								{
									_zombie setVariable ["I_timesHit",1,true];
									if (((_zombie worldToModel (_hitter modelToWorld [0, 0, 0])) select 1) < 0) exitWith {
										//[_zombie, [_zombie vectorModelToWorld [0,12,8], _zombie selectionPosition "body"]] remoteExec ["addForce", _zombie];
									};
										//[_zombie, [_zombie vectorModelToWorld [0,-12,8], _zombie selectionPosition "body"]] remoteExec ["addForce", _zombie];
									_hitter disableCollisionWith _zombie;
									
																													
									
									if (!(_zombie isKindOf "WBK_Grunt_1")||!(_zombie isKindOf "MAR_Grunt_Melee")) then {
										sleep 5;																						
										[_zombie, false] remoteExec ["setUnconscious", _zombie];
										_zombie setUnconscious false;
										_hitter enableCollisionWith _zombie;
									};
											
								}else { 
									private _dong = _zombie getVariable ["I_timesHit", 1];
									private _Ndong = _dong + 1;
									_zombie setVariable ["I_timesHit",_Ndong,true];
								};														
						};
			
						if !(isNil {"ace_medical_fnc_addDamageToUnit"})then {
							
							[_x, 0.5, "body", "stab"] remoteExec ["ace_medical_fnc_addDamageToUnit", _x];
							
						}else{									
							private _poop = damage _x;
							_x setDamage 0.20 + _poop;
						};																								
					};
			};
		
	} forEach nearestObjects [_zombie,["MAN"],2.5];
};


BugsLife_RangedAttack_FNC= {

	params ["_mantis","_en"];
	[_mantis,["ANT_Attack_Ranged", 0, 0.2, false]] remoteExec ["switchMove",0];
	_meleeSounds = [
		"\Bugs_life\data\AntSounds\antSpit.ogg"
	];
	[[_mantis,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
	if !(animationState _mantis in ["ant_attack_ranged"]) exitWith {};

	uiSleep 0.3;
	if !(animationState _mantis in ["ant_attack_ranged"]) exitWith {};
	if (((_mantis worldToModel (_en modelToWorld [0, 0, 0])) select 0) < 7) exitWith {					
		switch true do {
	
			case (_mantis isKindOf "MAR_ANT_Spitter"): {
				_mantis setVariable ["IsCanFire",1]; 
				_mantis setVariable ["WBK_OPTRE_AfterContact",1];
				_mantis spawn {uisleep selectRandom [1,2,3,4]; _this setVariable ["IsCanFire",nil];};																				
				uiSleep 0.3;				
				[_mantis,_mantis modelToWorldVisual [(_mantis selectionPosition ["a_spitPoint","Memory"])select 0,((_mantis selectionPosition ["a_spitPoint","Memory"]) select 1)+0,((_mantis selectionPosition ["a_spitPoint","Memory"])select 2)+0],"Smasher_AcidGrenade", _en, selectRandom [[(aimPos _en select 0) - 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) - 2,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 2,aimPos _en select 1,aimPos _en select 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 1]], (selectRandom [40,50,55]), false, [0,0,0]] spawn Bugzz_fnc_ProjectileCreate;						
			};

			case (_mantis isKindOf "MAR_ANT_Ice"): {
				_mantis setVariable ["IsCanFire",1]; 
				_mantis setVariable ["WBK_OPTRE_AfterContact",1];
				_mantis spawn {uisleep selectRandom [1,2,3,4]; _this setVariable ["IsCanFire",nil];};
				[_mantis,_mantis modelToWorldVisual (_mantis selectionPosition ["a_spitPoint","Memory"]),"G_40mm_HE", _en, selectRandom [[(aimPos _en select 0) - 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) - 2,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 2,aimPos _en select 1,aimPos _en select 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 1]], (selectRandom [120,150,160]), false, [0,0,0]] spawn Bugzz_fnc_ProjectileCreate;						
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
	if (count _startPos != 3 || {{typeName _x != typeName 0} count _startPos > 0}) exitWith {"fn_guidedProjectile invalid position, not a 3D vector" call BIS_fnc_error};   
	if (_startPos isEqualTo [0,0,0]) exitWith {"fn_guidedProjectile invalid position, at 0,0,0" call BIS_fnc_error};   
	if (typeName _class == typeName "" && {_class == ""}) exitWith {"fn_guidedProjectile invalid class provided" call BIS_fnc_error};   
	if (typeName _class == typeName objNull && {isNull _class}) exitWith {"fn_guidedProjectile invalid object provided" call BIS_fnc_error};   
	if (isNull _target) exitWith {"fn_guidedProjectile invalid target provided" call BIS_fnc_error};   
	private _rocket = createVehicle [_class,_startPos, [], 0, "CAN_COLLIDE"];
	_rocket setDir (getDir _shooter);

	if (_rocket isKindOf "Smasher_AcidGrenade") then {
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
			_fog1 setParticleCircle [0.001, [0, 0, -0.12]]; 
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
			//
			
			waitUntil {sleep 0.1; !(alive _grenade)};
			_boomSounds = [
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_01.wss",
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_02.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_03.wss", 
				"\a3\sounds_f\arsenal\explosives\grenades\grenadelight_closeexp_04.wss"  

			];
			[[_actualHitClass,_boomSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
			_meleeSounds = [
				"\a3\sounds_f\vehicles\crashes\watersplash_2.wss",
				"\a3\sounds_f\vehicles\crashes\watersplash_1.wss"
			];
			[[_actualHitClass,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
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

	_rocket setShotParents [vehicle _shooter, _shooter];  
	private _currentPos = getPosASLVisual _rocket;   
	private _targetPos = _tgtPos;   
	private _forwardVector = vectorNormalized (_targetPos vectorDiff _currentPos);   
	private _rightVector = (_forwardVector vectorCrossProduct [0,0,1]) vectorMultiply -1;   
	private _upVector = _forwardVector vectorCrossProduct _rightVector;   
	private _targetVelocity = _forwardVector vectorMultiply _speed;   
	[_rocket,[_forwardVector, _upVector]] remoteExecCall ["setVectorDirAndUp",0];   
	[_rocket,_targetVelocity] remoteExecCall ["setVelocity",0];
	uisleep 20;   
	deleteVehicle _rocket;
};

