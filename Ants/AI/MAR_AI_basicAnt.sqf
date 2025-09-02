_gruntBoy = _this select 0;



if ((isPlayer _gruntBoy) or !(alive _gruntBoy) or !(isNil {_gruntBoy getVariable "WBK_SynthHP"})) exitWith {
	switch typeOf _gruntBoy do {
		case ("MAR_ANT_Basic"):{
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTWORKERHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTWORKERHLTTH,true];
		};

		case ("MAR_ANT_Spitter"):{
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTSPITTERHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTSPITTERHLTTH,true];
		};
		case ("MAR_ANT_Guppy"):{
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTGRUBHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTGRUBHLTTH,true];
		};
		case ("MAR_ANT_Ice"):{
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTICEHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTICEHLTTH,true];
			[_gruntBoy,1.5]remoteExec ["setAnimSpeedCoef",0];
		};

		default {
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTWORKERHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTWORKERHLTTH,true];
		};
	};
};

_gruntBoy setSpeaker "NoVoice";
(group _gruntBoy) setFormation "LINE";
_gruntBoy disableConversation true;
switch typeOf _gruntBoy do {
	case ("MAR_ANT_Basic"):{
		_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTWORKERHLTTH,true];
		_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTWORKERHLTTH,true];
	};
	case ("MAR_ANT_Spitter"):{
		_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTSPITTERHLTTH,true];
		_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTSPITTERHLTTH,true];
	};
	case ("MAR_ANT_Guppy"):{
			_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTGRUBHLTTH,true];
			_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTGRUBHLTTH,true];
		};
	case ("MAR_ANT_Ice"):{
		_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTICEHLTTH,true];
		_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTICEHLTTH,true];
		[_gruntBoy,1.5]remoteExec ["setAnimSpeedCoef",0];
	};
	default {
		_gruntBoy setVariable ["WBK_SynthHP",MAR_BL_ANTWORKERHLTTH,true];
		_gruntBoy setVariable ["WBK_SynthHPMax",MAR_BL_ANTWORKERHLTTH,true];
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
	_unit setVariable ["WBK_AI_LastKnownLoc",(getPosATL _firer)];
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
		_this remoteExec ["Bugzlife_BugDeathContainer",_this];
	};
}];



_gruntBoy setVariable ["IMS_EventHandler_Hit",{
	_victim = _this select 0;
	_attacker = _this select 1;
	_weapon = _this select 2;
	_attacker call BugsLife_HandleMelee;
	if (((_victim worldToModel (_attacker modelToWorld [0, 0, 0])) select 1) < 0) exitWith {
		[_victim,["ANT_Hit_B", 0, 0.7, false]] remoteExec ["switchMove",0];
	};
	[_victim,["ANT_Hit_F", 0, 0.7, false]] remoteExec ["switchMove",0];
},true];

_gruntBoy addEventHandler ["Suppressed", {
	params ["_unit", "_distance", "_shooter", "_instigator", "_ammoObject", "_ammoClassName", "_ammoConfig"];
	if !(alive _unit) exitWith {};
	_unit reveal [_instigator, 4];
	_unit setVariable ["WBK_AI_LastKnownLoc",(getPosATL _shooter)];
}];

