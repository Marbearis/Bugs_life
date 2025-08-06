_gruntBoy = _this select 0;



if ((isPlayer _gruntBoy) or !(alive _gruntBoy) or !(isNil {_gruntBoy getVariable "WBK_HaloCustomHp"})) exitWith {};

_gruntBoy setSpeaker "NoVoice";
(group _gruntBoy) setFormation "LINE";
_gruntBoy disableConversation true;
switch typeOf _gruntBoy do {
	case ("MAR_ANT_Basic"):{
		_gruntBoy setVariable ["WBK_HaloCustomHp",MAR_BL_ANTWORKERHLTTH,true];
		_gruntBoy setVariable ["WBK_HaloCustomHpMax",MAR_BL_ANTWORKERHLTTH,true];
	};
	case ("MAR_ANT_Spitter"):{
		_gruntBoy setVariable ["WBK_HaloCustomHp",MAR_BL_ANTSPITTERHLTTH,true];
		_gruntBoy setVariable ["WBK_HaloCustomHpMax",MAR_BL_ANTSPITTERHLTTH,true];
	};
	case ("MAR_ANT_Ice"):{
		_gruntBoy setVariable ["WBK_HaloCustomHp",MAR_BL_ANTICEHLTTH,true];
		_gruntBoy setVariable ["WBK_HaloCustomHpMax",MAR_BL_ANTICEHLTTH,true];
		[_gruntBoy,1.5]remoteExec ["setAnimSpeedCoef",0];
	};
	default {
		_gruntBoy setVariable ["WBK_HaloCustomHp",MAR_BL_ANTWORKERHLTTH,true];
		_gruntBoy setVariable ["WBK_HaloCustomHpMax",MAR_BL_ANTWORKERHLTTH,true];
	};
};

_gruntBoy setVariable ["lambs_danger_disableAI", true];
_gruntBoy setVariable ["WBK_CovieAI", 1];
_gruntBoy allowFleeing 0;
sleep (selectRandom [0.1,0.5,0.3,0.9]);
if !(isNil "WBK_IsPresent_PIR") then {
	_gruntBoy setVariable ["dam_ignore_hit0",true,true];
	_gruntBoy setVariable ["dam_ignore_effect0",true,true];
};
_gruntBoy setUnitPos "UP";
_gruntBoy spawn {
sleep 0.7;
_this doMove (getPos _this);
};



if !(isNil{WBK_AI_AttachedHandlers})then 
{
	{
		[_x] call CBA_fnc_removePerFrameHandler;
	} forEach (_gruntBoy getVariable "WBK_AI_AttachedHandlers");	
};








_gruntBoy addEventHandler ["FiredNear", {
	params ["_unit", "_firer", "_distance", "_weapon", "_muzzle", "_mode", "_ammo", "_gunner"];
	if (!(alive _unit)) exitWith {};
	_unit reveal [_firer, 4];
}];


_gruntBoy addEventHandler ["Deleted", {
	params ["_zombie"];
	{
		_ifDelete = [_x] call CBA_fnc_removePerFrameHandler;
	} forEach (_zombie getVariable "WBK_AI_AttachedHandlers");

}];


_gruntBoy addEventHandler ["Killed", {
	{
		_ifDelete = [_x] call CBA_fnc_removePerFrameHandler;
	} forEach ((_this select 0) getVariable "WBK_AI_AttachedHandlers");
	(_this select 0) spawn {
		uisleep 0.1;	
		_this remoteExec ["Bugzlife_AntDeathContainer",_this];
	};
}];



_gruntBoy setVariable ["IMS_EventHandler_Hit",{
	_victim = _this select 0;
	_attacker = _this select 1;
	_weapon = _this select 2;
	//[_victim,selectRandom ["grunt_pain_1","grunt_pain_2","grunt_pain_3","grunt_pain_4","grunt_pain_5","grunt_pain_6","grunt_pain_7"],200] call CBA_fnc_GlobalSay3d;
	if (((_victim worldToModel (_attacker modelToWorld [0, 0, 0])) select 1) < 0) exitWith {
		[_victim,["ANT_Hit_B", 0, 0.7, false]] remoteExec ["switchMove",0];
	};
	[_victim,["ANT_Hit_F", 0, 0.7, false]] remoteExec ["switchMove",0];
},true];



