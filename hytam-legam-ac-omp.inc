//for logs ac
#include <file>

#if defined _hytam_legam_ac_omp_included
    #endinput
#endif
#define _hytam_legam_ac_omp_included


#define AC_MAX_ARMOR_VALUE 100.0
#define AC_MAX_HEALTH_VALUE 100.0
#define AC_MAX_VEHICLE_HEALTH 1000.0
#define AC_MAX_ATTACHED_OBJECTS 10
#define AC_MAX_WEAPON_MISMATCH 3
#define AC_MAX_SYNC_DELAY 300
#define AC_MAX_WEAPON_ID 46
#define AC_MAX_WARNINGS 3
#define AC_MAX_SPRINT_SPEED 50.0
#define AC_MAX_VEHICLE_SPEED 300.0
#define AC_MAX_SWIM_SPEED 15.0
#define AC_MAX_PING 500
#define AC_MAX_PACKET_LOSS 2.0
#define AC_MAX_MONEY_AMOUNT 999999999



#if !defined MAX_PLAYERS
    #define MAX_PLAYERS 1000
#endif

// Required natives
#if !defined GetPlayerResolution
    native GetPlayerResolution(playerid, &width, &height);
#endif
#if !defined IsPlayerInWater
    native bool:IsPlayerInWater(playerid);
#endif
#if !defined GetPlayerLastSyncedData
    native GetPlayerLastSyncedData(playerid, &health, &armour, &weapon, &specialaction);
#endif
#if !defined GetPlayerAttachedObject
    native GetPlayerAttachedObject(playerid, index, &modelid, &bone, Float:offset[3], Float:rotation[3], Float:scale[3], &materialcolor1, &materialcolor2);
#endif
#if !defined GetTickCount
    native GetTickCount();
#endif
#if !defined GetPlayerPing
    native GetPlayerPing(playerid);
#endif
#if !defined GetPlayerMoney
    native GetPlayerMoney(playerid);
#endif
#if !defined GetPlayerScore
    native GetPlayerScore(playerid);
#endif
#if !defined GetPlayerState
    native GetPlayerState(playerid);
#endif
#if !defined GetPlayerVehicleID
    native GetPlayerVehicleID(playerid);
#endif
#if !defined GetVehicleHealth
    native GetVehicleHealth(vehicleid, &health);
#endif
#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif
#if !defined GetPlayerPos
    native GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);
#endif
#if !defined GetPlayerHealth
    native GetPlayerHealth(playerid, &health);
#endif
#if !defined GetPlayerArmour
    native GetPlayerArmour(playerid, &armour);
#endif
#if !defined GetPlayerAnimationIndex
    native GetPlayerAnimationIndex(playerid, &index);
#endif
#if !defined GetPlayerSpecialAction
    native GetPlayerSpecialAction(playerid, &action);
#endif
#if !defined GetPlayerDistanceFromPoint
    native Float:GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z);
#endif
#if !defined GetPlayerWeapon
    native GetPlayerWeapon(playerid);
#endif
#if !defined GetPlayerWeaponData
    native GetPlayerWeaponData(playerid, slot, t_WEAPON_SLOT:weaponid, ammo);
#endif
#if !defined ResetPlayerWeapons
    native ResetPlayerWeapons(playerid);
#endif
#if !defined SetVehicleHealth
    native SetVehicleHealth(vehicleid, health);
#endif
#if !defined ResetPlayerMoney
    native ResetPlayerMoney(playerid);
#endif
#if !defined Kick
    native Kick(playerid);
#endif

// Forward declarations
forward Float:AC_GetDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
forward AC_IsValidWeapon(t_WEAPON_SLOT:weaponid);
forward t_WEAPON_SLOT:AC_GetWeaponSlot(t_WEAPON_SLOT:weaponid);
forward AC_OnPlayerCheatDetected(playerid, AC_FLAGS:cheatid, const details[]);
forward AC_OnPlayerACWarning(playerid, cheatid, warningid);
forward AC_OnPlayerACKick(playerid, cheatid, const reason[]);
forward AC_OnPlayerACBan(playerid, cheatid, const reason[]);

// Player states
enum E_AC_PLAYER_STATE {
    AC_STATE_NONE,
    AC_STATE_ONFOOT,
    AC_STATE_DRIVER,
    AC_STATE_PASSENGER,
    AC_STATE_WASTED,
    AC_STATE_SPAWNED,
    AC_STATE_SPECTATING
}

