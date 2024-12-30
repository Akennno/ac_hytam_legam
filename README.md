# 🛡️ Hytam Legam AC Pack

[![SA-MP](https://img.shields.io/badge/SA--MP-0.3.7-2f2f2f.svg)](https://www.sa-mp.com/)
[![open.mp](https://img.shields.io/badge/open.mp-1.1.0-2f2f2f.svg)](https://www.open.mp/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

> A comprehensive anti-cheat system implementation for SA-MP/open.mp servers using PAWN scripting language.

---

## ✨ Features

- 🚀 Speed Hack Detection (Vehicle, Sprint, Swimming)
- 🔫 Weapon Hack Detection
- 🎯 Ammo Hack Detection
- ❤️ Health/Armor Value Validation
- 🎮 Attached Objects Validation
- 📡 Ping and Packet Loss Monitoring
- 💰 Money Amount Validation

---

## 📋 Requirements

- 🎮 SA-MP Server 0.3.7-R2 or later / open.mp server
- 💻 PAWN Compiler 3.10.10 or later

---

## 🚀 Installation

1. Download the latest release from the repository
2. Copy the `hytam_legam_ac.inc` file to your `pawno/include` directory
3. Include the file in your gamemode:

```pawn
#include <hytam_legam_ac>
```

---

## 💡 Implementation

### 📢 Callbacks

The anti-cheat system provides several callbacks that you can use in your gamemode:

```pawn
public AC_OnCheatDetected(playerid, cheatid, const reason[])
{
    new string[128], name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    format(string, sizeof(string), "Player %s detected using cheat: %s", name, reason);
    SendAdminMessage(COLOR_RED, string);
    return 1;
}

public AC_OnPlayerSpawn(playerid)
{
    // Handle player spawn anti-cheat logic
    return 1;
}
```

### ⚙️ Configuration Constants

The system includes several configurable constants:

```pawn
#define AC_MAX_ARMOR_VALUE      100.0    // Maximum armor value
#define AC_MAX_HEALTH_VALUE     100.0    // Maximum health value
#define AC_MAX_VEHICLE_HEALTH   1000.0   // Maximum vehicle health
#define AC_MAX_ATTACHED_OBJECTS 10       // Maximum attached objects
#define AC_MAX_WEAPON_MISMATCH  3        // Maximum weapon mismatch count
#define AC_MAX_SYNC_DELAY       300      // Maximum sync delay (ms)
#define AC_MAX_SPRINT_SPEED     50.0     // Maximum sprint speed
#define AC_MAX_VEHICLE_SPEED    300.0    // Maximum vehicle speed
#define AC_MAX_SWIM_SPEED       15.0     // Maximum swim speed
#define AC_MAX_PING             500      // Maximum allowed ping
#define AC_MAX_PACKET_LOSS      2.0      // Maximum packet loss percentage
#define AC_MAX_MONEY_AMOUNT     999999999// Maximum money amount
```

### 🚫 Cheat Detection Flags

The system uses flags to identify different types of cheats:

```pawn
enum AC_FLAGS {
    AC_NONE = 0,         // No cheat detected
    AC_SPEEDHACK = 1,    // Speed hack detected
    AC_WEAPONHACK = 2,   // Weapon hack detected
    AC_AMMOHACK = 4      // Ammo hack detected
    // ... other flags
}
```

### 🛠️ Utility Functions

#### Check if player has cheat flag:
```pawn
bool:AC_HasPlayerFlag(playerid, AC_FLAGS:flagid)
```

---

## 🤝 Contributing

We welcome contributions! Feel free to:

- 🐛 Report bugs
- 💡 Suggest new features
- 🔧 Submit pull requests

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 💬 Support

Need help? Have questions?

- 📝 Open an issue in the repository
- 📧 Contact the development team

---

<div align="center">
Made with ❤️ by southclown n xenoisgod
</div>