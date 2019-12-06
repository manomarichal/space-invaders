cmake_minimum_required(VERSION 3.15)
project(space_invaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${SIZE--_SOURCE_DIR}/src/*.h  )
file(GLOB_RECURSE SRCS ${SIZE--_SOURCE_DIR}/src/*.cpp)

add_executable(space_invaders ${HDRS} ${SRCS} src/entities/enemies/hexagon/Hexagon.cpp src/entities/enemies/hexagon/Hexagon.h src/entities/enemies/Enemy.h src/entities/enemies/EnemyView.h src/entities/Observer.h src/entities/Subject.h src/entities/playership/PlayerShipView.cpp src/entities/playership/PlayerShipView.h src/entities/playership/PlayerShipController.cpp src/entities/playership/PlayerShipController.h src/entities/playership/PlayerShipEvent.h src/entities/projectiles/standard/StandardProjectile.cpp src/entities/projectiles/standard/StandardProjectile.h src/entities/projectiles/standard/StandardProjectileView.cpp src/entities/projectiles/standard/StandardProjectileView.h src/entities/projectiles/standard/StandardProjectileController.cpp src/entities/projectiles/standard/StandardProjectileController.h src/entities/projectiles/ProjectileFactory.cpp src/entities/projectiles/ProjectileFactory.h src/util/Object.h)
set(CMAKE_CXX_FLAGS " -march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wnull-dereference -Wdouble-promotion -Wformat=2")

target_link_libraries(space_invaders "-lsfml-graphics -lsfml-window -lsfml-system")

# -Wall
# -Werror # treat all warnings as errors
#- Wextra # reasonable and standard
# -Wshadow # warn the user if a variable declaration shadows one from a parent context
# -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor
# -Wold-style-cast # warn for c-style casts
# -Wcast-align # warn for potential performance problem casts
# -Wunused # warn on anything being unused
# -Woverloaded-virtual # warn if you overload (not override) a virtual function
# -Wpedantic # warn if non-standard C++ is used
# -Wconversion # warn on type conversions that may lose data
# -Wsign-conversion # warn on sign conversions
# -Wnull-dereference # warn if a null dereference is detected
# -Wdouble-promotion # warn if float is implicit promoted to double
# -Wformat=2 # warn on security issues around functions that format output (ie printf)