[_gruntBoy, {
_this removeAllEventHandlers "HitPart";
_this addEventHandler [
    "HitPart",
    {
		(_this select 0) params ["_target","_shooter","_bullet","_position","_velocity","_selection","_ammo","_direction","_radius","_surface","_direct"];
		if ((!(isNil {_shooter getVariable "WBK_CovieAI"}) && (side _shooter == side _target)) or (_target == _shooter) or !(alive _target) or (lifeState _target == "INCAPACITATED")) exitWith {};
		_target setVariable ["WBK_AI_LastKnownLoc",(getPosATL _shooter)];
		_isExplosive = _ammo select 3;
		_isEnoughDamage = _ammo select 0;
		_vv = _target getVariable "WBK_SynthHP";
		_vvMAX = _target getVariable "WBK_SynthHPMax";
		_new_vv = _vv - _isEnoughDamage;
		if (_new_vv <= 0) exitWith {
			_target removeAllEventHandlers "HitPart"; 
			[_target, [1, false, _shooter]] remoteExec ["setDamage",2];
		};
		[_target, "WBK_Halo_Hit",[_target,_shooter]] call BIS_fnc_callScriptedEventHandler;
		_target setVariable ["WBK_SynthHP",_new_vv,true];
		if (!(isNull objectParent _target) or !(isTouchingGround _target) or (animationState _target == "ANT_Hit_B") or (animationState _target == "ANT_Hit_F") or (animationState _target == "ANT_Death")) exitWith {};
      
		if ((isNil{_target getVariable "canBeStunned"}) && (_isEnoughDamage > 12))then
		{
			_target setVariable ["canBeStunned",false,true];
			_target spawn {sleep 6; _this setVariable ["canBeStunned",nil,true];};

			if (((_target worldToModel (_shooter modelToWorld [0, 0, 0])) select 1) < 0) exitWith {
				[_target,["ANT_Hit_B", 0, 0.7, false]] remoteExec ["switchMove",0];
			};
			[_target,["ANT_Hit_F", 0, 0.7, false]] remoteExec ["switchMove",0];
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
				"ant_attack_1",
				"ant_attack_ranged",
				"ant_death",
				"ant_death_static",
				"ant_inair",
				"ant_hit_f",
				"ant_hit_b"
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
			_en = _mutant findNearestEnemy _mutant;
			_ins = [_en, "FIRE", _mutant] checkVisibility [aimPos _mutant, eyePos _en];
			
			switch true do {
				
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

				case ((_ins >= 0.8) and
					(_mutant isKindOf "MAR_ANT_Spitter") and
					(isNil {_mutant getVariable "IsCanFire"}) and
					(isNull objectParent _mutant) and 
					!(animationState _mutant == "ANT_Attack_1")and
					!(animationState _mutant == "ANT_Attack_Ranged")and  								
					((_en distance _mutant) < 90) and ((_en distance _mutant) > 2.5) and
					!(isNull _en) and 
					(((_mutant worldToModel (_en modelToWorld [0, 0, 0])) select 0) < 7) and
					(alive _en)): {
					
						[_mutant,_en] spawn BugsLife_RangedAttack_FNC;
					
				};

		
				
				
			};
		};
	};
}, 0.1, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;

_loopPathfind = [{
    _array = _this select 0;
    _unit = _array select 0;
	_nearEnemy = _unit findNearestEnemy _unit; 
	switch true do {
		case (!(simulationEnabled _unit) || !(isNull (remoteControlled _unit)) || (isNull _nearEnemy) or !(alive _nearEnemy) or !(alive _unit) or !(isNull attachedTo _unit) or (lifeState _unit == "INCAPACITATED") or (_unit distance _nearEnemy >= 500)): {
			switch true do {
				case !(isNil {_unit getVariable "WBK_IsUnitLocked"}): {_unit setVariable ["WBK_IsUnitLocked",nil];};
				default {};
			};
		};
		case !(animationState _unit in ["ant_idle","ant_run","ant_walk_r","ant_walk_l","ant_walk_b","ant_turn_l","ant_turn_r","guppy_idle","guppy_inch"]): {
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
			_ifInter = [_nearEnemy, "FIRE", _unit] checkVisibility [_unit modelToWorldVisualWorld [0,0,0.7], _nearEnemy modelToWorldVisualWorld [0,0,0.7]];
			switch true do {
				case ((_ifInter >= 0.1) and (((getPosATL _unit select 2) - (getPosATL _nearEnemy select 2)) < 1.45) and (((getPosATL _unit select 2) - (getPosATL _nearEnemy select 2)) > (-1.45))): {
					_unit setVariable ["WBK_IsUnitLocked",0];
					_unit disableAI "MOVE";
					_unit disableAI "ANIM";
					doStop _unit;
					switch (typeOf _unit) do {
						case "MAR_ANT_Guppy": {
							[_unit,"Guppy_Inch",[0,0,0]] spawn ANTZ_MoveAi;
						};
						case "MAR_ANT_QUEEN":{

						};
						default {
							if  ((_unit distance _nearEnemy) > 2) then {
								[_unit,"ANT_Run",[0,0,0]] spawn ANTZ_MoveAi;
							}else{
								[_unit,"ANT_Walk",[0,0,0]] spawn ANTZ_MoveAi;
							};
						};
					};
				
					_unit setVariable ["WBK_AI_LastKnownLoc",getPosATLVisual _nearEnemy];
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
				};
				default {};
			};
		};
	};
}, 0.1, [_gruntBoy]] call CBA_fnc_addPerFrameHandler;

_loopPathfindDoMove = [{
    _array = _this select 0;
    _unit = _array select 0;
	switch true do {
		default {
			_nearEnemy = _unit findNearestEnemy _unit; 
			_unit enableAI "MOVE";
			_unit enableAI "ANIM";
			switch true do {
				case (!(simulationEnabled _unit) || !(alive _unit) || !(isNull attachedTo _unit) || (lifeState _unit == "INCAPACITATED")): {};
				
				case !(isNil {_unit getVariable "WBK_AI_LastKnownLoc"}): {
					switch true do {
						case ((_nearEnemy distance (_unit getVariable "WBK_AI_LastKnownLoc")) <= 200): {
							_unit doMove position _nearEnemy;
							_unit setVariable ["WBK_AI_LastKnownLoc",getPosATLVisual _nearEnemy];
							
						};
						default {};
					};
					
				};
				case (!(isNull _nearEnemy) && (alive _nearEnemy)): {
					_unit doMove (getPosATLVisual _nearEnemy);
					_unit setVariable ["WBK_AI_LastKnownLoc",getPosATLVisual _nearEnemy];
				};
				default {};
			};
		};
	};
}, selectRandom [4,5,6,7], [_gruntBoy]] call CBA_fnc_addPerFrameHandler;



_gruntBoy setVariable ["WBK_AI_AttachedHandlers",[_actFr,_loopPathfind,_loopPathfindDoMove]];