// Weapon slots
enum t_WEAPON_SLOT {
    AC_WEAPON_SLOT_HAND,
    AC_WEAPON_SLOT_MELEE,
    AC_WEAPON_SLOT_PISTOL,
    AC_WEAPON_SLOT_SHOTGUN,
    AC_WEAPON_SLOT_SMG,
    AC_WEAPON_SLOT_RIFLE,
    AC_WEAPON_SLOT_SNIPER,
    AC_WEAPON_SLOT_HEAVY,
    AC_WEAPON_SLOT_THROWN,
    AC_WEAPON_SLOT_SPECIAL
};

// Weapon types
enum E_WEAPON {
    AC_WEAPON_NONE,
    AC_WEAPON_BRASSKNUCKLE = 1,
    AC_WEAPON_GOLFCLUB,
    AC_WEAPON_NITESTICK,
    AC_WEAPON_KNIFE,
    AC_WEAPON_BAT,
    AC_WEAPON_SHOVEL,
    AC_WEAPON_POOLSTICK,
    AC_WEAPON_KATANA,
    AC_WEAPON_CHAINSAW,
    AC_WEAPON_DILDO,
    AC_WEAPON_DILDO2,
    AC_WEAPON_VIBRATOR,
    AC_WEAPON_VIBRATOR2,
    AC_WEAPON_FLOWER,
    AC_WEAPON_CANE,
    AC_WEAPON_GRENADE,
    AC_WEAPON_TEARGAS,
    AC_WEAPON_MOLTOV,
    AC_WEAPON_COLT45 = 22,
    AC_WEAPON_SILENCED,
    AC_WEAPON_DEAGLE,
    AC_WEAPON_SHOTGUN,
    AC_WEAPON_SAWEDOFF,
    AC_WEAPON_SHOTGSPA,
    AC_WEAPON_UZI,
    AC_WEAPON_MP5,
    AC_WEAPON_AK47,
    AC_WEAPON_M4,
    AC_WEAPON_TEC9,
    AC_WEAPON_RIFLE,
    AC_WEAPON_SNIPER,
    AC_WEAPON_ROCKETLAUNCHER,
    AC_WEAPON_HEATSEEKER,
    AC_WEAPON_FLAMETHROWER,
    AC_WEAPON_MINIGUN,
    AC_WEAPON_SATCHEL,
    AC_WEAPON_BOMB,
    AC_WEAPON_SPRAYCAN,
    AC_WEAPON_FIREEXTINGUISHER,
    AC_WEAPON_CAMERA,
    AC_WEAPON_PARACHUTE = 46
};

// Anti-Cheat flags
enum AC_FLAGS {
    AC_NONE = 0,
    AC_SPEEDHACK = 1,
    AC_WEAPONHACK = 2,
    AC_AMMOHACK = 4,
    AC_FLYHACK = 8,
    AC_AIRBREAK = 16,
    AC_TELEPORT = 32,
    AC_MONEYHACK = 64,
    AC_HEALTHHACK = 128,
    AC_ARMORHACK = 256,
    AC_RAPIDFIRE = 512,
    AC_CARJACK = 1024,
    AC_VEHICLEHACK = 2048,
    AC_AIMBOT = 4096,
    AC_WALLHACK = 8192,
    AC_SPAWNVEHICLE = 16384,
    AC_FAKEKILL = 32768,
    AC_GODMODE = 65536,
    AC_INVISIBLE = 131072,
    AC_LAGCOMP = 262144,
    AC_TUNINGHACK = 524288,
    AC_ATTACHMENTHACK = 1048576,
    AC_SYNCDATA = 2097152,
    AC_ANIMATION = 4194304,
    AC_PICKUPHACK = 8388608,
    AC_FAKESPAWN = 16777216
};

// Player data structure
enum E_PLAYER_AC_DATA {
    bool:pacEnabled,
    Float:pacLastPosX,
    Float:pacLastPosY,
    Float:pacLastPosZ,
    Float:pacLastHealth,
    Float:pacLastArmour,
    Float:pacLastVehicleHealth,
    pacLastMoney,
    pacLastScore,
    pacLastVehicle,
    pacLastWeapon,
    pacLastAmmo[AC_MAX_WEAPON_ID + 1],
    pacLastPing,
    pacLastState,
    pacLastAnimation,
    pacLastSpecialAction,
    pacLastUpdateTick,
    pacLastSpawnTick,
    pacLastSyncTick,
    pacLastShotTick,
    pacLastPacketLoss,
    pacResolutionX,
    pacResolutionY,
    pacSpawnedOnce,
    pacSpawnAttempts,
    pacDeathState,
    pacWeaponMismatchCount,
    AC_FLAGS:pacFlags,
    pacWarnings[10] // Fixed size for AC_FLAGS array
};

