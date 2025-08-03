





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



	BEXP_FNC_PlayerGruntMelee = {
		_zombie = _this;
		if !(isTouchingGround  _zombie) exitWith {}; 
		if !(alive _zombie) exitWith {};
		if !(_zombie isKindOf "WBK_Grunt_1") exitWith {};
		if (animationState _zombie in ["grunt_sleeping","grunt_salute","grunt_evade_r","grunt_evade_l","grunt_reload_plasma","grunt_reload_humanoid","grunt_reload_fuelrod","grunt_grenadethrow"])exitWith{};
		if (_zombie getVariable ["CanMelee",true]) then {
			_zombie setVariable ["CanMelee",false];
			_zombie spawn {uiSleep 1; _this setVariable ["CanMelee",true];};
			if (animationState _zombie in ["grunt_melee_armed","grunt_melee_1","grunt_melee_2"])exitWith {};
			if (isNil{((_zombie getVariable "WBK_HaloAi_Weapon")select 0)}) then {[_zombie,[selectRandom ["Grunt_Melee_2","Grunt_Melee_1"], 0, 0.2, false]] remoteExec ["switchMove",0];}else
			{[_zombie,["Grunt_Melee_Armed", 0, 0.2, false]] remoteExec ["switchMove",0];};
			[_zombie,selectRandom ["grunt_dodge_1","grunt_dodge_2","grunt_dodge_3"],200] call CBA_fnc_GlobalSay3d;
			uiSleep 0.1;
			if !(animationState _zombie in ["grunt_melee_armed","grunt_melee_1","grunt_melee_2"])exitWith {};
			
			
			uisleep 0.2;
			
			if !(animationState _zombie in ["grunt_melee_armed","grunt_melee_1","grunt_melee_2"])exitWith {};
			_zombie call MAR_BFNC_HandleMelee;
			
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
		if (_ins >= 0.7) exitWith {
			_tarArr = _x;
		};
	} forEach _targets;
	_tarArr
};

BEXP_FNC_GruntMelee = {
	params ["_zombie","_en"];
	
	if (_zombie getVariable ["CanMelee",true]) then {
		_zombie setVariable ["CanMelee",false];
		_zombie spawn {uiSleep 1; _this setVariable ["CanMelee",true];};
		if (animationState _zombie in ["ant_attack_1"])exitWith {};
	
		[_zombie,["ANT_Attack_1", 0, 0.2, false]] remoteExec ["switchMove",0];
			
		[_zombie,selectRandom ["grunt_dodge_1","grunt_dodge_2","grunt_dodge_3"],200] call CBA_fnc_GlobalSay3d;
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
