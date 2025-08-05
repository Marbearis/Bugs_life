if (!(hasInterface) or (isDedicated)) exitWith {};
[] spawn
{
	waitUntil { !isNull findDisplay 46 };
	["Marbearis' Bugs & critters", "Spawn Ant Hill",
    {
        params ["_modulePosASL", "_attachedobject"];
        deletevehicle _logic;
		
		[_modulePosASL] call Bugzlife_MARAntHill_SpawnHill
   
    },"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa"] call zen_custom_modules_fnc_register;

};