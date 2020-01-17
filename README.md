# SPACE INVADERS

## Practical information:
- The rapport is in the /docs file
- There is a doxygen, the doxyfile is located in /docs

Build Status: [![Build Status](https://travis-ci.com/shano19/space-invaders.svg?token=M5KHdSHUrgZ1sjKYe9px&branch=master)](https://travis-ci.com/shano19/space-invaders)

## How to set up:
First time installing run
``` bash
$ chmod +x run.sh
$ ./run.sh
```
This will compile and run the game with the basic settings file.
To play other sets of levels,  you will need to make a settings.json file, or use one of the examples.
This file contains how big the screen should be, and what levels you want to play.
``` json
{
  "Screen":
  {
    "width": 1200,
    "height":900
  },
  "Levels": [
    "./resources/levels/single_enemy.json"
  ]
}
```

## Run the game with a settings file:
./space_invaders path_to_settings_file

## Level files:
The first thing a level file has to have is a coordinate system, this is the coordinate system you can use to place objects
and that the game logic will use, example:

``` json
"Space": {
    "xmax": 4,
    "xmin": -4,
    "ymax": 3,
    "ymin": -3
  }
```
After that you need to specify where the playership's starting location is, example:

``` json
"Playership": {
    "x": 0,
    "y": -2.5
  }
```

Finally, you need to add objects to your level, you can add shields an different type of enemies, example:

```json
"Shields": [
    {
      "x":-2 ,
      "y":-1.5
    }
  ]
```

For enemies you have the choice between either red, green or purple aliens
- red aliens are standard enemies that take 1 hit to kill
- green aliens shoot back at you
- purple aliens take 3 hits to kill and shrink in size everytime they get hit
enemy example:

```json
"Enemies": [
    {
      "type": "RedAlien",
      "x": 3.0,
      "y": 1.3
    }
  ]
 ```
You can leave both of these empty if you dont want any shields or enemies.

## Controls:
- moving left: Q
- moving right: D
- shooting: space

## Extra rules:
- You have 3 lives for every level.
- You lose 1 life upon hitting an enemy projectile.
- You lose 1 life upon colliding with an enemy (which destroys the enemy).
- You lose the game if an enemy touches the bottom corner of the screen.
- Shields are destroyed when they collide with an enemy (which also destroys the enemy).