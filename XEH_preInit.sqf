





[ 
    "MAR_BL_ANTWORKERHLTTH", 
    "EDITBOX", 
    ["Worker Health"],
    ["Marbearis' Bugs Life","ANT Settings"],
    "200",
    1,
    {   
        params ["_value"];  
        _number = parseNumber _value;
		MAR_BL_ANTWORKERHLTTH = _number;
    }
] call CBA_fnc_addSetting;



//keybinds
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

["Banished Expansion", "JumpKey", ["Le jump", "boing!"], {
	_player = missionnamespace getVariable ["bis_fnc_moduleremoteControl_unit", player];
    if (_player getVariable ["BEXP_Keybind_KeyPressed", false]) exitWith {};

    _player setVariable ["BEXP_Keybind_KeyPressed", true]; // Set cooldown at start

    _player spawn {
        uiSleep 1;
        _this setVariable ["BEXP_Keybind_KeyPressed", false];
    };
    [_player] call BEXP_FNC_Jump;
}, {}, [DIK_J, [false, false, false]]] call CBA_fnc_addKeybind;

["Banished Expansion", "meleeKey", ["melee", "shwack"], {
	_player = missionnamespace getVariable ["bis_fnc_moduleremoteControl_unit", player];
    if (_player getVariable ["BEXP_Keybind_KeyPressed", false]) exitWith {};

    _player setVariable ["BEXP_Keybind_KeyPressed", true]; // Set cooldown at start

    _player spawn {
        uiSleep 1;
        _this setVariable ["BEXP_Keybind_KeyPressed", false];
    };
    _player spawn BEXP_FNC_PlayerGruntMelee;
}, {}, [DIK_F, [false, false, false]]] call CBA_fnc_addKeybind;




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
		_zombie call MAR_BFNC_HandleMelee;
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

MAR_BFNC_HandleMelee = 
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

		[[_x,_meleeSounds] ,{ params ["_player","_soundArray"];playSound3D [selectRandom _soundArray, _player];}] remoteExec ["spawn", [0,-2] select isDedicated];
		
		if (((_x != _zombie) and (alive _x)) and (_x isKindOf "MAR_ANT_BASE")) exitWith {
			
						
			private _chimp = _x getVariable "WBK_HaloCustomHp";
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

	uiSleep 0.2;
	if !(animationState _mantis in ["ant_attack_ranged"]) exitWith {};
	if (((_mantis worldToModel (_en modelToWorld [0, 0, 0])) select 0) < 7) exitWith {					
		switch true do {
	
			case (_mantis isKindOf "MAR_ANT_Spitter"): {
				_mantis setVariable ["IsCanFire",1]; 
				_mantis setVariable ["WBK_OPTRE_AfterContact",1];
				_mantis spawn {uisleep selectRandom [1,2,3,4]; _this setVariable ["IsCanFire",nil];};
				[_mantis,_mantis modelToWorldVisual (_mantis selectionPosition ["a_spitPoint","Memory"]),"B_BugsLife_Acid_Spit", _en, selectRandom [[(aimPos _en select 0) - 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 1,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) - 2,aimPos _en select 1,aimPos _en select 2],[(aimPos _en select 0) + 2,aimPos _en select 1,aimPos _en select 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 2],[eyePos _en select 0, eyePos _en select 1,(eyePos _en select 2) + 1]], (selectRandom [40,50,55]), false, [0,0,0]] spawn Bugzz_fnc_ProjectileCreate;						
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