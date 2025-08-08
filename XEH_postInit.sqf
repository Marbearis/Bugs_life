if (!(hasInterface) or (isDedicated)) exitWith {};
[] spawn
{
	waitUntil { !isNull findDisplay 46 };
	["Marbearis' Bugs & critters", "Spawn AntHill",
    {
        params ["_modulePosASL", "_attachedobject"];
       
		["Anthill settings", [
            ["SIDES", ["Side select (ONLY ONE!)", "The side the spawned ants will be on."], [east]],
            ["SLIDER",["ant amount","how many ants will spawn initially?"],[1,20,5,0]],
            ["CHECKBOX", ["is spawner?", "Spawns Ants Every ~60 seconds unless destroyed."], [false]],
            ["SLIDER",["Hill health","Amount of HP the Anthill has before it's destroyed"],[1,400,100,0]]       
        ], {
            params["_values", "_arguments"];
            _dropside=_values select 0;
            _spawnAmmount = _values select 1;
            _linger=_values select 2;
            _AntHillHP=_values select 3;
            
            
            _position=_arguments select 0;

            [_position,_dropside,_linger,_AntHillHP,_spawnAmmount] call Bugzlife_SpawnAntHill;
            
        }, {}, [_modulePosASL]] call zen_dialog_fnc_create;
        deletevehicle _logic;
    },"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa"] call zen_custom_modules_fnc_register;
    
    ["Marbearis' Bugs & critters", "Spawn TrapDoor Spider",
    {
        params ["_modulePosASL", "_attachedobject"];
        
        ["TrapDoor Settings", [
            ["SIDES", ["Side select (ONLY ONE!)", "The side the trap door will be on."], [east]],
            ["CHECKBOX", ["can die?", "whether or not you can kill it"], [false]]
        ], {
            params["_values", "_arguments"];
            _side=_values select 0;
            _canDie = _values select 1;         
            _position=_arguments select 0;
            
            [_position,_side#0,_canDie] call Bugzlife_TrapDoor
            
        }, {}, [_modulePosASL]] call zen_dialog_fnc_create;
        deletevehicle _logic;
		
    },"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa"] call zen_custom_modules_fnc_register;

};