[_gruntBoy, {
	_this removeAllEventHandlers "HitPart";
	_this addEventHandler [
    "HitPart",
    {
		(_this select 0) params ["_target","_shooter","_bullet","_position","_velocity","_selection","_ammo","_direction","_radius","_surface","_direct"];
		if ((!(isNil {_shooter getVariable "WBK_CovieAI"}) && (side _shooter == side _target)) or (_target == _shooter) or !(alive _target) or (lifeState _target == "INCAPACITATED")) exitWith {};
		_isExplosive = _ammo select 3;
		_isEnoughDamage = _ammo select 0;
		_vv = _target getVariable "WBK_HaloCustomHp";
		_vvMAX = _target getVariable "WBK_HaloCustomHpMax";
		_new_vv = _vv - _isEnoughDamage;
		if (_new_vv <= 0) exitWith {
			_target removeAllEventHandlers "HitPart"; 
			[_target, [1, false, _shooter]] remoteExec ["setDamage",2];
		};
		[_target, "WBK_Halo_Hit",[_target,_shooter]] call BIS_fnc_callScriptedEventHandler;
		_target setVariable ["WBK_HaloCustomHp",_new_vv,true];
		if (!(isNull objectParent _target) or !(isTouchingGround _target) or (animationState _target == "ANT_Hit_B") or (animationState _target == "ANT_Hit_F") or (animationState _target == "ANT_Death")) exitWith {};
       // [_target,selectRandom ["grunt_pain_1","grunt_pain_2","grunt_pain_3","grunt_pain_4","grunt_pain_5","grunt_pain_6","grunt_pain_7"],200] call CBA_fnc_GlobalSay3d;
		if ((isNil{_target getVariable "canBeStunned"}) && (_isEnoughDamage > 12))then
		{
			_target setVariable ["canBeStunned",false,true];
			_target spawn {sleep 6; _this setVariable ["canBeStunned",nil,true];};

			if (((_target worldToModel (_shooter modelToWorld [0, 0, 0])) select 1) < 0) exitWith {
				//[_target,["ANT_Hit_B", 0, 0.7, false]] remoteExec ["switchMove",0];
			};
			//[_target,["ANT_Hit_F", 0, 0.7, false]] remoteExec ["switchMove",0];
		};
	}
];
}] remoteExec ["spawn", [0,-2] select isDedicated,true];