// Global variables
new g_PlayerACData[MAX_PLAYERS][E_PLAYER_AC_DATA];

// Helper functions
Float:AC_GetDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    return floatsqroot(
        (x2 - x1) * (x2 - x1) +
        (y2 - y1) * (y2 - y1) +
        (z2 - z1) * (z2 - z1)
    );
}

AC_IsValidWeapon(t_WEAPON_SLOT:weaponid)
{
    return (weaponid >= t_WEAPON_SLOT:0 && weaponid <= t_WEAPON_SLOT:AC_MAX_WEAPON_ID);
}

t_WEAPON_SLOT:AC_GetWeaponSlot(t_WEAPON_SLOT:weaponid)
{
    switch(weaponid)
    {
        case 0: return AC_WEAPON_SLOT_HAND;
        case 1..9: return AC_WEAPON_SLOT_MELEE;
        case 22..24: return AC_WEAPON_SLOT_PISTOL;
        case 25..27: return AC_WEAPON_SLOT_SHOTGUN;
        case 28..32: return AC_WEAPON_SLOT_SMG;
        case 33..34: return AC_WEAPON_SLOT_RIFLE;
        case 35..36: return AC_WEAPON_SLOT_SNIPER;
        case 37..39: return AC_WEAPON_SLOT_HEAVY;
        case 16..18: return AC_WEAPON_SLOT_THROWN;
        case 40..46: return AC_WEAPON_SLOT_SPECIAL;
    }
    return AC_WEAPON_SLOT_HAND;
}

AC_ResetPlayerData(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    g_PlayerACData[playerid][pacEnabled] = true;
    g_PlayerACData[playerid][pacFlags] = AC_NONE;
    g_PlayerACData[playerid][pacWarnings] = 0;
    GetPlayerPos(playerid, g_PlayerACData[playerid][pacLastPosX], g_PlayerACData[playerid][pacLastPosY], g_PlayerACData[playerid][pacLastPosZ]);
    GetPlayerHealth(playerid, g_PlayerACData[playerid][pacLastHealth]);
    GetPlayerArmour(playerid, g_PlayerACData[playerid][pacLastArmour]);
    g_PlayerACData[playerid][pacLastMoney] = GetPlayerMoney(playerid);
    g_PlayerACData[playerid][pacLastScore] = GetPlayerScore(playerid);
    g_PlayerACData[playerid][pacLastVehicle] = GetPlayerVehicleID(playerid);
    g_PlayerACData[playerid][pacLastVehicleHealth] = 1000.0;
    g_PlayerACData[playerid][pacLastState] = GetPlayerState(playerid);
    g_PlayerACData[playerid][pacLastAnimation] = GetPlayerAnimationIndex(playerid);
    g_PlayerACData[playerid][pacLastSpecialAction] = GetPlayerSpecialAction(playerid);
    g_PlayerACData[playerid][pacLastSyncTick] = GetTickCount();
    g_PlayerACData[playerid][pacLastUpdateTick] = GetTickCount();
    g_PlayerACData[playerid][pacLastShotTick] = GetTickCount();
    g_PlayerACData[playerid][pacLastPing] = GetPlayerPing(playerid);
    GetPlayerResolution(playerid, g_PlayerACData[playerid][pacResolutionX], g_PlayerACData[playerid][pacResolutionY]);
    g_PlayerACData[playerid][pacSpawnedOnce] = false;
    g_PlayerACData[playerid][pacLastSpawnTick] = 0;
    g_PlayerACData[playerid][pacSpawnAttempts] = 0;
    g_PlayerACData[playerid][pacDeathState] = false;
    g_PlayerACData[playerid][pacWeaponMismatchCount] = 0;
    
    for(new i = 0; i < AC_MAX_WEAPON_ID + 1; i++)
    {
        g_PlayerACData[playerid][pacLastAmmo][i] = 0;
    }
    
    return 1;
}

