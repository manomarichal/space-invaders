SPACE INVADERS

How to set up:
You will need to make a settings.json file to play the game, or use one of the examples.
This file contains how big the screen should be, and what levels you want to play.
The executable space_invaders is located in ./build, run this with as argument the path to
your settings file relative to the build directory.

Level files:
The first thing a level file has to have is a coordinate system, this is the coordinate system you can use to place objects
and that the game logic will use, for example:

"Space": {
    "xmax": 4,
    "xmin": -4,
    "ymax": 3,
    "ymin": -3
  }

after that you need to specify where the playership's starting location is, example:

"Playership": {
    "x": 0,
    "y": -2.5
  },

Finally, you need to add objects to your level, you can add shields an different type of enemies:
shield example:

"Shields": [
    {
      "x":-2 ,
      "y":-1.5
    },
  ]

For enemies you have the choice between either red, green or purple aliens
- red aliens are standard enemies that take 1 hit to kill
- green aliens shoot back at you
- purple aliens take 3 hits to kill and shrink in size everytime they get hit
enemy example:

"Enemies": [
    {
      "type": "RedAlien",
      "x": 3.0,
      "y": 1.3
    }
  ]
You can leave both of these empty if you dont want any shields or enemies.

Controls:
- moving left: Q
- moving right: D
- shooting: space

Extra rules:
- you have 3 lives for every level
- you lose 1 life upon hitting an enemy projectile
- you lose 1 life upon colliding with an enemy (which destroys the enemy)
- you lose the game if an enemy touches the bottom corner of the screen
- shields are destroyed when they collide with an enemy (which also destroys the enemy)