_actFr = [{
    _array = _this select 0;
    _mutant = _array select 0;
	_mutant allowDamage false;
	switch true do {
		case !(isNull objectParent _mutant): {
			_mutant enableAI "TARGET";
			_mutant enableAI "AUTOCOMBAT";
			_mutant enableAI "WEAPONAIM";
		};
		
		case (!(alive _mutant) || (animationState _mutant in [
				"spider_attack",
				"spider_burrowed_attack",
				"spider_attack_ranged",
				"spider_death",
				"spider_death_static",
				"spider_inair",
				"spider_hit_f",
				"spider_hit_b"
			])): {};
		default {
			_mutant action ["SwitchWeapon", _mutant, _mutant, 100]; 
			removeAllWeapons _mutant;
			_mutant disableAI "MINEDETECTION";
			_mutant disableAI "WEAPONAIM";
			_mutant disableAI "SUPPRESSION";
			_mutant disableAI "COVER";
			_mutant disableAI "AIMINGERROR";
			_mutant disableAI "TARGET";
			_mutant disableAI "AUTOCOMBAT";
			_mutant disableAI "FSM";
			_mutant setCombatBehaviour "AWARE";
			_en = _mutant call MAR_Bugslife_FindTarget;
			_ins = [_en, "FIRE", _mutant] checkVisibility [aimPos _mutant, eyePos _en];
			//Spider_Burrowed_Idle
			switch true do {
				case ((_mutant isKindOf "MAR_Spider_Burrower")&&!(isNil {_mutant getVariable "trapDoor"})&&((vehicle _en) isKindOf "MAN")and((_en distance _mutant) < 6)):
				{
					[_mutant,_en] spawn Bugslife_TrapDoorAttack;
					[_mutant, "WBK_Halo_Melee",[_mutant,_en]] call BIS_fnc_callScriptedEventHandler;
				};
				case (
					(isNull objectParent _mutant) and 
					((vehicle _en) isKindOf "MAN") and 
					!(animationState _mutant == "ANT_Attack_1")and
					!(animationState _mutant == "ANT_Attack_Ranged")and  								
					((_en distance _mutant) < 2.5) and ((_en distance _mutant) > 0) and
					!(isNull _en) and 
					(alive _en) and 
					!((vehicle _en) isKindOf "Tank") and 
					!((vehicle _en) isKindOf "Air")): {
					
					[_mutant,_en] spawn Bugslife_ANTMelee;
					[_mutant, "WBK_Halo_Melee",[_mutant,_en]] call BIS_fnc_callScriptedEventHandler;
				};

				

		
				
				
			};
		};
	};
}, 0.1, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;

if ((_gruntBoy isKindOf "MAR_Spider_Burrower")&&!(isNil {_gruntBoy getVariable "trapDoor"})) then {

	_loopPathfindDoMove = [{
		_array = _this select 0;
		_unit = _array select 0;
		
		if (!(_unit checkAIFeature "MOVE") or !(_unit checkAIFeature "PATH") or !(animationState _unit in ["ant_idle","ant_run"])) exitWith {};
		_nearEnemy = _unit call MAR_Bugslife_FindTarget; 
		if ((isNull _nearEnemy) or !(alive _nearEnemy) or !(alive _unit) or (((_unit distance _nearEnemy) >= 400))) exitWith {
					
		};
		{_unit reveal [_x, 4]} forEach units group _nearEnemy;
		_unit setVariable ["WBK_OPTRE_AfterContact",1];
		_dir = [[0,1,0], -([_unit, _nearEnemy] call BIS_fnc_dirTo)] call BIS_fnc_rotateVector2D;
		_unit setVelocityTransformation [ 
			getPosASL _unit,  
			getPosASL _unit,  
			[0,0,(velocity _unit select 2) - 1],  
			[(velocity _unit select 0),(velocity _unit select 1),(velocity _unit select 2) - 1], 
			vectorDir _unit,  
			_dir,  
			vectorUp _unit,  
			vectorUp _unit, 
			0.1
		]; 
			
	}, 0.1, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;
	_gruntBoy setVariable ["WBK_AI_AttachedHandlers",[_actFr,_loopPathfindDoMove]];
}else {
	_loopPathfind = [{
		_array = _this select 0;
		_unit = _array select 0;
		_nearEnemy = _unit findNearestEnemy _unit; 

		switch true do {
			
			case (!(simulationEnabled _unit) || !(isNull (remoteControlled _unit)) || (isNull _nearEnemy) or !(alive _nearEnemy) or !(alive _unit) or !(isNull attachedTo _unit) or (lifeState _unit == "INCAPACITATED") or (_unit distance _nearEnemy >= 400)): {
				switch true do {
					case !(isNil {_unit getVariable "WBK_IsUnitLocked"}): {_unit setVariable ["WBK_IsUnitLocked",nil];};
					default {};
				};
			};
			case !(animationState _unit in ["ant_idle","ant_run"]): {
				_unit setVariable ["WBK_IsUnitLocked",0];
				_unit enableAI "ANIM";
				_unit disableAI "MOVE";
				_dir = [[0,1,0], -([_unit, _nearEnemy] call BIS_fnc_dirTo)] call BIS_fnc_rotateVector2D;
				_unit setVelocityTransformation [ 
				getPosASL _unit,  
				getPosASL _unit,  
				[0,0,(velocity _unit select 2) - 1],  
				[(velocity _unit select 0),(velocity _unit select 1),(velocity _unit select 2) - 1], 
				vectorDir _unit,  
				_dir,  
				vectorUp _unit,  
				vectorUp _unit, 
				0.1
				]; 
			};
			case (!(isNull _nearEnemy) && (alive _nearEnemy)): {
				_ifInter = lineIntersectsSurfaces [
					AGLToASL (_nearEnemy modelToWorld [0,0,0.5]), 
					AGLToASL (_unit modelToWorld [0,0,0.5]), 
					_unit,
					_nearEnemy,
					true,
					1,
					"FIRE",
					"NONE"
				];
				switch true do {
					case ((count _ifInter == 0) and (((getPosATL _unit select 2) - (getPosATL _nearEnemy select 2)) < 1.45) and (((getPosATL _unit select 2) - (getPosATL _nearEnemy select 2)) > (-1.45))): {
						_unit setVariable ["WBK_IsUnitLocked",0];
						_unit disableAI "MOVE";
						_unit disableAI "ANIM";
						doStop _unit;
						switch true do {
							case (lifeState _nearEnemy == "INCAPACITATED" || stance _nearEnemy == "PRONE" || gestureState _nearEnemy == "fp_dash_nostamina" || animationState _nearEnemy == "push_backwards"): {
								[_unit,"ANT_Run",[0,0,0]] spawn ANTZ_MoveAi;	
							};
							case ((_unit distance _nearEnemy) > 2): {
								[_unit,"ANT_Run",[0,0,0]] spawn ANTZ_MoveAi;	
							};
							default {
								[_unit,"ANT_Run",[0,0,0]] spawn ANTZ_MoveAi;	
							};
						};
						_dir = [[0,1,0], -([_unit, _nearEnemy] call BIS_fnc_dirTo)] call BIS_fnc_rotateVector2D;
						_unit setVelocityTransformation [ 
						getPosASL _unit,  
						getPosASL _unit,  
						[0,0,(velocity _unit select 2) - 1],  
						[(velocity _unit select 0),(velocity _unit select 1),(velocity _unit select 2) - 1], 
						vectorDir _unit,  
						_dir,  
						vectorUp _unit,  
						vectorUp _unit, 
						0.5
						]; 
					};
					default {
						switch true do {
							case !(isNil {_unit getVariable "WBK_IsUnitLocked"}): {
								_unit setVariable ["WBK_IsUnitLocked",nil];
								_unit enableAI "ANIM";
								_unit enableAI "MOVE";
								_unit doMove (getPosATLVisual _nearEnemy);
								_unit setVariable ["WBK_AI_LastKnownLoc",getPosATLVisual _nearEnemy];
							};
							default {};
						};
					};
				};
			};
			default {
				switch true do {
					case !(isNil {_unit getVariable "WBK_IsUnitLocked"}): {
						_unit setVariable ["WBK_IsUnitLocked",nil];
						_unit enableAI "ANIM";
						_unit enableAI "MOVE";
						_unit doMove (getPosATLVisual _nearEnemy);
						_unit setVariable ["WBK_AI_LastKnownLoc",getPosATLVisual _nearEnemy];
					};
					default {};
				};
			};
		};
	}, 0.1, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;


	_loopPathfindDoMove = [{
		_array = _this select 0;
		_unit = _array select 0;
		
		if (!(_unit checkAIFeature "MOVE") or !(_unit checkAIFeature "PATH") or !(animationState _unit in ["ant_idle","ant_run"])) exitWith {};
		_nearEnemy = _unit call MAR_Bugslife_FindTarget; 
		if ((isNull _nearEnemy) or !(alive _nearEnemy) or !(alive _unit) or (((_unit distance _nearEnemy) >= 400) and !((_unit distance _nearEnemy) < 2.5))) exitWith {
			_unit doFollow (leader group _unit);		
		};
			{_unit reveal [_x, 4]} forEach units group _nearEnemy;
			_unit setVariable ["WBK_OPTRE_AfterContact",1];
			if ((alive leader group _unit) and !(_unit == leader group _unit) and ((_unit distance (leader group _unit)) <= 40)) then {
				_unit doMove (_nearEnemy modelToWorldVisual [15,5,0]);
			}else{
				_unit doMove (getPosATLVisual _nearEnemy);
			};
	}, 4, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;



	_gruntBoy setVariable ["WBK_AI_AttachedHandlers",[_actFr,_loopPathfind,_loopPathfindDoMove]];
};