AC_EnablePlayerChecks(playerid, bool:enable)
{
    if(!IsPlayerConnected(playerid)) return 0;
    g_PlayerACData[playerid][pacEnabled] = enable;
    return 1;
}

AC_IsPlayerCheckEnabled(playerid)
{
    if(!IsPlayerConnected(playerid)) return false;
    return g_PlayerACData[playerid][pacEnabled];
}

AC_SetPlayerFlag(playerid, AC_FLAGS:flagid, value)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(value)
    {
        g_PlayerACData[playerid][pacFlags] |= flagid;
    }
    else
    {
        g_PlayerACData[playerid][pacFlags] &= ~flagid;
    }
    return 1;
}

AC_GetPlayerFlag(playerid, AC_FLAGS:flagid)
{
    if(!IsPlayerConnected(playerid)) return false;
    return !!(g_PlayerACData[playerid][pacFlags] & flagid);
}

AC_ResetPlayerFlags(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    g_PlayerACData[playerid][pacFlags] = AC_NONE;
    return 1;
}

AC_CheckSpeedHack(playerid)
{
    if(!IsPlayerConnected(playerid) || !g_PlayerACData[playerid][pacEnabled]) return 0;
    
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    
    new Float:speed = AC_GetDistance(x, y, z, g_PlayerACData[playerid][pacLastPosX], g_PlayerACData[playerid][pacLastPosY], g_PlayerACData[playerid][pacLastPosZ]);
    
    new currentTick = GetTickCount();
    new timeDiff = currentTick - g_PlayerACData[playerid][pacLastSyncTick];
    
    if(timeDiff < 1) return 0;
    
    speed = speed * 1000.0 / float(timeDiff);
    new Float:maxSpeed = AC_MAX_SPRINT_SPEED;
    
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        new Float:vHealth;
        GetVehicleHealth(vehicleid, vHealth);
        maxSpeed = AC_MAX_VEHICLE_SPEED;
        
        if(vHealth < g_PlayerACData[playerid][pacLastHealth] - 100.0)
        {
            AC_SetPlayerFlag(playerid, AC_VEHICLEHACK, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_VEHICLEHACK, "Vehicle health hack");
        }
        g_PlayerACData[playerid][pacLastHealth] = vHealth;
    }
    
    if(speed > maxSpeed && !IsPlayerInWater(playerid) && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
    {
        AC_SetPlayerFlag(playerid, AC_SPEEDHACK, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_SPEEDHACK, "Speed exceeds limits");
        return 1;
    }
    
    g_PlayerACData[playerid][pacLastPosX] = x;
    g_PlayerACData[playerid][pacLastPosY] = y;
    g_PlayerACData[playerid][pacLastPosZ] = z;
    g_PlayerACData[playerid][pacLastSyncTick] = currentTick;
    return 0;
}

AC_CheckWeaponHack(playerid)
{
    if(!IsPlayerConnected(playerid) || !g_PlayerACData[playerid][pacEnabled]) return 0;
    
    for(new slot = 0; slot < 13; slot++)
    {
        new weaponid, ammo;
        GetPlayerWeaponData(playerid, slot, weaponid, ammo);
        
        if(!AC_IsValidWeapon(t_WEAPON_SLOT:weaponid))
        {
            AC_SetPlayerFlag(playerid, AC_WEAPONHACK, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_WEAPONHACK, "Invalid weapon ID");
            ResetPlayerWeapons(playerid);
            return 1;
        }
        
        if(ammo > 9999 && _:weaponid != 38) // 38 = Minigun, tambahkan _: untuk mengkonversi tag
        {
            AC_SetPlayerFlag(playerid, AC_AMMOHACK, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_AMMOHACK, "Excessive ammo");
            ResetPlayerWeapons(playerid);
            return 1;
        }
    }
    return 0;
}

