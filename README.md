# Bomb the nuclear reactor game 🚁💥

A 2D action game built with SFML/C++ where you infiltrate a facility, plant explosives, and race against time to escape!

## Game Objective
- Collect all 4 TNT bombs
- Find keys to unlock gates
- Reach and activate the nuclear reactor
- Escape back to the starting helicopter before detonation

## Features
### Environment
- **Destructible Objects**:
  - Fences
  - Trees 
  - Stone piles
- **Indestructible Walls**:
  - Stone walls

### Power-ups (Presents)
| Type      | Effect                          |
|-----------|---------------------------------|
| Shield    | Temporary invincibility         |
| Extra Life| Add Life                        |
| Rockets   | Add High-damage rockets         |

### Combat
- Multiple enemy types
- Score system for:
  - Enemy kills
  - Present collection
  - Mission completion

## Controls
| Action          | Input                   |
|-----------------|-------------------------|
| Movement        | Arrow Keys              |
| Shoot           | Left Mouse Button       |
| Fire Rocket     | Right Mouse Button      |
| Interact        | Automatic (walk near)   |

## Requirements
- SFML 2.5+ (pre-installed)
- C++17 compiler


## Installation
- Clone the repository.
- Build with CMake or your preferred system.
- Ensure SFML libraries are properly linked.
