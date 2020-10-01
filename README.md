# cub3D

**Cub3D (42cursus)**

- **Actual Status** : v1.03
- **Result**        : 103 %
- **Observations**  :
  * The only mandatory setting required is the map. The program will use default values and textures if and only if none are specified by the cub file.
  * Handles errors with indicative error message.
  * Handles any kind of map (shape-wise), including empty islands in the middle of the map.
  * If a map section is isolated (not accessible by walking) the map will be rendered as long as there are no map-leaks or other errors in the playable portion. Any sprites on the unaccessible areas will not be rendered nor be included in calculations (slightly improving performance as well).
  * Default values can be changed in *cub3d.h*. For instance the **min/max resolution heights** (*SCREEN_HEIGHT_LL* and *SCREEN_HEIGHT_UL* respectively), **min/max resolution widths** (*SCREEN_WIDTH_LL* and *SCREEN_WIDTH_UL* respectively), rendered resolution will always be betweeen these values; **default resolution height** (*SH*) and **default resolution width** (*SW*); **extra information** about what the program is doing during start-up (*VERBOSE*), by default this is off (0), change to 1 to enable; **map handling information** (*PRINT_MAPS*) is off (0) by default, change to 1 to see how the information is read and loaded into the map matrix.
  * Contains an example cub file (*example.cub*).
- **Controls**     :
  * **_W_**: walk forward.
  * **_S_**: walk forward.
  * **_A_**: strafe left.
  * **_D_**: strafe right.
  * **_Right_**: rotate camera to the right (clockwise).
  * **_Left_**: rotate camera to the left (counter-clockwise).
  * **_Esc_**: Exit game.


Cub3D project on raycasting developped for the **42** cursus.
For a detailed version history, check *version_history_dev.md* and *version_history_master.md*.