AC_CheckSyncData(playerid)
{
    if(!IsPlayerConnected(playerid) || !g_PlayerACData[playerid][pacEnabled]) return 0;
    
    new health, armour, weapon, specialaction;
    GetPlayerLastSyncedData(playerid, health, armour, weapon, specialaction);
    
    new currentTick = GetTickCount();
    if(currentTick - g_PlayerACData[playerid][pacLastSyncTick] > AC_MAX_SYNC_DELAY)
    {
        AC_SetPlayerFlag(playerid, AC_SYNCDATA, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_SYNCDATA, "Sync data mismatch");
        return 1;
    }
    
    if(health > g_PlayerACData[playerid][pacLastHealth] + 50.0)
    {
        AC_SetPlayerFlag(playerid, AC_HEALTHHACK, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_HEALTHHACK, "Health hack detected");
        return 1;
    }
    
    if(armour > g_PlayerACData[playerid][pacLastArmour] + 50.0)
    {
        AC_SetPlayerFlag(playerid, AC_ARMORHACK, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_ARMORHACK, "Armour hack detected");
        return 1;
    }
    
    g_PlayerACData[playerid][pacLastHealth] = health;
    g_PlayerACData[playerid][pacLastArmour] = armour;
    g_PlayerACData[playerid][pacLastSyncTick] = currentTick;
    return 0;
}

AC_CheckAttachments(playerid)
{
    if(!IsPlayerConnected(playerid) || !g_PlayerACData[playerid][pacEnabled]) return 0;
    
    new count = 0;
    for(new i = 0; i < AC_MAX_ATTACHED_OBJECTS; i++)
    {
        new modelid, bone, Float:offset[3], Float:rot[3], Float:scale[3], color1, color2;
        if(GetPlayerAttachedObject(playerid, i, modelid, bone, offset[0], offset[1], offset[2], 
            rot[0], rot[1], rot[2], scale[0], scale[1], scale[2], color1, color2))
        {
            count++;
            
            if(scale[0] > 5.0 || scale[1] > 5.0 || scale[2] > 5.0)
            {
                AC_SetPlayerFlag(playerid, AC_ATTACHMENTHACK, true);
                CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_ATTACHMENTHACK, "Attachment hack detected");
                return 1;
            }
        }
    }
    
    if(count > g_PlayerACData[playerid][pacLastState] + 2)
    {
        AC_SetPlayerFlag(playerid, AC_ATTACHMENTHACK, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_ATTACHMENTHACK, "Attachment count mismatch");
        return 1;
    }
    
    g_PlayerACData[playerid][pacLastState] = count;
    return 0;
}

AC_CheckFakeSpawn(playerid)
{
    if(!IsPlayerConnected(playerid) || !g_PlayerACData[playerid][pacEnabled]) return 0;
    
    new currentTick = GetTickCount();
    new playerState = GetPlayerState(playerid);
    
    // Check if player hasn't spawned properly
    if(!g_PlayerACData[playerid][pacEnabled])
    {
        if(_:playerState != _:AC_STATE_NONE && _:playerState != _:AC_STATE_SPECTATING)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Fake spawn detected");
            Kick(playerid);
            return 1;
        }
    }
    
    // Check for rapid spawning
    if(currentTick - g_PlayerACData[playerid][pacLastSyncTick] < 1000)
    {
        g_PlayerACData[playerid][pacWarnings]++;
        if(g_PlayerACData[playerid][pacWarnings] > AC_MAX_WARNINGS)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Rapid spawn detected");
            Kick(playerid);
            return 1;
        }
    }
    else
    {
        g_PlayerACData[playerid][pacWarnings] = 0;
    }
    
    // Check for spawn state manipulation
    if(_:playerState == _:AC_STATE_WASTED)
    {
        new Float:health;
        GetPlayerHealth(playerid, health);
        if(health > 0)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Spawn state manipulation detected");
            Kick(playerid);
            return 1;
        }
    }
    
    return 0;
}

AC_CheckPlayerState(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new t_PLAYER_STATE:playerState = t_PLAYER_STATE:GetPlayerState(playerid);
    
    // Check if player hasn't spawned properly
    if(!g_PlayerACData[playerid][pacEnabled])
    {
        if(playerState != AC_STATE_NONE && playerState != AC_STATE_SPECTATING)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Fake spawn detected");
            Kick(playerid);
            return 1;
        }
    }
    
    // Check for rapid spawn
    new currentTick = GetTickCount();
    if(currentTick - g_PlayerACData[playerid][pacLastSyncTick] < 1000)
    {
        g_PlayerACData[playerid][pacWarnings]++;
        if(g_PlayerACData[playerid][pacWarnings] > AC_MAX_WARNINGS)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Rapid spawn detected");
            Kick(playerid);
            return 1;
        }
    }
    
    // Check for death state manipulation
    if(playerState == AC_STATE_WASTED)
    {
        new Float:health;
        GetPlayerHealth(playerid, health);
        if(health > 0)
        {
            AC_SetPlayerFlag(playerid, AC_FAKESPAWN, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_FAKESPAWN, "Spawn state manipulation detected");
            Kick(playerid);
            return 1;
        }
    }
    
    return 0;
}

// Callback hooks
public AC_OnPlayerConnect(playerid)
{
    AC_ResetPlayerData(playerid);
    
    #if defined AC_OnPlayerConnect
        return AC_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect AC_OnPlayerConnect
#if defined AC_OnPlayerConnect
    forward AC_OnPlayerConnect(playerid);
#endif

public AC_OnPlayerSpawn(playerid)
{
    g_PlayerACData[playerid][pacSpawnedOnce] = true;
    g_PlayerACData[playerid][pacLastSpawnTick] = GetTickCount();
    g_PlayerACData[playerid][pacDeathState] = false;
    AC_ResetPlayerFlags(playerid);
    AC_CheckFakeSpawn(playerid);
    
    #if defined AC_OnPlayerSpawn
        return AC_OnPlayerSpawn(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn AC_OnPlayerSpawn
#if defined AC_OnPlayerSpawn
    forward AC_OnPlayerSpawn(playerid);
#endif

public AC_OnPlayerUpdate(playerid)
{
    if(!g_PlayerACData[playerid][pacEnabled]) return 1;
    
    // Basic checks
    AC_CheckSpeedHack(playerid);
    AC_CheckWeaponHack(playerid);
    AC_CheckSyncData(playerid);
    AC_CheckAttachments(playerid);
    
    // Vehicle checks
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(!IsValidVehicle(vehicleid))
        {
            AC_SetPlayerFlag(playerid, AC_VEHICLEHACK, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_VEHICLEHACK, "Invalid vehicle entry");
            return 0;
        }
        
        new Float:vHealth;
        GetVehicleHealth(vehicleid, vHealth);
        if(vHealth > AC_MAX_VEHICLE_HEALTH)
        {
            AC_SetPlayerFlag(playerid, AC_VEHICLEHACK, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_VEHICLEHACK, "Vehicle health hack");
            SetVehicleHealth(vehicleid, AC_MAX_VEHICLE_HEALTH);
            return 0;
        }
    }
    
    // Money checks
    new money = GetPlayerMoney(playerid);
    if(money > g_PlayerACData[playerid][pacLastMoney] + AC_MAX_MONEY_AMOUNT)
    {
        AC_SetPlayerFlag(playerid, AC_MONEYHACK, true);
        CallLocalFunction("AC_OnPlayerCheatDetected", "iis", playerid, _:AC_MONEYHACK, "Money hack detected");
        ResetPlayerMoney(playerid);
        return 0;
    }
    g_PlayerACData[playerid][pacLastMoney] = money;
    
    // Ping checks
    new ping = GetPlayerPing(playerid);
    if(ping > AC_MAX_PING)
    {
        CallLocalFunction("AC_OnPlayerACKick", "iis", playerid, -1, "High ping");
        Kick(playerid);
        return 0;
    }
    g_PlayerACData[playerid][pacLastPing] = ping;
    
    // Update last sync time
    g_PlayerACData[playerid][pacLastUpdateTick] = GetTickCount();
    
    #if defined AC_OnPlayerUpdate
        return AC_OnPlayerUpdate(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate AC_OnPlayerUpdate
#if defined AC_OnPlayerUpdate
    forward AC_OnPlayerUpdate(playerid);
#endif

public AC_OnPlayerDeath(playerid, killerid, reason)
{
    if(!g_PlayerACData[playerid][pacEnabled]) return 1;
    
    g_PlayerACData[playerid][pacDeathState] = true;
    g_PlayerACData[playerid][pacSpawnedOnce] = false;
    
    if(killerid != INVALID_PLAYER_ID)
    {
        // Check for fake kills
        new Float:pos[3], Float:killerPos[3];
        GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
        GetPlayerPos(killerid, killerPos[0], killerPos[1], killerPos[2]);
        
        new Float:distance;
        distance = GetPlayerDistanceFromPoint(killerid, pos[0], pos[1], pos[2]);
        
        new weapon = GetPlayerWeapon(killerid);
        if(distance > 150.0 && weapon != 34 && weapon != 33 && weapon != 35) // Exclude sniper rifles
        {
            AC_SetPlayerFlag(killerid, AC_FAKEKILL, true);
            CallLocalFunction("AC_OnPlayerCheatDetected", "iis", killerid, _:AC_FAKEKILL, "Fake kill detected");
        }
    }
    
    #if defined AC_OnPlayerDeath
        return AC_OnPlayerDeath(playerid, killerid, reason);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath AC_OnPlayerDeath
#if defined AC_OnPlayerDeath
    forward AC_OnPlayerDeath(playerid, killerid, reason);
#endif


AC_Log(const message[])
{
    new File:file = fopen("logs/ac_hytam_log.txt", io_append);
    if(file)
    {
        new timestamp[32], year, month, day, hour, minute, second;
        getdate(year, month, day);
        gettime(hour, minute, second);
        format(timestamp, sizeof(timestamp), "[%02d/%02d/%d %02d:%02d:%02d]", day, month, year, hour, minute, second);
        
        fwrite(file, timestamp);
        fwrite(file, " ");
        fwrite(file, message);
        fwrite(file, "\r\n");
        fclose(file);
    }
}


public AC_OnPlayerCheatDetected(playerid, AC_FLAGS:cheatid, const details[])
{
    new logstr[256], name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    
    format(logstr, sizeof(logstr), "Player %s[%d] cheat detected: %s (%d) - %s", 
        name, playerid, AC_GetCheatName(cheatid), _:cheatid, details);
    AC_Log(logstr);
    
    return 1;
}


stock AC_GetCheatName(AC_FLAGS:cheatid)
{
    static cheatname[32];
    switch(_:(cheatid))
    {
        case (_:AC_SPEEDHACK): format(cheatname, sizeof(cheatname), "Speed Hack");
        case (_:AC_WEAPONHACK): format(cheatname, sizeof(cheatname), "Weapon Hack");
        case (_:AC_AMMOHACK): format(cheatname, sizeof(cheatname), "Ammo Hack");
        case (_:AC_FLYHACK): format(cheatname, sizeof(cheatname), "Fly Hack");
        case (_:AC_AIRBREAK): format(cheatname, sizeof(cheatname), "Air Break");
        case (_:AC_TELEPORT): format(cheatname, sizeof(cheatname), "Teleport Hack");
        case (_:AC_MONEYHACK): format(cheatname, sizeof(cheatname), "Money Hack");
        case (_:AC_HEALTHHACK): format(cheatname, sizeof(cheatname), "Health Hack");
        case (_:AC_ARMORHACK): format(cheatname, sizeof(cheatname), "Armor Hack");
        case (_:AC_RAPIDFIRE): format(cheatname, sizeof(cheatname), "Rapid Fire");
        case (_:AC_CARJACK): format(cheatname, sizeof(cheatname), "Car Jack");
        case (_:AC_VEHICLEHACK): format(cheatname, sizeof(cheatname), "Vehicle Hack");
        case (_:AC_AIMBOT): format(cheatname, sizeof(cheatname), "Aimbot");
        case (_:AC_WALLHACK): format(cheatname, sizeof(cheatname), "Wall Hack");
        case (_:AC_SPAWNVEHICLE): format(cheatname, sizeof(cheatname), "Vehicle Spawn Hack");
        case (_:AC_FAKEKILL): format(cheatname, sizeof(cheatname), "Fake Kill");
        case (_:AC_GODMODE): format(cheatname, sizeof(cheatname), "God Mode");
        case (_:AC_INVISIBLE): format(cheatname, sizeof(cheatname), "Invisibility Hack");
        case (_:AC_LAGCOMP): format(cheatname, sizeof(cheatname), "Lag Compensation Hack");
        case (_:AC_TUNINGHACK): format(cheatname, sizeof(cheatname), "Tuning Hack");
        case (_:AC_ATTACHMENTHACK): format(cheatname, sizeof(cheatname), "Attachment Hack");
        case (_:AC_SYNCDATA): format(cheatname, sizeof(cheatname), "Sync Data Hack");
        case (_:AC_ANIMATION): format(cheatname, sizeof(cheatname), "Animation Hack");
        case (_:AC_PICKUPHACK): format(cheatname, sizeof(cheatname), "Pickup Hack");
        case (_:AC_FAKESPAWN): format(cheatname, sizeof(cheatname), "Fake Spawn");
        default: format(cheatname, sizeof(cheatname), "Unknown (%d)", _:cheatid);
    }
    return cheatname;
}
